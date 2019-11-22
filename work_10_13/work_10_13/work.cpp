#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Find_frist_bit(int num)
{
	int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 32))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}
void Find_num(int arr[], int len, int* num1, int* num2)
{
	int result = 0;
	for (int i = 0; i < len; i++)
		result ^= arr[i];
	int index = Find_frist_bit(result);
	*num1 = *num2 = 0;
	for (int i = 0; i < len; i++)
	{
		if ((arr[i] >> index) & 1)
			*num1 ^= arr[i];
		else
			*num2 ^= arr[i];
	}
}

int main()
{
	int arr[] = { 2,4,3,6,3,2,5,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num1 = 0;
	int num2 = 0;
	Find_num(arr, len, &num1, &num2);
	printf("%d  %d\n", num1, num2);
	
	system("pause");
	return 0;
}