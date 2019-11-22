#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
int getnum(int* arr, int len)
{
	if (arr == NULL)
		return NULL;
	int left = 0;
	int right = len - 1;
	int mid = 0;
	while (right >= left)
	{
		mid = (left + right) / 2;
		if (arr[mid] == mid)
		{
			printf("%d ", mid);
			return mid;
		}
		else if (arr[mid] < mid)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}


int main()
{
	int arr[] = { -3,-1,1,3,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	getnum(arr, len);
	
	system("pause");
	return 0;
}