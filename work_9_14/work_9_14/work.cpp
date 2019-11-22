#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char First(char* string)
{
	if (string == NULL)
		return 0;
	const int size = 256;
	unsigned int hash[size] = { 0 };
	char* p = string;
	while (*(p) != '\0')
		hash[*(p++)]++;

	p = string;
	while (*p != '\0')
	{
		if (hash[*p] == 1)
			return *p;
		p++;
	}
	return 0;
}



int main()
{
	char arr[] = "abaccdeff";
	printf("%c", First(arr));
	
	system("pause");
	return 0;
}