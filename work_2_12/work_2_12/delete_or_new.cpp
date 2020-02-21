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
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int Getnum(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int lf = Getnum(root->left);
	int rt = Getnum(root->right);
	return lf>rt ? lf + 1 : rt + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int sum = Getnum(root->left) + Getnum(root->right);
	int m1 = diameterOfBinaryTree(root->left);
	int m2 = diameterOfBinaryTree(root->right);
	if (sum>m1)
	{
		if (sum>m2)
		{
			return sum;
		}
		else
			return m2;
	}
	else
	{
		if (m1>m2)
		{
			return m1;
		}
		return m2;
	}
}
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int i = 0;
bool find(struct TreeNode* root, int k, int temp)
{
	if (root == NULL)
		return false;
	if (k == temp + root->val)
		return true;
	if (find(root->left, k, temp))
		return true;
	return find(root->right, k, temp);
}

bool findTarget(struct TreeNode* root, int k) {
	if (root == NULL)
		return false;
	if (root == 1 && k == 2)
		return false;
	if (find(root, k, root->val))
		return true;
	if (findTarget(root->left, k))
		return true;
	return findTarget(root->right, k);
}
void leaf(struct TreeNode* root, int* arr, int* len)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		arr[(*len)++] = root->val;
	}
	leaf(root->left, arr, len);
	leaf(root->right, arr, len);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
	int* arr1 = (int*)malloc(sizeof(int) * 80);
	int* arr2 = (int*)malloc(sizeof(int) * 80);
	int len1 = 0;
	int len2 = 0;
	int flag = 0;
	leaf(root1, arr1, &len1);
	leaf(root2, arr2, &len2);
	if (len1 != len2)
		return false;
	for (int i = 0; i<len1; i++)
	{
		if (arr1[i] == arr2[i]);
		else
			return false;
	}
	return true;
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
	String(const String& another):str(nullptr)
	{
		this->str = new char[another.len * 2 + 1];
		this->len = another.len;
		this->capacity = another.capacity;
		strncpy(str, another.str,this->len);
		str[len + 1] = '\0';
		//String s1(another.str);
		//this->Swap(s1);
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
//istream& operator>>(istream& is, String& s1)
//{
//	//is >> s1.str;
//	char arr[100] = { 0 };
//	is >> arr;
//	int i = 0;
//	char* temp = s1.str;
//	for (i = 0; i < 100; i++)
//	{
//		if (arr[i] == '\0')
//			break;
//	}                                                                                     
//	if (s1.capacity >= i)
//	{
//		s1.len = i;
//		strncpy(s1.str, arr, i+1);
//	}
//	else
//	{
//		s1.str = (char*)malloc(i*2);
//		s1.len = i;
//		s1.capacity = i*2;
//		strncpy(s1.str, arr, i+1);
//	}
//	return is;
//}
istream& operator>>(istream& is, String& s1)
{
	char* str1 = new char[10];
	int count = 1;
	int cpity = 10;
	char* temp = str1;
	while (((*temp = getchar()) == ' ') || (*temp == '\n'));
	while (1)
	{

		if(count>=cpity)
		{
			str1 = (char*)realloc(str1, cpity *= 2);
			temp = str1 + count-1;
		}
		else if ((*temp == ' ') || *temp == '\n')
		{
			*temp = '\0';
			break;
		}
		*++temp = getchar();
		count++;
	}
	s1.str = str1;
	s1.capacity = cpity;
	s1.len = count;
	return is;
	//static const size_t default_buf_size = 10;
	//int capacity = default_buf_size;
	//char *str = (char *)malloc(sizeof(char) * default_buf_size);
	//char *buf = str;

	//size_t count = 0;

	////跳过字符串起始位置的空格或者换行
	//while ((*buf = getchar()) == ' ' || (*buf == '\n'));

	//for (;;)
	//{
	//	if (*buf == '\n' || *buf == ' ')
	//	{
	//		*buf = '\0';
	//		break;
	//	}
	//	else if (count >= capacity)
	//	{
	//		capacity *= 2;
	//		str = (char *)realloc(str, capacity);
	//		//重新定位buf的位置
	//		buf = str + count;
	//	}
	//	*++buf = getchar();
	//	count++;
	//}

	//s1.str = str;
	//s1.capacity = capacity;
	//s1.len = count;
	//return is;

}
ostream& operator<<(ostream& os, String& s1)
{
	//for (size_t i = 0; i < s1.len; i++)
	//{
	//	os << s1.str[i];
	//}
	//os << endl;
	os <<s1.str<< endl;
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