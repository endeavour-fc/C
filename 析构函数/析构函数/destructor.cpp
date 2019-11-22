#include<iostream>
using namespace std;

class A
{
public:
	A(int x)
	{
		cout << "A(int)...." << endl;
		m_a = x;
	}
	void printA()
	{
		cout << m_a << endl;
	}
	~A()
	{
		cout << "~A()......" << endl;
	}

private:
	int m_a;
};

class B
{
public:
	B(int x, int a1, int a2) :m_b1(a1), m_b2(a2)
	{
		cout << "B(int A& A& )....." << endl;
		b = x;
	}

	void printB()
	{
		cout << b << endl;
		m_b1.printA();
		m_b2.printA();
	}

	~B()
	{
		cout << "~B()...." << endl;
	}

private:
	int b;
	A m_b1;
	A m_b2;

};
#if 0
void test()
{
	A a1(10);
	A a2(20);
	B b1(10, a1, a2);
	b1.printB();
}
#endif
int main()
{
	B b2(10, 20, 30);
	b2.printB();
	return 0;
}