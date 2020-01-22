#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdio.h>
using namespace std;

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
int Get_Peek(ListNode* head)
{
	return head->next->val;
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

int GetRemove(ListNode* head)
{
	int result=Pop_Stack(head);
	if (Empty_Stack(head))
		return result;
	int i = GetRemove(head);
	ListNode* temp = GetNode(result);
	Push_Stack(head, temp);
	return i;
}
void Reverse(ListNode* head)
{
	if (Empty_Stack(head))
		return;
	int i = GetRemove(head);
	Reverse(head);
	ListNode* temp = GetNode(i);
	Push_Stack(head, temp);
}
void test3(int* arr, int len)
{
	ListNode* stack = NULL;
	ListNode* help = NULL;
	stack = (ListNode*)malloc(sizeof(ListNode));
	help = (ListNode*)malloc(sizeof(ListNode));
	help->next = stack->next = NULL;
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = GetNode(arr[i]);
		Push_Stack(stack, temp);
	}
	Print_Stack(stack);
	while (!Empty_Stack(stack))
	{
		int val = Pop_Stack(stack);
		ListNode* temp = GetNode(val);
		while (!Empty_Stack(help) && Get_Peek(help) > val)
		{
			int a = Pop_Stack(help);
			ListNode* tmp = GetNode(a);
			Push_Stack(stack, tmp);
		}
		Push_Stack(help, temp);
	}
	while (!Empty_Stack(help))
	{
		int val = Pop_Stack(help);
		ListNode* temp = GetNode(val);
		Push_Stack(stack, temp);
	}
	Print_Stack(stack);
}

void test2(int* arr, int len)
{
	ListNode* head1 = NULL;
//	ListNode* head2 = NULL;
	head1 = (ListNode*)malloc(sizeof(ListNode));
//	head2 = (ListNode*)malloc(sizeof(ListNode));
	head1->next = NULL;
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = GetNode(arr[i]);
		Push_Stack(head1, temp);
	}
	Print_Stack(head1);
	Reverse(head1);
	Print_Stack(head1);

}
bool test5(int* arr, int len)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	ListNode* Stack = (ListNode*)malloc(sizeof(ListNode));
	Stack->next = NULL;
	ListNode* pPre = head->next;
	ListNode* pCur = head->next;
	while (pCur->next != NULL && pCur->next->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next->next;
	}
	while (pPre != NULL)
	{
		ListNode* temp = GetNode(pPre->val);
		Push_Stack(Stack, temp);
		pPre = pPre->next;
	}
	while (!Empty_Stack(Stack))
	{
		if (Pop_Stack(Stack) != head->next->val)
			return false;
		head = head->next;
	}
	return true;

}
bool test6(int* arr, int len)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	ListNode* pPre = head->next;
	ListNode* pCur = head->next;
	while (pCur->next != NULL && pCur->next->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next->next;
	}
	ListNode* temp = NULL;
	pCur = pPre->next;
	pPre->next = NULL;
	while (pCur)
	{
		temp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;
	}
	head = head->next;
	while (head != NULL && pPre != NULL)
	{
		if (head->val != pPre->val)
			return false;
		head = head->next;
		pPre = pPre->next;
	}
	return true;
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
	int arr[] = { 1,2,3,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", test6(arr, len));

	system("pause");
	return 0;
}