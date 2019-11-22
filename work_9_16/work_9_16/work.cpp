#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = num1 ^ num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);
	return num1;
}


int main()
{
	printf("%d\n", Add(12, 5));
	
	system("pause");
	return 0;
}