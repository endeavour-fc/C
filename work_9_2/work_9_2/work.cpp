#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char arr[20] = "We are happy.";
	int len = strlen(arr) + 1;
	char* p = &arr[len];
	int len2 = 0;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == ' ')
			count++;
	}
	len2 = len + 2 * count;
	char* p2 = &arr[len2];
	while (p2 != p)
	{
		if (*p == ' ')
		{
			(*p2--) = '0';
			(*p2--) = '2';
			(*p2--) = '%';
			p--;
		}
		else
		{
			*p2 = *p;
			p2--;
			p--;
		}

	}


	/*while (*p != '\0')
	{
		if (*p == ' ')
		{
			for (int i = len; p != &arr[i]; i--)
			{
				arr[i + 2] = arr[i];
			}
			len += 2;
			(*p++) = '%';
			(*p++) = '2';
			*p = '0';
		}
		p++;
	}*/
	printf("%s\n", arr);
	system("pause");
	return 0;
}