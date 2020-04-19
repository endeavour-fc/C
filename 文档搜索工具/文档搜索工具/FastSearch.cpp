#include"sysutil.h"
#include"Sysutil.h"
#include"./sqlite3.h"
#include"DataManager.h"
#include"ScanManager.h"
#include"Sysframe.h"
char title[] = "文档快速搜索工具";



int main(int argc, char *argv[])

{

	const string &path = "G:\\Code\\C++\\2048";

	//const string &path = "C:\\";



	//创建扫描实例

	ScanManager::CreateInstance(path).ScanDirectory(path);



	//创建搜索实例
	DataManager &dm = DataManager::GetInstance();



	vector<pair<string, string>> doc_path;

	string key;

	while (1)

	{

		DrawFrame(title);

		DrawMenu();

		cin >> key;

		if (key == "exit")

			break;

		dm.Search(key, doc_path);



		int init_row = 5; //由界面决定

		int count = 0;

		string prefix, highlight, suffix;

		for (const auto &e : doc_path)

		{

			string doc_name = e.first;

			string doc_path = e.second;



			DataManager::SplitHighlight(doc_name, key, prefix, highlight, suffix);



			SetCurPos(2, init_row + count++);

			//printf("%-31s", prefix.c_str());

			cout << prefix;

			ColourPrintf(highlight.c_str());

			cout << suffix;



			SetCurPos(33, init_row + count - 1);

			printf("%-50s", doc_path.c_str());

			//printf("%-31s%-50s\n",e.first.c_str(), e.second.c_str());

		}

		SystemEnd();

		system("pause");

	}

	SystemEnd();

	return 0;

}
