#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct {
	int* data;
	int first;
	int last;
} seq;

seq* init_seq()
{
	seq* s = (seq*)malloc(sizeof(seq));
	s->data = (int*)malloc(sizeof(int) * 100);
	s->first = s->last = 0;
	return s;
}
bool empty_seq(seq* s)
{
	return s->last == s->first ? true : false;
}
void push_seq(seq* s, int x)
{
	s->data[s->last++] = x;
}
void pop_seq(seq* s)
{
	if (empty_seq(s))
		return;
	s->first++;
}
int get_num_top(seq* s)
{
	return s->data[s->last - 1];
}
int get_num_last(seq* s)
{
	return s->data[s->first];
}
typedef struct {
	seq* s1;
	seq* s2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* temp = (MyStack*)malloc(sizeof(MyStack));
	temp->s1=init_seq();
	temp->s2=init_seq();
	return temp;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (empty_seq(obj->s1))
	{
		push_seq(obj->s2,x);
	}
	else
	{
		push_seq(obj->s1,x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int val = 0;
	if (empty_seq(obj->s1))
	{
		while (!empty_seq(obj->s2))
		{
			if (obj->s2->first + 1 == obj->s2->last)
				break;
			push_seq(obj->s1, get_num_last(obj->s2));
			//  val=get_num_last(obj->s2);
			pop_seq(obj->s2);
		}
		val = get_num_last(obj->s2);
		pop_seq(obj->s2);
	}
	else
	{
		while (!empty_seq(obj->s1))
		{
			if (obj->s1->first + 1 == obj->s1->last)
				break;
			push_seq(obj->s2, get_num_last(obj->s1));
			//  val=get_num_last(obj->s2);
			pop_seq(obj->s1);
		}
		val = get_num_last(obj->s1);
		pop_seq(obj->s1);
	}
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	int val = 0;
	if (empty_seq(obj->s1))
	{
		while (!empty_seq(obj->s2))
		{
			push_seq(obj->s1, get_num_last(obj->s2));
			val = get_num_last(obj->s2);
			pop_seq(obj->s2);
		}
	}
	else
	{
		while (!empty_seq(obj->s1))
		{
			push_seq(obj->s2, get_num_last(obj->s1));
			val = get_num_last(obj->s1);
			pop_seq(obj->s1);
		}
	}
	return val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (empty_seq(obj->s1) == 1 && empty_seq(obj->s2) == 1)
		return true;
	return false;
}

void myStackFree(MyStack* obj) {
	free(obj->s1);
	free(obj->s2);
	free(obj);
}
//int main()
//{
//	int val = 0;
//	MyStack* temp = myStackCreate();
//	myStackPush(temp, 1);
//	myStackPush(temp, 2);
//	val=myStackTop(temp);
//	printf("%d ", val);
//	val=myStackPop(temp);
//	printf("%d ", val);
//	val=myStackEmpty(temp);
//	printf("%d ", val);
//
//	system("pause");
//	return 0;
//}

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int a) :val(a), left(NULL), right(NULL) {};
};
bool isfullTree(TreeNode* p)
{
	if (p == NULL)return true;
	
	queue<TreeNode*>help;
	help.push(p);
	TreeNode *end = p;
	TreeNode *next = NULL;
	int numNodes = 0;
	int numLayers = 0;
	while (!help.empty()) {
		p = help.front();
		help.pop();
		numNodes++;
		if (p->left != NULL) {
			help.push(p->left);
			next = p->left;
		}
		if (p->right != NULL) {
			help.push(p->right);
			next = p->right;
		}
		if (p == end) {
			end = next;
			next = NULL;
			numLayers++;
		}
	}
	if (numNodes == pow(2, numLayers) - 1)
		return true;
	else
		return false;
}

bool CompleteBinaryTree(TreeNode* root)
{
	if (root == NULL)
		return true;
	queue<TreeNode*> que;
	bool leaf = false;
	que.push(root);
	while (!que.empty())
	{
		TreeNode* temp = que.front();
		que.pop();
		if (leaf && (temp->left != NULL || temp->right != NULL || (temp->left == NULL && temp->right != NULL)))
		{
			return false;
		}
		if (temp->left)
			que.push(temp->left);
		if (temp->right)
			que.push(temp->right);
		if (temp->left == NULL || temp->right == NULL)
			leaf = true;
	}
	return true;
}

bool cmp(string s1, string s2)
{
	return s1.size()>s2.size();
}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<string> v(n, "");
//		for (int i = 0; i<n; ++i)
//			cin >> v[i];
//		sort(v.begin(), v.end());
//		for (auto& e : v)
//		{
//			cout << e << endl;
//		}
//		sort(v.begin(), v.end(), cmp);
//		for (auto& e : v)
//		{
//			cout << e << endl;
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int V = 0;
//	int n = 0;
//	while (cin >> V >> n)
//	{
//		vector<int> v(n, 0);
//		for (int i = 0; i<n; ++i)
//			cin >> v[i];
//		vector<int> dp(V + 1, 0);
//		for (int i = 0; i<n; ++i)
//		{
//			for (int j = V; j >= v[i]; --j)
//			{
//				dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
//			}
//		}
//		cout << V - dp[V] << endl;
//	}
//
//	return 0;
//}

class Solution_pondSizes {
public:
	vector<int> pondSizes(vector<vector<int>>& land) {
		vector<vector<bool>> bl(land.size(), vector<bool>(land[0].size()));
		queue<pair<int, int>> que;
		vector<int> ret;
		for (int i = 0; i<land.size(); ++i)
		{
			for (int j = 0; j<land[i].size(); ++j)
			{
				if (land[i][j] == 0)
				{
					que.push({ i,j });
				}
			}
		}
		while (!que.empty())
		{
			pair<int, int> temp = que.front();
			que.pop();
			if (bl[temp.first][temp.second])
				continue;
			//bl[temp.first][temp.second] = true;
			queue<pair<int, int>> q;
			q.push(temp);
			int count = 1;
			while (!q.empty())
			{
				pair<int, int> t = q.front();
				q.pop();
				bl[t.first][t.second] = true;
				int x = t.first;
				int y = t.second;
				for (int i = -1; i <= 1; ++i)
				{
					for (int j = -1; j <= 1; ++j)
					{
						if (i == 0 && j == 0)
							continue;
						if (i + x >= 0 && j + y >= 0 && i + x < land.size() && j + y < land[0].size() && bl[x + i][j + y] == false && land[x + i][y + j] == 0)
						{
							bl[i + x][j + y] = true;
							++count;
							q.push({ i + x,j + y });
						}
					}
				}

			}
			ret.push_back(count);
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
};
int findTargetSumWays(vector<int>& nums, int S) {
	int sum = 0;
	for (auto e : nums)
	{
		sum += e;
	}
	int len = (S + sum) / 2;
	if ((S + sum)%2 == 1 || sum<S)
		return 0;
	vector<int> v(len + 1, 0);
	v[0] = 1;
	for (int i = 0; i<nums.size(); ++i)
	{
		for (int j = len; j >= 0; --j)
		{
			if (j - nums[i] >= 0)
			{
				v[j] += v[j - nums[i]];
			}
		}
	}
	return v[len];
}

int main()
{
	vector<int> v(1, 1);
	cout << findTargetSumWays(v, 1) << endl;

	system("pause");
	return 0;
}