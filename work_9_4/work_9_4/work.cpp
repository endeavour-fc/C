#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stack>
using namespace std;

typedef struct Node
{
	int a;
	Node *next;
}Node;

void creat_node(Node** head_n, int num)
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
	if (head == NULL)
		return;
	Node* p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		printf("%d-> ", p->a);
	}
}

void dele_node(Node** head, int value)
{
	if (head == NULL)
		return;
	Node* p = *head;
	Node* h = NULL;
	Node* f = NULL;
	if (p->a == value)
	{
		h = p->next;
		free(p);
		*head = h;
		return;
	}
	else
	{
		for (p; p != NULL; p = p->next)
		{
			if (p->next == NULL)
			{
				printf("这个数不存在\n");
				return;
			}
			if (p->next->a == value)
			{
				h = p->next->next;
				free(p->next);
				p->next = h;
				return;

			}
		}
		
	}
}


void add_node(Node** head, int num)
{
	Node* p = (Node*)malloc(sizeof(Node));
	Node* f = *head;
	Node* h = NULL;
	if (p == NULL)
		return;
	p->a = num;

	if (f->a == num)
	{
		h = f->next;
		f->next = p;
		p->next = h;
		return;
	}

	for (f; f != NULL; f = f->next)
	{
		if (f->next == NULL)
		{
			f->next = p;
			p->next = NULL;
			return;
		}
		if (f->next->a == num)
		{
			h = f->next;
			f->next = p;
			p->next = h;
			return;
		}
	}
}


void des_node(Node** head_p)
{
	Node* p = NULL;
	Node* head = *head_p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

struct Node* reverseList(struct Node* head) {

		if (head == NULL)
			return NULL;
		struct Node* Pcur = NULL;
		struct Node* Ppre = head;

		while (Ppre != NULL)
		{
			struct Node* temp = Ppre->next;
			Ppre->next = Pcur;
			Pcur = Ppre;
			Ppre = temp;
		}
		return Pcur;
}


//int main()
//{
//	Node* head = NULL;
//	int a = 0;
//	int input = 0;
//	do
//	{
//		printf("请输入一个非-1的数\n");
//		scanf("%d", &input);
//		creat_node(&head, input);
//	} while (input != -1);
//
//	head= reverseList(head);
//	print_node(head);
//
//	//print_node(head);
//	//printf("\n");
//	//printf("请输入一删除的数\n");
//	//scanf("%d", &a);
//	//dele_node(&head, a);
//	//print_node(head);
//
//	//printf("\n");
//	//printf("请输入一增加的数\n");
//	//scanf("%d", &a);
//	//add_node(&head, a);
//	//print_node(head);
//
//
//	des_node(&head);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		set<pair<int, int>> v;
//		v.insert({ 0,0 });
//		int i = 0;
//		int pos_i = 0;
//		int pos_j = 0;
//		for (; i<s.size(); ++i)
//		{
//			if (s[i] == 'N')
//			{
//				pos_i -= 1;
//			}
//			else if (s[i] == 'S')
//			{
//				pos_i += 1;
//			}
//			else if (s[i] == 'E')
//			{
//				pos_j += 1;
//			}
//			else
//			{
//				pos_j -= 1;
//			}
//
//			if (v.find({ pos_i,pos_j }) == v.end())
//			{
//				v.insert({ pos_i,pos_j });
//			}
//			else
//				break;
//		}
//		if (i != s.size())
//			cout << "True" << endl;
//		else
//			cout << "False" << endl;
//	}
//
//	return 0;
//}
int main()
{
	string s;
	while (cin >> s)
	{
		stack<char> sta;
		int i = 0;
		for (i = 0; i<s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				sta.push(s[i]);
			}
			else
			{
				if (!sta.empty())
				{
					if (sta.top() == '('&&s[i] == ')')
						sta.pop();
					else if (sta.top() == '{'&&s[i] == '}')
						sta.pop();
					else if (sta.top() == '['&&s[i] == ']')
						sta.pop();
					else
						break;
				}
				else
				{
					break;
				}
			}
		}
		if (i == s.size() && sta.empty())
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}

	return 0;
}