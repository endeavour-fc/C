#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n >>= 1;
	}
	return count;
}

int number2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
			count++;

		flag = flag << 1;
	}
	return count;
}

int number3(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;
}

int main()
{
	
	
	system("pause");
	return 0;
}