#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findnum(int arr[], int len)
{
	if (arr == NULL && len <= 0)
		return 0;
	int sum[32] = { 0 };
	for (int i = 0; i < len; i++)
	{
		int temp = 1;
		for (int j = 31; j >= 0; j--)
		{
			int bit = arr[i] & temp;
			if (bit)
			{
				sum[j] += 1;
			}
			temp <<= 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;
		result += sum[i] % 3;
	}
	return result;
}


int main()
{
	int arr[] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,6,6,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	
	printf("%d\n", findnum(arr, len));

	system("pause");
	return 0;
}