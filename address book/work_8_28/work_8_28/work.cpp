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

	printf("请输入年龄\n");
	scanf("%d", &(p->date[temp].age));
	printf("请输入性别\n");
	scanf("%s", p->date[temp].sex);
	printf("请输入电话\n");
	scanf("%d", &(p->date[temp].tele));
	printf("请输入地址\n");
	scanf("%s", p->date[temp].addr);
	printf("修改完成\n");
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
		printf("增容成功\n");
		P* ps = NULL;
		ps = (P*)realloc(p->date, sizeof(P)*3);
		if (ps != NULL)
		{ 
			p->sz = p->sz + 3;
			p->date = ps;
			return 0;
		}
		printf("开辟失败\n");
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
		printf("添加失败\n");
		return;
	}

	printf("请输入姓名\n");
	scanf("%s", arr);
	if ((temp = sch(p, arr)) >= 0)
	{
		printf("已存在此人，改为对此人的信息的修改\n");
		mod2(p, p->date[p->num].name,temp);
	
		return;
	}
	strcpy(p->date[p->num].name, arr);
	printf("请输入年龄\n");
	scanf("%d", &(p->date[p->num].age));
	printf("请输入性别\n");
	scanf("%s", p->date[p->num].sex);
	printf("请输入电话\n");
	scanf("%d", &(p->date[p->num].tele));
	printf("请输入地址\n");
	scanf("%s", p->date[p->num].addr);
	(p->num)++;

}



void show(pcon* p)
{
	if (p == NULL)
		return;
	printf("%10s\t%5s\t%5s\t%15s\t%20s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < p->num; i++)
	{
		printf("%10s\t%5d\t%5s\t%15d\t%20s\n", p->date[i].name, p->date[i].age, p->date[i].sex, p->date[i].tele, p->date[i].addr);
	}
}


void dele(pcon* p)
{
	if (p->num == 0)
	{
		printf("通讯录已经删除完，不可删除\n");
		return;
	}
	int temp = 0;
	char arr[20] = { 0 };
	printf("请输入删除人的姓名\n");
	scanf("%s", &arr);
	if (temp=sch(p, arr) < 0)
	{
		printf("不存在此人\n");
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
	printf("请输入查找人的姓名\n");
	scanf("%s", &arr);
	if ((temp = sch(p, arr)) < 0)
	{
		printf("不存在此人\n");
		return;
	}
	printf("%10s\t%5s\t%5s\t%15s\t%20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("排序成功\n");
}


void mod(pcon* p)
{
	int temp = 0;
	char arr[20] = { 0 };
	printf("请输入修改人的姓名\n");
	scanf("%s", &arr);
	if ((temp = sch(p, arr)) < 0)
	{
		printf("不存在此人\n");
		return;
	}
	printf("请输入年龄\n");
	scanf("%d", &(p->date[temp].age));
	printf("请输入性别\n");
	scanf("%s", p->date[temp].sex);
	printf("请输入电话\n");
	scanf("%d", &(p->date[temp].tele));
	printf("请输入地址\n");
	scanf("%s", p->date[temp].addr);
	printf("修改完成\n");
}