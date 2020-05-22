#include<iostream>
using namespace std;
enum Color
{
	Red = 0,
	Black = 1
};
int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do 
	{
		sum = num1 ^ num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (carry);
	return num1;
}

int minus(int num1, int num2)
{
	num2 = Add(~num2, 1);
	num1 = Add(num1, num2);
	//num1 = ~(num1 - 1);
	return num1;
}
template<class T>
class RBTree;
template<class T>
class RBTreeNode
{
public:
	RBTreeNode(const T& val=T()):lchild(nullptr),rchild(nullptr),parent(nullptr),color(Red),m_val(val)
	{}
	friend RBTree<T>;
private:
	RBTreeNode<T>* lchild;
	RBTreeNode<T>* rchild;
	RBTreeNode<T>* parent;
	Color color;
	T m_val
};
template<class T>
class RBTree
{
public:
	RBTree()
	{
		NUL = new RBTreeNode<T>();
		NUL->lchild = NUL->rchild = NUL->parent = nullptr;
		NUL->color = Black;
		root = NUL;
	}
private:
	bool InsertNode(RBTreeNode<T>*& t, const T& x)
	{
		RBTreeNode<T>* pr = NUL;
		RBTreeNode<T>* s = t;
		while (s != NUL)
		{
			if (s->m_val > x)
				s = s->lchild;
			else if (s->m_val < x)
				s = s->rchild;
			else
				return false;
			pr = s;
		}
		s = BuyNode(x);
		if (pr == NUL)
		{
			t = s;
			t->parent = NUL;
		}
		else if (pr->m_val > x)
		{
			pr->lchild = s;
		}
		else
		{
			pr->rchild = s;
		}
		s->parent = pr;
		make_balance(t, s);
		return true;
	}
	void make_balance(RBTreeNode<T>*& t, RBTreeNode<T>*& x)
	{
		while (x->parent->color == Red)
		{
			RBTreeNode<T>* s;
			if (x->parent == x->parent->parent->lchild)
			{
				s = x->parent->parent->rchild;
				if (s->color == Red)
				{
					s->color = Black;
					x->parent->color = Black;
					x->parent->parent = Red;
					x = x->parent->parent;
					continue;
				}
				else if (x == x->parent->rchild)
				{
					x = x->parent;
					LeftRotate(t, x);
				}
				x->parent->color = Black;
				x->parent->parent->color = Red;
				RightRotate(t, x->parent->parent);
			}
			else
			{
				s = x->parent->parent->lchild;
				if (s->color == Red)
				{
					s->color = Black;
					x->parent->color = Black;
					x->parent->parent = Red;
					x = x->parent->parent;
					continue;
				}
				else if (x == x->parent->lchild)
				{
					x = x->parent;
					RightRotate(t, x);
				}
				x->parent->color = Black;
				x->parent->parent->color = Red;
				LeftRotate(t, x->parent->parent);
			}
		}
	}
	RBTreeNode<T>* BuyNode(const T& val=T())
	{
		RBTreeNode<T>* temp = new RBTreeNode<T>(val);
		temp->lchild = temp->rchild = NUL;
		return temp;
	}
	void LeftRotate(RBTreeNode<T>*& t, RBTreeNode<T>*& p)
	{
		RBTreeNode<T>* s = p->rchild;
		p->rchild = s->lchild;
		if (s->lchild != NUL)
			s->lchild->parent = p;
		if (p->parent == NUL)
			t = s;
		else if (p == p->parent->lchild)
		{
			p->parent->lchild = s;
		}
		else
		{
			p->parent->rchild = s;
		}
		s->lchild = p;
		p->parent = s;
	}
	void RightRotate(RBTreeNode<T>*& t, RBTreeNode<T>*& p)
	{
		RBTreeNode<T>* s = p->lchild;
		p->lchild = s->rchild;
		if (s->rchild != NUL)
			s->rchild->parent=p;
		if (p->parent == NUL)
			t = s;
		else if (p == p->parent->lchild)
		{
			p->parent->lchild = s;
		}
		else
		{
			p->parent->rchild = s;
		}
		s->rchild = p;
		p->parent = s;
	}
private:
	RBTreeNode<T>*  NUL;
	RBTreeNode<T>*	root;
};