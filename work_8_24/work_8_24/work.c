#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main01()
{
	char *c[] = { "ENTER","NEW","POINT","FIRST" };
	char**cp[] = { c + 3,c + 2,c + 1,c };
	char***cpp = cp; 
	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *--*++cpp + 3);//ER
	printf("%s\n", *cpp[-2] + 3); //ST
	printf("%s\n", cpp[-1][-1] + 1);//EW
	
	system("pause");
	return 0;
}

int num(int p)
{
	int count = 0;
	int a = p;
	int b = p;
	while (b>1)
	{
		count=b/2 ;
		a += count;
		if (b % 2)
			b = count + 1;
		else
			b = count;

	}
	return a;
}

char *my_strcat(char *des, const char *string)
{
	if (des == NULL && string == NULL)
		return 0;
	char *p = NULL;
	char *p2 = des;
	p = string;
	while (*(++p2))
	{
		;
	}
	for (int i = 0; ; i++)
	{
		p2[i] = *(p + i);
		if (*(p + i) == '\0')
			return des;
	}
	
}

char *my_strcpy(char *des, const char *string)
{
	if (des == NULL && string == NULL)
		return 0;
	/*char *p = string;
	for (int i = 0; *(string + i) != '\0'; i++)
	{
		des[i] = *(string + i);
		des[i + 1] = '\0';
	}*/
	while (*(des++) = *(string++))
	{
		;
	}
	return des;
}

int main()
{
	//char arr[20] = "dcvbvgada";
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int temp = 0;
	int k = 0;
	int sum = 0;
	for (int i = 0; i < sz; i++)
	{
		sum ^= arr[i];
	}
	//my_strcat(arr, "adasx");
	//my_strcpy(arr, "iyuiytyt");
	//printf("%d\n", num(10));
	//printf("%s\n", arr);
	/*printf("%d %d", sum^temp, temp);*/
	system("pause");
}