//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//string longestPalindrome(string s)
//{
//	if (s == " ")
//		return s;
//	string temp(s.rbegin(), s.rend());
//	vector<vector<int>> v(s.size(), vector<int>(s.size(), 0));
//	int MaxLen = 0;
//	int pos = 0;
//	for (size_t i = 0; i<s.size(); ++i)
//	{
//		for (size_t j = 0; j<s.size(); ++j)
//		{
//			if (s[i] == temp[j])
//			{
//				if (i == 0 || j == 0)
//					v[i][j] = 1;
//				else
//					v[i][j] = v[i - 1][j - 1] + 1;
//			}
//			if (v[i][j]>MaxLen)
//			{
//				int thispos = s.size() - 1 - j;
//				if (thispos + v[i][j] - 1 == i)
//				{
//					pos = i - v[i][j] + 1;
//					MaxLen = v[i][j];
//				}
//			}
//		}
//	}
//	return s.substr(pos, MaxLen);
//
//}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		cout << longestPalindrome(str) << endl;
//	}
//
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int max(int& a, int& b)
{
	return a > b ? a : b;
}

bool isMatch(string s, string p)
{
	vector<vector<int>> v(s.size() + 1, vector<int>(p.size() + 1, 0));
	v[0][0] = 1;
	for (int i = 1; i <= p.size(); i++)
	{
		if (i == 1)
			continue;
		v[0][i] = v[0][i - 2] && (p[i - 1] == '*');
	}
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= p.size(); j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				v[i][j] = v[i - 1][j - 1];
			else if (p[j - 1] == '*')
			{
				if (j<2)
					continue;
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
				{
					v[i][j] = v[i - 1][j] || v[i][j - 1] || v[i][j - 2];
				}
				else if (p[j - 2] != '.'&&p[j - 2] != s[i - 1])
				{
					v[i][j] = v[i][j - 2];
				}
			}
		}
	return v[s.size()][p.size()];
}
string lengthOfLongestSubstring(string s)
{
	vector<int> m(128, -1);
	int res = 0, left = -1;
	string str;
	for (int i = 0; i < s.size(); ++i) {
		left = max(left, m[s[i]]);
		m[s[i]] = i;
		if (res<i - left)
		{
			res = i - left;
			str = s.substr(left + 1, res);
		}
	}
	return str;

}
int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{
		if (isMatch(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}