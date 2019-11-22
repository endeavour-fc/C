#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	for (int i = 31; i >=0; i--)
	{
		printf("%d", (value >> i) & 1);
	}
	while (value)
	{
		count++;
		value = value & (value - 1);
	}
	printf("\n");
	return count;

}

void getnum(int num)
{
	int temp = 0;
	while (num > 1)
	{
		temp = num % 10;
		printf("%d ", temp);
		num /= 10;
	}
}


int main()
{
	int a = 8;
	int b = 16;
	int c = a ^ b;
	//printf("%d", count_one_bits(c));
	getnum(421241);

	system("pause");
	return 0;
}