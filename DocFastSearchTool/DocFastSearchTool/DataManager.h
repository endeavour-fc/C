#pragma once
#include"Common.h"
#include"Sysutil.h"
#include"./sqlite/sqlite3.h"

//数据库sqlite 封装
class SqliteManager
{
public :
	SqliteManager();
	~SqliteManager();
public:
	//打开数据库
	void Open(const string& path);
	//关闭数据库
	void Close();
	//执行sql语句
	void ExecuteSql(const string& sql);
	//获取表结果
	void GetResTable(const string& sql, int& row, int& col, char**&ppRet);
public:
	//c++11
	//不允许数据库对象进行拷贝构造
	SqliteManager(const SqliteManager&) = delete; 
	//不允许数据库对象进行赋值
	SqliteManager& operator=(const SqliteManager&) = delete; 
private:
	sqlite3* m_db; // 数据库对象
};

///////////////////////////////////////////////////////////////////////
//自动获取表结果类  资源的初始化即获取   自动
class AutoGetResTable
{
public:
	AutoGetResTable(SqliteManager *db, const string &sql, int &row, int &col, char **&ppRet);
	~AutoGetResTable();
public:
	AutoGetResTable(const AutoGetResTable &) = delete;
	AutoGetResTable& operator=(const AutoGetResTable &) = delete;
private:
	SqliteManager *m_db;
	char         **m_ppRet;
};

////////////////////////////////////////////////////////////////////////

#define DOC_DB     "doc.db"
#define DOC_TABLE  "doc_tb"

//数据库管理模块
class DataManager
{
public:
	static DataManager& CreateInstance();
public:
	~DataManager();
public:
	void InitSqlite();
public:
	//向数据库获取数据
	void GetDocs(const string &path, set<string>& docs);
	//向数据库插入文档
	void InsertDoc(const string &path, string doc);
	//向数据库删除文档
	void DeleteDoc(const string &path, string doc);
	void ClearDoc();
public:
	void Search(const string &key, vector<pair<string, string>> &doc_path);
	static void SplitHightLight(const string &str, const string &key, string &prefix, string &hightlight, string &suffix);
private:
	DataManager();
private:
	SqliteManager m_dbmgr;
};

