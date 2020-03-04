#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include <algorithm>
using namespace std;
void getstring(string::iterator it1, string::iterator it2)
{
	while (it1<it2)
	{
		char temp = *it1;
		*it1 = *it2;
		*it2 = temp;
		++it1;
		--it2;
	}
}
//int main()
//{
//	vector<int> arr;
//	string s1;
//	getline(std::cin, s1);
//	getstring(s1.begin(), --s1.end());
//	string::iterator pPre = s1.begin();
//	string::iterator pCur = s1.begin();
//	while (pPre != s1.end())
//	{
//		while (*pCur == ' '&&pCur != s1.end())
//		{
//			++pCur;
//		}
//		if (pCur == s1.end())
//		{
//			break;
//		}
//		pPre = pCur;
//		while (*pCur != ' '&&pCur != s1.end())
//		{
//			++pCur;
//		}
//		getstring(pPre, pCur - 1);
//
//	}
//	cout << s1 << endl;
//	return 0;
//}

int MoreThanHalfNum_Solution(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
	int temp = numbers[(numbers.size() / 2)];
	vector<int>::iterator it1 = numbers.begin();
	vector<int>::iterator it2 = numbers.end() - 1;
	while (*it1 != temp)
	{
		++it1;
	}
	while (*it2 != temp)
	{
		--it2;
	}
	if (it2 - it1 < (numbers.size()) / 2)
		return 0;
	return temp;
}
int main()
{
	vector<int> arr = { 1,2,3,4,2,2,2, };
	cout << MoreThanHalfNum_Solution(arr) << endl;

	system("pause");
	return 0;
}
//int main()
//{
//	string s1;
//	string s2;
//	getline(std::cin, s1);
//	string::iterator it1 = s1.begin();
//	string::iterator it2 = s1.begin();
//	while (it2 != s1.end())
//	{
//		while (it2 != s1.end() &&((*it2>'9') || (*it2<'0')))
//		{
//			it2++;
//		}
//		if (it2 == s1.end())
//		{
//			cout << s2 << endl;
//			return 0;
//		}
//		else
//		{
//			it1 = it2;
//			while (it2 != s1.end() && *it2 <= '9'&&*it2 >= '0')
//			{
//				it2++;
//			}
//			string s3(it1, it2);
//			if (s3.size()>s2.size())
//			{
//				s2 = s3;
//			}
//		}
//	}
//	cout << s2 << endl;
//	system("pause");
//	return 0;
//}