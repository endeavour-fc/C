#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Sort_Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void Bubble_Sort(int* arr, int len)
{
	for(int i=0;i<len-1;i++)
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}

void Select_Sort(int* arr, int len)
{
	for(int i=0;i<len-1;i++)
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
}

void Insert_Sort(int* arr, int len)
{
	int j = 0;
	int temp = 0;
	for (int i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

void Shell_Sort(int* arr, int len)
{
	int statement = len;
	int j = 0;
	int temp = 0;
	for (statement /= 2; statement > 0; statement /= 2)
	{
		for (int i = statement; i < len; i++)
		{
			temp = arr[i];
			for (j = i - statement; i >= 0 && arr[j] > temp; j-=statement)
				arr[j + statement] = arr[j];
			arr[j + statement] = temp;
		}
	}
}

void Quict_Sort(int* arr, int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[i];
	if (i < j)
	{
		while (i < j)
		{
			while (i < j&&temp <= arr[j])
				j--;
			if (i < j)
				arr[i] = arr[j];
			while (i < j&&temp >= arr[i])
				i++;
			if (i < j)
				arr[j] = arr[i];
		}
		arr[i] = temp;
		Quict_Sort(arr, start, i - 1);
		Quict_Sort(arr, i + 1, end);
	}

}

void Merge(int* arr, int start, int mid, int end, int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int len = 0;
	while (i_start <= i_end&&j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[len++] = arr[i_start++];
		}
		else
		{
			temp[len++] = arr[j_start++];
		}
	}
	while (i_start <= i_end)
	{
		temp[len++] = arr[i_start++];
	}
	while (j_start <= j_end)
	{
		temp[len++] = arr[j_start++];
	}
	for (int i = 0; i < len; i++)
	{
		arr[i + start] = temp[i];
	}
}

void Merge_Sort(int* arr, int start, int end, int* temp)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	Merge_Sort(arr, start, mid, temp);
	Merge_Sort(arr, mid+1, end, temp);
	Merge(arr, start, mid, end, temp);
}

int main()
{
	int arr[] = { 2,1,3,5,4,7,6,9,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* temp = (int*)malloc(sizeof(int)*len);
	Sort_Print(arr, len);
	//Bubble_Sort(arr, len);
	//Select_Sort(arr, len);
	//Insert_Sort(arr, len);
	//Shell_Sort(arr, len);
	//Quict_Sort(arr, 0, len - 1);
	Merge_Sort(arr, 0, len-1, temp);
	Sort_Print(arr, len);
	
	system("pause");
	return 0;
}