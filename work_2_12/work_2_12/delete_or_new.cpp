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
	}
	String()
	{
		this->len = 0;
		str = new char[1];
		*(this->str) = '\0';
		this->capacity = 1;
	}
	String(String& another)
	{
		this->str = new char[another.len * 2 + 1];
		this->len = another.len;
		this->capacity = this->len * 2 + 1;
		strcpy(str, another.str);
	}
	~String()
	{}
	String&operator+=(String& another)
	{
		if(this->len + another.len > this->capacity)
		{
			this->str = (char*)realloc(this->str, this->len + another.len + 10);
			this->capacity = this->len + 1 + 10;
		}
		this->len = another.len+this->len;
		strcat(this->str, another.str);
		return *this;
	}
	String&operator+=(const char* temp)
	{
		if(this->len + strlen(temp) > this->capacity)
		{
			this->str = (char*)realloc(this->str, this->len + strlen(temp) + 10);
			this->capacity = this->len + 1 + 10;
		}
		this->len += strlen(temp);
		strcat(this->str, temp);
		return *this;
	}
	String&operator+=(const char temp)
	{
		if(this->len + 1 > this->capacity)
		{
			this->str = (char*)realloc(this->str, this->len + 1 + 10);
			this->capacity = this->len + 1 + 10;
		}
		this->str[len] = temp;
		this->len += 1;
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
	is >> s1.str;
	int i = 0;
	char* temp = s1.str;
	while (*temp != '\n')
	{
		temp++;
		i++;
	}
	if (s1.capacity >= i)
	{

	}
	else
	{
		delete[] s1.str;
		s1.str = NULL;
		s1.len = i;
		s1.str = new char[s1.len * 2 + 1];
		s1.capacity = s1.len * 2 + 1;
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
	String s1("abcd");	String s2(s1);	String s3;	s1 += "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";	s3 += "fhcvbvcb";	cout << s1 << s2<<s3;
	system("pause");
	return 0;
}