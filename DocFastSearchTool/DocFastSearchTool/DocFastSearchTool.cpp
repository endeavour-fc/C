#include"Common.h"
#include"Sysutil.h"

#include"ScanManager.h"
#include"DataManager.h"

char *title = "文档快速搜索工具";

void main()
{
	//创建扫描实例
	//const string path = "C:\\Users\\baoso\\Desktop\\55班\\test\\阶段性考试试卷";
	const string path = "G:\\Code\\C++";
	//ScanManager sm;
	ScanManager::CreateInstance(path).ScanDirectory(path);

	//创建搜索实例
	string key;
	vector<pair<string, string>> doc_path; //用于保存搜索的结果
	DataManager &dm = DataManager::CreateInstance();

	int row = 5;
	int count;
	while(1)
	{
		DrawFrame(title);
		DrawMenu();
		cin>>key;
		if(key == string("exit"))
			break;
		dm.Search(key, doc_path);

		//显示结果
		count = 0;
		for(auto &e : doc_path)
		{
			string &name = e.first; //
			string &path = e.second;

			SetCurPos(row+count++, 2);
			//高亮处理
			//
			printf("%-30s%-85s\n", name.c_str(), path.c_str());
		}
		doc_path.clear();
		
		SystemEnd();
		system("pause");
	}

	SystemEnd();
}


/*
void Test_HightLight()
{
	string str = "123比特科技,让就业更简单666"; 
	//string key = "就业你好";
	//string key = "keji";
	string key = "jy";
	string prefix, hightlight, suffix;
	DataManager::SplitHightLight(str, key, prefix, hightlight, suffix);
	cout<<prefix;
	ColourPrintf(hightlight);
	cout<<suffix<<endl;
}
void main()
{
	Test_HightLight();
}


/*
void Test_DirectoryList()
{
	string path = "C:\\Users\\baoso\\Desktop\\55班\\test\\阶段性考试试卷";
	vector<string> subfile, subdir;
	DirectoryList(path, subfile, subdir);

	for(auto &e : subfile)
	{
		//cout<<typeid(e).name()<<endl; //string
		cout<<e<<endl;
	}
	for(auto &e : subdir)
		cout<<e<<endl;
}

void Test_Search()
{
	//创建扫描实例
	const string path = "C:\\Users\\baoso\\Desktop\\55班\\test\\阶段性考试试卷";
	ScanManager sm;
	sm.ScanDirectory(path);

	//创建搜索实例
	string key;
	vector<pair<string, string>> doc_path; //用于保存搜索的结果

	DataManager dm;

	//
	while(1)
	{
		cout<<"请输入要搜索的关键字:>";
		cin>>key;
		dm.Search(key, doc_path);
		//显示结果
		printf("%-30s%-50s\n","名称","路径");
		for(auto &e : doc_path)
		{
			string &name = e.first; //
			string &path = e.second;
			printf("%-30s%-50s\n", name.c_str(), path.c_str());
		}

		doc_path.clear();
	}
}

int main(int argc, char *argv[])
{
	//Test_DirectoryList();
	Test_Search();
	return 0;
}
*/