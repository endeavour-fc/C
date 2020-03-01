#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Brute_Force(char* Long_String,char* Short_String)
{
	char* p1 = Long_String;
	char* p2 = Short_String;
	char* pPre = p1;
	char* pCur = p2;
	while (*p1)
	{
		while (*pCur)
		{
			if (*pPre == *pCur)
			{
				pPre++;
				pCur++;
			}
			else
			{
				break;
			}
		}
		if (!(*pCur))
			break;
		p1++;
		pPre = p1;
		pCur = p2;
	}
	if (!*pCur)
		return p1;
	else
		return NULL;
}
int Hash(char* str, int len)
{
	int HashNum = 0;
	for (int i = 0; i < len; i++)
	{
		HashNum += str[i] - 'a';
	}
	return HashNum;
}
int NextHash(char* str, int hash, int index, int n)
{
	hash -= str[index] - 'a';
	hash += str[index + n] - 'a';
	return hash;
}
bool Equl_String(char* str1, char* str2, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}
int rabinKarp(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int str1_hash = Hash(str1,len2);
	int str2_hash = Hash(str2, len2);
	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		if (str1_hash == str2_hash && Equl_String(str1 + i, str2, len2))
		{
			return i;
		}
		if (i < len1 - len2)
		{
			str1_hash = NextHash(str1, str1_hash, i, len2);
		}
	}
	return -1;
}
int FindCharacter(char* str, char badCharacter, int index)
{
	for (int i = index - 1; i >= 0; i--)
	{
		if (str[i] == badCharacter)
			return i;
	}
	return -1;
}
int boyerMoore(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int start = 0;
	while (start <= len1 - len2)
	{
		int i = 0;
		for (i = len2 - 1; i >= 0; i--)
		{
			if (str1[start + i] != str2[i])
				break;
		}
		if (i < 0)
			return start;
		int charIndex = FindCharacter(str2, str1[i + start], i);
		int bcoffset = charIndex >= 0 ? i - charIndex : i + 1;
		start += bcoffset;
	}
	return -1;
}
int* GetNext(char* str, int len)
{
	int* next = (int*)malloc(sizeof(int)*len);
	int j = 0;
	*next = { 0 };
	for (int i = 2; i < len; i++)
	{
		while (j&&str[j] != str[i - 1])
		{
			j = next[j];
		}
		if (str[j] == str[i - 1])
			j++;
		next[i] = j;
	}
	return next;
}
int KMP(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int* next = GetNext(str2,len2);
	int j = 0;
	for (int i = 0; i < len1; i++)
	{
		while (j > 0 && str1[i] != str2[j])
		{
			j = next[j];
		}
		if (str1[i] == str2[j])
		{
			j++;
		}
		if (j == len2)
			return i - j + 1;
	}
	return -1;
}
int main()
{
	char arr1[] = "abcefdefdedefgh";
	char arr2[] = "dedef";
	char* p = arr1;
	int i = 0;
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	if ((i = KMP(arr1, arr2))!=-1)
	{
		printf("%s\n", p+i);
	}
	else
	{
		printf("find err!\n");
	}
	
	system("pause");
	return 0;
}