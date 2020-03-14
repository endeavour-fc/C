#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<iostream>
using namespace std;
class Base
{
public:
	Base(int a=0,int c=0)
	{
		m_a = a;
		m_c = c;
		cout << "this is base" << endl;
	}
	virtual void fun()
	{
		cout << "this is base" << endl;
	}
	void test()
	{
		fun();
	}
	int Geta()
	{
		return m_a;
	}
	int Getc()
	{
		return m_c;
	}
private:
	int m_a;
	int m_c;
};
class D: public Base
{
public:
	void fun()
	{
		cout << "this is D" << endl;
	}
private:
	int b;
};
class A
{
private:
	//static int a;

};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* change(ListNode* root)
{
	if (root == NULL || root->next == NULL)
		return root;
	ListNode* temp = NULL;
	ListNode* pPre = root;
	ListNode* pCur = root->next;
	while (pPre)
	{
		pPre->next = temp;
		temp = pPre;
		pPre = pCur;
		if (pCur == NULL)
			return temp;
		pCur = pCur->next;
	}
	return NULL;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1 && !l2)
		return NULL;
	if (!l1 || !l2)
	{
		return l1 ? l1 : l2;
	}
	ListNode* m1 = l1 = change(l1);
	ListNode* m2 = l2 = change(l2);
	int cn = 0;
	int sum = 0;
	int flag = 0;
	ListNode* k = NULL;
	while (l1&&l2)
	{
		sum = l1->val + l2->val + cn;
		cn = 0;
		if (sum >= 10)
			cn = 1;
		l1->val = sum % 10;
		l2->val = sum % 10;
		k = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		sum = l1->val + cn;
		cn = 0;
		if (sum >= 10)
			cn = 1;
		l1->val = sum % 10;
		flag = 0;
		k = l1;
		l1 = l1->next;
	}
	while (l2)
	{
		sum = l2->val + cn;
		cn = 0;
		if (sum >= 10)
			cn = 1;
		l2->val = sum % 10;
		k = l2;
		l2 = l2->next;
		flag = 1;
	}
	if (cin)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = 1;
		temp->next = NULL;
		k->next = temp;

	}
	if (flag)
		return change(m2);
	else
		return change(m1);
}
ListNode* Init_Node()
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = 0;
	temp->next = NULL;
	return temp;
}
ListNode* CreatNode(int a)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = a;
	temp->next = NULL;
	return temp;
}
void Insert_Head_List(ListNode* head, ListNode* inhl)
{
	if (head == NULL || inhl == NULL)
		return;
	inhl->next = head->next;
	head->next = inhl;
}
void Print_Node(ListNode* head)
{
	if (head == NULL)
		return;
	for (ListNode* temp = head->next; temp != NULL; temp = temp->next)
		printf("%d->", temp->val);
	printf("\n");
}
struct K
{
	uint16_t a;
	uint32_t b;
	uint64_t c;
};
void fun(int& x, int& y)
{
	cout << x << endl;
	cout << y << endl;
}
int main()
{
	int i = 0;
	fun(++i, i++);
	//K t = {};
	//uint64_t x = 0x00010001;
	//memcpy(&t, &x, sizeof(uint64_t));
	//printf("%11u,%11u,%11u",t.a,t.b,t.c);
	return 0;
}
//int main()
//{
//	ListNode* head1 = Init_Node();
//	ListNode* head2 = Init_Node();
//	for (int i = 1; i <=5; i++)
//	{
//		ListNode* temp = CreatNode(i);
//		Insert_Head_List(head1, temp);
//	}
//	for (int i = 1; i <= 5; i++)
//	{
//		ListNode* temp = CreatNode(i);
//		Insert_Head_List(head2, temp);
//	}
//	Print_Node(head1);
//	Print_Node(head2);
//	ListNode* head = addTwoNumbers(head1, head2);
//	Print_Node(head);
//
//	return 0;
//}
//bool is_prime_number_or_not(int num)
//{
//	if (num == 1)
//		return false;
//	if (num == 2)
//		return true;
//	int i = sqrt(num);
//	while (i >= 2)
//	{
//		if (num%i == 0)
//			return false;
//		--i;
//	}
//	return true;
//}
//int main()
//{
//	int num = 0;
//	int n1 = 0;
//	int n2 = 0;
//	while (cin >> num)
//	{
//		int n1 = num / 2;
//		int n2 = num - n1;
//		while (1)
//		{
//			if (is_prime_number_or_not(n1) && is_prime_number_or_not(n2))
//			{
//				cout << n1 << endl;
//				cout << n2 << endl;
//				break;
//			}
//			n1--;
//			n2 = num - n1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	D* p = new D;
//	p->test();
//
//	return 0;
//}
// static Safelevel GetPwdSecurityLevel(string pPasswordStr)
//{
//	string::iterator it = pPasswordStr.begin();
//	int sum = 0;
//	if (pPasswordStr.size() <= 4)
//		sum += 5;
//	else if (pPasswordStr.size() <= 7)
//		sum += 10;
//	else
//		sum += 25;
//	int num_flag = 0;
//	int str[2] = { 0 };
//	int symbol = 0;
//	while (it != pPasswordStr.end())
//	{
//		if (*it >= 'a'&&*it <= 'z')
//			str[0]++;
//		else if (*it >= 'A'&&*it <= 'Z')
//			str[1]++;
//		else if (*it >= '0'&&*it <= '9')
//			num_flag++;
//		else
//			symbol++;
//		it++;
//	}
//	if (str[1] && str[0])
//		sum += 20;
//	else if (str[0] || str[1])
//		sum += 10;
//
//	if (num_flag>1)
//		sum += 20;
//	else if (num_flag)
//		sum += 10;
//	if (symbol>1)
//		sum += 25;
//	else if (symbol)
//		sum += 10;
//	if (str[0] && str[1] && num_flag&&symbol)
//		sum += 5;
//	else if ((str[0] || str[1]) && num_flag&&symbol)
//		sum += 3;
//	else if ((str[0] || str[1]) && num_flag)
//		sum += 2;
//	if (sum >= 90)
//		cout << "VERY_SECURE" << endl;
//	else if (sum >= 80)
//		cout << "SECURE" << endl;
//	else if (sum >= 70)
//		cout << "VERY_STRONG" << endl;
//	else if (sum >= 60)
//		cout << "STRONG" << endl;
//	else if (sum >= 50)
//		cout << "AVERAGE" << endl;
//	else if (sum >= 25)
//		cout << "WEAK" << endl;
//	else
//		cout << "VERY_WEAK" << endl;
//
//	return NULL;
//}
//int getLCA(int a, int b) {
//	if (a == 0 || b == 0)
//		return 0;
//	if (a == b)
//		return a;
//
//	int left = getLCA((a) / 2, b);
//	int right = getLCA(a, (b) / 2);
//	if (left)
//		return left;
//	if (right)
//		return right;
//	return 0;
//
//}
//int main()
//{
//	//int** arr[3][4] = { 0 };
//	cout <<getLCA(4,5) << endl;
//}
//int main()
//{
//	string s1;
//	getline(std::cin, s1);
//	string::iterator it = s1.begin();
//	int sum = 0;
//	if (s1.size() <= 4)
//		sum += 5;
//	else if (s1.size() <= 7)
//		sum += 10;
//	else
//		sum += 25;
//	int num_flag = 0;
//	int str[2] = { 0 };
//	int symbol = 0;
//	while (it != s1.end())
//	{
//		if (*it >= 'a'&&*it <= 'z')
//			str[0]++;
//		else if (*it >= 'A'&&*it <= 'Z')
//			str[1]++;
//		else if (*it >= '0'&&*it <= '9')
//			num_flag++;
//		else
//			symbol++;
//		it++;
//	}
//	if (str[1] && str[0])
//		sum += 20;
//	else if (str[0] || str[1])
//		sum += 10;
//
//	if (num_flag>1)
//		sum += 20;
//	else if (num_flag)
//		sum += 10;
//	if (symbol>1)
//		sum += 25;
//	else if (symbol)
//		sum += 10;
//	if (str[0] && str[1] && num_flag&&symbol)
//		sum += 5;
//	else if ((str[0] || str[1]) && num_flag&&symbol)
//		sum += 3;
//	else if ((str[0] || str[1]) && num_flag)
//		sum += 2;
//	if (sum >= 90)
//		cout << "VERY_SECURE" << endl;
//	else if (sum >= 80)
//		cout << "SECURE" << endl;
//	else if (sum >= 70)
//		cout << "VERY_STRONG" << endl;
//	else if (sum >= 60)
//		cout << "STRONG" << endl;
//	else if (sum >= 50)
//		cout << "AVERAGE" << endl;
//	else if (sum >= 25)
//		cout << "WEAK" << endl;
//	else
//		cout << "VERY_WEAK" << endl;
//
//	return 0;
//}
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	return 0;
//}
//int getnum(int num1, int num2)
//{
//	if (num1 == 0 || num2 == 0)
//		return 1;
//	return getnum(num1 - 1, num2) + getnum(num1, num2 - 1);
//}
//
//int main()
//{
//	int n, m;
//	cin >> n;
//	cin >> m;
//	cout << getnum(n,m);
//	//system("pause");
//	return 0;
//}
//
//int count_step(int n, int m)
//{
//	if (m == 0 || n == 0)
//		return 0;
//	if (n == 1 && m >= 1)
//		return m + 1;
//	if (m == 1 && n >= 1)
//		return n + 1;
//	if (m>1 && n>1)
//		return count_step(n - 1, m) + count_step(n, m - 1);
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a;
//	cin >> b;
//	cout << getnum(a, b) << endl;
//
//	return 0;
//}
//int main()
//{
//	Base b1(5, 10);
//	int* p = (int*)(&b1);
//	*(p) = 100;
//	*(p + 1) = 200;
//	cout << b1.Geta() << b1.Getc() << endl;
//
//	system("pause");
//	return 0;
//}
//int main()
//{
//	Base a(4), b(5), c[3], *p[2] = { &a,&b };
//	
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	cin >> num1;
//	cin >> num2;
//	if (num1%num2 == 0 || num2%num1 == 0)
//	{
//		cout << (num1>num2 ? num1 : num2) << endl;
//		return 0;
//	}
//	if (num1 % 2 == 0 && num2 % 2 == 0)
//	{
//		while (num2%num1 == 0)
//		{
//			num2 *= 2;
//		}
//		cout << num2 << endl;
//		return 0;
//	}
//	else if (num1 % 2 == 1 && num2 % 2 == 1)
//	{
//		cout << num1 * num2 << endl;
//		return 0;
//	}
//	else
//	{
//		if (num1 % (num1>num2 ? num1 : num2) % (num1<num2 ? num1 : num2) == 0)
//		{
//			int temp =( num1>num2 ? num1 : num2) % (num1<num2 ? num1 : num2);
//			int sum = 1;
//			for (int i = 1; sum%num1 != 0 || sum % num2 != 0;i++)
//			{
//				sum = temp * i;
//			}
//			cout <<sum << endl;
//		}
//		else
//		{
//			cout << num1 * num2 << endl;
//			return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}