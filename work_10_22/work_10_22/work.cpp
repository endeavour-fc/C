#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

typedef struct {
	int* data;
	int top;
} Stack;

Stack* init_stack()
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->data = (int*)malloc(sizeof(int) * 100);
	temp->top = 0;
	return temp;
}
void push_stack(Stack* s, int x)
{
	s->data[s->top++] = x;
}
bool empty_stack(Stack* s)
{
	return s->top == 0 ? true : false;
}
void pop_stack(Stack* s)
{
	if (empty_stack(s))
		return;
	s->top--;
}
int top_stack(Stack* s)
{
	return s->data[s->top - 1];
}

typedef struct {
	Stack* s;
	Stack* min;

} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* temp = (MinStack*)malloc(sizeof(MinStack));
	temp->s = init_stack();
	temp->min = init_stack();
	return temp;
}

void minStackPush(MinStack* obj, int x) {
	if (empty_stack(obj->s))
	{
		push_stack(obj->s, x);
		push_stack(obj->min, x);
	}
	else
	{
		push_stack(obj->s, x);
		if(top_stack(obj->min) >= top_stack(obj->s))
			push_stack(obj->min, x);
	}
}

void minStackPop(MinStack* obj) {
	if (empty_stack(obj->s))
		return;
	if (top_stack(obj->min) == top_stack(obj->s))
	{
		pop_stack(obj->min);
	}
	pop_stack(obj->s);
}

int minStackTop(MinStack* obj) {
	return top_stack(obj->s);
}

int minStackGetMin(MinStack* obj) {
	return top_stack(obj->min);
}

void minStackFree(MinStack* obj) {
	free(obj->s);
	free(obj->min);
	free(obj);
}
void Swapstr(string::iterator it1, string::iterator it2)
{
	for (; it1 < it2; it1++, it2--)
	{
		swap(*it1, *it2);
	}
}
string reverseWords(string s) {
	Swapstr(s.begin(), s.end() - 1);
	string::iterator it1 = s.begin();
	string::iterator it2;
	while (it1 != s.end())
	{
		while (it1 != s.end() && *it1 == ' ')
			it1++;
		if (it1 == s.end())
			return s;
		it2 = it1;
		while (it2 != s.end() && *it2 != ' ')
			it2++;
		Swapstr(it1, it2-1);
		it1 = it2;
	}
	return s;
}
//int main()
//{
//	cout << reverseWords("the sky is blue") << endl;
//	system("pause");
//	return 0;
//}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void change(vector<int>& v, int pos)
{
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;
	if (right<v.size())
	{
		if (v[pos]<v[left])
			swap(v[pos], v[left]);
		if (v[pos]<v[right])
			swap(v[pos], v[right]);
	}
	else if (left<v.size())
	{
		if (v[pos]<v[left])
			swap(v[pos], v[left]);
	}
	else
	{
		return;
	}
}
int transform(char c)
{
	if (c >= '0' || c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}
string addStrings(string num1, string num2)
{
	int a1 = num1.size() - 1;
	int a2 = num2.size() - 1;
	int step = 0;
	string ret;
	int sum = 0;
	while (a1 >= 0 || a2 >= 0)
	{
		sum = 0;
		sum += step;
		if (a1 >= 0)
		{
			sum += num1[a1] - '0';
		}
		if (a2 >= 0)
		{
			sum += num2[a2] - '0';
		}
		if (sum >= 10)
		{
			sum -= 10;
			step = 1;
		}
		else
		{
			step = 0;
		}
		ret.insert(0, 1, sum + '0');
		a1--;
		a2--;

	}
	if (step == 1)
	{
		ret.insert(0, 1, '1');
	}
	return ret;
}
int main()
{
	string str;
	while (cin >> str)
	{
		int flag = 1;
		int i = 0;
		if (str[0] == '-')
		{
			flag = -1;
			i = 1;
		}
		//long long ret = 0;
		string ret("0");
		for (; i<str.size(); ++i)
		{
			ret = addStrings(ret, to_string(pow(36, str.size() - i)*(transform(str[i]))));
			//ret=ret*36+transform(str[i]);
		}
		if (flag == -1)
			cout << "-" << ret << endl;
		else
			cout << ret << endl;
	}

	return 0;
}
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		vector<int> v(n, 0);
//		for (int i = 0; i<n; ++i)
//			cin >> v[i];
//		int a = 0;
//		for (int i = 0; i<m; ++i)
//		{
//			int temp = 0;
//			cin >> temp;
//			if (temp == 1)
//			{
//				cin >> a;
//				change(v, a - 1);
//			}
//			else
//			{
//				cin >> a;
//				for (int i = a - 1; i<v.size(); ++i)
//					cout << v[i] << " ";
//				cout << endl;
//			}
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	MinStack* temp = minStackCreate();
//	minStackPush(temp, -2);
//	minStackPush(temp, 0);
//	minStackPush(temp, -3);
//	int val = minStackGetMin(temp);
//	printf("%d ", val);
//	minStackPop(temp);
//	val = minStackTop(temp);
//	printf("%d ", val);
//	val = minStackGetMin(temp);
//	printf("%d ", val);
//
//	system("pause");
//	return 0;
//}