#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<list>
#include<string>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int getnum(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int l = getnum(root->left);
	int r = getnum(root->right);
	return r>l ? r + 1 : l + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int ld = getnum(root->left);
	int rd = getnum(root->right);
	if (ld - rd>1 || rd - ld>1)
		return false;
	bool flag1 = isBalanced(root->left);
	bool flag2 = isBalanced(root->right);
	return flag1 && flag2;

}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return root;
	if (root == p || root == q)
		return root;
	struct TreeNode* r1 = lowestCommonAncestor(root->left, p, q);
	struct TreeNode* r2 = lowestCommonAncestor(root->right, p, q);
	if (r2 != NULL && r1 != NULL)
	{
		return root;
	}
	else if (r2 == NULL && r1 != NULL)
	{
		return r1;
	}
	else if (r1 == NULL && r2 != NULL)
	{
		return r2;
	}
	else
	{
		return NULL;
	}
}
using namespace std;
class test
{
public:
	test(int a1=0,int b1=0):a(a1),b(b1)
	{}
	~test()
	{}
	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<test>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;

	}
	void operator delete(void* p)
	{
		allocator<test>().deallocate((test*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
private:
	int a;
	int b;
};
class String
{
public:
	String(const char* temp)
	{
		this->len = strlen(temp);
		str = new char[strlen(temp)*2 + 1];
		this->capacity = this->len * 2 + 1;
		strcpy(str, temp);
		str[len + 1] = '\0';
	}
	String()
	{
		this->len = 0;
		str = new char[1];
		*(this->str) = '\0';
		this->capacity = 1;
	}
	String(const String& another)
	{
		this->str = new char[another.len * 2 + 1];
		this->len = another.len;
		this->capacity = another.capacity;
		strncpy(str, another.str,this->len);
		str[len + 1] = '\0';
	}
	~String()
	{
		if (str)
		{
			delete[] str;
			str = NULL;
		}
	}
	String&operator+=(String& another)
	{
		if(this->len + another.len >= this->capacity)
		{
			this->str = (char*)realloc(this->str, this->len + another.len + 10);
			this->capacity = this->len + 1 + 10;
		}
		strncat(this->str, another.str,another.len);
		this->len = another.len + this->len;
		str[len + 1] = '\0';
		return *this;
	}
	String&operator+=(const char* temp)
	{
		if(this->len + strlen(temp) >= this->capacity)
		{
			this->str = (char*)realloc(this->str, this->len + strlen(temp) + 10);
			this->capacity = this->len + 1 + 10;
		}
		this->len += strlen(temp);
		strcat(this->str, temp);
		str[len + 1] = '\0';
		return *this;
	}
	String&operator+=(const char temp)
	{
		if(this->len + 1 >= this->capacity)
		{
			this->str = (char*)realloc(this->str, this->len + 1 + 10);
			this->capacity = this->len + 1 + 10;
		}
		this->str[len] = temp;
		this->len += 1;
		str[len + 1] = '\0';
		return *this;
	}
	//String&operator=(const String& another)
	//{
	//	if (this != &another)
	//	{
	//		if (this->capacity < another.len)
	//		{
	//			delete[] this->str;
	//			this->str = new char[another.len * 2 + 1];
	//			this->len = another.len;
	//			this->capacity = another.len * 2 + 1;
	//		}
	//		strncpy(this->str, another.str, another.len);
	//	}
	//	return *this;
	//}
	void Swap(String& s2)
	{
		std::swap(str, s2.str);
		std::swap(capacity, s2.capacity);
		std::swap(len, s2.len);
	}
	String&operator=(const String& another)
	{
		if (this != &another)
		{
			String temp(another);
			this->Swap(temp);
		}
		return *this;
	}
	friend istream& operator>>(istream& is, String& s1);
	friend ostream& operator<<(ostream& os, String& s1);
private:
	char*str;
	size_t len;
	size_t capacity;
};
istream& operator>>(istream& is, String& s1)
{
	//is >> s1.str;
	char arr[100] = { 0 };
	is >> arr;
	int i = 0;
	char* temp = s1.str;
	for (i = 0; i < 100; i++)
	{
		if (arr[i] == '\0')
			break;
	}                                                                                     
	if (s1.capacity >= i)
	{
		s1.len = i;
		strncpy(s1.str, arr, i);
	}
	else
	{
		s1.str = (char*)malloc(i*2);
		s1.len = i;
		s1.capacity = i*2;
		strncpy(s1.str, arr, i);
	}
	return is;
}
ostream& operator<<(ostream& os, String& s1)
{
	for (size_t i = 0; i < s1.len; i++)
	{
		os << s1.str[i];
	}
	os << endl;
	return os;
}

int main()
{
	String s1;
	cin >> s1; 
	cout << s1;
	String s2;
	s2 = s1;
	cout << s2;
	String s3("dasfs");
	s3 += "xvvxfsdffffffffffffffffff";
	cout << s3;
	s3 += 'a';
	cout << s3;
	s3 += s2;
	cout << s3;



	//String s1("abcd");	//String s2(s1);	//String s3;	//s1 += "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";	//s3 += "fhcvbvcb";	//cout << s1 << s2<<s3;

	system("pause");
	return 0;
}