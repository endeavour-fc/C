#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include <algorithm>
using namespace std;
int count1=0;
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

int fib(int n)
{
	count1++;
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	return fib(n - 1) + fib(n - 2);
}
int main()
{
	string s1, s2;
	getline(std::cin, s1);
	getline(std::cin, s2);
	int sum = 0;
	string::iterator it1 = s1.begin();

	while (it1 <= s1.end())
	{
		s1.insert(it1, s2.begin(), s2.end());
		string::iterator right = s1.end() - 1;
		string::iterator left = s1.begin();
		while (left<right&&*left == *right)
		{
			left++;
			right--;
		}
		if (left >= right)
			++sum;
		it1 = s1.erase(it1, it1 + s2.size());
		if (it1 == s1.end())
			break;
		++it1;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
//int main()
//{
//	int x = 1;
//	do
//	{
//		printf("%2d\n", x++);
//	} while (x--);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int v1 = 0;
//	int n = 0;
//	char temp = 0;
//	int flag = 0;
//	cin >> v1;
//	cin >> n;
//	string s1;
//	if (v1 < 0)
//	{
//		flag = 1;
//		v1 = -v1;
//	}
//	while (v1)
//	{
//		if (v1%n<10)
//			temp = v1 % n + '0';
//		else
//		{
//			temp = (v1%n - 10) + 'A';
//		}
//		v1 /= n;
//		s1.insert(s1.begin(), temp);
//	}
//	if (flag)
//	{
//		cout << "-" << s1 << endl;
//	}
//	else
//		cout << s1 << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//vector<int> arr = { 1,2,3,4,2,2,2, };
//	//cout << MoreThanHalfNum_Solution(arr) << endl;
//	fib(8);
//	cout << count1 << endl;
//
//	system("pause");
//	return 0;
//}
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