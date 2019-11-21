#include"work.h"

void InitNode(Nodelist** head)
{
	if (*head == NULL)
		return;
	(*head)->back = NULL;
	(*head)->next = NULL;
	(*head)->num = 0;
}




void CreatNode_start(Nodelist** head)
{
	if (*head == NULL)
		return;
	int tmp = 0;
	if ((*head)->next == NULL)
	{
		
		Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
		if (temp == NULL)
			return;
		printf("请输入链表内的数值\n");
		scanf("%d", &tmp);
		if (tmp == -1)
			return;
		temp->num = tmp;
		temp->next = NULL;
		(*head)->next = temp;
		temp->back = (*head);
	}
	do
	{
		printf("请输入链表内的数值\n");
		scanf("%d", &tmp);
		if (tmp == -1)
			return;
		Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
		temp->num = tmp;
		temp->next = (*head)->next;
		(*head)->next->back = temp;
		(*head)->next = temp;
		temp->back = (*head);

	} while (tmp);
}


void PrintNode(Nodelist* head)
{
	if (head == NULL)
		return;
	for (Nodelist* p = head->next; p != NULL; p = p->next)
		printf("%d->", p->num);
	printf("over\n");
}


void DeleNode(Nodelist** head, int num)
{
	if (*head == NULL)
		return;
	Nodelist* p = NULL;
	Nodelist* pCur = NULL;
	Nodelist* pPre = NULL;
	for (p = (*head)->next; p != NULL && p->num != num; p = p->next)
		;
	if (p == NULL)
	{
		printf("不存在这个数\n");
		return;
	}
	pPre = p->next;
	pCur = p->back;
	free(p);
	p = NULL;
	pCur->next = pPre;
	pPre->back = pCur;

}


void InsertNode(Nodelist** head, int num)
{
	if (*head == NULL)
		return;
	Nodelist* p = NULL;
	Nodelist* pCur = NULL;
	if ((*head)->next == NULL)
	{

		Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
		if (temp == NULL)
			return;
		
		temp->num = num;
		temp->next = NULL;
		(*head)->next = temp;
		temp->back = (*head);
		return;
	}

	for (p = (*head)->next; p != NULL && p->num != num; p = p->next)
		;
	if (p == NULL)
	{
		Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
		temp->num = num;
		temp->next = (*head)->next;
		(*head)->next->back = temp;
		(*head)->next = temp;
		temp->back = (*head);
		return;
	}
	Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
	temp->num = num;
	p->back->next = temp;
	temp->next = p;
	p->back = temp;

}

void SortNode(Nodelist** head)
{
	if (*head == NULL)
		return;
	int temp = 0;
	
	for(Nodelist* pCur=(*head)->next;pCur->next!=NULL;pCur=pCur->next)
		for (Nodelist* pPre = pCur->next; pPre != NULL; pPre = pPre->next)
		{
			if (pCur->num > pPre->num)
			{
				temp = pCur->num;
				pCur->num = pPre->num;
				pPre->num = temp;
			}
		}
}

//********************************************
//********************************************

void InitNode_list(Node** head)
{
	if (*head == NULL)
		return;
	(*head)->first = (Nodelist*)malloc(sizeof(Nodelist));
	(*head)->first->next = NULL;
	(*head)->first->back = NULL;
	(*head)->last = (*head)->first;
	(*head)->size = 0;
}


void CreatNode_start_list(Node** head)
{
	if (*head == NULL)
		return;
	int tmp = 0;
	if ((*head)->first->next == NULL)
	{

		Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
		if (temp == NULL)
			return;
		printf("请输入链表内的数值\n");
		scanf("%d", &tmp);
		if (tmp == -1)
			return;
		temp->num = tmp;
		temp->next = NULL;
		(*head)->first->next = temp;
		temp->back = (*head)->first;
		(*head)->size++;
		(*head)->last = temp;
	}
	do
	{
		printf("请输入链表内的数值\n");
		scanf("%d", &tmp);
		if (tmp == -1)
			return;
		Nodelist* temp = (Nodelist*)malloc(sizeof(Nodelist));
		temp->num = tmp;
		temp->next = (*head)->first->next;
		(*head)->first->next->back = temp;
		(*head)->first->next = temp;
		temp->back = (*head)->first;
		(*head)->size++;

	} while (tmp);
}


void PrintNode_list(Node* head)
{
	if (head == NULL)
		return;
	for (Nodelist* p = head->first->next; p != NULL; p = p->next)
		printf("%d->", p->num);
	printf("over\n");
}

void PrintNode_list_end(Node* head)
{
	if (head == NULL)
		return;
	for (Nodelist* p = head->last; p->back != NULL; p = p->back)
		printf("%d->", p->num);
	printf("over\n");
}

void sort(Node** head)
{
	if (*head == NULL || (*head)->first->next == NULL || (*head)->first->next->next == NULL)
		return;
	Nodelist* pCur = (*head)->first;
	Nodelist* pPre = (*head)->first->next;
	Nodelist* temp = pPre->next;
	Nodelist* m = pPre;
	while (pCur != NULL)
	{
		while (temp != NULL)
		{
			if (pPre->num > temp->num)
			{
				m->next = temp->next;
				if(temp->next!=NULL)
					temp->next->back = m;

				pPre->back = temp;
				temp->next = pPre;
				temp->back = pCur;
				pCur->next = temp;
				pPre = temp;
				temp = m->next;
			}
			else
			{
				temp = temp->next;
				m = m->next;
			}
		}
		pCur = pCur->next;
		(*head)->last = pCur;
		pPre = pCur->next;
		if (pPre == NULL)
			return;
		temp = pPre->next;
		m = pPre;
	}
}