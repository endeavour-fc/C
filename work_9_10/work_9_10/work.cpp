#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
bool incre(char* number)
{
	bool overf = false;
	int ntake = 0;
	int len = strlen(number);
	for (int i = len - 1; i >=0; i--)
	{
		int sum = number[i] - '0' + ntake;
		if (i == (len - 1))
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
				overf = true;
			else
			{
				sum -= 10;
				ntake = 1;
				number[i] = '0' + sum;
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}
	return overf;
}

void printnum(char* number)
{
	bool begin = true;
	int len = strlen(number);

	for (int i = 0; i < len ; i++)
	{
		if (begin &&number[i] != '0')
			begin = false;
		if (!begin)
		{
			printf("%c", number[i]);
		}
	}
	printf("\n");
}

void PrintToMax(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!incre(number))
	{
		printnum(number);
	}
}

void printm(char* number, int length, int index)
{
	if (index == length - 1)
	{
		printnum(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		printm(number, length, index + 1);
	}
}


void printfn(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		printm(number, n, 0);
	}
}
int max(int a, int b)
{
	return a > b ? a : b;
}

template <typename T>
class AVLNode
{
public:
	AVLNode(T val)
	{
		this->val = val;
		this->lchild = nullptr;
		this->rchild = nullptr;
		this->height = 1;
	}
	T val;
	size_t height;
	AVLNode* lchild;
	AVLNode* rchild;
};

template <typename T>
class AVLTree
{
public:
	AVLNode<T>* root;
	size_t size;

public:
	AVLTree()
	{
		root = nullptr;
		size = 0;
	}
	int GetSize()
	{
		return size;
	}
	bool isEmpty(AVLNode<T>*& root)
	{
		return root == nullptr;
	}
	AVLNode<T>* add(AVLNode<T>*& node, T val)
	{
		if (node == nullptr) {
			size++;
			return new AVLNode<T>(val);
		}
		if (val < node->val)
			node->lchild = add(node->lchild, val);
		else if (val > node->val)
			node->rchild = add(node->rchild, val);
		//更新height
		node->height = 1 + max(GetHeight(node->lchild), GetHeight(node->rchild));
		//计算平衡因子
		int balanceFactor = GetBalanceFactor(node);
		if (balanceFactor > 1 && GetBalanceFactor(node->lchild)>0) {
			//右旋LL
			return rightRotate(node);
		}
		if (balanceFactor < -1 && GetBalanceFactor(node->rchild)<0) {
			//左旋RR
			return leftRotate(node);
		}
		//LR
		if (balanceFactor > 1 && GetBalanceFactor(node->lchild) < 0) {
			node->lchild = leftRotate(node->lchild);
			return rightRotate(node);
		}
		//RL
		if (balanceFactor < -1 && GetBalanceFactor(node->rchild) > 0) {
			node->rchild = rightRotate(node->rchild);
			return leftRotate(node);
		}
		return node;
	}
private:
	AVLNode<T> * leftRotate(AVLNode<T>*& node)
	{
		AVLNode<T>* t1 = node->rchild;
		AVLNode<T>* t2 = t1->lchild;
		t1->lchild = node;
		node->rchild = t2;
		t1->height = max(GetHeight(t1->lchild), GetHeight(t1->rchild)) + 1;
		node->height = max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
		return t1;
	}
	AVLNode<T>* rightRotate(AVLNode<T>*& node)
	{
		AVLNode<T>* x = node->lchild;
		AVLNode<T>* t3 = x->rchild;
		x->rchild = node;
		node->lchild = t3;
		//更新height
		x->height = max(GetHeight(x->lchild), GetHeight(x->rchild)) + 1;
		node->height = max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
		return x;
	}

	bool isBalance(AVLNode<T>*& node)
	{
		if (node == nullptr)
			return true;
		if (GetBalanceFactor(node) > 1 || GetBalanceFactor(node) < -1)
			return false;
		return isBalance(node->lchild) && isBalance(node->rchild);
	}
	int GetBalanceFactor(AVLNode<T>*& node)
	{
		if (node == nullptr)
			return 0;
		return GetHeight(node->lchild) - GetHeight(node->rchild);
		//return node->lchild->height - node->rchild->height;
	}
	int GetHeight(AVLNode<T>*& node)
	{
		if (node == nullptr)
			return 0;
		return node->height;
	}

};
int main()
{
	AVLTree<int> A;
	for (int i = 0; i < 5;i++)
		A.root=A.add(A.root, i);
	//PrintToMax(3);
	//printfn(3);
	
	system("pause");
	return 0;
}