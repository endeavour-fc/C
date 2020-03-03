#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
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
int main()
{
	vector<int> arr;
	string s1;
	getline(std::cin, s1);
	getstring(s1.begin(), --s1.end());
	string::iterator pPre = s1.begin();
	string::iterator pCur = s1.begin();
	while (pPre != s1.end())
	{
		while (*pCur == ' '&&pCur != s1.end())
		{
			++pCur;
		}
		if (pCur == s1.end())
		{
			break;
		}
		pPre = pCur;
		while (*pCur != ' '&&pCur != s1.end())
		{
			++pCur;
		}
		getstring(pPre, pCur - 1);

	}
	cout << s1 << endl;
	return 0;
}