#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main01()
{
	int key = 0;
	printf("输入所要的乘法口诀表\n");
	scanf("%d", &key);
	for (int i = 1; i <= key; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%2d*%2d=%3d", i, j, i*j);

		printf("\n");
	}
	system("pause");
	return 0;
}

void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;

}



int main02()
{
	int a = 5;
	int b = 4;
	printf("a is %d   b is %d\n", a, b);
	swap(&a,&b);
	printf("a is %d   b is %d\n", a, b);
	system("pause");
	return 0;
}

int judge(int a)
{
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
		return 1;
	return 0;
}

int main03()
{
	int year = 0;
	while (1)
	{
		printf("请输入年数\n");
		scanf("%d", &year);
		if (year > 0)
			break;
		printf("输入错误\n");
	}

	if (judge(year))
		printf("是闰年\n");
	else
		printf("不是闰年\n");

	system("pause");
	return 0;
}
void init(int a[],const int b)
{
	for (int i = 0; i < b; i++)
		a[i] = i;
}

void empty(int a[],const int b)
{
	for (int i = 0; i < b; i++)
	{
		a[i] = 0;
	}
}

void print(int a[],const int b)
{
	for (int i=0; i < b; i++)
	{
		printf("%2d ", a[i]);
	}
}

int * reverse(int a[], const int b,int arr2[])
{
	for (int i = 0; i < b; i++)
	{
		arr2[b - i - 1] = a[i];
	}
	return arr2;
}

int main()
{
	int arr[20] = { 0 };
	int arr2[20] = { 0 };
	int b=sizeof(arr) / sizeof(arr[0]);
	print(arr, b);
	printf("\n");
	init(arr,b);
	print(arr, b);
	printf("\n");
	empty(arr, b);
	print(arr, b);
	printf("\n");
	init(arr, b);
	print(reverse(arr,b,arr2), b);
	printf("\n");

	system("pause");
	return 0;
}