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

int main()
{
	int arr1[] = { 1,4,5,6 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = {9};
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	test1(arr1, len1,arr2,len2);
	
	system("pause");
	return 0;
}