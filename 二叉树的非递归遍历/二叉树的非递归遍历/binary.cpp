#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct BinaryNode
{
	char ch;
	BinaryNode* lchild;
	BinaryNode* rchild;
};
struct ListNode
{
	BinaryNode* Node;
	ListNode* next;
};
ListNode* Init_List()
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->next = NULL;
	return temp;
}
void Push_Stack(ListNode* head,BinaryNode* Node)
{
	ListNode* pPre = head->next;
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->Node = Node;
	head->next = temp;
	temp->next = pPre;
}
bool empty_stack(ListNode* head)
{
	return head->next == NULL ? true : false;
}
BinaryNode* Pop_stack(ListNode* head)
{
	if (empty_stack(head))
		return NULL;
	BinaryNode* pPre = head->next->Node;
	head->next = head->next->next;
	return pPre;
}
BinaryNode* Get_Top(ListNode* head)
{
	return head->next->Node;
}
void Recursion(BinaryNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);

}
void Free_Stack(ListNode* head)
{
	ListNode* temp = NULL;
	while (head->next != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	free(head);
}
void Recur_Node(BinaryNode* root)
{
	if (root == NULL)
		return;
	BinaryNode* p = NULL;
	ListNode* temp = Init_List();
	Push_Stack(temp,root);
	while (temp->next != NULL)
	{
		p = Pop_stack(temp);
		printf("%c", p->ch);
		if (p->rchild != NULL)
		{
			Push_Stack(temp, p->rchild);
		}
		if (p->lchild != NULL)
		{
			Push_Stack(temp, p->lchild);
		}
	}
	free(temp);
}

void InOrderNode(BinaryNode* root)
{
	if (root == NULL)
		return;
	BinaryNode* p = NULL;
	ListNode* temp = Init_List();
	//Push_Stack(temp, root);
	while (root != NULL || temp->next != NULL)
	{
		while (root != NULL)
		{
			Push_Stack(temp,root);
			root = root->lchild;
		}
		if (!empty_stack(temp))
		{
			root = Pop_stack(temp);
			printf("%c", root->ch);
			root = root->rchild;
		}

	}
}
void PostOrderNode(BinaryNode* root)
{
	if (root == NULL)
		return;
	BinaryNode* p = NULL;
	BinaryNode* s = NULL;
	ListNode* temp = Init_List();
	//Push_Stack(temp, root);
	do
	{
		while (root != NULL)
		{
			Push_Stack(temp, root);
			root = root->lchild;
		}
		s = Get_Top(temp);
		if (s->rchild == NULL || p == s->rchild)
		{
			Pop_stack(temp);
			printf("%c", s->ch);
			p = s;
		}
		else
		{
			root = s->rchild;
		}
	} while (temp->next != NULL);
}
BinaryNode* createTree(char* arr)
{
	//char c = 0;
	//fflush(stdin);
	//scanf("%c",&c);
	static int i = 0;
	//char arr[] = "abc##de##f##g#h##";
	if (*(arr + i) == '#' || *(arr + i) == '\0')
	{
		if (*(arr + i) == '\0')
			return NULL;
		i++;
		return NULL;
	}
	BinaryNode* root = (BinaryNode*)malloc(sizeof(BinaryNode));
	root->ch = *(arr + i);
	i++;
	root->lchild = createTree(arr);
	root->rchild = createTree(arr);

	return root;
}
void Free_Binary(BinaryNode* root)
{
	if (root == NULL)
		return;
	Free_Binary(root->lchild);
	Free_Binary(root->rchild);
	free(root);
}
int main()
{
	char arr[] = "abc##de##f##g#h##";
	BinaryNode* p = NULL;
	BinaryNode* root = createTree(arr);
	Recursion(root);
	printf("\n");
	Recur_Node(root);
	InOrderNode(root);
	PostOrderNode(root);
	Free_Binary(root);
	
	system("pause");
	return 0;
}