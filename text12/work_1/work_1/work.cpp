#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>



int main01()//100-200间的素数
{

	for(int i=100;i<=200;i++)
		for (int j = 2; j < 100; j++)
		{
			if (i%j == 0)
			{
				break;
			}
			if (j == 99)
			{
				printf("%d\n", i);
			}
		}

	return 0;
}

int main02()//乘法口诀表
{
	for(int i=1;i<=9;i++)
		for (int j = i; j <= 9; j++)
		{
			printf("%d*%d\n", i, j);
		}



	return 0;
}


int main03()//1000-2000间的闰年
{
	for (int i = 1000; i <= 2000; i++)
	{
		if (i % 4 == 0 && i % 100 != 0)
		{
			printf("闰年为%d\n", i);
		}
	}



	return 0;
}