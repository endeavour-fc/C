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

int getnum(vector<vector<int>> ret)
{
	for (size_t i = 1; i<ret.size(); ++i)
	{
		for (size_t j = 1; j<ret[0].size(); ++j)
		{
			if (ret[i][j])
				ret[i][j] = ret[i][j - 1] + ret[i - 1][j];
		}
	}
	return ret[ret.size() - 1][ret[0].size() - 1];
}
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<float>> ret1(n + 1, vector<float>(m + 1, 0));
		vector<vector<int>> ret2(n + 1, vector<int>(m + 1, 0));
		int n1, n2;
		for (int i = 0; i<k; ++i)
		{
			cin >> n1 >> n2;
			ret2[n1][n2] = 1;
		}
		ret1[1][1] = 1;
		for (size_t i = 1; i <= n; ++i)
		{
			for (size_t j = 1; j <= m; ++j)
			{
				if (i != 1 || j != 1)
				{
					if (ret2[i][j])
						ret1[i][j] = 0;
					else
						ret1[i][j] = ret1[i][j - 1] * (i == n ? 1 : 0.5) + ret1[i - 1][j] * (j == m ? 1 : 0.5);
				}
			}
		}
		printf("%.2lf\n", ret1[n][m]);
	}

	return 0;
}
int arr[] = { -1,0,1 };
int getnum(vector<vector<int>>& ret, int i, int j)
{
	ret[i][j] = 0;
	int sum = 1;
	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 3; ++b)
		{
			if (i + arr[a] < ret.size() && i + arr[a] >= 0 && j + arr[b] < ret[0].size() && j + arr[b] >= 0 && ret[i + arr[a]][j + arr[b]]&&abs(arr[a])!=abs(arr[b]))
				sum+=getnum(ret, i + arr[a], j + arr[b]);
		}
	}
	
	return sum;
}

int main03()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<string> str;
		int num = 0;
		string temp;
		vector<vector<int>> ret(m, vector<int>(n, 1));
		cin.get();
		for (int i = 0; i<m; ++i)
		{
			getline(cin, temp);
			str.push_back(temp);
		}
		int n1=0, n2=0;
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				if (str[i][j] == '#')
					ret[i][j] = 0;
				if (str[i][j] == '@')
				{
					n1 = i;
					n2 = j;
				}
			}
		}
		cout << getnum(ret, n1, n2) << endl;
	}

	return 0;
}
bool myfun(string s1, string s2)
{
	return s1.size() < s2.size();
}
int main02()
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