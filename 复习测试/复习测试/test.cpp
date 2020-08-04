#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
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

int main()
{
	A* p = new B;
	cout << "+++++++++++++++++++" << endl;
	p->funC();
	delete p;
	//system("pause");
	return 0;
}
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
//int main()
//{
//	vector<vector<int>> v = { {2,1,1},{0,1,1},{1,0,1} };
//	cout << orangesRotting(v) << endl;
//
//	system("pause");
//	return 0;
//}