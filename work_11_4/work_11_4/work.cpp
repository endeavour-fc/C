#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void removex(int* nums, int k, int len)
{
	for (int i = k; i<len - 1; i++)
	{
		nums[i] = nums[i + 1];
	}
}

int removeElement(int* nums, int numsSize, int val) {

	int len = numsSize;
	int i = 0;
	while (i<len)
	{
		if (nums[i] == val)
		{
			removex(nums, i, len);
			len--;
		}
		else
		{
			i++;
		}
	}
	return len;
}
typedef struct BinaryNode
{
	char ch;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;
}BinaryNode;

void Rescurion(BinaryNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->ch);
	Rescurion(root->lchild);
	Rescurion(root->rchild);
}

BinaryNode * CreatBinary(const char* s)
{
	static int i = 0;
	if (*(s + i) == '#' || *(s + i) == '\0')
	{
		i++;
		return NULL;
	}
	else
	{
		BinaryNode *root = (BinaryNode*)malloc(sizeof(BinaryNode));
		root->ch = *(s + i);
		i++;
		root->lchild=CreatBinary( s);
		root->rchild=CreatBinary(s);
		return root;
	}
}

void TwoInsertSort(int arr[], int len)
{
	int start = 0;
	int end = 0;
	int* a = (int*)malloc(sizeof(int)*len);
	a[0] = arr[0];
	int i = 1;
	while (start < end)
	{
		if (arr[i] >= a[start])
		{
			a[start++] = arr[i];
			i++;
		}
		else if (arr[i] < a[end])
		{
			end = (end - 1 + len) % len;
			a[end] = arr[i];
			i++;
		}
		else
		{
			int j = 0;
			int temp = arr[start];
			//for(j=)
		}
	}
}

void InsertSort(int arr[], int len)
{
	int j = 0;
	int temp = 0;
	for (int i = 1; i < len; i++)
	{
		temp = arr[i];
		
		if (temp < arr[i - 1])
		{
			for (j = i - 1; j >= 0&& temp<arr[j]; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}
}
void  BinInsertSort(int arr[], int len)
{
	int j = 0;
	int temp = 0;

	for (int i = 1; i < len; i++)
	{
		int right = i;
		int left = 0;
		int mid = 0;
		temp = arr[i];
		while (right >= left)
		{
			mid = (right + left) / 2;
			if (arr[mid] >= arr[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
		for(j=i-1;j>=left;j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}
void ShellSort(int arr[], int len)
{
	int j = 0;
	int temp = 0;
	for (int km = len / 2; km > 0; km /= 2)
	{
		for (int i = km; i < len; i++)
		{
			temp = arr[i];
			for (j = i - km; j >= 0 && temp < arr[j]; j -= km)
				arr[j + km] = arr[j];
			arr[j + km] = temp;
		}
	}
}
void QuickSort(int arr[], int start,int end)
{
	int i = start;
	int j = end;
	int temp = arr[start];
	if (i < j)
	{
		while (i < j)
		{
			while (temp < arr[j]&& i < j)
				j--;
			if (i < j)
			{
				arr[i] = arr[j];
				//i++;
			}
			while (temp > arr[i] && i < j)
				i++;
			if (i < j)
			{
				arr[j] = arr[i];
			//	j--;
			}
		}
		arr[i] = temp;
		QuickSort(arr, start, i - 1);
		QuickSort(arr, i + 1, end);
	}
}
void QuickSort2(int arr[], int start, int end)
{
	if (start < end)
	{
		int temp = arr[start];
		int pos = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[i] < temp)
			{
				pos++;
				if (pos != i)
				{
					int k = arr[i];
					arr[i] = arr[pos];
					arr[pos] = arr[i];
				}
			}
		}
		arr[start] = arr[pos];
		arr[pos] = temp;
		QuickSort(arr, start, pos - 1);
		QuickSort(arr, pos + 1, end);
	}
}
void Print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

int main()
{
	/*const char* s = "abc##de#g##f###";
	BinaryNode *root = CreatBinary(s);
	Rescurion(root);
	system("pause");*/
	int arr[] = { 10,2,1,4,6,7,3,8,5,9 ,0,11,15,12,14,13};
	int len = sizeof(arr) / sizeof(arr[0]);
	Print(arr, len);
	printf("\n");
	//InsertSort(arr, len);
	//ShellSort(arr, len);
	//BinInsertSort(arr, len);
	QuickSort2(arr, 0, len-1);
	Print(arr, len);

	system("pause");
	return 0;

}