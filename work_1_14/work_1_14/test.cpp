#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

ListNode* GetNode(int a)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)
		return NULL;
	temp->next = NULL;
	temp->val = a;
	return temp;
}
void Push_Stack(ListNode* head, ListNode* temp)
{
	if (head != NULL && temp != NULL)
	{
		temp->next = head->next;
		head->next = temp;
	}
}
bool Empty_Stack(ListNode* head)
{
	return head->next == NULL ? true : false;
}
int Pop_Stack(ListNode* head)
{
	ListNode* temp = head->next;
	head->next = head->next->next;
	int a = temp->val;
	free(temp);
	temp = NULL;
	return a;
}
void Print_Stack(ListNode* head)
{
	if (head == NULL)
		return;
	for (ListNode* temp = head->next; temp != NULL; temp = temp->next)
	{
		cout << temp->val << "->";
	}
	cout << endl;
}
void test(int* arr,int len)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	head1 = (ListNode*)malloc(sizeof(ListNode));
	head2 = (ListNode*)malloc(sizeof(ListNode));
	head1->next = head2->next = NULL;
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = GetNode(arr[i]);
		Push_Stack(head1, temp);
	}
	Print_Stack(head1);
	while (!Empty_Stack(head1))
	{
		int a = Pop_Stack(head1);
		ListNode* temp = GetNode(a);
		Push_Stack(head2, temp);
	}
	Print_Stack(head2);

}
void MySwap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

template<class T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test1()
{
	int a = 2;
	int b = 3;
	cout << "a:" << a << "      b:" << b << endl;
	Swap(a, b);
	//Swap<int>(a, b);
	cout << "a:" << a << "      b:" << b << endl;
	double d = 1.23;
	double c = 1.55;
	cout << "d:" << d << "      c:" << c << endl;
	Swap(d, c);
	cout << "d:" << d << "      c:" << c << endl;
}


int main()
{
	int arr[] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	test(arr,len);

	system("pause");
	return 0;
}