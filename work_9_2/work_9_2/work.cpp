#include<iostream>
#include<string>
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
int main()
{
	string str;
	string s;
	while (cin >> str >> s)
	{
		int i = 0;
		int num = 0;
		string sum = "0";
		while (i<s.size())
		{
			char count = 0;
			char len = 0;
			count = s[i];
			len = s[i + 1];
			i += 2;
			count -= '0';
			len -= '0';
			for (int j = 0; j<count; ++j)
			{
				sum = addStrings(sum, str.substr(num, len));
				num += len;
			}
		}
		cout << sum << endl;
	}


	return 0;
}