#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insert_sort(int arr[], int len)
{
	int temp = 0;
	int j = 0;
	for (int i = 1; i < len; i++)
	{
		temp = arr[i];
		//if (arr[i - 1] > arr[i])
		//{
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		//}
	}
}
void Shell_Sort(int arr[], int len)
{
	int temp = 0;
	int j = 0;
	int increase = 0;
	for (increase = len / 2; increase > 0; increase /= 2)
	{
		for (int i = increase; i < len; i++)
		{
			temp = arr[i];
			for (j = i - increase; j >= 0 && temp < arr[j]; j -= increase)
				arr[j + increase] = arr[j];
			arr[j + increase] = temp;
		}
	}
}

void Quick_sort(int arr[], int start, int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];
	if (i < j)
	{
		while (i<j)
		{
			while (i < j&&arr[j] >= temp)
				j--;
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			while (i < j&&arr[i] <= temp)
				i++;
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = temp;
		Quick_sort(arr, start, i - 1);
		Quick_sort(arr, i + 1, end);
	}
}
void Merge(int arr[], int start, int mid, int end,int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int len = 0;
	while (i_start<=i_end&&j_end>=j_start)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[len] = arr[i_start];
			len++;
			i_start++;
		}
		else
		{
			temp[len] = arr[j_start];
			len++;
			j_start++;
		}
	}
	while (i_start <= i_end)
	{
		temp[len] = arr[i_start];
		len++;
		i_start++;
	}
	while (j_start <= j_end)
	{
		temp[len] = arr[j_start];
		len++;
		j_start++;
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

int main()
{
	int arr[] = { 2,1,4,7,3,5,8,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* temp = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	//insert_sort(arr, len);
	//Shell_Sort(arr, len);
	//Quick_sort(arr, 0, len - 1);
	MergeSort(arr, 0, len - 1, temp);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	free(temp);
	
	system("pause");
	return 0;
}