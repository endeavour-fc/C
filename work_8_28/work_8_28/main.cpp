#include"work.h"




int main()
{
	int input = 7;
	pcon *pe = (pcon*)calloc(1, sizeof(pcon));
	init(pe);
	do {
		menu();
		printf("请输入你的选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(pe);
			break;
		case DELE:
			dele(pe);
			break;
		case SEARCH:
			search(pe);
			break;
		case MOD:
			mod(pe);
			break;
		case SHOW:
			show(pe);
			break;
		case SORT:
			sort(pe);
			break;
		case EXIT:
			printf("退出通讯录\n");
			free(pe->date);
			free(pe);
			pe->date = NULL;
			pe = NULL;
			break;
		default:
			printf("输入错误,请重新输入\n");
			Sleep(1000);
			break;
		}

	} while (input);
	
	system("pause");
	return 0;
}