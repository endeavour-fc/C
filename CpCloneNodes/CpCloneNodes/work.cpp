#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ComplexListNode
{
	int val;
	ComplexListNode* next;
	ComplexListNode* pSibling;
};

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode* temp = (ComplexListNode*)malloc(sizeof(ComplexListNode));
		temp->next = pNode->next;
		temp->val = temp->val;
		temp->pSibling = NULL;
		pNode->next = temp;
		pNode = temp->next;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode* temp = pNode->next;
		if (pNode->pSibling != NULL)
		{
			temp->pSibling = pNode->pSibling->next;
		}
		pNode = temp->next;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pHead2 = NULL;
	ComplexListNode* temp = NULL;
	if (pNode != NULL)
	{
		pHead2 = temp = pNode->next;
		pNode->next = pHead2->next;
		pNode = pNode->next;
	}
	while (pNode != NULL)
	{
		temp->next = pNode->next;
		temp = temp->next;
		pNode->next = temp->next;
		pNode = pNode->next;
	}
}

ComplexListNode* CreatNode(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ComplexListNode* Head = (ComplexListNode*)malloc(sizeof(ComplexListNode));
	ComplexListNode* pNode = pHead;
	Head->next = NULL;
	Head->val = pHead->val;
	Head->pSibling = NULL;
	ComplexListNode* p = Head;
	pNode = pNode->next;

	while (pNode != NULL)
	{
		ComplexListNode* temp = (ComplexListNode*)malloc(sizeof(ComplexListNode));
		temp->next = NULL;
		temp->val = pNode->val;
		p->next = temp;
		p = temp;
		pNode = pNode->next;
	}
	return Head;
}

//void LinkNode(ComplexListNode* pHead, ComplexListNode* Head)
//{
//
//}

int main()
{
	
	
	system("pause");
	return 0;
}