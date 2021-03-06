#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include <algorithm>
#include<string>
using namespace std;

void bubblesort(int* p,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;
	}
}

void selectsort(int* p, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 1;
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] > p[j])
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;
	}
}


void insertsort(int* p, int len)
{
	int j = 0;
	for (int i = 1; i < len; i++)
	{
		if (p[i - 1] > p[i])
		{
			int temp = p[i];
			for (j = i - 1; j >= 0 && p[j] > temp; j--)
				p[j + 1] = p[j];
			p[j + 1] = temp;
		}

	}
}

void ShellSort(int *arr, int size)
{
	int i=0, j=0, temp=0, increment=0;
	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < size; i++) 
		{
			temp = arr[i];
			for (j = i - increment; j >= 0 && temp < arr[j]; j -= increment)
			{
				arr[j + increment] = arr[j];
			}
			arr[j + increment] = temp;
		}
	}
}

int main01()
{
	string s;
	while (getline(cin, s))
	{
		vector<int> v;
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] == '2')
			{
				v.push_back(20);
			}
			if (s[i] == '5')
			{
				v.push_back(5);
			}
			if (s[i] == '1')
			{
				v.push_back(10);
			}
		}
		int n5 = 0;
		int n10 = 0;
		int n20 = 0;
		int ret = 0;
		for (int i = 0; i<v.size(); ++i)
		{
			if (v[i] == 5)
			{
				++n5;
				++ret;
			}
			if (v[i] == 10)
			{
				if (n5)
				{
					--n5;
					++n10;
					++ret;
				}
				else
				{
					break;
				}
			}
			if (v[i] == 20)
			{
				int temp = 20;
				if (n10)
				{
					--n10;
					temp -= 10;
				}
				while (temp&&n5)
				{
					--n5;
					temp -= 5;
				}
				if (temp == 0)
				{
					++n20;
					++ret;
				}
			}
		}
		if (ret == v.size())
		{
			cout << "true" << "," << v.size() << endl;
		}
		else
		{
			cout << "false" << "," << ret + 1 << endl;
		}
	}

	return 0;
}

//int main()
//{
//	int arr[] = { 2,4,1,7,5,9,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	//bubblesort(arr, len);
//	//selectsort(arr, len);
//	//insertsort(arr, len);
//	ShellSort(arr, len);
//
//	for (int i = 0; i < len; i++)
//		printf("%d\n", arr[i]);
//	
//	system("pause");
//	return 0;
//}

int main04()
{
	string str;
	while (cin >> str)
	{
		int n = 0;
		int count = 0;
		while (str.back() != ',')
		{
			n += (str.back() - '0')*pow(10, count++);
			str.pop_back();
		}
		str.pop_back();
		vector<string> v(n, "");
		int left = 0;
		int right = n - 1;
		int flag = 1;
		int i = 0;
		for (; i<str.size() - 1; )
		{
			if (flag)
			{
				v[left++].push_back(str[i]);
				v[right--].push_back(str[i + 1]);
				if (left == right)
				{
					i += 2;
					if (i<str.size())
						v[left].push_back(str[i]);
					flag = 0;
					--left;
					++right;
					++i;
				}
				else
				{
					i += 2;
				}
			}
			else
			{
				v[left--].push_back(str[i]);
				v[right++].push_back(str[i + 1]);
				if (left<0 || right >= n)
				{
					left = 1;
					right = n - 2;
					flag = 1;
					i += 2;
				}
				else
				{
					i += 2;
				}
			}
		}
		for (int i = 0; i<v.size(); ++i)
			cout << v[i];
		cout << endl;
	}

	return 0;
}

int str_wild_compare(string w1, string s2) {
	// write code here
	vector<vector<int>> v(w1.size() + 1, vector<int>(s2.size() + 1, 0));
	v[0][0] = 1;
	for (int i = 1; i <= s2.size(); ++i)
	{
		v[0][i] = v[0][i - 1] && w1[i - 1] == '*';
	}
	for (int i = 1; i <= w1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (w1[i - 1] == '*')
			{
				v[i][j] = v[i][j - 1] || v[i - 1][j];
			}
			else if (w1[i - 1] == '?' || w1[i - 1] == s2[j - 1])
			{
				v[i][j] = v[i - 1][j - 1];
			}
		}
	}
	return v[w1.size()][s2.size()];
}
bool isMatch(string s, string p) {
	vector<vector<int>> v(s.size() + 1, vector<int>(p.size() + 1, 0));
	v[0][0] = 1;
	for (int i = 1; i <= p.size(); i++)
	{
		v[0][i] = v[0][i - 1] && (p[i - 1] == '*');
	}
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= p.size(); j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
				v[i][j] = v[i - 1][j - 1];
			else if (p[j - 1] == '*')
			{
				v[i][j] = v[i - 1][j] || v[i][j - 1];
			}
		}
	return v[s.size()][p.size()];
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
	vector<int> v;
	if (arr.size() == 0 || k == 0)
		return v;

	make_heap(arr.begin(), arr.end(), greater<int>());
	auto it = arr.end();
	while (k--)
	{
		v.push_back(arr[0]);
		pop_heap(arr.begin(), it--, greater<int>());
	}
	return v;
}
class Solution_findMaxAverage {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int num = 0;
		for (int i = 0; i<k; ++i)
			num += nums[i];
		int ret = num;
		for (int i = k; i<nums.size(); ++i)
		{
			num = num - nums[i - k] + nums[i];
			ret = max(num, ret);
		}
		return (ret - 0.0) / k;
	}
};
int main()
{
	vector<int> v = { 3, 2, 1 };
	getLeastNumbers(v, 2);
	//cout << str_wild_compare("/et?/*", "/etc/passwd") << endl;

	system("pause");
	return 0;
}