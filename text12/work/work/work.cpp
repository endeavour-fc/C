#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

void swap(int &a, int &b)
{
	int f = 0;
	f=a;
	a=b;
	b = f;
	
}





int main01()
{
	int a = 9;
	int b = 3;
	printf("%d,%d \n", a, b);
	swap(a, b);
	printf("%d,%d ", a, b);

	return 0;
}


int main02()
{
		int temp = 0;
		int a[10] = { 1,2,34,5,56,57,7,6,75,6};
		for(int i=0;i<10;i++)
			for (int j = i; j < 10; j++)
			{
				if (a[i] < a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}

			}
	//	for (int i = 0; i<10; i++)
		printf("MAX=%d", a[0]);


	return 0;
}


int main03()
{

	int temp = 0;
	int a[3] = { 1,2,33 };
	for (int i = 0; i<3; i++)
		for (int j = i; j <3; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}
	for (int i = 0; i<3; i++)
	printf("%d  ", a[i]);
	return 0;
}



int main()
{
	int num1 = 0;
	int num2 = 0;
	int temp = 0;
	int Max = 0;
	printf("请输入两个整数\n");
	scanf("%d%d", &num1, &num2);
	Max = num1 > num2 ? num1 : num2;
	for (int i = 2; i < Max; i++)
	{
		if (num1%i == 0 && num2%i == 0)
		{
			temp = i;
		}
	}
	if (temp == 0)
	{
		printf("两个数不存在公约数\n");
	}
	else
		printf("公约数为：%d", temp);

	system("pause");
	return 0;
}