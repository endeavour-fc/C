#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

//剑指offer

//二维数组中查找

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


//替换空格
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

//旋转数组的最小数字
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

//二进制中1的个数
int hammingWeight(uint32_t n) {
	int ret = 0;
	while (n)
	{
		n &= n - 1;
		++ret;
	}
	return ret;
}
//数值的整数次方
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

//打印1到最大的n位数
void PrintNumber(string& num)
{
	for (int i = 0; i < num.size(); ++i)
	{
		//if (num[i] == '0')
		//	continue;
		cout << num[i];
	}
	cout << endl;
}
void PrintToMaxDigitsRecursively(string& num, int len)
{
	if (len == num.size())
	{
		PrintNumber(num);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		num += ('0' + i);
		PrintToMaxDigitsRecursively(num, len);
		num.pop_back();
	}
}

//int main()
//{
//	string str;
//	PrintToMaxDigitsRecursively(str, 2);
//
//	system("pause");
//
//	return 0;
//}
//调整数组顺序使奇数位于偶数前面 
vector<int> exchange(vector<int>& nums) {
	int i = 0;
	int j = nums.size() - 1;
	while (i<j)
	{
		while (i<j&&nums[i] % 2)
			++i;
		while (i<j&&nums[j] % 2 == 0)
			--j;
		swap(nums[i], nums[j]);
	}
	return nums;
}

//链表中倒数第 k 个节点
struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* getKthFromEnd(ListNode* head, int k) {
	ListNode* pPre = head;
	while (pPre&&k)
	{
		pPre = pPre->next;
		k--;
	}
	while (pPre)
	{
		head = head->next;
		pPre = pPre->next;
	}
	return head;
}

//反转链表
struct ListNode* reverseList(struct ListNode* head) {

	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* pPre = NULL;
	struct ListNode* pCur = head;
	struct ListNode* temp = head->next;
	while (pCur != NULL)
	{
		pCur->next = pPre;

		pPre = pCur;
		pCur = temp;
		if (temp == NULL)
			return pPre;
		temp = temp->next;
	}
	return pPre;
}