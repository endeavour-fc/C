#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main01()
{
	int m = 0;
	srand((unsigned)time(NULL));
	int key = rand() % 100;
	while (1)
	{
		printf("请输入你所猜的数\n");
		scanf("%d", &m);
		if (m > key)
			printf("猜大了\n");
		else if(m<key)
			printf("猜小了\n");
		else
		{
			printf("猜对了\n");
			break;
		}

	}
	
	system("pause");
	return 0;
}


int main02()
{
	int key = 0;
	int a[20] = { 0 };
	int right = 19;
	int left = 0;
	int mid = 0;
	printf("请输入一个要查找的数\n");
	scanf("%d", &key);
	for (int i = 0; i<20; i++)
		a[i] = i;
	while (right >= left)
	{
		mid = (right + left) / 2;
		if (a[mid] > key)
			right = mid - 1;
		else if (a[mid] < key)
			left = mid + 1;
		else if(a[mid]==key)
		{
			printf("找到了%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("没找到\n");

	system("pause");
	return 0;
}


int main03()
{
	char a[] = "asdfg";
	char b[20] = { 0 };
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", b);
		if (strcmp(b, a) == 0)
		{
			printf("输入正确\n");
			break;
		}
		printf("输入错误");
		j++;
	}
	if (j == 3)
		printf("关闭程序\n");

	system("pause");
	return 0;
}


int main04()
{
	char ms = 0;
	for (int i = 0; i < 50; i++)
	{
		ms = getchar();
		if (ms >= 65 && ms <= 90)
		{
			ms = ms + 32;
			printf("%c", ms);
		}
		else if (ms >= 97 && ms <= 122)
		{
			ms = ms - 32;
			printf("%c", ms);
		}
	}

	system("pause");
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
int cuttingRope(int n) {
	if (n<3)
		return 1;
	if (n == 3)
		return 2;
	vector<int> v(n + 1, 0);
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	for (int i = 4; i<=n; ++i)
	{
		for (int j = i / 2; j > 0; --j)
		{
			v[i] = max(v[i - j] * v[j], v[i]);
		}
	}
	return v[n];
}
int cuttingRope2(int n) {
	if (n<3)
		return 1;
	if (n == 3)
		return 2;
	long ret = 1;
	while (n>4)
	{
		ret *= 3;
		ret %= 1000000007;
		n -= 3;
	}
	return ret * n % 1000000007;
}
class Solution_isBalanced {
public:
	int get(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int num1 = get(root->left);
		int num2 = get(root->right);
		return num1>num2 ? num1 + 1 : num2 + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (abs(get(root->left) - get(root->right))>1)
		{
			return false;
		}
		return isBalanced(root->left) && isBalanced(root->right);
	}
};
int main()
{
	cout << cuttingRope(120) << endl;

	system("pause");
	return 0;
}