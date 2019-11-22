#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_char(char* arr,const int len)
{
	if (arr == NULL || arr == " " || arr == "\0")
		return;
	int  Hash[256] = { 0 };
	for (int i = 0; i < len; i++)
	{
		Hash[arr[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		if (Hash[i] == 1)
			printf("%c", i);
	}
}


int main()
{
	char arr[] = "asdfghsdfg";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	get_char(arr, len);
	
	system("pause");
	return 0;
}