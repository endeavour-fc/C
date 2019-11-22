#include "Circle.h"


void Circle::setXYR(double x, double y, double r)
{
	y0 = y;
	x0 = x;
	r0 = r;
}

bool Circle::judgelength(Circle &c1)
{
	double length;
	length = (y0 - c1.y0)*(y0 - c1.y0) + (x0 - c1.x0)*(x0 - c1.x0);
	if (length > ((r0 + c1.r0)*(r0 + c1.r0)))
	{
		return false;
	}
	else
		return true;
}
