#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

int main01()
{
	int m = 0;
	srand((unsigned)time(NULL));
	int key = rand() % 100;
	while (1)
	{
		printf("�����������µ���\n");
		scanf("%d", &m);
		if (m > key)
			printf("�´���\n");
		else if(m<key)
			printf("��С��\n");
		else
		{
			printf("�¶���\n");
			break;
		}

	}
	
	system("pause");
	return 0;
}


int main02()
{
	int key = 0;
	int a[20] = { 0 };
	int right = 19;
	int left = 0;
	int mid = 0;
	printf("������һ��Ҫ���ҵ���\n");
	scanf("%d", &key);
	for (int i = 0; i<20; i++)
		a[i] = i;
	while (right >= left)
	{
		mid = (right + left) / 2;
		if (a[mid] > key)
			right = mid - 1;
		else if (a[mid] < key)
			left = mid + 1;
		else if(a[mid]==key)
		{
			printf("�ҵ���%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("û�ҵ�\n");

	system("pause");
	return 0;
}


int main03()
{
	char a[] = "asdfg";
	char b[20] = { 0 };
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("����������\n");
		scanf("%s", b);
		if (strcmp(b, a) == 0)
		{
			printf("������ȷ\n");
			break;
		}
		printf("�������");
		j++;
	}
	if (j == 3)
		printf("�رճ���\n");

	system("pause");
	return 0;
}


int main()
{
	char ms = 0;
	for (int i = 0; i < 50; i++)
	{
		ms = getchar();
		if (ms >= 65 && ms <= 90)
		{
			ms = ms + 32;
			printf("%c", ms);
		}
		else if (ms >= 97 && ms <= 122)
		{
			ms = ms - 32;
			printf("%c", ms);
		}
	}

	system("pause");
	return 0;
}