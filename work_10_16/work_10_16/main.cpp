//#include"stack.h"
//int main()
//{
//	seqstack stack;
//	stack_init(&stack);
//	
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int get(vector<int>& v, int num, vector<bool>& bl)
{
	// int count=0;
	for (int i = 0; i<v.size(); ++i)
	{
		if (!bl[i] && v[i] >= num)
			return i + 1;
	}
	return -1;
}

//int main()
//{
//	int T = 0;
//	int n, m = 0;
//	while (cin >> T)
//	{
//		for (int i = 0; i<T; ++i)
//		{
//			cin >> n >> m;
//			vector<int> v1(n, 0);
//			vector<int> v2(m, 0);
//			for (int j = 0; j<n; ++j)
//				cin >> v1[j];
//			for (int j = 0; j<m; ++j)
//				cin >> v2[j];
//			vector<bool> bl(m, 0);
//			for (int j = 0; j<n; ++j)
//			{
//				int temp = get(v2, v1[j], bl);
//				if (temp != -1)
//					bl[temp - 1] = true;
//				cout << temp << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	return 0;
//}

void get(int m, int n, int& num, int len, vector<int>& v)
{
	if (len == m)
	{
		num += 1;
		return;
	}
	int size = v.size();
	int j = 0;
	bool flag = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (len + i <= m)
		{
			for (j = size - 1; j >= 0 && j >= size - 2; --j)
			{
				if (v[j] == i)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				flag = false;
				continue;
			}
			v.push_back(i);
			get(m, n, num, len + i, v);
			v.pop_back();
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int m, n = 0;
	while (cin >> m >> n)
	{
		vector<int> v;
		int num = 0;
		get(m, n, num, 0, v);
		cout << num << endl;

	}

	return 0;
}