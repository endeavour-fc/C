#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int a;
	Node *next;
}Node;

void creat_node(Node** head_n,int num)
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
	Node* p = NULL;
	for (p=head; p != NULL;p= p->next)
	{
		printf("%d->", p->a);
	}
}

int main()
{
	Node* head = NULL;
	int input = 0;
	do
	{
		printf("请输入一个非-1的数\n");
		scanf("%d", &input);
		creat_node(&head, input);
	} while (input!=-1);
	
	print_node(head);

	system("pause");
	return 0;
}