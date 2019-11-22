#include"seqlist.h"

void listinit(seqlist* p)
{
	if (p == NULL)
		return;
	p->len = MIN;
	p->size = 0;
	p->date = (int*)(malloc(sizeof(int)*(p->len)));
}

static void Capacity_expansion(seqlist* p)
{
	if (p == NULL)
		return;
	int* p1 = (int*)realloc(p->date, sizeof(int)*(p->len + MIN));
	//p->date = (int*)realloc((p->date), sizeof(int)*(p->len) + MIN);
	if (p1 != NULL)
	{
		printf("增容成功\n");
		p->date = p1;
		p->len += MIN;
		//p1 = NULL;
	  return;
	}
	else
	 {
		printf("开辟失败\n");
		return;
	 }
}

void listpushback(seqlist* p)
{
	if (p == NULL)
		return;
	if (p->len <= p->size)
		Capacity_expansion(p);
	
	if (p == NULL)
		return;
	int num = 0;
	printf("please input num\n");
	scanf("%d",&num);
	((int*)(p->date))[(p->size)++] = num;
}

void listpushbegin(seqlist* p)
{
	if (p == NULL)
		return;
	if (p->len <= p->size)
		Capacity_expansion(p);
	if (p == NULL)
		return;

	for (int i = (p->size)++; i > 0; i--)
	{
		((int*)(p->date))[i] = ((int*)(p->date))[i - 1];
	}
	printf("please input num\n");
	scanf("%d", &((int*)(p->date))[0]);
}

void listsort(seqlist* p)
{
	if (p == NULL)
		return;
	for(int i=0;i<p->size-1;i++)
		for (int j = 0; j < p->size-i-1; j++)
		{
			if (((int*)(p->date))[j] > ((int*)(p->date))[j + 1])
			{
				int temp = ((int*)(p->date))[j];
				((int*)(p->date))[j] = ((int*)(p->date))[j + 1];
				((int*)(p->date))[j + 1] = temp;
			}
		}
}

void printlist(seqlist* p)
{
	if (p == NULL||p->size<=0)
		return;
	for (int i = 0; i < p->size; i++)
		printf("%d->", ((int*)(p->date))[i]);
	printf("\n");
}

void menu()
{
	printf("********************************\n");
	printf("********************************\n");
	printf("****                        ****\n");
	printf("****                        ****\n");
	printf("****                        ****\n");
	printf("****                        ****\n");
	printf("****                        ****\n");
	printf("****                        ****\n");
	printf("****                        ****\n");
	printf("********************************\n");
	printf("********************************\n");

}