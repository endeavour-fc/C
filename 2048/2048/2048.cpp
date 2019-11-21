#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int num[4][4] = { 0 };
int MAX = 0;
int t[4] = { 0 };
int coun = 1;
void Srand()   //产生随机数
{
	int i = 0;
	int j = 0;
	do
	{

		i = ((unsigned)rand()) % 4;
		j = ((unsigned)rand()) % 4;

	} while (num[i][j] != 0);

	if (((unsigned)rand() % 4)==0)
	{
		num[i][j] = 4;
	}
	else
	{
		num[i][j] = 2;
	}

}


void fun()    //消除数组中的0
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		if (t[i] == 0)
		{
			for (j = i + 1; j < 4; j++)
			{
				if (t[j] != 0)
				{
					break;
				}
		
			}
			t[i] = t[j];
			t[j] = 0;
		}


		if (j >= 3)
		{
			break;
		}
	}
}

void add()  //将两个临近的数合并
{

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (t[i] == t[i + 1])
		{
			t[i] += t[i];
			t[i + 1] = 0;
			fun();
			if (MAX <= t[i])
			{
				MAX = t[i];
			}
		}
	}
}


void left()//向左
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
		
			t[j] = num[i][j];

		}
		fun();

		add();

		for (j = 0; j < 4; j++)
		{
			num[i][j] = t[j];
		}
	}



}



void right()//向右
{

	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{

			t[j] = num[i][j];

		}
		fun();
		add();
		
		
			for (j = 0; j < 4; j++)
			{
				if (t[j]==0)
				{
					num[i][3-j]=t[j-1];
				}
			}
		
	}


}


void up()  //向上
{

	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{

			t[j] = num[j][i];

		}
		fun();
		add();
		for (j = 0; j < 4; j++)
		{
			num[j][i] = t[j];
		}
	}


}


void down()//向下
{

	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{

			t[j] = num[j][i];

		}
		fun();
		add();
		for (j = 0; j < 4; j++)
		{
			num[j][i] = t[3 - j];
		}
	}

}


int main()
{
	int i = 0;
	int j = 0;
	char s=NULL;

	while (1)
	{

		

		if (coun == 1)
		{
			Srand();
		}
		system("CLS");
		printf("--------------------\n");
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (num[i][j] == 0)
				{
					printf("|  ");
				}
				else
				{
					printf("| %d", num[i][j]);
				}
				if (j == 3)
				{
					printf("\n");
				}
			}

		}
		printf("--------------------\n");
		printf("please input a or s or w or d\n");
		s = getch();
		switch (s)
		{
		case 'a':
			left(); break;
		case 'd':
			right(); break;
		case 'w':
			up(); break;
		case's':
			down(); break;
		
		}


		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (num[i][j] == 0)
				{
					coun = 1;
				}
				else
				{
					coun = 0;
				}
			}
		}

	}

	return 0;

}