#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void InsertSort(int* arr, int len)
{
	int j = 0;
	int temp = 0;
	for (int i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
}
void ShellSort(int* arr, int len)
{
	int j = 0;
	int temp = 0;
	for (int statement = len / 2; statement > 0; statement /= 2)
	{
		for (int i = statement; i < len; i++)
		{
			temp = arr[i];
			for (j = i - statement; j >= 0 && temp < arr[j]; j -= statement)
				arr[j + statement] = arr[j];
			arr[j + statement] = temp;
		}
	}
}
void QuickSort(int* arr, int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];
	if (i < j)
	{
		while (i < j)
		{
			while (i<j&&arr[j]>=temp)
				j--;
			if (i < j)
			{
				arr[i] = arr[j];
			}
			while (i < j&&arr[i] <= temp)
				i++;
			if (i < j)
			{
				arr[j] = arr[i];
			}
		}
		arr[i] = temp;
		QuickSort(arr, start, i - 1);
		QuickSort(arr, i + 1, end);
	}
}

void Merge(int* arr, int start, int mid, int end,  int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int len = 0;
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[len++] = arr[i_start++];
		//	len++;
			//i_start++;
		}
		else
		{
			temp[len++] = arr[j_start++];
			//len++;
			//j_start++;
		}
	}
	while (i_start <= i_end)
	{
		temp[len++] = arr[i_start++];
		//len++;
		//i_start++;
	}
	while (j_start <= j_end)
	{
		temp[len++] = arr[j_start++];
		//len++;
		//j_start++;
	}
	for (int i = 0; i < len; i++)
	{
		arr[start + i] = temp[i];
	}
}
void MergeSort(int arr[], int start, int end, int* temp)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);
	Merge(arr, start, mid, end, temp);
}
void Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);
}
void HeapAdjust(int* arr, int index, int len)
{
	int max = index;
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (len > lchild&&arr[lchild] > arr[max])
	{
		max = lchild;
	}
	if (len > rchild&&arr[rchild] > arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		int temp = arr[max];
		arr[max] = arr[index];
		arr[index] = temp;
		HeapAdjust(arr, max, len);
	}
}
void HeapSort(int* arr, int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr, i, len);
	}
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		HeapAdjust(arr, 0, len);
	}
}

int main()
{
	int arr[] = { 2,1,4,3,6,5,8,7,0,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*Print(arr, len);
	printf("\n");
	InsertSort(arr, len);*/
	/*Print(arr, len);
	printf("\n");
	ShellSort(arr, len);*/
	Print(arr, len);
	printf("\n");
	QuickSort(arr, 0, len - 1);
	//Print(arr, len);
	//printf("\n");
	/*int* temp = (int*)malloc(sizeof(int)*len);
	MergeSort(arr, 0, len - 1, temp);
	Print(arr, len);
	printf("\n");*/
	//HeapSort(arr, len);
	Print(arr, len);
	printf("\n");

	system("pause");
	return 0;
}