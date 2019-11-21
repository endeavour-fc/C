#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse_bit(unsigned int value)
{
	int num = 0;
	for (int i = 0; i <32; i++)
	{
		if ((value >>i)&1)
		{
			num=(num >> (31 - i)) + 1;
			num=num << (31 - i);
		}
	}
	//num >>= 1;
	return num;
}


int main()
{
	int arr[10] = { 1,3,4,5,7,5,7,4,1,0 };
	int a = 10;
	int b = 5;
	int temp = 0;
	a ^= b;
	b ^= a;
	a ^= b;
	for (int i = 0; i < 10; i++)
	{
		temp ^= arr[i];
	}
	printf("%d \n", temp);

	printf("%d %d\n", a, b);

	printf("%u ", reverse_bit(25));
	
	system("pause");
	return 0;
}


//int main02()
//{
//	char *pcur = NULL;
//	char *ppre = NULL;
//	int count = 0;
//	char arr1[20] = "i am a student ";
//	char arr2[20] = "i am a student ";
//	int len = strlen(arr1);
//	pcur = arr1;
//	ppre = arr1;
//	while (*ppre != '\0')
//	{
//		//ppre++;
//		if (*(ppre) == ' ')
//		{
//			count = ppre - pcur+1;
//			for(int i=count;i>0;i--)
//				arr2[len - i] = *(pcur++);
//			//arr2[len - count - 1] = ' ';
//			len -= count;
//		}
//	} 
//	printf("%s", arr2);
//
//
//	system("pause");
//	return 0;
//}
//
//void swap(char* b, char*e)
//{
//	char temp = 0;
//	while (e > b)
//	{
//		temp = *e;
//		*e = *b;
//		*b = temp;
//		e--;
//		b++;
//	}
//}
//
//
//int main()
//{
//	int count = 0;
//	char *begin = NULL;
//	char *end = NULL;
//	char arr1[20] = "i am a student";
//	int len = strlen(arr1);
//	begin = arr1;
//	end = arr1 + len-1;
//	swap(begin, end);
//	begin = arr1;
//	end = arr1;
//	while (1)
//	{
//		end++;
//		if (*end == ' ')
//		{
//			swap(begin, end-1);
//			begin = end+1;
//		}
//		if (*end == '\0')
//		{
//			swap(begin, end-1);
//			break;
//		}
//	}
//	printf("%s", arr1);
//
//	system("pause");
//	return 0;
//}