#include"work.h"
LinkList* Init_List()
{
	LinkList* temp = (LinkList*)malloc(sizeof(LinkList));
	temp->num = 0;
	temp->Node.next = NULL;
	return temp;
}

void Creat_List(LinkList* head)
{
	if (head == NULL)
		return;
	int tmp = 0;
	if (head->Node.next == NULL)
	{
		printf("请输入链表的数\n");
		scanf("%d", &tmp);
		if (tmp == -1)
			return;
		LinkList* temp = (LinkList*)malloc(sizeof(LinkList));
		temp->num = tmp;
		head->Node.next = &(temp->Node);
		temp->Node.next = NULL;
	}
	while (tmp != -1)
	{
		//ListNode* p = head->Node.next;
		printf("请输入链表的数\n");
		scanf("%d", &tmp);
		if (tmp == -1)
			return;
		LinkList* temp = (LinkList*)malloc(sizeof(LinkList));
		temp->num = tmp;
		temp->Node.next = head->Node.next;
		head->Node.next = &(temp->Node);
		
	}
}


void Print_List(LinkList* head)
{
	if (head == NULL || head->Node.next == NULL)
		return;
	for (ListNode* temp = head->Node.next; temp != NULL; temp = temp->next)
	{
		LinkList* p = (LinkList*)temp;
		printf("%d->", p->num);
	}
}