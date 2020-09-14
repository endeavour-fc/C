#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include <algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;



struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class A
{
public:
	A()
	{
		funA();
	}
	virtual void  funA()
	{
		cout << "A::funA()" << endl;
		funB();
	}
	virtual void funB()
	{
		cout << "A::funB()" << endl;
	}
	void funC()
	{
		cout << "A::funC()" << endl;
		funA();
	}
	~A()
	{
		cout << "A::~A()" << endl;
		funA();
	}
};

class B:public A
{
public:
	B()
	{
		funA();
	}
	virtual void funA()
	{
		cout << "B::funA()" << endl;
	}
	virtual void  funB()
	{
		cout << "B::funB()" << endl;
	}
	~B()
	{
		cout << "B::~B()" << endl;
		funA();
	}
};

//int main()
//{
//	A* p = new B;
//	cout << "+++++++++++++++++++" << endl;
//	p->funC();
//	delete p;
//	//system("pause");
//	return 0;
//}
void Quick_Sort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int temp = arr[left];
	if (i < j)
	{
		while (i < j)
		{
			while (i<j&&temp <= arr[j])
				--j;
			if (i < j)
				arr[i++] = arr[j];
			while (i<j&&temp >= arr[i])
				++i;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = temp;
		Quick_Sort(arr, left, i - 1);
		Quick_Sort(arr, i + 1, right);
	}
}
void Merge_Sort(int arr[], int left, int right, int mid, int* temp)
{
	int i_begin = left;
	int i_end = mid;
	int j_begin = mid + 1;
	int j_end = right;
	int len = 0;
	while (i_begin <= i_end && j_begin <= j_end)
	{
		if (arr[i_begin] > arr[j_begin])
			temp[len++] = arr[j_begin++];
		else
			temp[len++] = arr[i_begin++];
	}
	while (i_begin <= i_end)
	{
		temp[len++] = arr[i_begin++];
	}
	while (j_begin <= j_end)
	{
		temp[len++] = arr[j_begin++];
	}
	for (int i = 0; i < len; ++i)
		arr[left + i] = temp[i];
}
void Merge(int arr[], int left, int right, int* temp)
{
	if (right <= left)
		return;
	int mid = (left + right) / 2;
	Merge(arr, left, mid, temp);
	Merge(arr, mid+1, right, temp);
	Merge_Sort(arr, left, right, mid, temp);
}
void MakeBigHeap(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		int pre = i;
		int father = (i - 1) / 2;
		while (arr[pre] > arr[father])
		{
			swap(arr[pre], arr[father]);
			pre = father;
			father = (pre - 1) / 2;
		}
	}
}
void Heap(int arr[], int index,int len)
{
	int left = index*2+1;
	int right = index*2+2;
	int Max = 0;
	while (left < len)
	{
		if (right<len&&arr[right]>arr[left])
			Max = right;
		else
			Max = left;
		if (arr[index] >= arr[Max])
			return;
		swap(arr[index], arr[Max]);
		index = Max;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}
void Heap_Sort(int arr[], int len)
{
	MakeBigHeap(arr, len);
	while (len>1)
	{
		swap(arr[0], arr[len-- -1]);
		Heap(arr,0, len);
	}
}
void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int* Next(char* arr, int len)
{
	int* next = new int[10];
	*next = { 0 };
	int j = 0;
	for (int i = 2; i < len; ++i)
	{
		while (j&&arr[i - 1] != arr[j])
			j = next[j];
		if (arr[i - 1] == arr[j])
			++j;
		next[i] = j;
	}
	return next;
}
int KMP(char* long_string, char* short_string)
{
	int len1 = strlen(long_string);
	int len2 = strlen(short_string);
	int* next = Next(short_string, len2);
	int j = 0;
	for (int i = 0; i < len1; ++i)
	{
		while (j&&long_string[i] != short_string[j])
			j = next[j];
		if (long_string[i] == short_string[j])
			++j;
		if (j == len2)
			return i - j + 1;

	}
	return -1;
	
}
typedef enum { RED = 0, BLACK = 1 }Color_Type;

template<class Type>
class RBTree;

template<class Type>
class rb_iterator;

template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
	friend class rb_iterator<Type>;
public:
	RBTreeNode(const Type &d = Type())
		: data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr), color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type> *leftChild;
	RBTreeNode<Type> *rightChild;
	RBTreeNode<Type> *parent;
	Color_Type        color;
};

template<class Type>
class rb_iterator
{
	typedef rb_iterator<Type> self;
public:
	rb_iterator(RBTreeNode<Type> *p, RBTreeNode<Type> *nil, RBTreeNode<Type> *enode)
		: node(p), NIL(nil), end_node(enode)
	{}
	Type& operator*()
	{
		return node->data;
	}
	RBTreeNode<Type>* operator->()
	{
		return node;
	}

	self& operator++()
	{
		increment();
		return *this;
	}
	self operator++(int);
	self& operator--()
	{
		decrement();
		return *this;
	}
	self operator--(int);

	bool operator==(self & it)
	{
		return node == it.node;
	}
	bool operator!=(self & it)
	{
		return node != it.node;
	}
protected:
	void increment()
	{
		if (node->rightChild != NIL)
		{
			node = node->rightChild;
			if (node == end_node)
				return;
			while (node->leftChild != NIL)
				node = node->leftChild;
		}
		else
		{
			RBTreeNode<Type> *pr = node->parent;
			while (node == pr->rightChild)
			{
				node = pr;
				pr = node->parent;
			}
			node = pr;
		}
	}
	void decrement()
	{
		if (node->leftChild != NIL)
		{
			node = node->leftChild;
			while (node->rightChild != NIL)
				node = node->rightChild;
		}
		else
		{
			RBTreeNode<Type> *pr = node->parent;
			while (node == pr->leftChild)
			{
				node = pr;
				pr = node->parent;
			}
			node = pr;
		}
	}
private:
	RBTreeNode<Type> *node;
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *end_node;
};

template<class Type>
class RBTree
{
public:
	typedef rb_iterator<Type> iterator;
	RBTree() : root(NIL), NIL(_Buynode()), end_node(_Buynode())
	{
		NIL->parent = NIL->leftChild = NIL->rightChild = nullptr;
		NIL->color = BLACK;
		end_node->leftChild = end_node->rightChild = end_node->parent = NIL;
	}
public:
	iterator begin()
	{
		RBTreeNode<Type> *p = root;
		while (p != NIL && p->leftChild != NIL)
			p = p->leftChild;
		return iterator(p, NIL, end_node);
	}
	iterator end()
	{
		return iterator(end_node, NIL, end_node);
	}
	void set_endnode()
	{
		RBTreeNode<Type> *p = root;
		while (p != NIL && p->rightChild != NIL)
			p = p->rightChild;
		p->rightChild = end_node;
		end_node->parent = p;
	}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(RBTreeNode<Type> *&t, const Type &x);
	void Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
public:
	bool Remove(RBTreeNode<Type> *&t, const Type &key);
	void Remove_FixUp(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
protected:
	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
protected:
	RBTreeNode<Type>* _Buynode(const Type &x = Type())
	{
		RBTreeNode<Type> *s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = NIL;
		return s;
	}
private:
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *root;
	RBTreeNode<Type> *end_node;
};

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type> *&t, const Type &x)
{
	//1 根据bst的规则插入数据
	RBTreeNode<Type> *pr = NIL;
	RBTreeNode<Type> *s = t;
	while (s != NIL)
	{
		if (x == s->data)
			return false;
		pr = s;
		if (x < s->data)
			s = s->leftChild;
		else
			s = s->rightChild;
	}

	s = _Buynode(x);
	if (pr == NIL)
	{
		t = s;
		t->parent = NIL;
	}
	else if (x < pr->data)
		pr->leftChild = s;
	else
		pr->rightChild = s;
	s->parent = pr;

	//2 调整平衡
	Insert_Fixup(t, s);
	return true;
}

template<class Type>
void RBTree<Type>::Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
{
	while (x->parent->color == RED)
	{
		RBTreeNode<Type> *s;
		if (x->parent == x->parent->parent->leftChild)//左分支
		{
			s = x->parent->parent->rightChild;
			if (s->color == RED)
			{
				//状况三
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			else if (x == x->parent->rightChild)
			{
				//状况二
				x = x->parent;
				LeftRotate(t, x);
			}
			//状况一
			x->parent->color = BLACK;        //p
			x->parent->parent->color = RED;  //g
			RightRotate(t, x->parent->parent);
		}
		else //右分支
		{
			s = x->parent->parent->leftChild;
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			else if (x == x->parent->leftChild)
			{
				x = x->parent;
				RightRotate(t, x);
			}
			x->parent->color = BLACK;
			x->parent->parent->color = RED;
			LeftRotate(t, x->parent->parent);
		}
	}
	t->color = BLACK;
}

template<class Type>
bool RBTree<Type>::Remove(RBTreeNode<Type> *&t, const Type &key)
{
	//1 根据bst删除节点
	RBTreeNode<Type> *p = t, *q, *c;
	while (p != NIL && p->data != key)
	{
		if (key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if (p == NIL)
		return false;

	//把删除的节点化解为最终只有一个子女节点
	if (p->leftChild != NIL && p->rightChild != NIL)
	{
		q = p->rightChild;
		while (q->leftChild != NIL)
			q = q->leftChild;
	}
	else
		q = p;

	if (q->leftChild != NIL)
		c = q->leftChild;
	else
		c = q->rightChild;

	c->parent = q->parent;
	if (q->parent == NIL)
		t = c;
	else if (q = q->parent->leftChild)
		q->parent->leftChild = c;
	else
		q->parent->rightChild = c;

	if (p != q)
		p->data = q->data;

	//2 调整平衡
	if (q->color == BLACK)
		Remove_FixUp(t, c);
	delete q;
	return true;
}

template<class Type>
void RBTree<Type>::Remove_FixUp(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
{
	RBTreeNode<Type> *w; //兄弟节点
	while (x != t && x->color == BLACK)
	{
		if (x == x->parent->leftChild)
		{
			//左分支
			w = x->parent->rightChild;

			//情形四
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(t, x->parent);
				w = x->parent->rightChild;
			}

			//情形三
			if (w->leftChild->color == BLACK && w->rightChild->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				//情形二
				//if(w->leftChild->color == RED)
				if (w->rightChild->color == BLACK)
				{
					w->leftChild->color = BLACK;
					w->color = RED;
					RightRotate(t, w);
					w = x->parent->rightChild;
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->rightChild->color = BLACK;
				LeftRotate(t, x->parent);
				x = t;
			}
		}
		else
		{
			//右分支
			w = x->parent->leftChild;
			//情形四
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RightRotate(t, x->parent);
				w = x->parent->leftChild;
			}
			//情形三
			if (w->leftChild->color == BLACK && w->rightChild->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				//情形二
				if (w->leftChild->color == BLACK)
				{
					w->rightChild->color = BLACK;
					w->color = RED;
					LeftRotate(t, w);
					w = x->parent->leftChild;
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->leftChild->color = BLACK;
				RightRotate(t, x->parent);
				x = t;
			}
		}
	}
	x->color = BLACK;
}

template<class Type>
void RBTree<Type>::LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->rightChild;
	p->rightChild = s->leftChild;
	if (s->leftChild != NIL)
		s->leftChild->parent = p;
	s->parent = p->parent;
	if (p->parent == NIL)
		t = s;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->leftChild = p;
	p->parent = s;
}

template<class Type>
void RBTree<Type>::RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->leftChild;
	p->leftChild = s->rightChild;
	if (s->rightChild != NIL)
		s->rightChild->parent = p;
	s->parent = p->parent;
	if (p->parent == NIL)
		t = s;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->rightChild = p;
	p->parent = s;
}


//void main()
//{
//	vector<int> iv{ 10, 7, 8, 15, 5, 6, 11 };
//	//vector<int> iv {10, 7, 8};
//	RBTree<int> rb;
//	for (const auto &e : iv)
//		rb.Insert(e);
//
//	rb.Remove(10);
//
//}
//int main()
//{
//	int arr[] = { 2,1,4,0,6,7,9,3,8,5 };
//	int* temp = new int[10];
//	//Quick_Sort(arr, 0, 9);
//	//Merge(arr, 0, 9, temp);
//	//MakeBigHeap(arr, 10);
//	Heap_Sort(arr, 10);
//	PrintArr(arr, 10);
//
//	system("pause");
//	return 0;
//}


int orangesRotting(vector<vector<int>>& grid) {
	queue<pair<int, int>> que;
	int arr[3] = { -1,0,1 };
	int count = 0;
	for (int i = 0; i<grid.size(); ++i)
	{
		for (int j = 0; j<grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
				++count;
			if (grid[i][j] == 2)
				que.push({ i,j });
		}
	}
	int ret = 0;
	while (count&&!que.empty())
	{
		++ret;
		int n = que.size();
		for (int i = 0; i<n; ++i)
		{
			pair<int, int> temp = que.front();
			que.pop();
			for (int j = 0; j<3; ++j)
			{
				for (int k = 0; k<3; ++k)
				{
					if (arr[j] + temp.first<grid.size() && arr[j] + temp.first >= 0 && arr[k] + temp.second >= 0 && arr[k] + temp.second<grid[0].size() && grid[arr[j] + temp.first][arr[k] + temp.second] == 1&&abs(arr[j])!=abs(arr[k]))
					{
						que.push({ arr[j] + temp.first,arr[k] + temp.second });
						grid[arr[j] + temp.first][arr[k] + temp.second] = 2;
						--count;
					}
				}
			}
		}
	}
	if (count)
		return -1;
	return ret;
}

bool is_similar(string& s1, string& s2)
{
	int flag = 0;
	for (int i = 0; i<s1.size(); ++i)
	{
		if (s1[i] != s2[i])
			++flag;
		if (flag>1)
			return false;
	}
	return flag == 1;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	//set<string> st(wordList.begin(),wordList.end());
	if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
		return 0;
	queue<string> que;
	vector<bool> bl(wordList.size(), 0);
	que.push(beginWord);
	int count = 0;
	while (!que.empty())
	{
		++count;
		int size = que.size();
		for (int i = 0; i<size; ++i)
		{
			string temp = que.front();
			que.pop();
			for (int j = 0; j<wordList.size(); ++j)
			{
				if (bl[j])
					continue;
				if (!is_similar(wordList[j], temp))
					continue;
				if (wordList[j] == endWord)
					return count + 1;
				que.push(wordList[j]);
				bl[j] = true;
			}
		}
	}
	return 0;
}



class Solution_buildTree {
public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.empty() || inorder.empty())
			return NULL;

		return get(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* get(vector<int>& preorder, int pre_begin, int pre_end, vector<int>& inorder, int in_begin, int in_end)
	{
		if (pre_begin>pre_end || in_begin>in_end)
			return NULL;
		TreeNode* root = new TreeNode(preorder[pre_begin]);
		int pos = 0;
		for (int i = in_begin; i <= in_end; ++i)
		{
			if (inorder[i] == root->val)
			{
				root->left = get(preorder, pre_begin + 1, i - in_begin + pre_begin, inorder, in_begin, i - 1);
				root->right = get(preorder, i - in_begin + pre_begin + 1, pre_end, inorder, i + 1, in_end);
				break;
			}
		}
		return root;
	}
};

class Solution_buildTree2 {
public:
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty())
			return NULL;
		return get(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	TreeNode* get(vector<int>& inorder, int in_begin, int in_end, vector<int>& postorder, int pos_begin, int pos_end)
	{
		if (in_begin>in_end || pos_begin>pos_end)
			return NULL;
		int i = 0;
		for (i = in_begin; i <= in_end; ++i)
		{
			if (inorder[i] == postorder[pos_end])
				break;
		}
		TreeNode* root = new TreeNode(inorder[i]);
		root->left = get(inorder, in_begin, i - 1, postorder, pos_begin, i - in_begin + pos_begin - 1);
		root->right = get(inorder, i + 1, in_end, postorder, i - in_begin + pos_begin, pos_end - 1);
		return root;
	}
};
class Singleton1 {

private:
	static Singleton1* instance;

private:
	Singleton1() {
	}

public:
	static Singleton1* getInstance() {
		return instance;
	}
};
Singleton1* Singleton1::instance  = new Singleton1();

class Singleton2 {

private:
	static Singleton2* instance;

private:
	Singleton2() {
	}

public:
	static Singleton2* getInstance() {
		return instance;
	}
};
Singleton2* Singleton2::instance = new Singleton2();

class Solution_eraseOverlapIntervals {
public:
	static bool cmp(vector<int>& v1, vector<int>& v2)
	{
		return v2[1] >= v1[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int pre = 0;
		int ret = 1;
		for (int i = 1; i<intervals.size(); ++i)
		{
			if (intervals[pre][1] <= intervals[i][0])
			{
				++ret;
				pre = i;
			}
		}
		return intervals.size() - ret;
	}
};

//全错位排列
int findDerangement(int n)
{
	if (n <= 1)
		return 0;
	if (n == 2)
		return 1;
	int dp1 = 0;
	int dp2 = 1;
	for (int i = 3; i <= n; ++i)
	{
		swap(dp1, dp2);
		dp2 = (i - 1)*(dp1 + dp2);
	}
	return dp2;
}
int getvalue(int num)
{
	if (num == 1) return 0;
	else if (num == 2) return 1;
	else {
		int f1 = 0;
		int f2 = 1;
		for (int i = 3; i <= num; i++) {
			int temp = f2;
			f2 = (i - 1) * (f1 + f2);
			f1 = temp;
		}
		return f2;
	}
}
//int backPackII(int m, vector<int> &A, vector<int> &V) {
//	// write your code here
//	vector<int> dp(m + 1, 0);
//	for (int i = 1; i <= m; ++i)
//	{
//		for (int j = 0; j<A.size(); ++j)
//		{
//			if (i<A[j])
//			{
//				dp[i] = max(dp[i],dp[i-1]);
//			}
//			else
//			{
//				dp[i] = max(dp[i], V[j]);
//				dp[i] = max(dp[i - A[j]] + dp[A[j]], dp[i]);
//			}
//		}
//	}
//	return dp[m];
//}
int backPackII(int m, vector<int> &A, vector<int> &V) {
	// write your code here
	vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (A[i - 1]>j)
				dp[i][j] = dp[i - 1][j];
			else
			{

				dp[i][j] = max(dp[i - 1][j - A[i - 1]] + V[i - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[A.size()][m];
}
//int main()
//{
//	//vector<vector<int>> v = { {2,1,1},{0,1,1},{1,0,1} };
//	//cout << orangesRotting(v) << endl;
//	//set<int> st{ 2,1,4,3,5,8,6,7,9 };
//	//for (auto& e : st)
//	//	cout << e << endl;
//	vector<int> A = { 2, 3, 5, 7 };
//	vector<int> V = { 1, 5, 2, 4 };
//	cout << backPackII(10,A,V) << endl;
//
//
//	system("pause");
//	return 0;
//}

void get(vector<vector<int>>& v, vector<pair<int, int>>& ret, vector<pair<int, int>>& temp, int i, int j, int n, int& max)
{
	if (n<0)
		return;
	if (v[i][j] == 0)
		return;
	if (i == 0 && j == v[0].size() - 1)
	{
		if (max<n)
		{
			max = n;
			ret = temp;
		}
		return;
	}
	if (i + 1<v.size() && v[i + 1][j])
	{
		temp.push_back({ i + 1,j });
		get(v, ret, temp, i + 1, j, n, max);
		temp.pop_back();
	}
	if (j + 1<v[0].size() && v[i][j + 1])
	{
		temp.push_back({ i,j + 1 });
		get(v, ret, temp, i, j + 1, n - 1, max);
		temp.pop_back();
	}
	if (j - 1 >= 0 && v[i][j - 1])
	{
		temp.push_back({ i,j - 1 });
		get(v, ret, temp, i, j - 1, n - 1, max);
		temp.pop_back();
	}
	if (i - 1 >= 0 && v[i - 1][j])
	{
		temp.push_back({ i - 1,j });
		get(v, ret, temp, i - 1, j, n - 3, max);
		temp.pop_back();
	}
}

//int main()
//{
//	int raw, col = 0;
//	int n = 0;
//	cin >> raw >> col >> n;
//	vector<vector<int>> v(raw, vector<int>(col, 0));
//	vector<pair<int, int>> ret;
//	//pair<int, int> ret;
//	for (int i = 0; i<raw; ++i)
//	{
//		for (int j = 0; j<col; ++j)
//		{
//			cin >> v[i][j];
//		}
//	}
//	int max = -1;
//	vector<pair<int, int>> temp;
//	temp.push_back({ 0,0 });
//	get(v, ret, temp, 0, 0, n, max);
//	if (ret.size())
//	{
//		for (int i = 0; i<ret.size(); ++i)
//		{
//			cout << "[" << ret[i].first << "," << ret[i].second << "]";
//			if (i != ret.size() - 1)
//				cout << ",";
//		}
//	}
//	else
//		cout << "Can not escape!";
//	cout << endl;
//	return 0;
//}

int get(int num)
{
	int ret = 0;
	for (int i = 5; i <= num; i += 5)
	{
		int temp = i;
		while (temp % 5 == 0)
		{
			temp /= 5;
			++ret;
		}
	}
	return ret;
}
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		cout << get(num) << endl;
//	}
//
//	return 0;
//}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first<p2.first;
}

//int main()
//{
//	int n, m = 0;
//	while (cin >> n >> m)
//	{
//		vector<int> v(n, 0);
//		for (int i = 0; i<n; ++i)
//			cin >> v[i];
//		vector<pair<int, int>> p(m, { 0,0 });
//		for (int i = 0; i<m; ++i)
//		{
//			cin >> p[i].first >> p[i].second;
//		}
//		sort(p.begin(), p.end(), compare);
//		int ret = 0;
//		int flag = m;
//		vector<bool> bl(m+1, false);
//		for (int i = 0; i<n; ++i)
//		{
//			int temp = 0;
//			for (int j = 0; j<m; ++j)
//			{
//				if (bl[j])
//					continue;
//				if (v[i]<p[j].first)
//					break;
//				if (temp < p[j].second)
//				{
//					temp = p[j].second;
//					flag = j;
//				}
//			}
//			ret += temp;
//			bl[flag] = 1;
//			flag = m;
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}

//约瑟夫环
int fun(int m, int k, int i) {

	if (i == 1)
		return (m + k - 1) % m;
	else
		return (fun(m - 1, k, i - 1) + k) % m;

}
//int main()
//{
//
//	for (int i = 1; i <= 10; i++)
//		printf("第%2d次出环：%2d\n", i, fun(10, 3, i));
//	return 0;
//}

void Inversion(string& str, int i, int j)
{
	while (i<j)
	{
		swap(str[i++], str[j--]);
	}
}

//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		Inversion(str, 0, str.size() - 1);
//		int i = 0;
//		int j = 0;
//		while (i<str.size())
//		{
//			while (i<str.size() && str[i] != ' ')
//				++i;
//			Inversion(str, j, i - 1);
//			while (i<str.size() && str[i] == ' ')
//				++i;
//			j = i;
//		}
//		//Inversion(str, i, j - 1);
//		//Inversion(str, 0, str.size() - 1);
//		cout << str << endl;
//	}
//
//	return 0;
//}
class Solution_maxEvents {
public:
	static bool cmp(vector<int>& v1, vector<int>& v2)
	{
		return v1[1]<v2[1];
	}

	int maxEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end(), cmp);
		int pre = 0;
		int count = 0;
		for (int i = 1; i<events.size(); ++i)
		{
			if (events[pre][0]<events[i][0])
			{
				if (events[pre][1] <= events[i][0])
				{
					++count;
					pre = i;
				}
			}
		}
		return count;
	}
};
class Solution_smallestRangeII {
public:
	int smallestRangeII(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int ret = A[A.size() - 1] - A[0];
		for (int i = 0; i<A.size() - 1; ++i)
		{
			int hight = max(A[A.size() - 1] - K, A[i] + K);
			int low = min(A[0] + K, A[i + 1] - K);
			ret = min(ret, hight - low);
		}
		return ret;
	}
};



class Product
{
public:
	virtual ~Product() = 0;
protected:
	Product();
private:
};
class ConcreteProduct :public Product
{
public:
	~ConcreteProduct();
	ConcreteProduct();
protected:
private:
};


Product::Product()
{}
Product::~Product()
{}
ConcreteProduct::ConcreteProduct()
{
	cout << "ConcreteProduct...." << endl;
}
ConcreteProduct::~ConcreteProduct()
{}

class Product;

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;
protected:
	Factory();
private:
};
class ConcreteFactory :public Factory
{
public:
	~ConcreteFactory();
	ConcreteFactory();
	Product* CreateProduct();
protected:
private:
};

Factory::Factory()
{
}
Factory::~Factory()
{
}
ConcreteFactory::ConcreteFactory()
{
	cout << "ConcreteFactory....." << endl;
}
ConcreteFactory::~ConcreteFactory()
{
}
Product* ConcreteFactory::CreateProduct()
{
	return new ConcreteProduct();
}

//int main(int argc, char* argv[])
//{
//	Factory* fac = new ConcreteFactory();
//	Product* p = fac->CreateProduct();
//	return 0;
//}

void Reverse(string &str, int start, int end) {
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
string ReverseSentence(string str) {
	//先局部逆置，在整体逆置
	if (str.size() == 0) {
		return str;
	}
	int i = 0;
	int j = i;
	int len = str.size();
	while (i < len) {
		while (i < len && !isspace(str[i])) i++; //让i一直往后走，碰到第一个空格
		Reverse(str, j, i - 1); //逆置当前有效子串，我们采用闭区间
		while (i < len && isspace(str[i])) i++; //过滤所有空格，指向下一个有效子串的开始
			j = i; //保存起始位置
	}
	Reverse(str, 0, i - 1); //最后在整体逆置
	return str;
}



//int main()
//{
//	string str("my name is jane");
//	cout << ReverseSentence(str);
//
//	return 0;
//}

//template<typename T>
//bool isArray(T)
//{
//	return false;
//}

//template<typename T>
//bool isArray(T[])
//{
//	return true;
//}
//
//template<typename T>
//void copy(T[] src, T[] dest)
//{
//	for (int i = 0; i < src.size(); i++)
//	{
//		if (isArray(src[i])) //判断是否成员是数组
//		{
//			dest[i] = new T[src[i].size()];//将这个子数组插入到复制对象中
//			copy(src[i], dest[i]);//对对象子数组进行递归复制
//		}
//		else
//		{
//			dest[i] = src[i];//若不成员不是数组，则直接复制
//		}
//	}
//}
//int main()
//{
//	vector<int> v;
//	//int *arr = new int[v.size()];
//
//	//int a[] = { 1,2 };
//	//int b = 0;
//	//cout << isArray(a) << endl;
//	//cout << isArray(b) << endl;
//	return 0;
//}

int main5555()
{
	int n = 0;
	while (cin >> n)
	{
		int col, row = 0;
		cin >> col >> row;
		vector<vector<int>> v(col, vector<int>(row, 0));
		vector<vector<bool>> bl(col, vector<bool>(row, 0));
		for (int i = 0; i<col; ++i)
		{
			for (int j = 0; j<row; ++j)
				cin >> v[i][j];
		}
		queue<pair<int, int>> que;
		int flag = 0;
		que.push({ 0,0 });
		bl[0][0] = true;
		while (!que.empty())
		{
			int i = que.front().first;
			int j = que.front().second;
			if (i == col - 1 && j == row - 1)
			{
				if (v[i][j] == 1)
					flag = 1;
				break;
			}
			que.pop();
			if (i + n<col && !bl[i + n][j] && v[i + n][j])
			{
				que.push({ i + n,j });
				bl[i + n][j] = true;
			}
			if (i - n >= 0 && !bl[i - n][j] && v[i - n][j])
			{
				que.push({ i - n,j });
				bl[i - n][j] = true;
			}
			if (j + n<row && !bl[i][j + n] && v[i][j + n])
			{
				que.push({ i,j + n });
				bl[i][j + n] = true;
			}
			if (j - n >= 0 && !bl[i][j - n] && v[i][j - n])
			{
				que.push({ i,j - n });
				bl[i][j - n] = true;;
			}
		}
		if (flag == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}

	return 0;
}


int main11()
{
	string s;
	while (getline(cin, s))
	{
		vector<int> v;
		for (int i = 0; i<s.size(); ++i)
		{
			if (s[i] = '2')
			{
				v.push_back(20);
			}
			if (s[i] == '5')
			{
				v.push_back(5);
			}
			if (s[i] == '1')
			{
				v.push_back(10);
			}
		}
		int n5 = 0;
		int n10 = 0;
		int n20 = 0;
		int ret = 0;
		for (int i = 0; i<v.size(); ++i)
		{
			if (v[i] == 5)
			{
				++n5;
				++ret;
			}
			if (v[i] == 10)
			{
				if (n5)
				{
					--n5;
					++n10;
					++ret;
				}
				else
				{
					break;
				}
			}
			if (v[i] == 20)
			{
				int temp = 20;
				if (n10)
				{
					--n10;
					temp -= 10;
				}
				while (temp&&n5)
				{
					--n5;
					temp -= 5;
				}
				if (temp == 0)
				{
					++n20;
					++ret;
				}
			}
		}
		if (ret == v.size())
		{
			cout << "true" << "," << v.size() << endl;
		}
		else
		{
			cout << "false" << "," << ret + 1 << endl;
		}
	}

	return 0;
}


typedef string State;
class Observer;
class ConcreteObserverA;
class ConcreteObserverB;
class Subject
{
public:
	virtual ~Subject();
	virtual void Attach(Observer* obv);
	virtual void Detach(Observer* obv);
	virtual void Notify();
	virtual void SetState(const State& st) = 0;
	virtual State GetState() = 0;
protected:
	Subject();
private:
	list<Observer* >* _obvs;
};
class ConcreteSubject :public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();
	State GetState();
	void SetState(const State& st);
protected:

private:
	State _st;
};

Subject::Subject()
{
	//****在模板的使用之前一定要 new，创建
	_obvs = new list<Observer*>;
}
Subject::~Subject()
{

}
void Subject::Attach(Observer* obv)
{

	_obvs->push_front(obv);
}
void Subject::Detach(Observer* obv)
{
	if (obv != NULL)
		_obvs->remove(obv);
}
void Subject::Notify()
{
	list<Observer*>::iterator it;
	it = _obvs->begin();
	for (; it != _obvs->end(); it++)
	{
		//关于模板和 iterator 的用法
		(*it)->Update(this);
	}
}
ConcreteSubject::ConcreteSubject()
{
	_st = '\0';
}
ConcreteSubject::~ConcreteSubject()
{

}
State ConcreteSubject::GetState()
{
	return _st;
}
void ConcreteSubject::SetState(const State& st)
{
	_st = st;
}

class Observer
{
public:
	virtual ~Observer();
	virtual void Update(Subject* sub) = 0;
	virtual void PrintInfo() = 0;
protected:
	Observer();
	State _st;
private:
};
class ConcreteObserverA :public Observer
{
public:
	virtual Subject* GetSubject();

	ConcreteObserverA(Subject* sub);
	virtual ~ConcreteObserverA();
	//传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
	void Update(Subject* sub);
	void PrintInfo();
protected:
private:
	Subject * _sub;
};
class ConcreteObserverB :public Observer
{
public:
	virtual Subject* GetSubject();
	ConcreteObserverB(Subject* sub);

	virtual ~ConcreteObserverB();
	//传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
	void Update(Subject* sub);
	void PrintInfo();
protected:
private:
	Subject * _sub;
};

Observer::Observer()
{
	_st = '\0';
}
Observer::~Observer()
{
}
ConcreteObserverA::ConcreteObserverA(Subject* sub)
{
	_sub = sub;
	_sub->Attach(this);
}
ConcreteObserverA::~ConcreteObserverA()
{
	_sub->Detach(this);
	if (_sub != 0)
	{
		delete _sub;
	}
}
Subject* ConcreteObserverA::GetSubject()
{
	return _sub;
}
void ConcreteObserverA::PrintInfo()
{
	cout << "ConcreteObserverA observer...."<<_sub->GetState()<<endl;
}
void ConcreteObserverA::Update(Subject* sub)
{
	_st = sub->GetState();
	PrintInfo();
}
ConcreteObserverB::ConcreteObserverB(Subject* sub)
{
	_sub = sub;
	_sub->Attach(this);
}
ConcreteObserverB::~ConcreteObserverB()
{
	_sub->Detach(this);
	if (_sub != 0)
	{
		delete _sub;
	}
}
Subject* ConcreteObserverB::GetSubject()
{
	return _sub;
}
void ConcreteObserverB::PrintInfo()
{
	cout << "ConcreteObserverB observer...."<<_sub->GetState()<<endl;
}
void ConcreteObserverB::Update(Subject* sub)
{
	_st = sub->GetState();
	PrintInfo();
}

//int main(int argc, char* argv[])
//{
//	ConcreteSubject* sub = new ConcreteSubject();
//	Observer* o1 = new ConcreteObserverA(sub);
//	Observer* o2 = new ConcreteObserverB(sub);
//	sub->SetState("old");
//	sub->Notify();
//	sub->SetState("new"); //也可以由 Observer 调用
//	sub->Notify();
//	return 0;
//}





class AbstractProductA
{
public:
	virtual ~AbstractProductA();
protected:
	AbstractProductA();
private:
};
class AbstractProductB
{
public:
	virtual ~AbstractProductB();
protected:
	AbstractProductB();
private:
};
class ProductA1 :public AbstractProductA
{
public:
	ProductA1();
	~ProductA1();
protected:
private:
};
class ProductA2 :public AbstractProductA
{
public:
	ProductA2();
	~ProductA2();
protected:
private:
};
class ProductB1 :public AbstractProductB
{
public:
	ProductB1();
	~ProductB1();
protected:
private:
};
class ProductB2 :public AbstractProductB
{
public:
	ProductB2();
	~ProductB2();
protected:
private:
};
AbstractProductA::AbstractProductA()
{
}
AbstractProductA::~AbstractProductA()
{
}
AbstractProductB::AbstractProductB()
{
}
AbstractProductB::~AbstractProductB()
{
}
ProductA1::ProductA1()
{
	cout << "ProductA1..." << endl;
}
ProductA1::~ProductA1()
{
}
ProductA2::ProductA2()
{
	cout << "ProductA2..." << endl;
}
ProductA2::~ProductA2()
{
}
ProductB1::ProductB1()
{
	cout << "ProductB1..." << endl;
}
ProductB1::~ProductB1()
{
}
ProductB2::ProductB2()
{
	cout << "ProductB2..." << endl;
}
ProductB2::~ProductB2()
{
}
class AbstractProductA;
class AbstractProductB;
class AbstractFactory
{
public:
	virtual ~AbstractFactory();
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
protected:
	AbstractFactory();
private:
};
class ConcreteFactory1 :public AbstractFactory
{
public:
	ConcreteFactory1();
	~ConcreteFactory1();
	AbstractProductA* CreateProductA();
	AbstractProductB* CreateProductB();
protected:
private:
};
class ConcreteFactory2 :public AbstractFactory
{
public:
	ConcreteFactory2();
	~ConcreteFactory2();
	AbstractProductA* CreateProductA();
	AbstractProductB* CreateProductB();
protected:
private:
};

AbstractFactory::AbstractFactory()
{
}
AbstractFactory::~AbstractFactory()
{
}
ConcreteFactory1::ConcreteFactory1()
{
}
ConcreteFactory1::~ConcreteFactory1()
{
}
AbstractProductA* ConcreteFactory1::CreateProductA()
{
	return new ProductA1();
}
AbstractProductB* ConcreteFactory1::CreateProductB()
{
	return new ProductB1();
}
ConcreteFactory2::ConcreteFactory2()
{
}
ConcreteFactory2::~ConcreteFactory2()
{
}
AbstractProductA* ConcreteFactory2::CreateProductA()
{
	return new ProductA2();
}
AbstractProductB* ConcreteFactory2::CreateProductB()
{
	return new ProductB2();
}

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node * copyRandomList(Node* head) {
		unordered_map<Node*, Node*> mp;
		Node* pPre = head;
		while (pPre)
		{
			mp[pPre] = new Node(pPre->val);
			pPre = pPre->next;
		}
		pPre = head;
		while (pPre)
		{
			mp[pPre]->next = mp[pPre->next];
			mp[pPre]->random = mp[pPre->random];
			pPre = pPre->next;
		}
		return mp[head];
	}
};
class Solution_exist {
public:
	int arr[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	bool chack(vector<vector<char>>& board, string& word, vector<vector<bool>>& bl, int i, int j, int k)
	{
		if (board[i][j] != word[k])
			return false;
		if (k == word.size() - 1)
			return true;
		bl[i][j] = true;
		for (int m = 0; m<4; ++m)
		{
			int m_i = i + arr[m][0];
			int m_j = j + arr[m][1];
			if (m_i >= 0 && m_j >= 0 && m_i<board.size() && m_j<board[0].size() && !bl[m_i][m_j])
			{
				if (chack(board, word, bl, m_i, m_j, k + 1))
					return true;
			}
		}

		bl[i][j] = false;
		return false;

	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> bl(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[i].size(); ++j)
			{
				if (chack(board, word, bl, i, j, 0))
					return true;
			}
		}
		return false;
	}
};
int main(int argc, char* argv[])
{
	AbstractFactory* cf1 = new ConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();
	AbstractFactory* cf2 = new ConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();
	return 0;
}