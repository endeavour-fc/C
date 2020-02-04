#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};
struct BinTree
{
	BinTree* rchild;
	BinTree* lchild;
	char ch;
};
struct TreeNode
{
	BinTree* tree;
	TreeNode* next;
};
ListNode* Init_Node()
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = 0;
	temp->next = NULL;
	return temp;
}
TreeNode* InitTreeNode()
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->next = NULL;
	temp->tree = NULL;
	return temp;
}
ListNode* CreatNode(int a)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = a;
	temp->next = NULL;
	return temp;
}
TreeNode* CreatTreeeNode(BinTree* t)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->tree = t;
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
void PushStack(TreeNode* head, TreeNode* temp)
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
bool EmptyStack(TreeNode* head)
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
BinTree* PopStack(TreeNode* head)
{
	TreeNode* temp = head->next;
	head->next = head->next->next;
	BinTree* a = temp->tree;
	free(temp);
	temp = NULL;
	return a;
}
int Get_Peek(ListNode* head)
{
	return head->next->val;
}
BinTree* GetPeek(TreeNode* head)
{
	return head->next->tree;
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
void test7(int* arr, int len,int k)
{
	ListNode* head = Init_Node();
	for (int i = 0; i < len; i++)
	{
		ListNode* temp = CreatNode(arr[i]);
		Insert_Head_List(head, temp);
	}
	ListNode* First_head = NULL;
	ListNode* First_tail = NULL;
	ListNode* Last_head = NULL;
	ListNode* Last_tail = NULL;
	ListNode* Middle_head = NULL;
	ListNode* Middle_tail = NULL;
	ListNode* pPre = head->next;
	while (pPre != NULL)
	{
		if (pPre->val < k)
		{
			if (First_head == NULL)
			{
				First_head = pPre;
				First_tail = pPre;
			}
			else
			{
				First_tail->next = pPre;
				First_tail = pPre;
			}
		}
		else if (pPre->val > k)
		{
			if (Last_head == NULL)
			{
				Last_head = pPre;
				Last_tail = pPre;
			}
			else
			{
				Last_tail->next = pPre;
				Last_tail = pPre;
			}
		}
		else
		{
			if (Middle_head == NULL)
			{
				Middle_head = pPre;
				Middle_tail = pPre;
			}
			else
			{
				Middle_tail->next = pPre;
				Middle_tail = pPre;
			}
		}
		pPre = pPre->next;
	}

	if (First_tail != NULL)
	{
		First_tail->next = Middle_head;
		Middle_tail = Middle_tail == NULL ? First_tail : Middle_tail;
	}
	if (Middle_tail)
		Middle_tail->next = Last_head;
	head->next = First_head != NULL ? First_head : Middle_head ? Middle_head : Last_head;
	if (Last_head != NULL)
		Last_tail->next = NULL;
	Print_Node(head);
	
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
BinTree* CreatTree(char* str)
{
	static int i = 0;
	if (*(str + i) == '#' || *(str + i) == '\0')
	{
		if (*(str + i) == '\0')
			return NULL;
		i++;
		return NULL;
	}
	BinTree* root = (BinTree*)malloc(sizeof(BinTree));
	root->ch = *(str + i);
	i++;
	root->lchild = CreatTree(str);
	root->rchild = CreatTree(str);
	return root;

}
void Print_Tree(BinTree* root)
{
	if (root == NULL)
		return;
	printf("%c", root->ch);

	Print_Tree(root->lchild);
	Print_Tree(root->rchild);
}

void FirstPrint(BinTree* root)
{
	TreeNode* head = InitTreeNode();
	TreeNode* temp = CreatTreeeNode(root);
	PushStack(head, temp);
	while (!EmptyStack(head))
	{
		BinTree* temp = PopStack(head);
		printf("%c ", temp->ch);
		if (temp->rchild != NULL)
		{
			TreeNode* tmp = CreatTreeeNode(temp->rchild);
			PushStack(head, tmp);
		}
		if (temp->lchild)
		{
			TreeNode* tmp = CreatTreeeNode(temp->lchild);
			PushStack(head, tmp);
		}
	}
}
void MiddlePrint(BinTree* root)
{
	TreeNode* head = InitTreeNode();
	while (!EmptyStack(head) || root != NULL)
	{
		while (root)
		{
			TreeNode* temp = CreatTreeeNode(root);
			PushStack(head, temp);
			root = root->lchild;
		}
		if (!EmptyStack(head))
		{
			root = PopStack(head);
			printf("%c ", root->ch);
			root = root->rchild;
		}
	}
}
void LastPrint(BinTree* root)
{
	TreeNode* head = InitTreeNode();
	BinTree* pPre = NULL;
	BinTree* pCur = NULL;
	do
	{
		while (root)
		{
			TreeNode* temp = CreatTreeeNode(root);
			PushStack(head, temp);
			root = root->lchild;
		}
		pCur = GetPeek(head);
		if (pCur->rchild == NULL || pPre == pCur->rchild)
		{
			PopStack(head);
			printf("%c ", pCur->ch);
			pPre = pCur;
		}
		else
		{
			root = pCur->rchild;
		}
	} while (!EmptyStack(head));
}
int main()
{
	//int arr[] = { 1,2,3,1 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//test7(arr, len, 5);
	//printf("%d\n", test6(arr, len));
	char str[] = "abc###d##";
	BinTree* root = CreatTree(str);
	//Print_Tree(root);
	//FirstPrint(root);
	//MiddlePrint(root);
	LastPrint(root);

	system("pause");
	return 0;
}