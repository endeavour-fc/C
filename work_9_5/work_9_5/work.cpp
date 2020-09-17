#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int find_num(int arr[], int num,int len)
{
	int end = len - 1;
	int start = 0;
	int middle = end / 2;
	while (end >= start)
	{
		if (arr[middle] > num)
		{
			end = middle - 1;
			middle = (end + start) / 2;
		}
		else if (arr[middle] < num)
		{
			start = middle + 1;
			middle = (end + start) / 2;
		}
		else
			return middle;
	}
	return -1;
}


int order(int arr[], int start, int end)
{
	int temp = arr[start];
	for (int i = start; i <= end; i++)
	{
		if (temp > arr[i])
		{
			temp = arr[i];
		}
	}
	return temp;
}


int min(int arr[], int len)
{
	int start = 0;
	int end = len - 1;
	int middle = end/2;
	while (arr[start] >= arr[end])
	{
		if (end - start == 1)
		{
			middle = end;
			break;
		}

		if (arr[start] == arr[middle] && arr[middle] == arr[end])
			return order(arr, start, end);

		if (arr[middle] >= arr[start])
		{
			start = middle;
			middle = (end + start) / 2;
		}
		else if (arr[middle] <= arr[start])
		{
			end = middle;
			middle = (end + start) / 2;
		}
	}
	return arr[middle];
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int backPackII(int m, vector<int> A, vector<int> V) {
	if (A.empty() || V.empty() || m < 1)
	{
		return 0;
	}
	const int N = A.size();
	const int M = m + 1;
	vector<int> result;
	result.resize(M, 0);
		for (int i = 0; i != N; ++i) {
			for (int j = M - 1; j > 0; --j) {
				if (A[i] > j) {
					result[j] = result[j];
				}
				else 
				{
					int newValue = result[j - A[i]] + V[i];
					result[j] = max(newValue, result[j]);
				}
			}
		}
	return result[m];
}
void Put(vector<vector<bool>>& v, int n1, int n2)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i][n1])
		{
			v[i][n2] = true;
		}
		if (v[i][n2])
			v[i][n1] = true;
	}
}
int main()
{
	int n, m, q;
	while (cin >> n >> m >> q)
	{
		vector<vector<bool>> v(n, vector<bool>(n, false));
		int n1, n2;
		for (int i = 0; i<m; ++i)
		{
			cin >> n1 >> n2;
			v[n2 - 1][n1 - 1] = true;
			v[n1 - 1][n2 - 1] = true;
			Put(v, n1 - 1, n2 - 1);
		}
		for (int i = 0; i<q; ++i)
		{
			cin >> n1 >> n2;
			if (n1 == n2)
			{
				cout << "YES" << endl;
				continue;
			}
			if (v[n1 - 1][n2 - 1] || v[n2 - 1][n1 - 1])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}


	return 0;
}