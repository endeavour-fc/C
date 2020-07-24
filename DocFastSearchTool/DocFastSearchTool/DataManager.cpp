#include"DataManager.h"

#pragma comment(lib, "./sqlite/sqlite3.lib")

SqliteManager::SqliteManager() :m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	Close();
}
void SqliteManager::Open(const string &path)
{
	int rc = sqlite3_open(path.c_str(), &m_db);
	if(rc != SQLITE_OK)
	{
		ERROR_LOG("Can't open database");
		return;
	}
	else
		TRACE_LOG("Opened database successfully")
}

void SqliteManager::Close()
{
	if(m_db)
	{
		int rc = sqlite3_close(m_db);
		if(rc != SQLITE_OK)
		{
			ERROR_LOG("Close Database failed.");
			return;
		}
		else
			TRACE_LOG("Close Database successfully.");
		m_db = nullptr;
	}
}

void SqliteManager::ExecuteSql(const string &sql)
{
	char *zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("SQL error(sql: %s): %s\n",sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		TRACE_LOG("Exec Sql(sql:%s) successfully\n", sql.c_str());
	}
}

void SqliteManager::GetResTable(const string& sql, int &row, int &col, char**&ppRet)
{
	char *zErrMsg = 0;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		ERROR_LOG("GetResTable error(sql: %s): %s\n",sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		TRACE_LOG("GetResTable  successfully");
	}
}

//////////////////////////////////////////////////////////////////////
//自动获取表结果类 实现
AutoGetResTable::AutoGetResTable(SqliteManager *db, const string &sql, int &row, int &col, char **&ppRet)
:m_db(db),m_ppRet(nullptr)
{
	m_db->GetResTable(sql, row, col, ppRet);
	m_ppRet = ppRet;

}
AutoGetResTable::~AutoGetResTable()
{
	if(m_ppRet)
		sqlite3_free_table(m_ppRet);
}

/////////////////////////////////////////////////////////////////////

DataManager& DataManager::CreateInstance()
{
	static DataManager inst;
	return inst;
}

DataManager::DataManager()
{
	m_dbmgr.Open(DOC_DB);
	
	//创建数据库表
	InitSqlite();
}
DataManager::~DataManager()
{}

void DataManager::InitSqlite()
{
	char sql[MAX_SQL_SIZE] = {0};
	sprintf(sql,  "create table if not exists %s (id INTEGER PRIMARY KEY autoincrement, doc_path text, doc_name text,doc_name_pinyin text, doc_name_initials text)", DOC_TABLE);
	m_dbmgr.ExecuteSql(sql);

	//清空数据库
	ClearDoc();
}

//向数据库获取数据
void DataManager::GetDocs(const string &path, set<string>& docs)
{
	//select doc_name from doc_tb where doc_path = path.c_str()
	char sql[MAX_SQL_SIZE] = {0};
	sprintf(sql, "select doc_name from %s where doc_path='%s'", DOC_TABLE, path.c_str());

	int row=0, col=0;
	char **ppRet = 0;

	//获取结果表
	//m_dbmgr.GetResTable(sql, row, col, ppRet);
	AutoGetResTable at(&m_dbmgr, sql, row, col, ppRet);

    //将结果保存到set
	for(int i=1; i<=row; ++i)
		docs.insert(ppRet[i]);

	//释放结果表
	//sqlite3_free_table(ppRet);
}
//向数据库插入文档
void DataManager::InsertDoc(const string &path, string doc)
{
	char sql[MAX_SQL_SIZE] = {0};
	string pinyin = ChineseConvertPinYinAllSpell(doc);
	string initials = ChineseConvertPinYinInitials(doc);

	sprintf(sql, "insert into %s values(NULL, '%s', '%s', '%s', '%s')",
			DOC_TABLE, path.c_str(), doc.c_str(), pinyin.c_str(), initials.c_str());
	m_dbmgr.ExecuteSql(sql);
}

//向数据库删除文档
void DataManager::DeleteDoc(const string &path, string doc)
{
	char sql[MAX_SQL_SIZE] = {0};
	sprintf(sql, "delete from  %s where doc_path='%s' and doc_name='%s'", DOC_TABLE, path.c_str(), doc.c_str());
	m_dbmgr.ExecuteSql(sql);

	//递归删除子目录
	//C:\Users\baoso\Desktop\55班\test\阶段性考试试卷\my_dir
	string doc_path = path;
	doc_path += "\\";
	//C:\Users\baoso\Desktop\55班\test\阶段性考试试卷\my_dir\
	doc_path += doc;
	//C:\Users\baoso\Desktop\55班\test\阶段性考试试卷\my_dir\AA
	sprintf(sql, "delete from %s where doc_path like '%s%%'", DOC_TABLE, doc_path.c_str());
	m_dbmgr.ExecuteSql(sql);
}

void DataManager::ClearDoc()
{
	char sql[MAX_SQL_SIZE] = {0};
	sprintf(sql, "delete from %s", DOC_TABLE);
	m_dbmgr.ExecuteSql(sql);
}

void DataManager::Search(const string &key, vector<pair<string, string>> &doc_path)
{
	char sql[MAX_SQL_SIZE] = {0};
	int row=0, col=0;
	char **ppRet = 0;
	
	//科技   %keji%
	string key_pinyin = "%";
	key_pinyin += ChineseConvertPinYinAllSpell(key);
	key_pinyin +="%";

	//科技   %kj%
	string key_initials = "%";
	key_initials += ChineseConvertPinYinInitials(key);
	key_initials += "%";

	//select dco_name, doc_path from doc_tb where doc_name like '%%s%';
	sprintf(sql, "select doc_name, doc_path from %s where doc_name_pinyin like '%s' or doc_name_initials like '%s'",
			DOC_TABLE, key_pinyin.c_str(), key_initials.c_str());

	//m_dbmgr.GetResTable(sql, row, col, ppRet);
	AutoGetResTable at(&m_dbmgr, sql, row, col, ppRet);


	for(int i=1; i<=row; ++i)
	{   										//name            path
		doc_path.push_back(make_pair(ppRet[i*col+0], ppRet[i*col+1]));
	}
	
	//sqlite3_free_table(ppRet);  //源代码级别
}

void DataManager::SplitHightLight(const string &str, const string &key, 
								  string &prefix, string &hightlight, string &suffix)
{
	//str = "123比特科技,让就业更简单666"; 
	//key = "就业";

	string strlower = str;
	string keylower = key;
	transform(str.begin(), str.end(), strlower.begin(), tolower);
	transform(key.begin(), key.end(), keylower.begin(), tolower);

	//1 中文搜索, 如果匹配，直接分割
	size_t pos = strlower.find(keylower);
	if(pos != string::npos)
	{
		prefix = str.substr(0, pos);
		hightlight = str.substr(pos, keylower.size());
		suffix = str.substr(pos+keylower.size(), string::npos);
		return;
	}

	//2 拼音全拼搜索，如果能匹配，则需要匹配分离的汉字和拼音
	//str = "123比特科技,abc,让就业更简单666"; 
	//str_pinyin = "123bitekeji,abc,rangjiuyegengjiandan666"
	//key_pinyin = "jiuye"

	string str_pinyin = ChineseConvertPinYinAllSpell(strlower);
	string key_pinyin = ChineseConvertPinYinAllSpell(keylower);
	pos = str_pinyin.find(key_pinyin);
	if(pos != string::npos)
	{
		size_t str_index = 0;
		size_t pinyin_index = 0;

		size_t hightlight_index = 0;
		size_t hightlight_len = 0;

		while(str_index < strlower.size())
		{
			if(pinyin_index == pos)
			{
				hightlight_index = str_index;
			}
			if(pinyin_index >= pos + key_pinyin.size())
			{
				hightlight_len = str_index - hightlight_index + 1;
				break;
			}
			//判断原字符串str_index下标所指是否为字符
			if(strlower[str_index]>=0 && strlower[str_index]<=127)
			{
				//是字符
				str_index++;
				pinyin_index++;
			}
			else
			{
				//是汉字
				string  word(strlower, str_index, 2); //提取一个汉字
				string  subpinyin = ChineseConvertPinYinAllSpell(word);
				str_index += 2;
				pinyin_index += subpinyin.size();
			}
		}
		prefix = str.substr(0, hightlight_index);
		hightlight = str.substr(hightlight_index, hightlight_len);
		suffix = str.substr(hightlight_index+hightlight_len, string::npos);
		return;
	}

	//3 首字母搜索 如果能匹配，则需要匹配分离汉字和首字母
	//留给同学们自行完成


	//搜索失败，按照不高亮处理
	prefix = str;
	hightlight.clear();
	suffix.clear();
}