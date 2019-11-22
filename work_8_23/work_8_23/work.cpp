#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void route(char arr[], char arr2[], int len, int k)
{
	//arr2[len] = '\0';
	for (int i = 0; i < k; i++)
	{
		arr2[len - i-1] = arr[i];
	}
	for (int i = 0; i < len - k; i++)
	{
		arr2[i] = arr[i + k];
	}
}

int jude(char arr3[], char arr2[],int sz)
{
	//route(arr, arr2, sz, 3);
	return strcmp(arr3, arr2);
}

int main()
{
	char arr[20] = "ABCDEGHI";
	char arr2[20] = "ABCDEGHI";
	char arr3[20]= "CDEGHIBAm";
	int sz = strlen(arr);
	//int sz = (sizeof(arr) / sizeof(arr[0]))-1;
	route(arr, arr2, sz, 2);
	int ret = jude(arr3, arr2, sz);

	printf("%s\n", arr2);
	printf("%d ", ret);
	
	system("pause");
	return 0;
}