#include<iostream>
#include"Tree.h"
using namespace std;

int main()
{
	Tree t;
	t.setage(10);
	t.grow(10);

	cout << "Ê÷µÄÄêÁäÊÇ£º" << t.getage() << endl;

	system("pause");
	return 0;
}