#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	ListNode* next;
};
ListNode* Init_Node()
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = 0;
	temp->next = NULL;
	return temp;
}
ListNode* CreatNode(int a)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = a;
	temp->next = NULL;
	return temp;
}
void Insert_Head_List(ListNode* head, ListNode* inhl)
{
	if (head == NULL || inhl == NULL)
		return;
	inhl->next = head->next;
	head->next = inhl;
}
void Print_Node(ListNode* head)
{
	if (head == NULL)
		return;
	for (ListNode* temp = head->next; temp != NULL; temp = temp->next)
		printf("%d->", temp->val);
	printf("\n");
}
void test1(int* arr1, int len1,int* arr2,int len2)
{
	ListNode* head1 = Init_Node();
	ListNode* head2 = Init_Node();
	for (int i = 0; i < len1; i++)
	{
		ListNode* temp = CreatNode(arr1[i]);
		Insert_Head_List(head1, temp);
	}
	Print_Node(head1);
	for (int i = 0; i < len2; i++)
	{
		ListNode* temp = CreatNode(arr2[i]);
		Insert_Head_List(head2, temp);
	}
	Print_Node(head2);
	head1 = head1->next;
	head2 = head2->next;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->val == head2->val)
		{
			printf("%d->", head1->val);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if(head1->val<head2->val)
		{
			head2 = head2->next;
		}
		else
		{
			head1 = head1->next;
		}
	}
}
void test3(ListNode* head, int k);
void test2(int* arr,int len,int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	test3(head, k);
	/*
	Print_Node(head);
	if (k > len)
		return;
	ListNode* pCur = head;
	ListNode* pPre = head->next;
	k = len - k;
	while (k >0)
	{
		pCur = pCur->next;
		pPre = pPre->next;
		k--;
	}
	pCur->next = pPre->next;
	free(pPre);
	pPre = NULL;
	Print_Node(head);*/
}
void test5(ListNode** head);

void test4(int* arr, int len)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	if (head->next == NULL)
		return;
	Print_Node(head);
	test5(&head);
	//ListNode* pCur = head;
	//ListNode* pPre = head->next->next;
	//if (pPre == NULL)
	//{
	//	Print_Node(head);
	//	return;
	//}
	//while (pPre != NULL)
	//{
	//	if (pPre->next == NULL)
	//		break;
	//	pPre = pPre->next->next;
	//	pCur = pCur->next;

	//}
	//pCur->next = pCur->next->next;
	Print_Node(head);

}
void test5(ListNode** head)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		Print_Node(*head);
		return;
	}
	ListNode* pPre = (*head)->next;
	ListNode* pCur = (*head)->next;
	ListNode* temp = NULL;
	while (pPre != NULL)
	{
		pPre = pPre->next;
		pCur->next = temp;
		if (pPre == NULL)
			break;
		temp = pCur;
		pCur = pPre;
	}
	(*head)->next = pCur;
	Print_Node(*head);
}
void test3(ListNode* head, int k)
{
	Print_Node(head);
	ListNode* pCur = head;
	ListNode* pPre = head;
	while (k >0)
	{
		pPre = pPre->next;
		if (pPre == NULL)
		{
			Print_Node(head);
			return;
		}
		k--;
	}
	while (pPre->next != NULL)
	{
		pCur = pCur->next;
		pPre = pPre->next;
	}
	ListNode* temp = pCur->next;
	pCur->next = pCur->next->next;
	free(temp);
	temp = NULL;
	Print_Node(head);
}
void test6(int* arr, int len, int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	Print_Node(head);
	if (head->next == NULL)
		return;
	ListNode* pCur = head->next;
	while (pCur->next != NULL)
	{
		ListNode* pPre = pCur;
		int i = 0;
		while (pPre->next != NULL)
		{
			if (i++ == 2)
			{
				ListNode* temp = pPre->next;
				pPre->next = pPre->next->next;
				free(temp);
			}
			pPre = pPre->next;
		}
	}
	Print_Node(head);
}
int main()
{
	int arr1[] = {1,2};
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	test4(arr1, len1);
	//int arr2[] = {9};
	//int len2 = sizeof(arr2) / sizeof(arr2[0]);
	//test1(arr1, len1,arr2,len2);
	//test2(arr1, len1,5);
	
	system("pause");
	return 0;
}