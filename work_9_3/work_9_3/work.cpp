#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
typedef struct Node
{
	int a;
	Node *next;
}Node;

void creat_node(Node** head_n,int num)
{
	Node* head = *head_n;
	Node* temp = *head_n;
	Node* p = NULL;
	if (*head_n == NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
			return;
		temp->a = num;
		temp->next = NULL;
	}
	else
	{
		p = (Node *)malloc(sizeof(Node));
		if (p == NULL)
			return;
		while (head->next != NULL)
			head = head->next;
		p->a = num;
		p->next = head->next;
		head->next = p;
	}
	*head_n = temp;
}

void print_node(Node* head)
{
	Node* p = NULL;
	for (p=head; p != NULL;p= p->next)
	{
		printf("%d->", p->a);
	}
}
 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<string> ret;
	void get(TreeNode* root, string str)
	{
		if (root == NULL)
			return;
		str += to_string(root->val);
		if (root->left || root->right)
			str += "->";
		else
		{
			ret.push_back(str);
			return;
		}
		get(root->left, str);
		get(root->right, str);
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		string str;
		get(root, str);
		return ret;
	}
};

unordered_map<string, int> mp;
void get(string& password, int pos, string ret)
{
	if (ret.size() == password.size())
	{
		++mp[ret];
		return;
	}
	if ((password[pos] - '0' + ret[ret.size() - 1] - '0') % 2)
	{
		ret += (password[pos] - '0' + ret[ret.size() - 1] - '0') / 2 + 1+'0';
		get(password, pos + 1, ret);
		ret.pop_back();
	}
	ret += (password[pos] - '0' + ret[ret.size() - 1] - '0') / 2+'0';
	get(password, pos + 1, ret);
}
long long getPasswordCount(string password) {
	// write code here

	for (int i = 0; i<10; ++i)
	{
		string temp;
		temp += ('0' + i);
		get(password, 1, temp);
	}
	return mp.size() - mp.count(password);
}
int main()
{
	cout << getPasswordCount("123") << endl;
	//Node* head = NULL;
	//int input = 0;
	//do
	//{
	//	printf("请输入一个非-1的数\n");
	//	scanf("%d", &input);
	//	creat_node(&head, input);
	//} while (input!=-1);
	//
	//print_node(head);

	system("pause");
	return 0;
}