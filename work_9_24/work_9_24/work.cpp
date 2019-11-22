#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int g_Maxnumlen = 10;
char* g_str1 = new char[g_Maxnumlen * 2 + 1];
char* g_str2 = new char[g_Maxnumlen * 2 + 1];

int compare(const void* str1, const void* str2)
{
	strcpy(g_str1, *(const char**)str1);
	strcat(g_str1,*(const char**)str2);

	strcpy(g_str2, *(const char**)str2);
	strcat(g_str2, *(const char**)str1);

	return strcmp(g_str1, g_str2);
}

void printnum(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	char** strnum = (char**)(new int[len]);
	for (int i = 0; i < len; i++)
	{
		strnum[i] = new char[g_Maxnumlen + 1];
		sprintf(strnum[i], "%d", num[i]);
	}
	qsort(strnum, len, sizeof(char*), compare);

	for (int i = 0; i < len; i++)
		printf("%s", strnum[i]);
	printf("\n");
	for (int i = 0; i < len; i++)
		delete[] strnum[i];
	delete[] strnum;
}


int main()
{
	int arr[] = { 3,32,321 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printnum(arr, len);
	
	system("pause");
	return 0;
}