#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int len = 0;
struct BinaryNode
{
	char ch;
	BinaryNode* lchild;
	BinaryNode* rchild;
};
struct ListNode
{
	char ch;
	bool flag;
	ListNode* next;
};	
struct MyList
{
	ListNode* first;
	ListNode* last;
};


MyList* Init_List()
{
	MyList* temp = (MyList*)malloc(sizeof(MyList));
	temp->first = NULL;
	temp->last = NULL;
	return temp;
}
void Insert_Node(MyList* ML, char s)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (ML->first == NULL)
	{
		ML->first = temp;
		ML->last = temp;
		temp->ch = s;
		temp->flag = 0;
		temp->next = NULL;
		return;
	}
	temp->next = ML->first;
	ML->first = temp;
	temp->ch = s;
	temp->flag = 0;
}
bool empty(MyList* ML)
{
	return ML->first == NULL ? true : false;
}
bool Pop_Node(MyList* ML)
{
	if (empty(ML))
		return false;
	ListNode* temp = NULL;
	temp = ML->first;
	ML->first = ML->first->next;
	free(temp);
	return true;
}
bool Get_Num(MyList* ML)
{
	return ML->first->flag;
}
char Get_char(MyList* ML)
{
	return ML->first->ch;
}
void Recursion(BinaryNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);

}
BinaryNode* createTree(char* arr)
{
	//char c = 0;
	//fflush(stdin);
	//scanf("%c",&c);
	static int i = 0;
	//char arr[] = "abc##de##f##g#h##";
	if (*(arr+i) == '#'|| *(arr + i) == '\0')
	{
		if (*(arr + i) == '\0')
			return NULL;
		i++;
		return NULL;
	}
	BinaryNode* root = (BinaryNode*)malloc(sizeof(BinaryNode));
	root->ch = *(arr+i);
	i++;
	root->lchild = createTree(arr);
	root->rchild = createTree(arr);

	return root;
}
void Leaf_num(BinaryNode* root,int* num)
{
	if (root == NULL)
		return;
	if (root->lchild == NULL && root->rchild == NULL)
		(*num)++;
	Leaf_num(root->lchild,num);
	Leaf_num(root->rchild,num);
}
BinaryNode* Find_Node(BinaryNode* root, char c)
{
	BinaryNode* p = NULL;
	if (root == NULL)
		return NULL;
	if (root->ch == c)
		return root;
	p=Find_Node(root->lchild, c);
	if (p != NULL)
		return p;
	return Find_Node(root->rchild, c);
}

BinaryNode* Copy_Binary(BinaryNode* root)
{
	if (root == NULL)
		return NULL;
	BinaryNode* lnode = Copy_Binary(root->lchild);
	BinaryNode* rnode = Copy_Binary(root->rchild);

	BinaryNode* temp = (BinaryNode*)malloc(sizeof(BinaryNode));
	temp->ch = root->ch;
	temp->lchild = lnode;
	temp->rchild = rnode;
	return temp;
}
void Free_BinaryNode(BinaryNode* root)
{
	if (root == NULL)
		return;
	Free_BinaryNode(root->lchild);
	Free_BinaryNode(root->rchild);
	free(root);
}
void Creat_Node()
{
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	Recursion(&node1);
	BinaryNode* root = Copy_Binary(&node1);
	printf("\n");
	Recursion(root);
	Free_BinaryNode(root);
	//int num = 0;
	//Leaf_num(&node1,&num);
	//printf("%d ", num);
}
BinaryNode* Find_Root(BinaryNode* root, char c)
{
	BinaryNode *pr;
	BinaryNode *p = Find_Node(root, c);

	if (root == NULL || p == NULL || p == root)
		return NULL;
	if (root->lchild == p || root->rchild == p)
		return root;
	pr = Find_Root(root->lchild, c);
	if (pr != NULL)
		return pr;
	return Find_Node(root->rchild, c);
}
int main()
{
	char arr[] = "abc##de##f##g#h##";
	BinaryNode* p = NULL;
	BinaryNode* root = createTree(arr);
	Recursion(root);
	printf("\n");
	p = Find_Root(root, 'g');
	if (p == NULL)
		printf("not find\n");
	else
		printf("%c", p->ch);
	Free_BinaryNode(root);
	
	system("pause");
	return 0;
}