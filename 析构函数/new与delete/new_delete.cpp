#include<iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)
	{
		cout << "Test(int int)...." << endl;
		t1 = a;
		t2 = b;
	}
	~Test()
	{
		cout << "~Test()..." << endl;
	}
	void printT()
	{
		cout << "printF()...." << endl;
		cout << t1 << "    " << t2 << endl;

	}
private:
	int t1;
	int t2;
};

void test2()
{
	Test *t = new Test(10,20);
	t->printT();
	delete t;
}

void test1()
{
	int *p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " ";
	}

	delete[]p;
}


int main()
{
	test1();
	test2();
	return 0;
}