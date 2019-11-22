#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_num(int arr[], int num,int len)
{
	int end = len - 1;
	int start = 0;
	int middle = end / 2;
	while (end >= start)
	{
		if (arr[middle] > num)
		{
			end = middle - 1;
			middle = (end + start) / 2;
		}
		else if (arr[middle] < num)
		{
			start = middle + 1;
			middle = (end + start) / 2;
		}
		else
			return middle;
	}
	return -1;
}


int order(int arr[], int start, int end)
{
	int temp = arr[start];
	for (int i = start; i <= end; i++)
	{
		if (temp > arr[i])
		{
			temp = arr[i];
		}
	}
	return temp;
}


int min(int arr[], int len)
{
	int start = 0;
	int end = len - 1;
	int middle = end/2;
	while (arr[start] >= arr[end])
	{
		if (end - start == 1)
		{
			middle = end;
			break;
		}

		if (arr[start] == arr[middle] && arr[middle] == arr[end])
			return order(arr, start, end);

		if (arr[middle] >= arr[start])
		{
			start = middle;
			middle = (end + start) / 2;
		}
		else if (arr[middle] <= arr[start])
		{
			end = middle;
			middle = (end + start) / 2;
		}
	}
	return arr[middle];
}

int main()
{
	int arr[] = { 1,0,1,1,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*int ret = 0;
	if ((ret = find_num(arr, 10, len)) > 0)
	{
		printf("%d\n", ret);
	}
	else*/
		printf("%d\n",min(arr,len));

	system("pause");
	return 0;
}