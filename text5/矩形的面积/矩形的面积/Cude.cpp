#include "Cude.h"



double Cude:: getarea()
{
	return ((x1 - x0)*(y1 - y0));
}

void Cude::setX0Y0X1Y1(double x, double y, double xx, double yy)
{
	x0 = x;
	x1 = xx;
	y0 = y;
	y1 = yy;

}