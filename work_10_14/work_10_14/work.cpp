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
private:
	AVLNode<T> * root;
private:

	AVLNode<T>* RotateR(AVLNode<T>*& p)
	{
		AVLNode<T>* s = p;
		p = p->rchild;
		s->rchild = p->lchild;
		p->lchild = s;
		s->flag_bl = (s->rchild->flag_bl - s->lchild->flag_bl);
		p->flag_bl = (p->rchild->flag_bl - p->lchild->flag_bl);
		return p;
	}
	AVLNode<T>* RotateL(AVLNode<T>*& p)
	{
		AVLNode<T>* s = p;
		p = p->lchild;
		s->lchild = p->rchild;
		p->rchild = s;
		s->flag_bl = (s->rchild->flag_bl - s->lchild->flag_bl);
		p->flag_bl = (p->rchild->flag_bl - p->lchild->flag_bl);
		return p;
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
				if (pre->flag_bl > 1)
				{
					if (s->flag_bl > 0)
					{
						pre=RotateR(pre);
					}
					else
					{
						pre->rchild = RotateL(pre->rchild);
						pre=RotateR(pre);
					}
				}
				else
				{
					if (s->flag_bl < 0)
					{
						pre = RotateL(pre);
					}
					else
					{
						pre->lchild = RotateR(pre->lchild);
						pre = RotateL(pre);
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
			AVLNode<T>* temp = stack.top();
			if (temp->val > pre)
				temp->lchild = pre;
			else
				temp->rchild = pre;
		}
		return true;
	}
};