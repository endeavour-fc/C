#include<iostream>
using namespace std;

class A
{
public:
	virtual void  funA()
	{
		cout << "A::A" << endl;
	}
	virtual void funB()
	{
		cout << "A::B" << endl;
	}
	void funC()
	{
		cout << "A::C" << endl;
	}
};

class B:public A
{
public:
	virtual void funA()
	{
		cout << "B::A" << endl;
	}
	virtual void  funB()
	{
		cout << "B::B" << endl;
	}
};
void Quick_Sort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int temp = arr[left];
	if (i < j)
	{
		while (i < j)
		{
			while (i<j&&temp <= arr[j])
				--j;
			if (i < j)
				arr[i++] = arr[j];
			while (i<j&&temp >= arr[i])
				++i;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = temp;
		Quick_Sort(arr, left, i - 1);
		Quick_Sort(arr, i + 1, right);
	}
}
void Merge_Sort(int arr[], int left, int right, int mid, int* temp)
{
	int i_begin = left;
	int i_end = mid;
	int j_begin = mid + 1;
	int j_end = right;
	int len = 0;
	while (i_begin <= i_end && j_begin <= j_end)
	{
		if (arr[i_begin] > arr[j_begin])
			temp[len++] = arr[j_begin++];
		else
			temp[len++] = arr[i_begin++];
	}
	while (i_begin <= i_end)
	{
		temp[len++] = arr[i_begin++];
	}
	while (j_begin <= j_end)
	{
		temp[len++] = arr[j_begin++];
	}
	for (int i = 0; i < len; ++i)
		arr[left + i] = temp[i];
}
void Merge(int arr[], int left, int right, int* temp)
{
	if (right <= left)
		return;
	int mid = (left + right) / 2;
	Merge(arr, left, mid, temp);
	Merge(arr, mid+1, right, temp);
	Merge_Sort(arr, left, right, mid, temp);
}
void MakeBigHeap(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		int pre = i;
		int father = (i - 1) / 2;
		while (arr[pre] > arr[father])
		{
			swap(arr[pre], arr[father]);
			pre = father;
			father = (pre - 1) / 2;
		}
	}
}
void Heap(int arr[], int index,int len)
{
	int left = index*2+1;
	int right = index*2+2;
	int Max = 0;
	while (left < len)
	{
		if (right<len&&arr[right]>arr[left])
			Max = right;
		else
			Max = left;
		if (arr[index] >= arr[Max])
			return;
		swap(arr[index], arr[Max]);
		index = Max;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}
void Heap_Sort(int arr[], int len)
{
	MakeBigHeap(arr, len);
	while (len>1)
	{
		swap(arr[0], arr[len-- -1]);
		Heap(arr,0, len);
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
int* Next(char* arr, int len)
{
	int* next = new int[10];
	*next = { 0 };
	int j = 0;
	for (int i = 2; i < len; ++i)
	{
		while (j&&arr[i - 1] != arr[j])
			j = next[j];
		if (arr[i - 1] == arr[j])
			++j;
		next[i] = j;
	}
	return next;
}
int KMP(char* long_string, char* short_string)
{
	int len1 = strlen(long_string);
	int len2 = strlen(short_string);
	int* next = Next(short_string, len2);
	int j = 0;
	for (int i = 0; i < len1; ++i)
	{
		while (j&&long_string[i] != short_string[j])
			j = next[j];
		if (long_string[i] == short_string[j])
			++j;
		if (j == len2)
			return i - j + 1;

	}
	return -1;
	
}

int main()
{
	int arr[] = { 2,1,4,0,6,7,9,3,8,5 };
	int* temp = new int[10];
	//Quick_Sort(arr, 0, 9);
	//Merge(arr, 0, 9, temp);
	//MakeBigHeap(arr, 10);
	Heap_Sort(arr, 10);
	PrintArr(arr, 10);

	system("pause");
	return 0;
}