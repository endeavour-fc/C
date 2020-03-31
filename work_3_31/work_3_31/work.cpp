#include<iostream>
using namespace std;
int ADD(int num1, int num2)
{
	while (num2)
	{
		//int a = num1;
		//int b = num2;
		//num1 = a ^ b;
		//num2 = (a&b) << 1;
		int temp = num1 ^ num2;
		num2 = (num1&num2) << 1;
		num1 = temp;
	}
	return num1;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	while (cin >> num1 >> num2)
	{
		cout << ADD(num1, num2) << endl;
	}
	
	return 0;
}