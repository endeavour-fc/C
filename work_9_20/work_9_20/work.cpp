#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}
void Permutation(char* pStr)
{
	if (pStr == NULL)
		return;
	permutation(pStr, pStr);
}

int main()
{
	char arr[] = "abc";
	Permutation(arr);
	
	system("pause");
	return 0;
}