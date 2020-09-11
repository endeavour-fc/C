#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

//��ָoffer

//��ά�����в���

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
{
	if (matrix.size() == 0)
		return false;

	int rows = 0;
	int cols = matrix[0].size() - 1;
	while (rows<matrix.size() && cols >= 0)
	{
		if (matrix[rows][cols]<target)
		{
			++rows;
		}
		else if (matrix[rows][cols]>target)
		{
			--cols;
		}
		else
		{
			return true;
		}
	}

	return false;
}


//�滻�ո�
string replaceSpace(string s) {
	int count = 0;
	for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] == ' ')
			++count;
	}
	int len = s.size();
	s.resize(s.size() + count * 2);
	int left = len - 1;
	int right = s.size() - 1;
	while (left >= 0 && left<right)
	{
		if (s[left] == ' ')
		{
			s[right--] = '0';
			s[right--] = '2';
			s[right--] = '%';
		}
		else
		{
			s[right--] = s[left];
		}
		--left;
	}
	return s;
}

//��ת�������С����
int MinInOrder(vector<int>& numbers, int index1, int index2)
{
	int ret = numbers[index1];
	for (int i = index1; i <= index2; ++i)
		ret = min(ret, numbers[i]);
	return ret;
}
int minArray(vector<int>& numbers) {
	if (numbers.size() == 0)
		return -1;

	int index1 = 0;
	int index2 = numbers.size() - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index2 - index1) / 2 + index1;
		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

//��������1�ĸ���
int hammingWeight(uint32_t n) {
	int ret = 0;
	while (n)
	{
		n &= n - 1;
		++ret;
	}
	return ret;
}
//��ֵ�������η�
double PowerWithUnsignedExponent(double base, long exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 1)
		result *= base;

	return result;
}
double myPow(double x, int n) {
	if (x == 1)
		return 1;
	if (x == 0 && n<0)
		return 0;
	long flag = n;
	if (flag<0)
		flag = -flag;

	double result = PowerWithUnsignedExponent(x, flag);
	if (n<0)
		result = 1.0 / result;

	return result;
}