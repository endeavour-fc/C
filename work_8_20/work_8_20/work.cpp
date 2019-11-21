#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>


int main01()
{
	int num[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int num2[10] = { 1,1,1,1,1,1,1,1,1,1 };
	for(int i=0;i<9;i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				num2[j] = 1;
			else if (j == i)
				num2[j] = 1;
			else
				num[j] = num2[j] + num2[j - 1];
		}
		for (int j = 0; j <= i; j++)
			num2[j] = num[j];
		for (int j = 0; j <= i; j++)
			printf("%d ", num[j]);
		printf("\n");

	}
	
	system("pause");
	return 0;
}

int main02()
{
	for (char i = 'A'; i <= 'D'; i++)
		if ((i != 'A') + (i == 'C') + (i == 'D') + (i != 'D')==3)
			printf("%c", i);
	system("pause");
	return 0;
}

void getnum()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;

		for (a=1; a<=5; a++)
			for (b=1; b<=5; b++)
				for (c=1; c<=5; c++)
					for (d=1; d<=5; d++)
						for (e=1; e<=5; e++)
						{
							if (a*b*c*d*e != 120)
								continue;
							if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1)
								if ((2 == b && 4 != e) || (2 != b && 4 == e) == 1)
									if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1)
										if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1)
											if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1)
											{	
												printf("%d %d %d %d %d \n", a, b, c, d, e);
												//return;
											}
						}

}


int main()
{
	getnum();
	system("pause");
	return 0;
}