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
		printf("******   1. 游戏   ******\n");
		printf("******   0. 退出   ******\n");
		printf("*************************\n");
		printf("*************************\n");

		printf("输入你的选择\n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
			game(a,b,RS,MS);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (key);
	
	
	system("pause");
	return 0;
}