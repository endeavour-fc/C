#include<iostream>
using namespace std;

class A
{
public:
	virtual void  funA()
	{
		cout << "A::A" << endl;
	}
	virtual void funB()
	{
		cout << "A::B" << endl;
	}
	void funC()
	{
		cout << "A::C" << endl;
	}
};

class B:public A
{
public:
	virtual void funA()
	{
		cout << "B::A" << endl;
	}
	virtual void  funB()
	{
		cout << "B::B" << endl;
	}
};

int main()
{
	A* p = new B;

	p->funA();
	p->funB();
	
	system("pause");
	return 0;
}