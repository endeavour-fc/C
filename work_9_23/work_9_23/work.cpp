#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

void Reverse(char* begin, char* end)
{
	if (begin == NULL || end == NULL)
		return;
	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
int arr[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
vector<string> v = { "ABCE","SFCS","ADEE" };
bool get(vector<vector<bool>> bl, string str, int a, int b)
{
	int len = 1;
	queue<pair<int,int>> que;
	que.push({ a,b });
	while (!que.empty())
	{
		if (len == str.size())
			return true;
		auto temp = que.front();
		int i = temp.first;
		int j = temp.second;
		que.pop();
		for (int t = 0; t < 4; ++t)
		{
			int m_i = i + arr[i][0];
			int m_j = j + arr[i][1];
			if (m_i >= 0 && m_i < v.size() && m_j >= 0 && m_j <= v[0].size() && !bl[m_i][m_j])
			{
				if (v[m_i][m_j] == str[len])
				{
					que.push({ m_i,m_j });
					++len;
					bl[i][j] = true;
				}
			}
		}
		return false;
	}
}
int main()
{
		string str;
		while (cin >> str)
		{
			int flag = 0;
			vector<vector<bool>> bl(v.size(), vector<bool>(v[0].size(), false));
			for (int i = 0; i<v.size(); ++i)
			{
				for (int j = 0; j<v[i].size(); ++i)
				{
					if (v[i][j] == str[0])
					{
						bl[i][j] = true;
						if (get(bl, str, i, j))
						{
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag)
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}
		//cout << "true" << endl;
		return 0;
}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		if (str.size()<8 || str.size()>120)
//		{
//			cout << 1 << endl;
//		}
//		else
//		{
//			vector<int> v(4, 0);
//			for (int i = 0; i<str.size(); ++i)
//			{
//				if (str[i] >= 'a'&&str[i] <= 'z')
//					++v[0];
//				else if (str[i] >= 'A'&&str[i] <= 'A')
//					++v[1];
//				else if (str[i] >= '0'&&str[i] <= '9')
//					++v[2];
//				else
//					++v[3];
//			}
//			int flag = 0;
//			for (int i = 0; i<4; ++i)
//			{
//				if (!v[i])
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag)
//				cout << 2 << endl;
//			else
//				cout << 0 << endl;
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "student a am i";
//	int len = strlen(arr)-1;
//	char* start = arr;
//	char* end = arr;
//	Reverse(start, start + len);
//
//	while (start != '\0')
//	{
//		if (*end == ' '||*end=='\0')
//		{
//			Reverse(start, end - 1);
//			if (*end == '\0')
//				break;
//			start = end + 1;
//			end++;
//		}
//		end++;
//	}
//	printf("%s\n", arr);
//
//
//	system("pause");
//	return 0;
//}