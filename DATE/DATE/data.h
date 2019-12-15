#pragma once
#include<iostream>
#include<time.h>
using namespace std;
class Date
{
public:
	friend ostream & operator<<(ostream& os, Date d1);
	friend istream & operator>>(istream& is, Date d1);
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};