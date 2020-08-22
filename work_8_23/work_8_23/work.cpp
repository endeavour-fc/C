#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
void route(char arr[], char arr2[], int len, int k)
{
	//arr2[len] = '\0';
	for (int i = 0; i < k; i++)
	{
		arr2[len - i-1] = arr[i];
	}
	for (int i = 0; i < len - k; i++)
	{
		arr2[i] = arr[i + k];
	}
}

int jude(char arr3[], char arr2[],int sz)
{
	//route(arr, arr2, sz, 3);
	return strcmp(arr3, arr2);
}

//int main()
//{
//	char arr[20] = "ABCDEGHI";
//	char arr2[20] = "ABCDEGHI";
//	char arr3[20]= "CDEGHIBAm";
//	int sz = strlen(arr);
//	//int sz = (sizeof(arr) / sizeof(arr[0]))-1;
//	route(arr, arr2, sz, 2);
//	int ret = jude(arr3, arr2, sz);
//
//	printf("%s\n", arr2);
//	printf("%d ", ret);
//	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int que_size = 0;
//	int n = 0;
//	while (cin >> que_size>>n)
//	{
//		queue<int> que;
//		int commodity = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			int num = 0;
//			cin >> num;
//			if (num == 0)
//			{
//				int temp = 0;
//				cin >> temp;
//				commodity += temp;
//				while (commodity&&!que.empty())
//				{
//					que.pop();
//					--commodity;
//				}
//			}
//			else
//			{
//				for (int i = 0; i < num; ++i)
//				{
//					int temp = 0;
//					cin >> temp;
//					if (que.empty())
//					{
//						if (commodity)
//							--commodity;
//						else
//						{
//							que.push(temp);
//						}
//					}
//					else
//					{
//						if (que.size() == que_size)
//						{
//							break;
//						}
//						else
//						{
//							que.push(temp);
//						}
//					}
//				}
//			}
//
//		}
//		while (!que.empty())
//		{
//			cout << que.front();
//			que.pop();
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		vector<string> v(num, "");
//		for (int i = 0; i<num; ++i)
//			cin >> v[i];
//		int count = 0;
//		for (int i = 0; i<num; ++i)
//		{
//			if (v[i].size()>10)
//				continue;
//			int j = 0;
//			for (j; j<v[i].size(); ++i)
//			{
//				if ((v[i][j] <= 'z'&&v[i][j] >= 'a') || (v[i][j] <= 'Z'&&v[i][j] >= 'A'))
//					continue;
//				else
//					break;
//			}
//			if (j == v[i].size())
//				++count;
//		}
//		cout << count << endl;
//	}
//
//	return 0;
//}

void swap(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int n, m = 0;
	while (cin >> n >> m)
	{
		vector<int> v(n, 0);
		vector<int> arr(m, 0);
		for (int i = 0; i<n; ++i)
			v[i] = i + 1;
		for (int i = 0; i < m; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i<m; ++i)
		{

			if (arr[i] == 1)
			{
				int num = v[0];
				v.erase(v.begin());
				v.push_back(num);
			}
			else
			{
				for (int j = 0; j<n - 1; j += 2)
					swap(v[j], v[j + 1]);
			}
		}
		for (int i = 0; i<n; ++i)
			cout << v[i] << " ";
		cout << endl;
	}

	return 0;
}