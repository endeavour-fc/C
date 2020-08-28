#pragma once
#include"Common.h"
#include"sysutil.h"
class sqliteManager
{
public:
	sqliteManager():m_db(nullptr)
	{}
	~sqliteManager()
	{
		Close();
	}
	void Open(const std::string& path);
	void Close();
	void ExecuteSql(const std::string& sql);
	void GetTable(const std::string& sql, int& row, int& col, char**&ppRet);
	sqliteManager(const sqliteManager&) = delete;
	sqliteManager& operator=(const sqliteManager&) = delete;
private:
	sqlite3 * m_db;
};
class DataManager
{
public:
	~DataManager()
	{
		_dbmgr.Close();
	}
	static DataManager& GetInstance()
	{
		static DataManager inst;
		return inst;
	}
	void Init();
	void GetDocs(const string &path, multiset<string> &docs);
	void InsertDoc(const string &path, const string &doc);
	void DeleteDoc(const std::string path, std::string doc);
	void Search(const std::string& key,
		std::vector<std::pair<std::string, std::string>>& doc_paths);
	static void SplitHighlight(const std::string& str, const
		std::string& key,
		std::string& prefix, std::string& highlight, std::string&suffix);
private:
	DataManager()
	{
		// 打开数据库
		_dbmgr.Open(DOC_DB);
		Init();
	}
	DataManager(const DataManager&) = delete;
	sqliteManager _dbmgr;
	//mutex _mtx;
};


class AutoGetResultTable
{
public:
	AutoGetResultTable(sqliteManager *db, const string &sql, int &row, int &col, char **&ppRet);
	~AutoGetResultTable();
public:
	AutoGetResultTable(const AutoGetResultTable &) = delete;
	AutoGetResultTable& operator=(const AutoGetResultTable &) = delete;
private:
	sqliteManager * m_db;
	char          **m_ppRet;
};