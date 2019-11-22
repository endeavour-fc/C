#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void move_num(int arr[], int len)
{
	if (arr == NULL || len == 0)
		return;
	int* pBegin = arr;
	int* pEnd = arr + len - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && (*pBegin & 1) != 0)
			pBegin++;
		while (pBegin < pEnd && (*pEnd & 1) == 0)
			pEnd--;
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	move_num(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	system("pause");
	return 0;
}