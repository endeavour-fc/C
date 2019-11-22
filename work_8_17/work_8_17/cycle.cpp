#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getnum(int num)
{
	
	if (num > 2)
		return getnum(num - 1) + getnum(num - 2);
	return 1;
}

int getnum2(int num, int k)
{
	if (k > 0)
		return getnum2(num, k - 1)*num;
	return 1;
}


int getnum3(int num)
{
	if(num>10)
		return getnum3(num/10)+num%10;
	return num;
}
char temp = 0;
char getstring(char a[30],int num,int s)
{
	
	if (s < num/2)
	{
		temp = a[s];
		a[s] = a[num - s-1];
		a[num - s-1] = temp;
		return getstring(a, num, s + 1);
	}
	return 0;
}

int getnum4(char a[30],int num)
{
	static int cot = 0;
	if (a[num] != '\0')
	{
		cot++;
		return getnum4(a, num+1);
	}
	return cot;
}

int getnum5(int num)
{
	if (num > 1)
		return getnum5(num - 1)*num;
	return 1;
}

int getnum6(int num)
{
	if (num > 10)
	{
		printf(" %d ", num % 10);
		return getnum6(num / 10);
	}
	else
	{
		printf(" %d ", num);
		return 0;
	}
}


int main()
{
	char a[30] = "fsddgcb";
	int count = 0;
	char b[30] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		if (a[i] != '\0')
			count++;
		else
			break;
	}
	//printf("%d", getnum6(2465));
	getnum6(2465);
	//int num = sizeof(a) / sizeof(a[0])-1;
	//printf("%s\n", a);
	//getstring(a,count,0);
	//printf("%s", a);
	//int key = getnum(6);
	//int key = getnum3(1234);
	//printf("%d", key);
	
	system("pause");
	return 0;
}