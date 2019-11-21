#include"work.h"


static int sch(pcon* p, char str[])
{
	for (int i = 0; i < p->num; i++)
	{
		if (strcmp(p->date[i].name, str) == 0)
			return i;
	}
	return -1;
}


void mod2(pcon* p,char* arr,int temp)
{

	printf("����������\n");
	scanf("%d", &(p->date[temp].age));
	printf("�������Ա�\n");
	scanf("%s", p->date[temp].sex);
	printf("������绰\n");
	scanf("%d", &(p->date[temp].tele));
	printf("�������ַ\n");
	scanf("%s", p->date[temp].addr);
	printf("�޸����\n");
}

void menu()
{
	printf("**************************************\n");
	printf("*****  1. add           2. dele  *****\n");
	printf("*****  3. search        4. mod   *****\n");
	printf("*****  5. show          6. sort  *****\n");
	printf("*****  0. exit                   *****\n");
	printf("**************************************\n");

}

int enlarg(pcon* p)
{
	if (p == NULL)
		return 1;
	if (p->num < p->sz)
		return 0;
	else
	{
		printf("���ݳɹ�\n");
		P* ps = NULL;
		ps = (P*)realloc(p->date, sizeof(P)*3);
		if (ps != NULL)
		{ 
			p->sz = p->sz + 3;
			p->date = ps;
			return 0;
		}
		printf("����ʧ��\n");
		return 1;
	}
}

void init(pcon* p)
{
	p->date = (P*)calloc(3, sizeof(P));
	p->num = 0;
	p->sz = 3;

}

void add(pcon* p)
{
	char arr[30] = { 0 };
	int temp = 0;
	if (p == NULL)
		return;
	if (enlarg(p))
	{
		printf("���ʧ��\n");
		return;
	}

	printf("����������\n");
	scanf("%s", arr);
	if ((temp = sch(p, arr)) >= 0)
	{
		printf("�Ѵ��ڴ��ˣ���Ϊ�Դ��˵���Ϣ���޸�\n");
		mod2(p, p->date[p->num].name,temp);
	
		return;
	}
	strcpy(p->date[p->num].name, arr);
	printf("����������\n");
	scanf("%d", &(p->date[p->num].age));
	printf("�������Ա�\n");
	scanf("%s", p->date[p->num].sex);
	printf("������绰\n");
	scanf("%d", &(p->date[p->num].tele));
	printf("�������ַ\n");
	scanf("%s", p->date[p->num].addr);
	(p->num)++;

}



void show(pcon* p)
{
	if (p == NULL)
		return;
	printf("%10s\t%5s\t%5s\t%15s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < p->num; i++)
	{
		printf("%10s\t%5d\t%5s\t%15d\t%20s\n", p->date[i].name, p->date[i].age, p->date[i].sex, p->date[i].tele, p->date[i].addr);
	}
}


void dele(pcon* p)
{
	if (p->num == 0)
	{
		printf("ͨѶ¼�Ѿ�ɾ���꣬����ɾ��\n");
		return;
	}
	int temp = 0;
	char arr[20] = { 0 };
	printf("������ɾ���˵�����\n");
	scanf("%s", &arr);
	if (temp=sch(p, arr) < 0)
	{
		printf("�����ڴ���\n");
		return;
	}
	for (int i = temp; i < p->num; i++)
	{
		strcpy(p->date[i].addr, p->date[i + 1].addr);
		strcpy(p->date[i].sex, p->date[i + 1].sex);
		strcpy(p->date[i].name, p->date[i + 1].name);
		p->date[i].age = p->date[i + 1].age;
		p->date[i].tele = p->date[i + 1].tele;
	}
	p->num--;

}



void search(pcon* p)
{
	int temp = 0;
	char arr[20] = { 0 };
	printf("����������˵�����\n");
	scanf("%s", &arr);
	if ((temp = sch(p, arr)) < 0)
	{
		printf("�����ڴ���\n");
		return;
	}
	printf("%10s\t%5s\t%5s\t%15s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%10s\t%5d\t%5s\t%15d\t%20s\n", p->date[temp].name, p->date[temp].age, p->date[temp].sex, p->date[temp].tele, p->date[temp].addr);
}

void sort(pcon* p)
{
	char arr[30] = { 0 };
	int temp = 0;
	for(int i=0;i<p->num-1;i++)
		for (int j = 0; j < p->num - i - 1; j++)
		{
			if (strcmp(p->date[j].name, p->date[j + 1].name) > 0)
			{
				strcpy(arr, p->date[j].addr);
				strcpy(p->date[j].addr, p->date[j + 1].addr);
				strcpy(p->date[j+1].addr, arr);

				strcpy(arr, p->date[j].sex);
				strcpy(p->date[j].sex, p->date[j + 1].sex);
				strcpy(p->date[j+1].sex, arr);

				strcpy(arr, p->date[j].name);
				strcpy(p->date[j].name, p->date[j + 1].name);
				strcpy(p->date[j+1].name, arr);

				temp = p->date[j].age;
				p->date[j].age = p->date[j+ 1].age;
				p->date[j + 1].age = temp;

				temp = p->date[j].tele;
				p->date[j].tele = p->date[j + 1].tele;
				p->date[j + 1].tele = temp;
			}
		}
	printf("����ɹ�\n");
}


void mod(pcon* p)
{
	int temp = 0;
	char arr[20] = { 0 };
	printf("�������޸��˵�����\n");
	scanf("%s", &arr);
	if ((temp = sch(p, arr)) < 0)
	{
		printf("�����ڴ���\n");
		return;
	}
	printf("����������\n");
	scanf("%d", &(p->date[temp].age));
	printf("�������Ա�\n");
	scanf("%s", p->date[temp].sex);
	printf("������绰\n");
	scanf("%d", &(p->date[temp].tele));
	printf("�������ַ\n");
	scanf("%s", p->date[temp].addr);
	printf("�޸����\n");
}