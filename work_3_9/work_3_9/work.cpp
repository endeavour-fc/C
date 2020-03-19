#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<math.h>
#include<queue>
using namespace std;
class Base
{
public:
	Base(int a=0,int c=0)
	{
		m_a = a;
		m_c = c;
		//cout << "this is base" << endl;
	}
	void fun()
	{
		//delete this;
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
	virtual void fun()
	{
		//delete this;
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
static int a = 0;
void  fun()
{
	static int a = 4;
}
void ch(char* arr)
{
	if (*arr)
	{
		ch(++arr);
		printf("%c", *arr);
	}
}
int main()
{
	Base *p = new D;
	p->fun();
	int i = 0;
	printf("%d%d", ++i, ++i);
	cout << endl;
	char arr[] = "Geneius";
	ch(arr);
	//cout << a << endl;
	return 0;
}
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
bool isPalindrome(string s) {
	string::iterator it1 = s.begin();
	string::iterator it2 = s.end() - 1;
	while (it1<it2)
	{
		while (it2 != it1)
		{
			if ((*it1 >= 'a'&&*it1 <= 'z') || (*it1 >= 'A'&&*it1 <= 'Z') || (*it1 >= '0'&&*it1 <= '9'))
				break;
			it1++;
		}
		if (it2 == it1)
			return true;
		while (it2 != it1)
		{
			if ((*it2 >= 'a'&&*it2 <= 'z') || (*it2 >= 'A'&&*it2 <= 'Z') || (*it2 >= '0'&&*it2 <= '9'))
				break;
			it2--;
		}
		if (it2 == it1)
			return true;
		if (*it1 == *it2 || (*it1 + 32) == *it2 || (*it2 + 32) == *it1)
			;
		else
			return false;
		it1++;
		it2--;
	}
	return true;
}
vector<int> GetNum(int num)
{
	int temp = sqrt(num);
	vector<int> v1;
	for (int i = 2; i <= temp; i++)
	{
		if (num%i == 0)
			v1.push_back(i);
		if (num / i != i)
			v1.push_back(num / i);
	}
	return v1;
}
string countAndSay(int n) {
	queue<char> que;
	string str("1");
	int i = 1;
	while (i != n)
	{
		string temp;
		string::iterator it = str.begin();
		while (it != str.end())
		{
			while (it != str.end()&&(que.empty() || *it == que.back()))
			{
				que.push(*it);
				it++;
			}
			char ch = que.size() +'0';
			temp+=ch;
			temp+=que.front();
			while (!que.empty())
			{
				que.pop();
			}
		}
		str = temp;
		i++;
	}
	return str;
}
void GetLuck(vector<int> arr, int len, int* sum)
{
	if (len == 0)
		return;
	int s = 0;
	int x = 1;
	for (int i = 0; i<len; i++)
	{
		s += arr[i];
		x *= arr[i];
		vector<int> v = arr;
		v.erase(v.begin() + i);
		GetLuck(v, len - 1, sum);
	}
	if (s > x)
		*sum += 1;

}
int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int sum = 0;
	int max = 0;
	vector<int>::iterator it = left.begin();
	for (int i = 0; i<n; i++)
	{
		if (left[i]>right[i])
		{
			sum += left[i];
			if (left[i]>max)
				max = left[i];
		}
		else
		{
			sum += right[i];
			if (right[i]>max)
				max = right[i];
		}
	}
	sum -= max;
	sum += 2;
	return sum;
}
//int main()
//{
//	vector<int> arr1 = { 0,7,1,6 };
//	vector<int> arr2 = { 1,5,0,6 };
//	cout << findMinimum(4,arr1, arr2)<<endl;
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int a[10] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	vector<int> arr(a, a + n);
//	int sum = 0;
//	for (int i = 0; i<n; i++)
//	{
//		for (int j = 0; j<n-i; j++)
//		{
//			vector<int> v = arr;
//			v.erase(v.begin() + j, v.begin() + j + i);
//			int s = 0;
//			int x = 1;
//			for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//			{
//				s += *it;
//				x *= (*it);
//			}
//			if (s>x)
//			{
//				(sum) += 1;
//				break;
//			}
//		}
//	}
//	//GetLuck(arr,n,&sum);
//	cout << sum << endl;
//
//
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int a[10] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	vector<int> arr(a,a+n);
//	int sum = 0;
//	GetLuck(arr, n, &sum);
//	cout << sum << endl;
//
//
//	return 0;
//}
//int main()
//{
//	cout << countAndSay(3) << endl;
//	return 0;
//}
//int main()
//{
//	int n1, n2;
//	while (cin >> n1 >> n2)
//	{
//		vector<int> v(n2 + 1, 0);
//		v[n1] = 1;
//		for (int i = n1; i<n2 + 1; i++)
//		{
//			if (v[i] == 0)
//				continue;
//			vector<int> temp = GetNum(i);
//			for (int j = 0; j<temp.size(); j++)
//			{
//				if (temp[j] + i <= n2 && v[i + temp[j]])
//				{
//					v[i + temp[j]] = min(v[i + temp[j]], v[i] + 1);
//				}
//				else if (temp[j] + i <= n2)
//					v[i + temp[j]] = v[i] + 1;
//			}
//		}
//		if (v[n2])
//			cout << v[n2] - 1 << endl;
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}
//int main()
//{
//	string s1("0P");
//	cout << isPalindrome(s1) << endl;
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	fun(++i, i++);
//	//K t = {};
//	//uint64_t x = 0x00010001;
//	//memcpy(&t, &x, sizeof(uint64_t));
//	//printf("%11u,%11u,%11u",t.a,t.b,t.c);
//	return 0;
//}
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
int lengthOfLongestSubstring(string s) {
	string::iterator it1 = s.begin();
	while (it1 != s.end() - 1)
	{
		if (*it1 == *(it1 + 1))
			it1=s.erase(it1++);
		else
			it1++;
	}
	int len = 0;
	int flag = 0;
	it1 = s.begin();
	string::iterator it2 = s.begin() + 1;
	while (it1 != s.end() - 1)
	{
		while (it2 != s.end())
		{
			if (*it1 == *it2)
			{
				int temp = it2 - it1-1;
				if (temp>len)
					len = temp;
				break;
			}
			it2++;
		}
		if (it2 == s.end())
		{
			int temp = s.end() - it1;
			if (temp>len)
				len = temp;
			break;
		}
		it1++;
		it2 = it1+1;
	}
	return len;

}
//int main()
//{
//	string s("abcabcbb");
//	cout << lengthOfLongestSubstring(s) << endl;
//
//	return 0;
//}
vector<int> GetNum1(int num)
{
	vector<int> arr;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
		{
			arr.push_back(i);
			if (i*i != num)
			{
				arr.push_back(num / i);
			}
		}
	}
	return arr;
}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 2; i <= n; i++)
//		{
//			vector<int> arr = GetNum1(i);
//			int sum = 0;
//			if (!arr.empty())
//			{
//				for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
//					sum += *it;
//			}
//			if (sum + 1 == i)
//				count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}