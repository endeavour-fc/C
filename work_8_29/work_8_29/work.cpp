#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {

	int temp = 0;
	for (int i = 0; i<k; i++)
		for (int j = numsSize - 1; j>0; j--)
		{
			temp = nums[j];
			nums[j] = nums[j - 1];
			nums[j - 1] = temp;
		}


}


void rotate2(int* nums, int numsSize, int k) {
	int count = 0;
	int count2 = 0;
	int temp = 0;
	for (int j = 0; j<numsSize / 2; j++)
	{
		temp = nums[j];
		nums[j] = nums[numsSize - j - 1];
		nums[numsSize - j - 1] = temp;
	}
	for (int i = k; i<(k + numsSize) / 2; i++)
	{

		temp = nums[i];
		nums[i] = nums[numsSize - count - 1];
		nums[numsSize - count - 1] = temp;
		count++;
	}

	for (int i = 0; i<k / 2; i++)
	{
		temp = nums[i];
		nums[i] = nums[k - 1-count2];
		nums[k - 1-count2] = temp;
		count2++;
	}


}

char* my_strncpy(char* p, const char *p2, int num)
{
	//char *ret = p;
	for (int i = 0; i < num; i++)
		*(p + i) = *(p2 + i);
	*(p + num) = '\0';
	return p;
}

char* my_strncat(char* p, const char *p2, int num)
{
	char* ret = p;
	while (*p != '\0')
	{
		p++;
	}
	for (int i = 0; i < num; i++)
	{
		*(p + i) = *(p2 + i);
	}
	*(p + num) = '\0';

	return ret;
}

int my_strncmp(char* p, const char *p2, int num)
{
	char* ret = p;
	while (*p == *p2 && num > 0)
	{
		p++;
		p2++;
		num--;
	}
	if (num > 0)
		return 1;
	return 0;
}

int main()
{
	/*int arr[5] = {2147483647,-2147483648,33,219,0};
	rotate2(arr, 5, 4);
	for (int i = 0; i < 7; i++)
		printf("%d ",arr[i]);*/
	char arr[10] = "asdzczc";
	int ret = my_strncmp(arr, "asdzcz", 7);
	printf("%d", ret);



	system("pause");
	return 0;
}