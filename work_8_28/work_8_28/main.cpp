//#include<iostream>
//#include<string>
//using namespace std;
//void reverse(string& str, int begin, int end)
//{
//	if (end >= str.size())
//		end = str.size() - 1;
//
//	while (begin<end)
//	{
//		char temp = str[begin];
//		str[begin] = str[end];
//		str[end] = temp;
//		++begin;
//		--end;
//	}
//}
//
//int main()
//{
//	string str;
//	int n = 0;
//	while (cin >> n)
//	{
//		getchar();
//		getline(cin, str);
//
//		if (n >= 1)
//		{
//			int begin = 0;
//			int end = n-1;
//			if (end >= str.size())
//				end = str.size() - 1;
//			while (end<str.size())
//			{
//				reverse(str, begin, end);
//				begin = end + 1;
//				end += n;
//			}
//		}
//		cout << str << endl;
//	}
//
//	return 0;
//}


#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int T;
	while (cin >> T)
	{
		for (int t = 0; t<T; ++t)
		{
			int n, m, k;
			cin >> n >> m >> k;
			vector<vector<int>> v(m, vector<int>(m, 0));
			for (int i = 0; i<m; ++i)
			{
				int n1, n2, p;
				cin >> n1 >> n2 >> p;
				if (p<k)
				{
					v[n1 - 1][n2 - 1] = 1;
					v[n2 - 1][n1 - 1] = 1;
				}
			}
			int flag = 0;
			for (int i = 0; i<v.size(); ++i)
			{
				int count = 0;
				for (int j = 0; j<v[0].size(); ++j)
				{
					if (i == j)
					{
						++count;
						continue;
					}
					if (v[i][j] == 0)
						break;
					++count;
				}
				if (count == m)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}