#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

int max(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int* arr = new int[length + 1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			int temp = arr[j] * arr[i - j];
			if (max < temp)
				max = temp;
			arr[i] = max;
		}
	}
	max = arr[length];
	delete[]arr;
	return max;

}


int Max(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int temp = length / 3;
	if (length - temp * 3 == 1)
		temp -= 1;
	int temp2 = (length - temp * 3) / 2;
	return (int)(pow(3, temp))*(int)(pow(2, temp2));
}

int main()
{
	printf("%d\n", Max(6));

	
	system("pause");
	return 0;
}