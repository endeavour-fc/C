#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
class Base
{
public:
	Base(int a=0)
	{
		cout << "this is base" << endl;
	}
	void fun()
	{
		cout << "this is base" << endl;
	}
protected:
	int c;
private:
	int a;
};
class D: public Base
{
public:
	void fun2()
	{
		cout << "this is D" << endl;
		c = 0;
	}
private:
	int b;
};
//int main()
//{
//	Base a(4), b(5), c[3], *p[2] = { &a,&b };
//	
//	system("pause");
//	return 0;
//}
int main()
{
	int num1 = 0;
	int num2 = 0;
	cin >> num1;
	cin >> num2;
	if (num1%num2 == 0 || num2%num1 == 0)
	{
		cout << (num1>num2 ? num1 : num2) << endl;
		return 0;
	}
	if (num1 % 2 == 0 && num2 % 2 == 0)
	{
		while (num2%num1 == 0)
		{
			num2 *= 2;
		}
		cout << num2 << endl;
		return 0;
	}
	else if (num1 % 2 == 1 && num2 % 2 == 1)
	{
		cout << num1 * num2 << endl;
		return 0;
	}
	else
	{
		if (num1 % (num1>num2 ? num1 : num2) % (num1<num2 ? num1 : num2) == 0)
		{
			int temp =( num1>num2 ? num1 : num2) % (num1<num2 ? num1 : num2);
			int sum = 1;
			for (int i = 1; sum%num1 != 0 || sum % num2 != 0;i++)
			{
				sum = temp * i;
			}
			cout <<sum << endl;
		}
		else
		{
			cout << num1 * num2 << endl;
			return 0;
		}
	}
	system("pause");
	return 0;
}