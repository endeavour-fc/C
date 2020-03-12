#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<iostream>
using namespace std;
class Base
{
public:
	Base(int a=0,int c=0)
	{
		m_a = a;
		m_c = c;
		cout << "this is base" << endl;
	}
	void fun()
	{
		cout << "this is base" << endl;
	}
	int Geta()
	{
		return m_a;
	}
	int Getc()
	{
		return m_c;
	}
private:
	int m_a;
	int m_c;
};
class D: public Base
{
public:
	void fun2()
	{
		cout << "this is D" << endl;
	}
private:
	int b;
};
class A
{
private:
	//static int a;

};
// static Safelevel GetPwdSecurityLevel(string pPasswordStr)
//{
//	string::iterator it = pPasswordStr.begin();
//	int sum = 0;
//	if (pPasswordStr.size() <= 4)
//		sum += 5;
//	else if (pPasswordStr.size() <= 7)
//		sum += 10;
//	else
//		sum += 25;
//	int num_flag = 0;
//	int str[2] = { 0 };
//	int symbol = 0;
//	while (it != pPasswordStr.end())
//	{
//		if (*it >= 'a'&&*it <= 'z')
//			str[0]++;
//		else if (*it >= 'A'&&*it <= 'Z')
//			str[1]++;
//		else if (*it >= '0'&&*it <= '9')
//			num_flag++;
//		else
//			symbol++;
//		it++;
//	}
//	if (str[1] && str[0])
//		sum += 20;
//	else if (str[0] || str[1])
//		sum += 10;
//
//	if (num_flag>1)
//		sum += 20;
//	else if (num_flag)
//		sum += 10;
//	if (symbol>1)
//		sum += 25;
//	else if (symbol)
//		sum += 10;
//	if (str[0] && str[1] && num_flag&&symbol)
//		sum += 5;
//	else if ((str[0] || str[1]) && num_flag&&symbol)
//		sum += 3;
//	else if ((str[0] || str[1]) && num_flag)
//		sum += 2;
//	if (sum >= 90)
//		cout << "VERY_SECURE" << endl;
//	else if (sum >= 80)
//		cout << "SECURE" << endl;
//	else if (sum >= 70)
//		cout << "VERY_STRONG" << endl;
//	else if (sum >= 60)
//		cout << "STRONG" << endl;
//	else if (sum >= 50)
//		cout << "AVERAGE" << endl;
//	else if (sum >= 25)
//		cout << "WEAK" << endl;
//	else
//		cout << "VERY_WEAK" << endl;
//
//	return NULL;
//}
int main()
{
	int** arr[3][4] = { 0 };
	cout << sizeof(arr) << endl;
}
//int main()
//{
//	string s1;
//	getline(std::cin, s1);
//	string::iterator it = s1.begin();
//	int sum = 0;
//	if (s1.size() <= 4)
//		sum += 5;
//	else if (s1.size() <= 7)
//		sum += 10;
//	else
//		sum += 25;
//	int num_flag = 0;
//	int str[2] = { 0 };
//	int symbol = 0;
//	while (it != s1.end())
//	{
//		if (*it >= 'a'&&*it <= 'z')
//			str[0]++;
//		else if (*it >= 'A'&&*it <= 'Z')
//			str[1]++;
//		else if (*it >= '0'&&*it <= '9')
//			num_flag++;
//		else
//			symbol++;
//		it++;
//	}
//	if (str[1] && str[0])
//		sum += 20;
//	else if (str[0] || str[1])
//		sum += 10;
//
//	if (num_flag>1)
//		sum += 20;
//	else if (num_flag)
//		sum += 10;
//	if (symbol>1)
//		sum += 25;
//	else if (symbol)
//		sum += 10;
//	if (str[0] && str[1] && num_flag&&symbol)
//		sum += 5;
//	else if ((str[0] || str[1]) && num_flag&&symbol)
//		sum += 3;
//	else if ((str[0] || str[1]) && num_flag)
//		sum += 2;
//	if (sum >= 90)
//		cout << "VERY_SECURE" << endl;
//	else if (sum >= 80)
//		cout << "SECURE" << endl;
//	else if (sum >= 70)
//		cout << "VERY_STRONG" << endl;
//	else if (sum >= 60)
//		cout << "STRONG" << endl;
//	else if (sum >= 50)
//		cout << "AVERAGE" << endl;
//	else if (sum >= 25)
//		cout << "WEAK" << endl;
//	else
//		cout << "VERY_WEAK" << endl;
//
//	return 0;
//}
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	return 0;
//}
//int getnum(int num1, int num2)
//{
//	if (num1 == 0 || num2 == 0)
//		return 1;
//	return getnum(num1 - 1, num2) + getnum(num1, num2 - 1);
//}
//
//int main()
//{
//	int n, m;
//	cin >> n;
//	cin >> m;
//	cout << getnum(n,m);
//	//system("pause");
//	return 0;
//}
//
//int count_step(int n, int m)
//{
//	if (m == 0 || n == 0)
//		return 0;
//	if (n == 1 && m >= 1)
//		return m + 1;
//	if (m == 1 && n >= 1)
//		return n + 1;
//	if (m>1 && n>1)
//		return count_step(n - 1, m) + count_step(n, m - 1);
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a;
//	cin >> b;
//	cout << getnum(a, b) << endl;
//
//	return 0;
//}
//int main()
//{
//	Base b1(5, 10);
//	int* p = (int*)(&b1);
//	*(p) = 100;
//	*(p + 1) = 200;
//	cout << b1.Geta() << b1.Getc() << endl;
//
//	system("pause");
//	return 0;
//}
//int main()
//{
//	Base a(4), b(5), c[3], *p[2] = { &a,&b };
//	
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	cin >> num1;
//	cin >> num2;
//	if (num1%num2 == 0 || num2%num1 == 0)
//	{
//		cout << (num1>num2 ? num1 : num2) << endl;
//		return 0;
//	}
//	if (num1 % 2 == 0 && num2 % 2 == 0)
//	{
//		while (num2%num1 == 0)
//		{
//			num2 *= 2;
//		}
//		cout << num2 << endl;
//		return 0;
//	}
//	else if (num1 % 2 == 1 && num2 % 2 == 1)
//	{
//		cout << num1 * num2 << endl;
//		return 0;
//	}
//	else
//	{
//		if (num1 % (num1>num2 ? num1 : num2) % (num1<num2 ? num1 : num2) == 0)
//		{
//			int temp =( num1>num2 ? num1 : num2) % (num1<num2 ? num1 : num2);
//			int sum = 1;
//			for (int i = 1; sum%num1 != 0 || sum % num2 != 0;i++)
//			{
//				sum = temp * i;
//			}
//			cout <<sum << endl;
//		}
//		else
//		{
//			cout << num1 * num2 << endl;
//			return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}