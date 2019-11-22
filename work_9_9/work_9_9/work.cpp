#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int equal(double base, double aid)
{
	if (base < 0.1)
		return 1;
	else
		return 0;
}

double powerwithexponent(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = powerwithexponent(base, exponent >> 1);
	result *= result;
	if (exponent & 1 == 1)
		result *= result;

	return result;
}

double power(double base, int exponent)
{
	if (equal(base, 0.0) && exponent<0)
		return 0;
	if (base < 0 && exponent < 0)
		return;
	int temp = 0;
	if (exponent < 0)
	{
		temp = exponent * -1;
	}
	double result = powerwithexponent(base, temp);
	if (exponent < 0)
	{
		result = 1 / result;
	}
	return result;
}

int main()
{
	
	
	system("pause");
	return 0;
}