#include "string.h"



String::String()
{
	this->len = 0;
	this->date = NULL;

}
String::String(const char *date)
{
	
	this->len = strlen(date);
	this->date = new char[len+1];
	strcpy(this->date, date);

}
String::String(const String &another)
{
	this->len = strlen(another.date);
	this->date = new char[len+1];
	strcpy(this->date, another.date);
}
String &String::operator=(const String &another)
{
	if (this->date == another.date)
	{
		return *this;
	}


	if (this->date == NULL)
	{
		this->len = strlen(another.date);
		this->date = new char[len+1];
		strcpy(this->date, another.date);
		return *this;
	}
	else
	{
		delete[]this->date;
		this->date = NULL;
		this->len = strlen(another.date);
		this->date = new char[len+1];
		strcpy(this->date, another.date);
		return *this;
	}
}

String::~String()
{
	if (this->date != NULL)
	{
		delete []this->date;
		this->date = NULL;
	}
}
ostream & operator << (ostream &os,const String &s1)
{
	os << s1.date << endl;
	return os;
}

istream & operator >> (istream &is, String &s1)
{
	if (s1.date == NULL)
	{
		int i = 0;
		cout << "ÇëÊäÈë×Ö·û´®µÄ´óÐ¡" << endl;
		cin >>i;
		s1.date = new char[i + 1];
		cout << "ÇëÊäÈë×Ö·û´®" << endl;
		is >> s1.date;
		return is;
	}
	else
	{
		delete[]s1.date;
		s1.date = NULL;
		int i = 0;
		cout << "ÇëÊäÈë×Ö·û´®µÄ´óÐ¡" << endl;
		cin >> i;
		s1.date = new char[i + 1];
		cout << "ÇëÊäÈë×Ö·û´®" << endl;
		is >> s1.date;
		return is;
	}
}



String String::operator + (const String &another)
{
	String temp;
	temp.len = this->len + another.len;
	temp.date = new char[temp.len +1];
	/*for (int i = 0; i < temp.len; i++)
	{
		if (i < this->len)
		{
			temp.date[i] = this->date[i];
		}
		else
		{
			temp.date[i] = another.date[i - this->len];
		}
	}
	temp.date[temp.len] = '\0';
	*/
	//memset(temp.date, 0, temp.len + 1);//½«temp.date¿Õ¼äÇå¿Õ
	strcpy(temp.date, this->date);
	strcat(temp.date, another.date);
	return temp;

}