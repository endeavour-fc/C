#include<iostream>
using namespace std;
class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout << "Test()" << endl;
	}
	Test(Test &t1):m_data(t1.m_data)
	{
		cout << "Test(Test& t1)" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
private:
	int m_data;
 };

int main()
{

	return 0;
}