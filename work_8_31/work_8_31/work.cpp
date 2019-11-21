#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == NULL || length <= 0)
		return false;
	for (int i = 0; i < length; i++)
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				//return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}


int main()
{
	int arr[] = { 2,3,1,0,2,5,3 };
	int arr2[5] = { 0 };
	int temp = 0;
	const int num = sizeof(arr) / sizeof(arr[0]);
	int* p = arr2;
	duplicate(arr, num, p);
	printf("%d\n", *p);
	/*int arr2[num] = { 0 };
	for(int i=0;i<num-1;i++)
		for (int j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	for (int i = 0; i < num - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			printf("%d\n", arr[i]);
		}
	}*/

	/*for (int i = 0; i < num; i++)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				printf("%d\n", arr[i]);
				break;
			}
			else
			{
				temp = arr[i];
				arr[i] = arr[temp];
				arr[temp] = temp;
			}
		}
	}*/



	
	system("pause");
	return 0;
}