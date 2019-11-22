#include"seqlist.h"

int main()
{
	seqlist sl;
	listinit(&sl);
	int select = 1;
	
	while (select)
	{
		printf("please input your num\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printlist(&sl);
			break;
		case 2:
			listpushback(&sl);
			break;
		case 3:
			listpushbegin(&sl);
			break;
		case 4:
			break;
		}
	}
	
	system("pause");
	return 0;
}