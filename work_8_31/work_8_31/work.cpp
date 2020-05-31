#include<iostream>
#include<vector>
#include<cmath>
#include<functional>
#include <algorithm>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == NULL || length <= 0)
		return false;
	for (int i = 0; i < length; i++)
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				//return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}
int get(int num)
{
	int i = 0;
	for (i = sqrt(num); num%i != 0; --i)
		;
	return i;
}
bool isPrime(unsigned int n) {
	if (n <= 3) {
		return n > 1;
	}
	else if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	else {
		for (unsigned int i = 5; i * i <= n; i += 6) {
			if (n%i == 0 || n % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
}
void ret(vector<unsigned int>& v, int num)
{
	if (isPrime(num))
	{
		v.push_back(num);
		return;
	}
	int temp = get(num);
	ret(v,temp);
	ret(v,num / temp);
}


//int main()
//{
//	unsigned int num = 0;
//	while (cin >> num)
//	{
//		vector<unsigned int> v;
//		ret(v, num);
//		sort(v.begin(), v.end());
//		cout << 10 << " = ";
//		for (int i = 0; i<v.size(); ++i)
//		{
//			cout << v[i];
//			if (i != v.size() - 1)
//				cout << " * ";
//		}
//		cout << endl;
//	}
//}

//int main()
//{
//	int arr[] = { 2,3,1,0,2,5,3 };
//	int arr2[5] = { 0 };
//	int temp = 0;
//	const int num = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr2;
//	duplicate(arr, num, p);
//	printf("%d\n", *p);
//	/*int arr2[num] = { 0 };
//	for(int i=0;i<num-1;i++)
//		for (int j = 0; j < num - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	for (int i = 0; i < num - 1; i++)
//	{
//		if (arr[i] == arr[i + 1])
//		{
//			printf("%d\n", arr[i]);
//		}
//	}*/
//
//	/*for (int i = 0; i < num; i++)
//	{
//		while (arr[i] != i)
//		{
//			if (arr[i] == arr[arr[i]])
//			{
//				printf("%d\n", arr[i]);
//				break;
//			}
//			else
//			{
//				temp = arr[i];
//				arr[i] = arr[temp];
//				arr[temp] = temp;
//			}
//		}
//	}*/
//
//
//
//	
//	system("pause");
//	return 0;
//}