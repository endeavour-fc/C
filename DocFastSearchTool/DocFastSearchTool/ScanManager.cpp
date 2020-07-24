#include"ScanManager.h"

size_t g_FileCount = 0;
size_t g_ScanCount = 0;

ScanManager::ScanManager()
{}

void ScanManager::StartScan(const string &path)
{
	while(1)
	{
		//this_thread::sleep_for(chrono::seconds(2)); //1 bug 效率损伤
		unique_lock<mutex> lock(m_mutex);
		m_cond.wait(lock);  //条件变量
		ScanDirectory(path);
	}
}

void ScanManager::StartWatch(const string &path)
{
	g_FileCount = GetFileCount(path);
	while(1)
	{
		this_thread::sleep_for(chrono::seconds(5));
		g_ScanCount = 0;
		bool ischange = DirectoryWatch(path);
		if(ischange)
		{
			m_cond.notify_one();
			g_FileCount = g_ScanCount;
		}
	}
}

ScanManager& ScanManager::CreateInstance(const string &path)
{
	static ScanManager inst;
	//创建扫描线程
	thread scan_thread(&StartScan, &inst, path);
	scan_thread.detach();

	thread watch_thread(&StartWatch, &inst, path);
	watch_thread.detach();

	return inst;
}

void ScanManager::ScanDirectory(const string &path)
{
	//1 扫描本地文件 并进行存储
	vector<string> local_files;
	vector<string> local_dirs;
	DirectoryList(path, local_files, local_dirs);
	set<string> local_set;
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());

	DataManager &m_db = DataManager::CreateInstance();

	//2 扫描数据库文件 并进行存储
	set<string> db_set;
	//查询数据数据库
	m_db.GetDocs(path, db_set);

	//3 进行文件对比
	auto local_it = local_set.begin();
	auto db_it = db_set.begin();
	while(local_it!=local_set.end() && db_it!=db_set.end())
	{
		if(*local_it < *db_it)
		{
			//本地文件存在，数据库文件不存在，则数据库增加文件
			//增加文件
			m_db.InsertDoc(path, *local_it);
			++local_it;
		}
		else if(*local_it > *db_it)
		{
			//本地文件不存在，数据库文件存在，则数据库删除文件
			//删除文件
			m_db.DeleteDoc(path, *db_it);
			++db_it;
		}
		else
		{
			//本地文件存在，数据库文件也存在，则数据库不变
			++local_it;
			++db_it;
		}
	}

	//本地文件存在， 增加数据库文件
	while(local_it != local_set.end())
	{
		//增加文件
		m_db.InsertDoc(path, *local_it);
		++local_it;
	}

	//数据库文件存在， 删除数据库文件
	while(db_it != db_set.end())
	{
		//删除文件
		m_db.DeleteDoc(path, *db_it);
		++db_it;
	}

	//递归遍历子目录
	for(auto &dir : local_dirs)
	{
		//C:\Users\baoso\Desktop\55班\test\阶段性考试试卷\C语言
		string dir_path = path;
		dir_path += '\\';
		dir_path += dir;

		ScanDirectory(dir_path);
	}
}