#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>
using namespace std;

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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> v;
	if (matrix.size() == 0)
		return v;
	int left = 0;
	int right = matrix[0].size() - 1;
	int top = 0;
	int bottom = matrix.size() - 1;
	while (left <= right && top <= bottom)
	{
		for (int i = left; i <= right; ++i)
			v.push_back(matrix[top][i]);
		for (int i = top + 1; i <= bottom; ++i)
			v.push_back(matrix[i][right]);
		if (left<right&&top<bottom)
		{
			for (int i = right - 1; i >= left; --i)
				v.push_back(matrix[bottom][i]);
			for (int i = bottom - 1; i>top; --i)
				v.push_back(matrix[i][left]);
		}
		++left;
		--right;
		++top;
		--bottom;
	}
	return v;

}
int main()
{
	vector<vector<int>> v = { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12} };
	spiralOrder(v);
	//getnum();
	system("pause");
	return 0;
}