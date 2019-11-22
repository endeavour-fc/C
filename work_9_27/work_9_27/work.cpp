#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubblesort(int* p,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;
	}
}

void selectsort(int* p, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 1;
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] > p[j])
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				flag = 0;
			}
		}
		if (flag)
			return;
	}
}


void insertsort(int* p, int len)
{
	int j = 0;
	for (int i = 1; i < len; i++)
	{
		if (p[i - 1] > p[i])
		{
			int temp = p[i];
			for (j = i - 1; j >= 0 && p[j] > temp; j--)
				p[j + 1] = p[j];
			p[j + 1] = temp;
		}

	}
}

void ShellSort(int *arr, int size)
{
	int i=0, j=0, temp=0, increment=0;
	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < size; i++) 
		{
			temp = arr[i];
			for (j = i - increment; j >= 0 && temp < arr[j]; j -= increment)
			{
				arr[j + increment] = arr[j];
			}
			arr[j + increment] = temp;
		}
	}
}



int main()
{
	int arr[] = { 2,4,1,7,5,9,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//bubblesort(arr, len);
	//selectsort(arr, len);
	//insertsort(arr, len);
	ShellSort(arr, len);

	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);
	
	system("pause");
	return 0;
}