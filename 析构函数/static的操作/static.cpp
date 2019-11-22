#include<iostream>
using namespace std;

class Box
{
public:
	Box(double l, double w)
	{
		length = l;
		width = w;
	}

	double &getheight()
	{
		return height;
	}

	void getvolumn()
	{
		cout << length * width*height << endl;
	}

private:
	double length;
	double width;
	static double height;
};

double Box::height=100;

int main()
{
	Box b1(20, 30);
	Box b2(30, 40);

	b1.getvolumn();
	b2.getvolumn();

	b1.getheight() = 200;
	b1.getvolumn();
	b2.getvolumn();
	system("pause");
	return 0;
}