#include"work.h"

void init(node** head)
{
	if (*head == NULL)
		return;
	(*head)->next = NULL;
}

void creatlist_start(node** head)
{
	int temp = 0;
	
	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
	{
		printf("please input number\n");
		scanf("%d", &temp);
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		(*head)->next = m;
		m->next = NULL;
	}
	
	//seqlist* init = (*head)->next->next;
	do 
	{
		node* p = (*head);
		printf("please input number\n");
		scanf("%d", &temp);
		if (temp == -1)
			break;
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		m->next = p->next;
		//m->next = p->next->next;
		(p)->next = m;
	} while (1);
}

void printlist(node* head)
{
	if (head == NULL||head->next==NULL)
		return;

	node* p = head;
	for (p = head; p != NULL; p = p->next)
		printf("%d->", p->num);
}


void creatlist_end(node** head)
{
	int temp = 0;

	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
	{
		printf("please input number\n");
		scanf("%d", &temp);
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		(*head)->next = m;
		m->next = NULL;
	}

	
	do
	{
		node* k = *head;
		while ((k->next) != NULL)
			k = k->next;
		printf("please input number\n");
		scanf("%d", &temp);
		if (temp == -1)
			break;
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		k->next=m;
	
		m->next=NULL;
	} while (1);
}


void list_sort(node** head)
{
	if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
		return;
	for (node* p = (*head)->next; p != NULL; p = p->next)
	{
		for (node* p2 = p->next; p2 != NULL; p2 = p2->next)
		{
			if (p->num > p2->num)
			{
				int temp = p2->num;
				p2->num = p->num;
				p->num = temp;
			}
		}
	}
}


void dele_list(node** head, int mx)
{
	if (*head == NULL || (*head)->next == NULL)
		return;
	int flag = 0;
	node* pCur = (*head);
	node* pPre = (*head)->next;
	for (; pPre != NULL; pPre = pPre->next, pCur = pCur->next)
	{
		if (pPre->num == mx)
		{
			pCur->next = pPre->next;
			free(pPre);
			pPre = NULL;
			printf("删除成功\n");
		//	flag++;
			return;
		}
	}
	//if(flag)
		printf("不存在这个数\n");
}





//*************************************
//*************************************
node* getlist(int date)
{
	node* temp = (node*)malloc(sizeof(node));
	if (temp == NULL)
		return 0;
	return temp;
}


void init_list(list** head)
{
	if (*head == NULL)
		return;
	node* temp = getlist(0);
	(*head)->first = temp;
	(*head)->last = temp;
	(*head)->last->next = NULL;
	(*head)->size = 0;
}

void list_start(list** head)
{
	int temp = 0;

	if (*head == NULL)
		return;
	if ((*head)->last->next == NULL)
	{
		printf("please input number\n");
		scanf("%d", &temp);
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		(*head)->first->next = m;
		m->next = NULL;
		(*head)->size++;
		//(*head)->first
	}

	//seqlist* init = (*head)->next->next;
	do
	{
		node* p = (*head)->first;
		printf("please input number\n");
		scanf("%d", &temp);
		if (temp == -1)
			break;
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		m->next = p->next;
		//m->next = p->next->next;
		(p)->next = m;
		(*head)->size++;
	} while (1);
}


void print(list* head)
{
	if (head == NULL &&head->size<1)
		return;

	node* p = head->first;
	for (p = head->first->next; p != NULL; p = p->next)
		printf("%d->", p->num);
}


void list_end(list** head)
{
	int temp = 0;

	if (*head == NULL)
		return;
	if ((*head)->last->next == NULL)
	{
		printf("please input number\n");
		scanf("%d", &temp);
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		(*head)->last->next = m;
		(*head)->last = m;
		m->next = NULL;
		(*head)->size++;
		//(*head)->first
	}

	//seqlist* init = (*head)->next->next;
	do
	{
		node* k = (*head)->last;
		printf("please input number\n");
		scanf("%d", &temp);
		if (temp == -1)
			break;
		node* m = (node*)malloc(sizeof(node));
		m->num = temp;
		k->next = m;
		(*head)->last = m;
		m->next = NULL;
		(*head)->size++;
	} while (1);
}

void dele_start(list** head, int mx)
{
	if (*head == NULL || (*head)->first->next == NULL)
		return;
	int flag = 0;
	node* pCur = (*head)->first;
	node* pPre = (*head)->first->next;
	for (; pPre != NULL; pPre = pPre->next, pCur = pCur->next)
	{
		if (pPre->num == mx)
		{
			pCur->next = pPre->next;
			free(pPre);
			pPre = NULL;
			printf("删除成功\n");
			(*head)->size--;
			//	flag++;
			return;
		}
	}
	//if(flag)
	printf("不存在这个数\n");
}

void dele_list_end(list** head)
{
	if (*head == NULL || (*head)->first->next == NULL)
		return;
	//node* p = NULL;
	node* k = (*head)->first;
	while ((k->next) != (*head)->last)
		k = k->next;
	free(k->next);
	k->next = NULL;
	(*head)->last = k;
	(*head)->size--;
}



void sort(list** head)
{
	if (*head == NULL || (*head)->first->next == NULL || (*head)->first->next->next == NULL)
		return;
	node* kmp = (*head)->first;
	node* pCur = (*head)->first->next;
	node* pPre = pCur->next;
	node* temp = NULL;
	node* m = pCur;
	int flag = 0;
	while (pCur != NULL)
	{
		while (pPre != NULL)
		{
			if (pPre->num < pCur->num)
			{
				temp = pPre->next;
				kmp->next = pPre;
				pPre->next = pCur;
				m->next = temp;

				pCur = pPre;
				pPre = temp;
			}
			else
			{
				pPre = pPre->next;
				m = m->next;
			}
		}
		/*if (flag++ == 0)
			(*head)->first = kmp;*/
		
		kmp = kmp->next;
		pCur = kmp->next;
		m = pCur;
		if (pCur == NULL)
			return;
		pPre = pCur->next;
	}
	/*for (node* p = (*head)->first->next; p != NULL; p = p->next)
	{
		for (node* p2 = p->next; p2 != NULL; p2 = p2->next)
		{
			if (p->num > p2->num)
			{
				int temp = p2->num;
				p2->num = p->num;
				p->num = temp;
			}
		}
	}*/
}


node*  find_list(list* head, int mx)
{
	node* temp = head->first->next;
	while (temp != NULL && temp->num != mx)
		temp = temp->next;
	return temp;
}


node* Reverse_list(list** head)
{
	if (*head == NULL || (*head)->first->next == NULL||(*head)->first->next->next == NULL)
		return NULL;
	node* pPre = NULL;
	node* pCur = (*head)->first->next;
	node* temp = (*head)->first->next->next;
	while (pCur != NULL)
	{
		pCur->next = pPre;
		pPre = pCur;
		pCur = temp;
		if(temp==NULL)
			return pPre;
		temp = temp->next;
	}
	//return pPre;
}