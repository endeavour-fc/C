#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
string addStrings(string num1, string num2)
{
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	int value1 = 0;
	int value2 = 0;
	int next = 0;
	string addret;
	while (end1 >= 0 || end2 >= 0)//只要有一个串没走完就不会终止循环
	{
		if (end1 >= 0)
		{
			value1 = num1[end1--] - '0';//把ASCLL码转换成数值
		}
		else
		{
			value1 = 0;
		}
		if (end2 >= 0)
		{
			value2 = num2[end2--] - '0';
		}
		else
		{
			value2 = 0;
		}
		int valueaddret = value1 + value2 + next;
		if (valueaddret > 9)
		{
			next = 1;
			valueaddret -= 10;
		}
		else
		{
			next = 0;
		}
		addret += valueaddret + '0';
	}
	if (next == 1)//走到头部如果next等于1，就要向前进位
	{
		addret += '1';
	}
	//逆置
	reverse(addret.begin(), addret.end());
	return addret;
}


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
string Typing()
{
	string str;
	cin >> str;
	stack<char> sta;
	for (int i = 0; i<str.size(); ++i)
	{
		if (str[i] == '<')
		{
			if (!sta.empty())
				sta.pop();
		}
		else
		{
			sta.push(str[i]);
		}
	}
	string temp;
	while (!sta.empty())
	{
		temp += sta.top();
		sta.pop();
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
/******************************结束写代码******************************/


//int main() {
//	string res;
//
//
//	res = Typing();
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		for (int i = 0; i<n; ++i)
//		{
//			string str;
//			cin >> str;
//			if (str.size() % 3)
//			{
//				cout << "No" << endl;
//			}
//			else
//			{
//				map<string, int> mp;
//				string temp = str.substr(0, 3);
//				//vector<string> v(str.size()/3);
//				for (int j = 0; j<3; ++j)
//				{
//					for (int k = 0; k<26; ++k)
//					{
//						string s = temp;
//						s[j] = k + 'A';
//						++mp[s];
//					}
//				}
//				int flag = 0;
//				for (int j = 0; j<str.size(); j += 3)
//				{
//					string p = str.substr(j, 3);
//					if (mp.find(p)==mp.end())
//					{
//						flag = 1;
//						break;
//					}
//				}
//				if (flag)
//					cout << "No" << endl;
//				else
//					cout << "Yes" << endl;
//			}
//		}
//	}
//
//	return 0;
//}
//int main()
//{
//	string str;
//	string s;
//	while (cin >> str >> s)
//	{
//		int i = 0;
//		int num = 0;
//		string sum = "0";
//		while (i<s.size())
//		{
//			char count = 0;
//			char len = 0;
//			count = s[i];
//			len = s[i + 1];
//			i += 2;
//			count -= '0';
//			len -= '0';
//			for (int j = 0; j<count; ++j)
//			{
//				sum = addStrings(sum, str.substr(num, len));
//				num += len;
//			}
//		}
//		cout << sum << endl;
//	}
//
//
//	return 0;
//}

int arr[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int min(int&a, int&b)
{
	return a>b ? b : a;
}
int get(vector<string>& v, int i, int j, int num, vector<vector<bool>>& bl)
{
	if (i == v.size() - 1 && j == v[0].size() - 1)
		return num;
	bl[i][j] = true;
	int m = 99999;
	for (int k = 0; k<4; ++k)
	{
		int m_i = i + arr[k][0];
		int m_j = j + arr[k][1];
		if (m_j >= 0 && m_i >= 0 && m_j<v[0].size() && m_i<v.size() && !bl[m_i][m_j])
		{
			if (v[m_i][m_j] == '.')
				m = min(get(v, m_i, m_j, num, bl), m);
			else if (v[m_i][m_j] == '*')
				m = min(get(v, m_i, m_j, num + 1, bl), m);
		}
	}
}

int main()
{
	int T;
	while (cin >> T)
	{
		for (int i = 0; i<T; ++i)
		{
			int n1, n2;
			cin >> n1 >> n2;
			vector<string> v(n1);
			for (int j = 0; j<n2; ++j)
				cin >> v[j];
			vector<vector<bool>> bl(n1, vector<bool>(n2, false));
			for (int j = 0; j < n1; ++j)
			{
				for (int k = 0; k < n2; ++k)
				{
					if (v[j][k] == '@')
						cout << get(v, j, k, 0, bl) << endl;
				}
			}

		}
	}

	return 0;
}