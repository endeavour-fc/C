#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;

int findnum(int arr[], int len)
{
	if (arr == NULL && len <= 0)
		return 0;
	int sum[32] = { 0 };
	for (int i = 0; i < len; i++)
	{
		int temp = 1;
		for (int j = 31; j >= 0; j--)
		{
			int bit = arr[i] & temp;
			if (bit)
			{
				sum[j] += 1;
			}
			temp <<= 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;
		result += sum[i] % 3;
	}
	return result;
}


//int main()
//{
//	int arr[] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,6,6,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	
//	printf("%d\n", findnum(arr, len));
//
//	system("pause");
//	return 0;
//}
bool myfun(string s1, string s2)
{
	return s1.size() < s2.size();
}
int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<string> ret;
		string temp;
		for (int i = 0; i<num; ++i)
		{
			cin >> temp;
			ret.push_back(temp);
		}
		sort(ret.begin(), ret.end(), myfun);
		vector<string>::iterator it1 = ret.begin()+1;
		while (it1 != ret.end())
		{
			if ((*it1).find((*(it1 - 1))) != string::npos)
				it1=ret.erase(it1 - 1);
			it1++;
		}

		for (int i = 0; i < ret.size(); ++i)
		{
			cout <<"mkdir -p "<< ret[i] << endl;
		}
		cout << endl;
	}

	return 0;
}


int main01()
{
	string s;
	int name;
	int num;
	while (cin >> num)
	{
		int temp = 0;
		int ret = 0;
		for (int i = 0; i<num; ++i)
		{
			cin.get();
			getline(cin, s);
			if (s.find("disconnect") !=string::npos)
				--temp;
			else
				++temp;
			ret = (ret>temp ? ret : temp);
		}
		cout << ret << endl;
	}

	return 0;
}