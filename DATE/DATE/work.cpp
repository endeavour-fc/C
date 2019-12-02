#include"data.h"
Date::Date(int year = 1900, int month = 1, int day = 1):_year(year),_month(month),_day(day)
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
	
}