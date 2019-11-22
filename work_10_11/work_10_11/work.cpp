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
	} while (carry);
	return num1;
}

int minus(int num1, int num2)
{
	num2 = Add(~num2, 1);
	num1 = Add(num1, num2);
	//num1 = ~(num1 - 1);
	return num1;
}

int main()
{
	printf("%d\n", Add(2, 4));
	printf("%d\n", minus(2, 3));
	
	system("pause");
	return 0;
}