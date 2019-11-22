#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcpy(char *des,const char *string)
{
	char*p = des;
	if (des == NULL && string == NULL)
		return NULL;
	while (*des++ = *string++)
	{
		;
	}
	return p;
}

const char *my_strstr(const char *p1, const char *p2)
{
	if (p1 == NULL && p2 == NULL && p1&&p2)
		return NULL;
	const char *temp = p2;
	const char *start = p1;

	while (*p1)
	{
		while (*p1 == *p2&&*p2&&*p1)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
			return start;
		start++;
		p1 = start;
		p2 = temp;
	}
	return NULL;
}

char *my_strcat(char *des, const char *string)
{
	if (des == NULL && string == NULL)
		return NULL;

	char *p = des;

	while (*des)
	{
		des++;
	}
	while (*des++ = *string++)
	{
		;
	}
	return p;
}


const char* my_strchr(const char* p1, const char* p2)
{
	if (p1 == NULL && p2 == NULL && p1&&p2)
		return NULL;

	while (*p1)
	{
		while (*p1 == *p2)
		{
			return p1;
		}
		p1++;
	}
	return NULL;
}


int my_strcmp(const char* p1, const char* p2)
{
	if (p1 == NULL && p2 == NULL && p1&&p2)
		return NULL;


	while (*p1||*p2)
	{
		if (*p1 > *p2)
			return 1;
		else if (*p1 < *p2)
			return -1;
		else
		{
			p1++;
			p2++;
		}

	}
	return 0;
}

void* my_memset(void* des, int c, unsigned int count)
{
	char* p=(char*)des;
	for (int i = 0; i < count; i++)
	{
		p[i] = c;
	}
	return p;
}

void *my_memmove(void *dest, const void *src, size_t count)
{
	if (dest == NULL && src == NULL)
		return NULL;
	char* p = (char*)dest;
	char* p2 = (char*)src;
	char* arr[30] = { 0 };
	//char* p3 = p;
	for (int i = 0; i < count; i++)
	{
		*p = *p2;
		p2++;
		p++;
	}
	return p;
}

int main()
{
	char arr[30] = "aeavxgd";
	my_memmove(arr+2, arr+4, 8);
	printf("%s\n",arr );
	
	system("pause");
	return 0;
}