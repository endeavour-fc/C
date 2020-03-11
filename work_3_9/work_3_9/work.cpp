#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
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
int main()
{
	cout << sizeof(A) << endl;

	return 0;
}
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