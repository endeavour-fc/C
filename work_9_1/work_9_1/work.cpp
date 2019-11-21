#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




bool isHappy(int n) {
	int temp = 0;
	int sum = 0;
	while (n>0)
	{
		temp = n % 10;
		sum += temp * temp;
		n /= 10;
		if (n == 0 && sum >= 3)
		{
			n = sum;
			sum = 0;
		}
	}
	if (sum == 1)
		return true;
	else
		return false;
}

int main()
{
	//int arr[][4] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	//int temp = 0;
	//int num = sizeof(arr) / sizeof(arr[0])-1;
	//int row = 0;
	//int a = 7;
	///////*int arr2[num+1] = { 0 };
	//////for (int i = 0; i < num; i++)
	//////{
	//////	if (arr[i] == arr2[arr[i]])
	//////		printf("%d\n", arr[i]);
	//////	else
	//////		arr2[arr[i]] = arr[i];
	//////}*/
	//while (row < 4 && num >= 0)
	//{
	//	if (arr[row][num] > a)
	//		num--;
	//	else if (arr[row][num] < a)
	//		row++;
	//	else
	//		break;

	//}

	printf("%d\n", isHappy(1111111));


	
	system("pause");
	return 0;
}