#include<iostream> 
#include<string> 
#include<vector>
#include<stdio.h>
#include<stack>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
//#define x        ((x>> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);
class MyData 
{     public:
       int  GetData()
       {
           return this->data;
       }
        void SetData(int num)        {
           this->data=num;
        }
        MyData()
        {
            this->data=0;
        }
       MyData(int num)
        {
          this->data=num;
        }
        ~MyData()
        {
  
       }
     private:
        int data;
 };
#define      N       3
#define      Y(n)       ( (N+1)*n)

int  fa(int  x) { return  x * x; }
int  fb(int  x) { return  x * x*x; }
int  f(int(*f1)(int), int(*f2)(int), int x)
{
	return f2(x) - f1(x);
}

void Foo()
{
	long  x = 0x12345678;
	int  y;
	for (y = 0; x = (x&(x - 1));) {
		y += 1000;
	}
	printf("%d", y);
}
class BASE {
	char c;
public:
	BASE(char n) :c(n) {}
	virtual ~BASE() { cout << c; }
	virtual void foo() { cout << c; }
};
class DERIVED : public BASE {
	char c;
public:
	DERIVED(char n) :BASE(n + 1), c(n) {}
	~DERIVED() { cout << c; }
	void foo() { cout << (char)(c + 2); }
};
void rlt1()
{
	DERIVED d('X');
	return;
}
void rlt2()
{
	DERIVED d('X');
	BASE *b = &d;
	b->foo();
	return;
}

//int main()
//{
//	char *pstr=(char*)malloc(sizeof(char) * 8);                              //3                              //4
//	printf("%s", pstr);                         //5
//	strcpy(pstr, "123456789");                  //6
//	cout << endl;
//	printf("%s", pstr);                         //7
//	for (int i = 0; i<10; ++i);
//
//	//rlt1();
//	//cout << endl;
//	//rlt2();
//	//int  i;
//	//i = f(fa, fb, 2);
//	//printf("%d\n", i);
//	//Foo();
//	//int x=1 , y=1 , z = 1;
//	//int t = ++x || ++y&&++z;
//	//cout << t << endl;
//	//int x = 0;
//	//int y = 0;
//	//for (y = 1, x = 1; y <= 50; y++)
//	//{
//	//	if (x >= 10) break;
//	//	if (x % 2 == 1)
//	//	{
//	//		x += 5;
//	//		continue;
//	//	}
//	//	x -= 3;
//	//}
//
//	//cout << 2 * (N + Y(5 + 1)) << endl;
//	//int arr[] = { 6,7,8,9,10 };    
//	//int * ptr = arr;
//	//*(ptr + 2) += 2;
//	//printf("%d,%d\n", *ptr, *(ptr + 2));
//	//enum  em { eml = 3, em2 = 1, em3 };
//	//const char*  aa[] = { "TT","MM","FF","SS" };
//	//printf("%s%s%s\n",aa[eml],aa[em2],aa[em3]);
//
//
//
//	system("pause");
//
//	return 0;
//}

class CGoods
 {
     public:
         void RegisterGoods(string name,int count, float price)
        {
            this->name=name;
            this->count=count;
            this->price=price;
        }

         void SetName(string name) 
			{  
			 this->name=name;
          }
         void SetCount(int count)
        {
             this->count=count;
         }
         void SetPrice(float price)
         {
            this->price=price;
         }
         string GetName()
         {
             return this->name;
         }
         int GetCount()
         {
            return this->count;
         }
         float GetPrice()
         {
                       return this->price;
         }
         float GetTotal_price()
         {
             return this->count*this->price;
        }
     private:
         string name;
         int count;
        float price;
         float total_price;
  
 };
 //int main()
 //{
 //  //  MyData d1,d2;
 //  CGoods g1,g2;
 //  g1.RegisterGoods("abc",15,12.4);
 // cout<< g1.GetName()<<endl;
 // cout<< g1.GetCount()<<endl;
 // cout<< g1.GetPrice()<<endl;
 // cout << g1.GetPrice() << endl;
 // g1.SetName("bcd");
 // cout << g1.GetName() << endl;
 //    return 0;
 //}
int min(int a, int b)
{
	return a > b ? b : a;
}
int minSubArrayLen(int s, vector<int>& nums) {
	for (int i = 1; i<nums.size(); ++i)
		nums[i] += nums[i - 1];
	int ret = INT_MAX;
	nums.insert(nums.begin(), 0);
	for (int i = 1; i<nums.size(); ++i)
	{
		for (int j = 0; j<i; ++j)
		{
			if (nums[i] - nums[j] >= s)
			{
				ret = min(ret, i - j);
			}
		}
	}
	return ret == INT_MAX ? 0 : ret;
}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5};
//	cout<<minSubArrayLen(11, v)<<endl;
//
//	system("pause");
//	return 0;
//}
void stringtonum(string str)
{
	vector<string> v;
	int begin = 0;
	int end = 0;
	while (begin < str.size())
	{
		end = str.find(' ',begin);
		v.push_back(str.substr(begin, end - begin));
		if (end == -1)
			break;
		begin = end + 1;
	}

	for (auto& e : v)
	{
		cout << e << endl;
	}
}
//int main()
//{
//
//	stringtonum("12 13 15 27 18 30");
//
//	system("pause");
//	return 0;
//}
bool isequal(vector<int>& v)
{
	for (int i = 1; i<v.size(); ++i)
	{
		if (v[i] != v[i - 1])
			return false;
	}
	return true;
}
int getmax(vector<int>& v)
{
	int max = 0;
	int ret = 0;
	for (int i = 0; i<v.size(); ++i)
	{
		if (v[i]>max)
		{
			max = v[i];
			ret = i;
		}
	}
	return ret;
}
void addone(vector<int>& v, int flag)
{
	for (int i = 0; i<v.size(); ++i)
	{
		if (i != flag)
		{
			++v[i];
		}
	}
}

//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> v(n, 0);
//		for (int i = 0; i<n; ++i)
//			cin >> v[i];
//		int num = 0;
//		while (!isequal(v))
//		{
//			int flag = getmax(v);
//			addone(v, flag);
//			++num;
//		}
//		cout << num << endl;
//	}
//
//	return 0;
//}
void reverseString(string &s)
{
	int i, j;
	for (i = 0, j = s.size() - 1; i < j; ++i, --j)
	{
		swap(s[i], s[j]);
	}
}
int main()
{
	string str;
	stack<char> st;
	while (cin >> str)
	{
		//cout << str << endl;
		if (str == "=")
		{
			string strnum1;
			string strnum2;
			char ch = '+';
			while (!st.empty()&&st.top()<='9'&&st.top()>='0')
			{
				strnum1 += st.top();
				st.pop();
			}
			if (!st.empty())
			{
				ch = st.top();
				st.pop();
			}
			while (!st.empty())
			{
				strnum2 += st.top();
				st.pop();
			}
			if (strnum1.size() && strnum2.size())
			{
				reverseString(strnum1);
				reverseString(strnum2);
				int num1 = atoi(strnum2.c_str());
				int num2 = atoi(strnum1.c_str());
				if (ch == '+')
					cout << num1 + num2 << endl;
				else if (ch == '-')
					cout << num1 - num2 << endl;
				else if (ch == '*')
					cout << num1 * num2 << endl;
				else if (ch == '/')
				{
					if (num2 == 0)
						cout << "err" << endl;
					else
						cout << num1 / num2 << endl;
				}
				else
					cout << "err" << endl;
			}
		}
		else if (!st.empty()&&(str == "+" || str == "-" || str == "*" || str == "/"))
		{
			st.push(str[0]);
		}
		else if (!st.empty()&&str == "<-")
		{
			st.pop();
		}
		else if (str == "ce")
		{
			stack<char> temp;
			swap(temp, st);
		}
		else if (st.empty() || (st.top() == '-'||st.top() == '*'||st.top() == '/'||st.top() == '+'))
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] >= '0'&&str[i] <= '9')
				{
					st.push(str[i]);
				}
				else
				{
					while (!st.empty() && !(st.top() == '-' || st.top() == '*' || st.top() == '/' || st.top() == '+'))
					{
						st.pop();
					}
					break;
				}
			}
		}
		else
		{
			stack<char> temp;
			swap(temp, st);
		}
	}

	return 0;
}

class Solution_longestPalindrome {
public:
	int longestPalindrome(string s) {
		int arr[256] = { 0 };
		for (int i = 0; i<s.size(); ++i)
		{
			++arr[s[i]];
		}
		int ret = 0;
		for (int i = 0; i<256; ++i)
		{
			ret += (arr[i] / 2) * 2;
			if (ret % 2 == 0 && arr[i] % 2 == 1)
				++ret;
		}
		return ret;
	}
};

class Solution_findContinuousSequence {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> v;
		int i = 1;
		int j = 1;
		int sum = 0;
		while (i <= target / 2 + 1)
		{
			if (sum<target)
			{
				sum += j;
				++j;
			}
			else if (sum>target)
			{
				sum -= i;
				++i;
			}
			else
			{
				vector<int> temp;
				for (int k = i; k<j; ++k)
					temp.push_back(k);
				v.push_back(temp);
				sum += j;
				sum -= i;
				++i;
				++j;
			}
		}
		return v;
	}
};