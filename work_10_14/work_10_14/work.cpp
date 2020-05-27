#include<iostream>
#include<stack>
using namespace std;
void move_num(int arr[], int len)
{
	if (arr == NULL || len == 0)
		return;
	int* pBegin = arr;
	int* pEnd = arr + len - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && (*pBegin & 1) != 0)
			pBegin++;
		while (pBegin < pEnd && (*pEnd & 1) == 0)
			pEnd--;
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	move_num(arr, len);
//	for (int i = 0; i < len; i++)
//		printf("%d ", arr[i]);
//	
//	system("pause");
//	return 0;
//}
template<typename T>
class AVLTree;


template<typename T>
class AVLNode
{
public:
	AVLNode(T& x = T()) :lchild(nullptr), rchild(nullptr), val(x),flag_bl(0)
	{}
	~AVLNode(){}
	friend class AVLTree<T>;
private:
	AVLNode<T>* lchild;
	AVLNode<T>* rchild;
	T val;
	int flag_bl;
};
template<typename T>
class AVLTree
{
public:
	void InsertNode(T& x)
	{
		insert(root, x);
	}
	AVLTree()
	{
		root = nullptr;
	}
private:
	AVLNode<T> * root;
private:

	void RotateR(AVLNode<T>*& p)
	{
		AVLNode<T>* s = p;
		p = p->rchild;
		s->rchild = p->lchild;
		p->lchild = s;
		p->flag_bl = s->flag_bl = 0;

	}
	void RotateL(AVLNode<T>*& p)
	{
		AVLNode<T>* s = p;
		p = p->lchild;
		s->lchild = p->rchild;
		p->rchild = s;
		p->flag_bl = s->flag_bl = 0;

	}
	void RotateLR(AVLNode<T> *&ptr)
	{
		AVLNode<T> *subL = ptr->lchild;
		AVLNode<T> *subR = ptr;
		ptr = subL->rchild;
		//先左转
		subL->rchild = ptr->lchild;
		ptr->lchild = subL;
		//subL bf
		if (ptr->flag_bl == 1)
			subL->flag_bl = -1;
		else
			subL->flag_bl = 0;
		//后右转
		subR->lchild = ptr->rchild;
		ptr->rchild = subR;
		//subR bf
		if (ptr->flag_bl == -1)
			subR->flag_bl = 1;
		else
			subR->flag_bl = 0;
		ptr->flag_bl = 0;
	}
	void RotateRL(AVLNode<T> *&ptr)
	{
		AVLNode<T> *subL = ptr;
		AVLNode<T> *subR = ptr->rchild;
		ptr = subR->lchild;
		//先右转
		subR->lchild = ptr->rchild;
		ptr->rchild = subR;
		//subR bf
		if (ptr->flag_bl >= 0)
			subR->flag_bl = 0;
		else
			subR->flag_bl = 1;
		//后左转
		subL->rchild = ptr->lchild;
		ptr->lchild = subL;
		//subL bf
		if (ptr->flag_bl <= 0)
			subL->flag_bl = 0;
		else
			subL->flag_bl = -1;
		ptr->flag_bl = 0;
	}
	bool insert(AVLNode<T>*& t, T& x)
	{
		AVLNode<T>* pre = nullptr;
		AVLNode<T>* s = t;
		stack<AVLNode<T>*> sta;
		while (s)
		{
			pre = s;
			sta.push(s);
			if (s->val < x)
				s = s->rchild;
			else if (s->val > x)
				s = s->lchild;
			else
				return false;
		}
		s = new AVLNode<T>(x);
		if (pre == nullptr)
		{
			t = s;
			return true;
		}
		if (pre->val > x)
			pre->lchild = s;
		else
			pre->rchild = s;

		while (!sta.empty())
		{
			pre = sta.top();
			sta.pop();
			if (pre->lchild == s)
				pre->flag_bl--;
			else
				pre->flag_bl++;
			if (pre->flag_bl == 0)
				return true;
			if (pre->flag_bl == -1 || pre->flag_bl == 1)
				s = pre;
			else
			{
				if (pre->flag_bl > 0)
				{
					if (s->flag_bl > 0)
					{
						RotateR(pre);
					}
					else
					{
						RotateLR(pre);
					}
				}
				else
				{
					if (s->flag_bl < 0)
					{
						RotateL(pre);
					}
					else
					{
						RotateRL(pre);
					}
				}
				break;
			}

		}
		if(sta.empty())
		{
			t = pre;
		}
		else
		{
			AVLNode<T>* temp = sta.top();
			if (temp->val > pre->val)
				temp->lchild = pre;
			else
				temp->rchild = pre;
		}
		return true;
	}
};

int main()
{
	AVLTree<int> t;
	for (int i = 0; i < 5; i++)
		t.InsertNode(i);

	system("pause");
	return 0;
}