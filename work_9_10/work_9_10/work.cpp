#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool incre(char* number)
{
	bool overf = false;
	int ntake = 0;
	int len = strlen(number);
	for (int i = len - 1; i >=0; i--)
	{
		int sum = number[i] - '0' + ntake;
		if (i == (len - 1))
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
				overf = true;
			else
			{
				sum -= 10;
				ntake = 1;
				number[i] = '0' + sum;
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}
	return overf;
}

void printnum(char* number)
{
	bool begin = true;
	int len = strlen(number);

	for (int i = 0; i < len ; i++)
	{
		if (begin &&number[i] != '0')
			begin = false;
		if (!begin)
		{
			printf("%c", number[i]);
		}
	}
	printf("\n");
}

void PrintToMax(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!incre(number))
	{
		printnum(number);
	}
}

void printm(char* number, int length, int index)
{
	if (index == length - 1)
	{
		printnum(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		printm(number, length, index + 1);
	}
}


void printfn(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		printm(number, n, 0);
	}
}


int main()
{
	//PrintToMax(3);
	printfn(3);
	
	system("pause");
	return 0;
}