#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
class String
{
public:
	String();
	String(const char *date);
	String( const String &another);
	~String();
	String &operator=(const String &another);
	String operator+(const String &another);
	friend ostream & operator << (ostream &os, const String &s1);
	friend istream & operator >> (istream &is, String &s1);
private:
	int len;
	char *date;
};

