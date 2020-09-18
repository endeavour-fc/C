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
	ListNode(int x=0) : val(x), next(NULL) {}
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
//合并两个排序的链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode;
	ListNode* temp = head;
	while (l1&&l2)
	{
		if (l1->val<l2->val)
		{
			head->next = l1;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			l2 = l2->next;
		}
		head = head->next;
	}
	while (l1)
	{
		head->next = l1;
		l1 = l1->next;
		head = head->next;
	}
	while (l2)
	{
		head->next = l2;
		l2 = l2->next;
		head = head->next;
	}
	head = temp->next;
	delete temp;
	return head;
}
//斐波那契数列
int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	int n1 = 1;
	int n2 = 1;
	for (int i = 2; i<n; ++i)
	{
		swap(n1, n2);
		n2 += n1;
		n2 %= 1000000007;
	}
	return n2;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//二叉树的镜像
TreeNode* mirrorTree(TreeNode* root) {
	if (root == NULL)
		return NULL;
	swap(root->right, root->left);
	mirrorTree(root->right);
	mirrorTree(root->left);
	return root;
}
//顺时针打印矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0)
	{
		vector<int> v;
		return v;
	}
	vector<int> v(matrix.size()*matrix[0].size(), 0);
	int index = 0;
	int right = matrix[0].size() - 1;
	int left = 0;
	int front = 0;
	int back = matrix.size() - 1;

	while (left <= right && front <= back)
	{
		for (int col = left; col <= right; ++col)
			v[index++] = matrix[front][col];
		for (int row = front + 1; row <= back; ++row)
			v[index++] = matrix[row][right];

		if (left<right&&front<back)
		{
			for (int col = right - 1; col >= left; --col)
				v[index++] = matrix[back][col];
			for (int row = back - 1; row>front; --row)
				v[index++] = matrix[row][left];
		}
		++left;
		--right;
		++front;
		--back;
	}
	return v;

}
//快排

void QuickSort(vector<int>& v,int left,int right)
{
	if (left < right)
	{
		int temp = v[left];
		int i = left;
		int j = right;
		while (i < j)
		{
			while (i < j&&temp < v[j])
				--j;
			if (i < j)
				v[i++] = v[j];
			while (i<j&&temp>v[i])
				++i;
			if (i < j)
				v[j--] = v[i];
		}
		v[i] = temp;
		QuickSort(v, left, i - 1);
		QuickSort(v, i + 1, right);
	}
}
//堆排
void MakeHeap(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		int index = i;
		int father = (index - 1) / 2;
		while (v[index] > v[father])
		{
			swap(v[index], v[father]);
			index = father;
			father = (index - 1) / 2;
		}
	}
}
void Heapily(vector<int>& v, int len)
{
	int index = 0;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int Max = 0;
	while (right < len)
	{
		if (right < len&&v[right]>v[left])
			Max = right;
		else
			Max = left;
		if (v[index] >= v[Max])
			return;
		swap(v[index], v[Max]);
		index = Max;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}
void HeapSort(vector<int>& v)
{
	MakeHeap(v);
	int len = v.size()-1;
	while (len > 0)
	{
		swap(v[0], v[len]);
		Heapily(v, len);
		--len;
	}
}
//插入排序
void InsertSort(vector<int>& v)
{
	for (int i = 1; i < v.size(); ++i)
	{
		int temp = v[i];
		int j = 0;
		for (j = i - 1; j >= 0 && temp < v[j]; --j)
			v[j + 1] = v[j];
		v[j + 1] = temp;
	}
}
class Solution_pathSum {
public:
	vector<vector<int>> ret;
	void get(TreeNode* root, vector<int>& v, int sum)
	{
		if (root == NULL)
			return;
		v.push_back(root->val);
		if (root->val == sum && root->left == NULL && root->right == NULL)
		{
			ret.push_back(v);
			v.pop_back();
			return;
		}
		get(root->left, v, sum - root->val);
		get(root->right, v, sum - root->val);
		v.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> v;
		get(root, v, sum);
		return ret;
	}
};
int main()
{
	vector<int> v = { 2,1,4,3,6,7,5,9,8 };
	InsertSort(v);
	//HeapSort(v);
	//QuickSort(v, 0, v.size() - 1);
	for (const auto& e : v)
		cout << e << " ";
	cout << endl;

	return 0;
}