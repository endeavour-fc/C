#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template<class T>
class print
{
public:
	void operator()(const T& elem)
	{
		cout << elem << " ";
	}
};

template<class T>
class testClass
{
public:
	static const int _datai = 5;
	static const int _datal = 3L;
	static const char _datac = 'c';
};

class INT
{
	friend ostream& operator<<(ostream& os, const INT& i);
public:
	INT(int i) :m_i(i) {};
	INT& operator++()
	{
		++(this->m_i);
		return *this;
	}
	const INT operator++(int)
	{
		INT temp = *this;
		++(*this);
		return temp;
	}
	INT& operator--()
	{
		--(this->m_i);
		return *this;
	}
	INT operator--(int)
	{
		INT temp = *this;
		--(*this);
		return temp;
	}
	int& operator*()const
	{
		return (int&)m_i;
	}
private:
	int m_i;
};
ostream& operator<<(ostream& os, const INT& i)
{
	os << "[" << i.m_i << "]";
	return os;
}
int main()
{
	vector<int> v = { 0,1,2,3,4,5,6 };
	for_each(v.begin(), v.end(), print<int>());
	
	system("pause");
	return 0;
}