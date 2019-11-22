#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * swap(int arr[], int len,int len2,int arr2[])
{
	
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arr2[len2 + count] = arr[i];
			count++;
		}
		if (arr[i] % 2 == 1)
		{
			arr2[count2] = arr[i];
			count2++;
		}
	}
	return arr2;
}


int main01()
{
	int arr2[10] = { 0 };
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = (sizeof(arr) / sizeof(arr[0]));
	int len2 = len / 2;
	int *p = swap(arr, len, len2,arr2);
	for (int i = 0; i < len; i++)
		printf("%d ", *(p + i));


	system("pause");
	return 0;
}
int main()
{
	int a = 5;
	int temp = 0;
	int arr[3][3] = { 1,2,3,2,3,4,3,4,5 };
	for (int i = 0; i<3; i++)
	{
		if (arr[2][i] >= a)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[j][i] == a)
				{
					printf("找到了\n");
					temp = 1;
				}
					
			}
		}
	}
	if (temp == 0)
	{
		printf("没找到\n");
	}


	system("pause");
	return 0;
}