#include"data.h"
int GetMonth(int year, int month)
{
	int days[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 28;
	return days[month];
}
Date::Date(int year, int month , int day):_year(year),_month(month),_day(day)
{

}
Date::Date(const Date& d)
{
	this->_day = d._day;
	this->_month = d._month;
	this->_year = d._month;
}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->_day = d._day;
		this->_month = d._month;
		this->_year = d._month;
	}
	return *this;
}
Date Date::operator+(int days)
{
	Date temp=*this;
	int mdays = GetMonth(temp._year, temp._month);
	while (days + temp._day > mdays)
	{
		days -= mdays;
		temp._month++;
		if (temp._month > 12)
		{
			temp._month %= 12;
			temp._year++;
		}
	}
	temp._day += days;
	return temp;
}
Date Date::operator-(int days)
{
	Date temp = *this;
	while (temp._day - days <= 0)
	{
		if (temp._month == 1)
		{
			temp._year--;
			temp._month = 13;
		}
		temp._month--;
		int mdays = GetMonth(temp._year, temp._month);
		days -= temp._day;
	}
	temp._day = GetMonth(temp._year, temp._month) - days;
	return temp;
}
int Date::operator-(const Date& d)
{

}
Date Date::operator++(int)
{
	return *this + 1;
}
Date& Date::operator--()
{

}
Date Date::operator--(int)
{

}
bool  Date::operator>(const Date& d)const
{
	if (this->_year > d._year)
		return true;
	else if (this->_year == d._year)
	{
		if (this->_month > d._month)
			return true;
		else if (this->_month == d._month)
		{
			if (this->_day > d._day)
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	else
		return false;
}
bool  Date::operator>=(const Date& d)const
{
	return !(*this < d);
}
bool  Date::operator<(const Date& d)const
{
	if (this->_year < d._year)
		return true;
	else if (this->_year == d._year)
	{
		if (this->_month < d._month)
			return true;
		else if (this->_month == d._month)
		{
			if (this->_day < d._day)
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	else
		return false;
}
bool  Date::operator<=(const Date& d)const
{
	return !(*this > d);
}
bool  Date::operator==(const Date& d)const
{
	return (this->_year == d._year) && (this->_month == d._month) && (this->_day == d._day);
}
bool Date::operator!=(const Date& d)const
{
	return (this->_year != d._year) || (this->_month != d._month) || (this->_day != d._day);
}

ostream& operator<<(ostream& os, Date d1)
{
	if (d1 != NULL)
	{
		os << d1._year << ":" << d1._month << ":" << d1._day << endl;
	}
	return os;
}
istream & operator>>(istream& is, Date d1)
{
	if (d1 != NULL)
	{
		cout << "please input year" << endl;
		cin >> d1._year;
		cout << "please input month" << endl;
		cin >> d1._month;
		cout << "please input day" << endl;
		cin >> d1._day;
	}
	return is;
}