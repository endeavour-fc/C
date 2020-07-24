#include"Common.h"
#include"Sysutil.h"

#include"ScanManager.h"
#include"DataManager.h"

char *title = "�ĵ�������������";

void main()
{
	//����ɨ��ʵ��
	//const string path = "C:\\Users\\baoso\\Desktop\\55��\\test\\�׶��Կ����Ծ�";
	const string path = "G:\\Code\\C++";
	//ScanManager sm;
	ScanManager::CreateInstance(path).ScanDirectory(path);

	//��������ʵ��
	string key;
	vector<pair<string, string>> doc_path; //���ڱ��������Ľ��
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

		//��ʾ���
		count = 0;
		for(auto &e : doc_path)
		{
			string &name = e.first; //
			string &path = e.second;

			SetCurPos(row+count++, 2);
			//��������
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
	string str = "123���ؿƼ�,�þ�ҵ����666"; 
	//string key = "��ҵ���";
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
	string path = "C:\\Users\\baoso\\Desktop\\55��\\test\\�׶��Կ����Ծ�";
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
	//����ɨ��ʵ��
	const string path = "C:\\Users\\baoso\\Desktop\\55��\\test\\�׶��Կ����Ծ�";
	ScanManager sm;
	sm.ScanDirectory(path);

	//��������ʵ��
	string key;
	vector<pair<string, string>> doc_path; //���ڱ��������Ľ��

	DataManager dm;

	//
	while(1)
	{
		cout<<"������Ҫ�����Ĺؼ���:>";
		cin>>key;
		dm.Search(key, doc_path);
		//��ʾ���
		printf("%-30s%-50s\n","����","·��");
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