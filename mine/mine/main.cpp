#define  _CRT_SECURE_NO_WARNINGS 
#include"mine.h"

int main()
{
	srand((unsigned)time(NULL));
	int key = 0;
	char a[RS][MS] = { 0 };
	char b[RS][MS] = { 0 };
	do
	{
		printf("*************************\n");
		printf("*************************\n");
		printf("******   1. ��Ϸ   ******\n");
		printf("******   0. �˳�   ******\n");
		printf("*************************\n");
		printf("*************************\n");

		printf("�������ѡ��\n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			game(a,b,RS,MS);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (key);
	
	
	system("pause");
	return 0;
}