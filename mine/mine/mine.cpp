#include"mine.h"

void init(char a[RS][MS], int r, int s, char string)
{
	memset(a, string, r*s);
}

void print(char a[RS][MS], int r, int s)
{

	for (int k = 0; k < s+1; k++)
		printf("%d ", k);
	printf("\n");
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if (j == 1)
				printf("%d ", i);
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}

void getmine(char a[RS][MS], int r, int s)
{
	int p = 0;
	int q = 0;
	int count = 0;
	while (1)
	{
		p = rand() % r+1;
		q = rand() % r+1;
		if (a[p][q] != '1')
		{
			a[p][q] = '1';
			count++;
		}
		if (count == MIN)
			break;
	}
}

int num(char a[RS][MS], int z, int c)
{
	return ((a[z - 1][c - 1] + a[z - 1][c] + a[z - 1][c + 1] + a[z][c - 1] + a[z][c + 1]+  a[z + 1][c - 1] + a[z + 1][c] + a[z + 1][c + 1]) -( 8 * '0'));
}

void larg(char a[RS][MS], char b[RS][MS], int r, int s,int z,int c)
{
	//printf("\n");
	if ((z < 1||z>10) || (c < 1 || c>10))
		return;
	if (a[z][c] != '0')
		return;
	else
	{
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
					return;
				else if (a[z + i][j + c] != '0')
					return;
				else if (num(a, z + i, c + j))
				{
					b[z + i][c + j] = num(a, z + i, c + j)+ '0';
					//return;
				}
				else
				{
					b[z + i][c + j] = '0';
					larg(a, b, R, M, z + i, c + j);
				}
			}
	}
}

int choose(char b[RS][MS], char a[RS][MS], int r, int s)
{
	int z = 0;
	int c = 0;
	while (1)
	{
		printf("ÇëÊäÈë×ø±ê\n");
		scanf("%d%d", &z, &c);
		if (z <= R && z > 0 && c <= M && c > 0 && b[z][c] == '*')
		{
			if (num(a, z, c))
				b[z][c] = num(a, z, c) + '0';
			else
				b[z][c] =  '0';
			larg(a, b, R, M, z, c);
			return 1;
		}
		else if (a[z][c] == '1')
			return 0;
	}
}

int getnum(char b[RS][MS], int r, int s)
{
	int count = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if (b[i][j] == '*')
				count++;
		}
	}
	return count;
}

void game(char a[RS][MS], char b[RS][MS], int r, int s)
{
	//int ret = 0;
	init(a,r,s,'0');
	init(b, r, s, '*');
	print(b, R, M);
	printf("\n");
	getmine(a, R, M);
	while (1)
	{
		//print(b, R, M);
		
		print(a, R, M);
		//printf("ÇëÊäÈë×ø±ê\n");
		if (choose(b, a, R, M))
			print(b, R, M);
		else
		{
			print(a, R, M);
			printf("\n");
			print(b, R, M);
			printf("À×Õ¨ÁË\n");
			break;
		}
		if (getnum(b, R, M) == MIN)
		{
			printf("ÄãÓ®ÁË\n");
			printf("\n");
			break;
		}

	}
}


