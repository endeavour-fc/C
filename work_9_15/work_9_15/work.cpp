#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_first_num(int *date, int len, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middle_num = (start + end) / 2;
	int middle_date = date[middle_num];
	if (middle_date == k)
	{
		if ((middle_num > 0 && date[middle_num - 1] != k) || middle_num == 0)
			return middle_num;
		else
			end = middle_num - 1;
	}
	else if (middle_date > k)
		end = middle_num - 1;
	else
		start = middle_num + 1;

	return get_first_num(date, len, k, start, end);
}

int get_last_num(int *date, int len, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middle_num = (start + end) / 2;
	int middle_date = date[middle_num];
	if (middle_date == k)
	{
		if ((middle_num < len-1 && date[middle_num + 1] != k) || middle_num == len-1)
			return middle_num;
		else
			start = middle_num + 1;
	}
	else if (middle_date > k)
		end = middle_num - 1;
	else
		start = middle_num + 1;

	return get_last_num(date, len, k, start, end);
}

int getnum(int date[], int len, int k)
{
	int num = 0;
	int first = get_first_num(date, len, k, 0, len - 1);
	int last = get_last_num(date, len, k, 0, len - 1);
	if (first > -1 && last > -1)
		num = last - first+1;

	return num;
}


int main()
{
	int arr[] = { 1,2,3,3,3,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", getnum(arr, len, 3));
	
	system("pause");
	return 0;
}