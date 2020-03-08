#include<iostream>
using namespace std;
void SelectArr(int* arr, int len)
{
	int j = 0;
	for (int i = 1; i < len; i++)
	{
		int temp = arr[i];
		if (arr[i] < arr[i - 1])
		{
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}
}
void ShellSort(int* arr, int len)
{
	int j = 0;
	int temp = 0;
	for (int statement = len / 2; statement > 0; statement /= 2)
	{
		for (int i = statement; i < len; i++)
		{
			int temp = arr[i];
			if (arr[i] < arr[i - statement])
			{
				for (j = i - statement; j >= 0 && arr[j] > temp; j -= statement)
					arr[j + statement] = arr[j];
				arr[j + statement] = temp;
			}
		}
	}
}
void QuickSort(int* arr, int left, int right)
{
	int temp = arr[left];
	int i = left;
	int j = right;
	if (i < j)
	{
		while (i < j)
		{
			while (i < j&&arr[j]>=temp)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}
			while (i < j&&arr[i]<=temp)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}
		arr[i] = temp;
		QuickSort(arr, left, i-1);
		QuickSort(arr, i+1, right);
	}
}
void Merge(int* arr, int begin, int mid, int end, int* temp)
{
	int i_begin = begin;
	int i_end = mid;
	int j_begin = mid + 1;
	int j_end = end;
	int k = 0;
	while (i_begin <= i_end && j_begin <= j_end)
	{
		if (arr[i_begin] < arr[j_begin])
		{
			temp[k++] = arr[i_begin++];
		}
		else
		{
			temp[k++] = arr[j_begin++];
		}
	}
	while (i_begin <= i_end)
	{
		temp[k++] = arr[i_begin++];
	}
	while (j_begin <= j_end)
	{
		temp[k++] = arr[j_begin++];
	}
	for (int i = 0; i < k; i++)
		arr[i + begin] = temp[i];
}
void MergeSort(int* arr, int left,int right,int* temp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(arr, left, mid,temp);
	MergeSort(arr, mid + 1, right, temp);
	Merge(arr, left,mid, right, temp);
}
void MakeBigHeap(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int Pre = i;
		int Father = (Pre - 1) / 2;
		while (arr[Pre] > arr[Father])
		{
			std::swap(arr[Pre], arr[Father]);
			Pre = Father;
			Father = (Pre - 1) / 2;
		}
	}
}
void Heapily(int* arr,int index, int len)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int Max = 0;
	while (left < len)
	{
		if (right<len&&arr[right]>arr[left])
			Max = right;
		else
			Max = left;
		if (arr[index] > arr[Max])
			return;
		std::swap(arr[index], arr[Max]);
		index = Max;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}
void HeapSort(int* arr, int len)
{
	MakeBigHeap(arr, len);
	while (len > 1)
	{
		swap(arr[0], arr[len-- - 1]);
		Heapily(arr, 0, len);
	}

}
void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 3,5,4,2,7,9,1,8,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* temp = (int*)malloc(sizeof(int)*len);
	PrintArr(arr, len);
	//SelectArr(arr, len);
	//ShellSort(arr, len);
	//QuickSort(arr, 0, len - 1);
	//MergeSort(arr, 0, len - 1, temp);
	//MakeBigHeap(arr, len);
	HeapSort(arr, len);
	PrintArr(arr, len);
	
	system("pause");
	return 0;
}