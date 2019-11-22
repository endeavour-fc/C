#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool core(const char* arr, int rows, int cols, int row, int col, int &count, const char* str, bool* visit)
{
	if (str[count] == '\0')
		return true;
	bool temp = false;
	if (row >= 0 && row < rows&&col >= 0 && col < cols&&arr[row*cols + col] == str[count] && !visit[row*cols + col])
	{
		count++;
		visit[row*cols + col] = true;
		temp = core(arr, rows, cols, row, col - 1, count, str, visit)
			|| core(arr, rows, cols, row - 1, col, count, str, visit)
			|| core(arr, rows, cols, row + 1, col, count, str, visit)
			|| core(arr, rows, cols, row, col + 1, count, str, visit);
		if (!temp)
		{
			count--;
			visit[row*cols + col] = false;
		}
	}
	return temp;
}


bool haspath(const char* arr, int rows, int cols, const char* str)
{
	if (arr == NULL || rows < 1 || cols < 1 || str == NULL)
		return false;
	bool* visit = new bool[rows*cols];
	memset(visit, 0, rows*cols);
	int count=0;
	int k = 0;
	for(int row=0;row<rows;row++)
		for (int col = 0; col < cols; col++)
		{
			if (core(arr, rows, cols, row, col, count, str, visit))
			{
				for (int i = 0; i < 12; i++)
				{
					k++;
					printf("%d ", visit[i]);
					if (k == 4)
					{
						printf("\n");
						k = 0;
					}
				}
				return true;
			}
		}
	delete[]visit;
	return false;
}

int main()
{
	//int visit[3][4] = { 0 };
	const char *arr = "abtgcfcsjdeh";
	haspath(arr, 3, 4, "bfce");
	

	
	system("pause");
	return 0;
}