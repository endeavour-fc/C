#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"game.h"

int main()
{
	int key = 1;
	char a[S][M] = { 0 };
	do
	{
		printf("****************************\n");
		printf("****************************\n");
		printf("********   1. ��Ϸ   *******\n");
		printf("********   0. �˳�   *******\n");
		printf("****************************\n");
		printf("****************************\n");
		

		printf("���������ѡ��\n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			game(a,S,M);
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}
	
	} while (key);


	
	system("pause");
	return 0;
}