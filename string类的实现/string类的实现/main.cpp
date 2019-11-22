#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include"string.h"
using namespace std;

int main()
{
	string a;
	String s2;
	String s3;
	String s1("dadasd");
	cout << s1;
	cin >> s1;
	cout << s1;
	s2 = s1;
	cout << s2;
	 s3=(s1 + s2);

	 cout << s3;


	return 0;
}