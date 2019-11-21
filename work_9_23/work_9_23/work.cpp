#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Reverse(char* begin, char* end)
{
	if (begin == NULL || end == NULL)
		return;
	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}

int main()
{
	char arr[] = "student a am i";
	int len = strlen(arr)-1;
	char* start = arr;
	char* end = arr;
	Reverse(start, start + len);

	while (start != '\0')
	{
		if (*end == ' '||*end=='\0')
		{
			Reverse(start, end - 1);
			if (*end == '\0')
				break;
			start = end + 1;
			end++;
		}
		end++;
	}
	printf("%s\n", arr);


	system("pause");
	return 0;
}