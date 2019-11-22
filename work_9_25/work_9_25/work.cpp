#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Status{K1=0,K2};
int g_status = K1;

long long Strcore(const char* digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit >= '0'&&*digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			if ((!minus&&num > 0x7FFFFFFF) || (minus&&num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
	{
		g_status = K1;
	}
	return num;
}

int Str(const char* str)
{
	g_status = K2;
	long long num = 0;
	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
		{
			num = Strcore(str, minus);
		}
	}
	return num;
}



int main()
{
	printf("%d\n", Str("13456567"));
	
	system("pause");
	return 0;
}