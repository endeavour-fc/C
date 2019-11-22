#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"game.h"
#include<time.h>

void init(char a[S][M],int s,int m)
{
	memset(a, ' ', s*m);
}

void print(char a[S][M], int s, int m)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", a[i][j]);
			if (j < m - 1)
				printf(" | ");
		}
		printf("\n");
		if(i<s-1)
		for (int i = 0; i < 3 * m; i++)
		{
			printf("-");
		}
		printf("\n");
	}
}

void play(char a[S][M], int s, int m)
{
	int b = 0;
	int c = 0;
	while (1)
	{
		printf("请输入你所下棋的位置\n");
		scanf("%d%d", &b, &c);
		if ((c < s&&c >= 0) && (b < m&&b >= 0) && a[b][c] == ' ')
		{
			a[b][c] = '*';
			break;
		}
		printf("输入错误\n");
	}

}
void computer(char a[S][M], int s, int m)
{
	int b = 0;
	int c = 0;
	while (1)
	{
		b = rand() % s;
		c = rand() % m;

		if ((c < s&&c >= 0) && (b < m&&b >= 0) && a[b][c] == ' ')
		{
			a[b][c] = '#';
			break;
		}
	}
}

int search(char a[S][M], int s, int m)
{
	for(int i=0;i<s;i++)
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == ' ')
				return 0;
		}
	return 1;
}

char jude(char a[S][M], int s, int m)
{
	for (int i = 0; i < m; i++)
	{
		if ((a[i][0] == a[i][1]&& a[i][1] == a[i][2] && a[i][0] != ' ') || (a[0][i] == a[1][i]&& a[1][i] == a[2][i] && a[0][i] != ' '))
			return a[i][0];
	}
		if ((a[0][0] == a[1][1]&& a[1][1] == a[2][2] || a[2][0] == a[1][1] && a[1][1] == a[0][2]) && a[1][1] != ' ')
			return a[1][1];
		else if (search(a, s, m))
			return 'p';
		else
			return 'k';
}


void game(char a[S][M],int s,int m)
{
	char ret = 0;
	srand(unsigned(time(NULL)));
	init(a,s,m);
	print(a, s, m);
	while (1)
	{
		printf("人下棋\n");
		play(a, s, m);
		print(a, s, m);
		ret = jude(a, s, m);
		if (ret != 'k')
		{
			if (ret == '*')
			{
				printf("你赢了\n");
				break;
			}
			else if (ret == '#')
			{
				printf("电脑赢了\n");
				break;
			}
			else
			{
				printf("平局\n");
				break;
			}
		}
			printf("电脑下棋\n");
			computer(a, s, m);
			print(a, s, m);
			ret = jude(a, s, m);
			if (ret != 'k')
			{
				if (ret == '*')
				{
					printf("你赢了\n");
					break;
				}
				else if (ret == '#')
				{
					printf("电脑赢了\n");
					break;
				}
				else
				{
					printf("平局\n");
					break;
				}
			}
	}
}
