#include<iostream>
#include"Cude.h"
using namespace std;

int main()
{

	Cude a1;
	a1.setX0Y0X1Y1(1, 2, 4, 5);

	cout << "Ãæ»ýÊÇ£º" <<a1.getarea() << endl;

	system("pause");
}