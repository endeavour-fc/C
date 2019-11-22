#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
int main()
{
	int num = 0;
	char arr[50] = { 0 };
	printf("请输入你想要的菱形（为奇数最大不超过50）\n");
	scanf("%d", &num);
	int m = num / 2;
	for (int i = 0; i<=m; i++)
	{
		if ( 0 == i )
		{
			arr[m] = '*';
			for(int i=0;i<50;i++)
			printf("%c", arr[i]);
			printf("\n");
		}
		else
		{
			arr[m - i] = '*';
			arr[m + i] = '*';
			for (int i = 0; i<50; i++)
				printf("%c", arr[i]);
			printf("\n");
		}
	}
	for (int i = 0; i < m; i++)
	{
		arr[i] = ' ';
		arr[num - i-1] = ' ';
		for (int i = 0; i<50; i++)
			printf("%c", arr[i]);
		printf("\n");
	}

	system("pause");
	return 0;
}


int main02()
{
	int q = 0;
	int s = 0;
	int g = 0;
	for (int i = 0; i < 1000; i++)
	{
		q = i / 100;
		s = (i /10 )%10;
		g = i % 10;
		if ((q*q*q + s*s*s + g*g*g) == i)
			printf("%d  ", i);
	}

//	system("pause");
	return 0;
}


int main03()
{
	int k = 0;
	int sum = 0;
	int num = 0;
	int b = 0;
	printf("请输入一个0~10的整数\n");
	scanf("%d", &num);
	b = num;
	for (int i = 0; i < 5; i++)
	{
		k = num;
		sum += num;
		num =b*pow(10,i+1);
		num += k;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}