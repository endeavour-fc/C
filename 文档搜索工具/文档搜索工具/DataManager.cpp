#include"DataManager.h"
#pragma comment(lib, "./sqlite3.lib")




void sqliteManager::Open(const string &path)
{
	char *zErrMsg = 0;
	int rc;
	rc = sqlite3_open(path.c_str(), &m_db);
	if (rc)
	{
		ERROR_LOG("Can't open database: %s", sqlite3_errmsg(m_db));
		exit(0);
	}
	else
	{
		TRACE_LOG("Opened database successfully.");
	}
}

void sqliteManager::Close()
{
	if (m_db)
	{
		int rc = sqlite3_close(m_db);
		if (rc != SQLITE_OK)
		{
			ERROR_LOG("Close database failed: %s", sqlite3_errmsg(m_db));
		}
		else
			TRACE_LOG("Close database successfully.");
	}
}



void sqliteManager::ExecuteSql(const string &sql)
{
	char *zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("SQL(%s) error: %s", sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		TRACE_LOG("SQL(%s) Execute successfully.", sql.c_str());
	}
}



void sqliteManager::GetTable(const string &sql, int &row, int &col, char **&ppRet)
{
	char *zErrMsg = 0;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("Get Result Table error: %s", zErrMsg);
	}
	else
	{
		TRACE_LOG("Get Result Table successfully.", zErrMsg);
	}
}





void DataManager::Init()
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "create table if not exists %s(id integer primary key autoincrement, doc_name text, doc_path text, doc_pinyin text, doc_initials text)", DOC_TABLE);
	_dbmgr.ExecuteSql(sql);
}


AutoGetResultTable::AutoGetResultTable(sqliteManager *db, const string &sql, int &row,
	int &col, char **&ppRet) : m_db(db)
{
	m_db->GetTable(sql, row, col, ppRet);
	m_ppRet = ppRet;
}

AutoGetResultTable::~AutoGetResultTable()
{
	if (m_ppRet)
		sqlite3_free_table(m_ppRet);
}

void DataManager::InsertDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };

	string pinyin = ChineseConvertPinYinAllSpell(doc);
	string initials = ChineseConvertPinYinInitials(doc);

	sprintf(sql,
		"insert into %s values(null, '%s', '%s', '%s', '%s')",
		DOC_TABLE, doc.c_str(), path.c_str(), pinyin.c_str(), initials.c_str());

	_dbmgr.ExecuteSql(sql);
}

void DataManager::GetDocs(const string &path, multiset<string> &docs)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "select doc_name from %s where doc_path='%s'", DOC_TABLE, path.c_str());
	int row = 0, col = 0;
	char **ppRet = 0;
	_dbmgr.GetTable(sql, row, col, ppRet);
	for (int i = 1; i <= row; ++i)
		docs.insert(ppRet[i]);
	sqlite3_free_table(ppRet);
}

void DataManager::DeleteDoc(const std::string path, std::string doc)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "delete from %s where doc_name='%s' and doc_path='%s'", DOC_TABLE, doc.c_str(), path.c_str());
	_dbmgr.ExecuteSql(sql);
	string doc_path = path;
	doc_path += "\\";
	doc_path += doc;

	memset(sql, 0, SQL_BUFFER_SIZE);

	sprintf(sql, "delete from %s where doc_path like '%s%%'", DOC_TABLE, doc_path.c_str());

	_dbmgr.ExecuteSql(sql);
}
void DataManager::Search(const string &key, vector<pair<string, string>> &doc_path)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	string pinyin = ChineseConvertPinYinAllSpell(key);
	string initials = ChineseConvertPinYinInitials(key);

	sprintf(sql,
		"select doc_name, doc_path from %s where doc_pinyin like '%%%s%%' or doc_initials like '%%%s%%'",
		DOC_TABLE, pinyin.c_str(), initials.c_str());

	int row = 0, col = 0;
	char **ppRet = nullptr;

	AutoGetResultTable at(&_dbmgr, sql, row, col, ppRet);

	doc_path.clear();
	for (int i = 1; i <= row; ++i)
		doc_path.push_back(make_pair(ppRet[i*col], ppRet[i*col + 1]));
}

void DataManager::SplitHighlight(const string &str, const string &key,
	string &prefix, string &highlight, string &suffix)
{
	string strlower(str), keylower(key);
	transform(strlower.begin(), strlower.end(), strlower.begin(), ::tolower);
	transform(keylower.begin(), keylower.end(), keylower.begin(), ::tolower);
	//1 如果中文搜索，并能搜索成功，则直接分离
	size_t pos = strlower.find(keylower);
	if (pos != string::npos)
	{
		prefix = str.substr(0, pos);
		highlight = str.substr(pos, keylower.size());
		suffix = str.substr(pos + keylower.size(), string::npos);
		return;
	}
	//2 使用拼音全拼搜索, 则需要匹配分离子串汉字和拼音
	string str_pinyin = ChineseConvertPinYinAllSpell(strlower);
	string key_pinyin = ChineseConvertPinYinAllSpell(keylower);
	pos = str_pinyin.find(key_pinyin);
	if (pos != string::npos)
	{
		size_t str_index = 0;
		size_t pinyin_index = 0;
		size_t highlight_index = 0;
		size_t highlight_len = 0;
		while (str_index < strlower.size())
		{
			if (pinyin_index == pos)
			{
				highlight_index = str_index;
			}
			if (pinyin_index >= pos + key_pinyin.size())
			{
				highlight_len = str_index - highlight_index;
				break;
			}
			if (strlower[str_index] >= 0 && strlower[str_index] <= 127)
			{
				//是一个字符
				++str_index;
				++pinyin_index;
			}
			else
			{
				//是一个汉字
				string word(strlower, str_index, 2);  //文
				string word_pinyin = ChineseConvertPinYinAllSpell(word); //wen
				str_index += 2;
				pinyin_index += word_pinyin.size();
			}
		}
		prefix = str.substr(0, highlight_index);
		highlight = str.substr(highlight_index, highlight_len);
		suffix = str.substr(highlight_index + highlight_len, string::npos);
		return;
	}
	//3 使用首字母搜索
	string str_initials = ChineseConvertPinYinInitials(strlower);
	string key_initials = ChineseConvertPinYinInitials(keylower);
	pos = str_initials.find(key_initials);
	if (pos != string::npos)
	{
		size_t str_index = 0;
		size_t initials_index = 0;
		size_t highlight_index = 0;
		size_t highlight_len = 0;
		while (str_index < strlower.size())
		{
			if (initials_index == pos)
			{
				highlight_index = str_index;
			}
			if (initials_index >= pos + key_initials.size())
			{
				highlight_len = str_index - highlight_index;
				break;
			}
			if (strlower[str_index] >= 0 && strlower[str_index] <= 127)
			{
				//是一个字符
				++str_index;
				++initials_index;
			}
			else
			{
				//是一个汉字
				str_index += 2;
				initials_index++;
			}
		}
		prefix = str.substr(0, highlight_index);
		highlight = str.substr(highlight_index, highlight_len);
		suffix = str.substr(highlight_index + highlight_len, string::npos);
		return;
	}

	prefix = str;
	highlight.clear();
	suffix.clear();
}