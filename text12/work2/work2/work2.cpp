#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main01()
{
	int temp = 0;
	int a[5] = { 1,3,2,4,5 };
	int b[5] = { 2,3,5,6,1 };

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}

	//system("pause");
	return 0;
}


int main02()
{
	double sum = 0;
	int k = 1;
	double f = 1;
	for (int i = 0; i < 100; i++)
	{

		if (k == 1)
		{
			sum =sum + (1 / f);
			k--;
		}
		else if (k == 0)
		{
			sum =sum - (1 / f);
			k++;
		}
		f++;
	}

	printf("%lf", sum);
	system("pause");
	return 0;
}



int main()
{
	int temp = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 10 == 9 || i == 9)
			temp++;

	}

	printf("%d ", temp);


	system("pause");
	return 0;
}