#include<iostream>
#include"Circle.h"
using namespace std;

int main()
{

	Circle c1;
	Circle c2;
	c1.setXYR(1, 2, 1);
	c2.setXYR(8, 8, 1);
	if (c1.judgelength(c2) == true)
	{
		cout << "�ཻ" << endl;
	}
	else
		cout << "����" << endl;

	system("pause");
	return 0;

}