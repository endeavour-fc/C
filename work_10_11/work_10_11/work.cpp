#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
//enum Color
//{
//	Red = 0,
//	Black = 1
//};
//int Add(int num1, int num2)
//{
//	int sum = 0;
//	int carry = 0;
//	do 
//	{
//		sum = num1 ^ num2;
//		carry = (num1&num2) << 1;
//		num1 = sum;
//		num2 = carry;
//	} while (carry);
//	return num1;
//}
//
//int minus(int num1, int num2)
//{
//	num2 = Add(~num2, 1);
//	num1 = Add(num1, num2);
//	//num1 = ~(num1 - 1);
//	return num1;
//}
//template<class T>
//class RBTree;
//template<class T>
//class RBTreeNode
//{
//public:
//	RBTreeNode(const T& val=T()):lchild(nullptr),rchild(nullptr),parent(nullptr),color(Red),m_val(val)
//	{}
//	friend RBTree<T>;
//private:
//	RBTreeNode<T>* lchild;
//	RBTreeNode<T>* rchild;
//	RBTreeNode<T>* parent;
//	Color color;
//	T m_val
//};
//template<class T>
//class RBTree
//{
//public:
//	RBTree()
//	{
//		NUL = new RBTreeNode<T>();
//		NUL->lchild = NUL->rchild = NUL->parent = nullptr;
//		NUL->color = Black;
//		root = NUL;
//	}
//private:
//	bool InsertNode(RBTreeNode<T>*& t, const T& x)
//	{
//		RBTreeNode<T>* pr = NUL;
//		RBTreeNode<T>* s = t;
//		while (s != NUL)
//		{
//			if (s->m_val > x)
//				s = s->lchild;
//			else if (s->m_val < x)
//				s = s->rchild;
//			else
//				return false;
//			pr = s;
//		}
//		s = BuyNode(x);
//		if (pr == NUL)
//		{
//			t = s;
//			t->parent = NUL;
//		}
//		else if (pr->m_val > x)
//		{
//			pr->lchild = s;
//		}
//		else
//		{
//			pr->rchild = s;
//		}
//		s->parent = pr;
//		make_balance(t, s);
//		return true;
//	}
//	void make_balance(RBTreeNode<T>*& t, RBTreeNode<T>*& x)
//	{
//		while (x->parent->color == Red)
//		{
//			RBTreeNode<T>* s;
//			if (x->parent == x->parent->parent->lchild)
//			{
//				s = x->parent->parent->rchild;
//				if (s->color == Red)
//				{
//					s->color = Black;
//					x->parent->color = Black;
//					x->parent->parent = Red;
//					x = x->parent->parent;
//					continue;
//				}
//				else if (x == x->parent->rchild)
//				{
//					x = x->parent;
//					LeftRotate(t, x);
//				}
//				x->parent->color = Black;
//				x->parent->parent->color = Red;
//				RightRotate(t, x->parent->parent);
//			}
//			else
//			{
//				s = x->parent->parent->lchild;
//				if (s->color == Red)
//				{
//					s->color = Black;
//					x->parent->color = Black;
//					x->parent->parent = Red;
//					x = x->parent->parent;
//					continue;
//				}
//				else if (x == x->parent->lchild)
//				{
//					x = x->parent;
//					RightRotate(t, x);
//				}
//				x->parent->color = Black;
//				x->parent->parent->color = Red;
//				LeftRotate(t, x->parent->parent);
//			}
//		}
//	}
//	RBTreeNode<T>* BuyNode(const T& val=T())
//	{
//		RBTreeNode<T>* temp = new RBTreeNode<T>(val);
//		temp->lchild = temp->rchild = NUL;
//		return temp;
//	}
//	void LeftRotate(RBTreeNode<T>*& t, RBTreeNode<T>*& p)
//	{
//		RBTreeNode<T>* s = p->rchild;
//		p->rchild = s->lchild;
//		if (s->lchild != NUL)
//			s->lchild->parent = p;
//		if (p->parent == NUL)
//			t = s;
//		else if (p == p->parent->lchild)
//		{
//			p->parent->lchild = s;
//		}
//		else
//		{
//			p->parent->rchild = s;
//		}
//		s->lchild = p;
//		p->parent = s;
//	}
//	void RightRotate(RBTreeNode<T>*& t, RBTreeNode<T>*& p)
//	{
//		RBTreeNode<T>* s = p->lchild;
//		p->lchild = s->rchild;
//		if (s->rchild != NUL)
//			s->rchild->parent=p;
//		if (p->parent == NUL)
//			t = s;
//		else if (p == p->parent->lchild)
//		{
//			p->parent->lchild = s;
//		}
//		else
//		{
//			p->parent->rchild = s;
//		}
//		s->rchild = p;
//		p->parent = s;
//	}
//private:
//	RBTreeNode<T>*  NUL;
//	RBTreeNode<T>*	root;
//};


int dp[25][25];

long long solve(string pre, string post, int n) {
	long long sum = 1, num = 0;
	size_t k = 0;
	pre.erase(pre.begin());//忽略根节点
	post.pop_back();//忽略根节点
	while (k < pre.size())
	{
		for (size_t i = 0; i < post.size(); i++)
		{
			if (post[i] == pre[k])
			{//前序后序相遇，找到了一颗子树
				sum *= solve(pre.substr(k, i - k + 1), post.substr(k, i - k + 1), n);
				num++;
				k = i + 1;
				break;
			}
		}
	}
	return sum * dp[n][num];
}

//int main01() {
//	dp[0][0] = 1;
//	for (int i = 1; i < 25; i++)
//	{
//		dp[i][0] = 0;
//		for (int j = 0; j < i; j++)
//		{
//			if (j == 0)
//			{
//				dp[i][j] = dp[i - 1][j];
//				continue;
//			}
//			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//		}
//		dp[i][i] = 1;
//	}
//	int n = 0;
//	string s1, s2;
//	while (cin >> n && n) {
//		cin >> s1 >> s2;
//		cout << solve(s1, s2, n) << endl;
//	}
//}
int max(int a, int b)
{
	return a>b ? a : b;
}
bool wordBreak(string s, unordered_set<string> &dict) {
	int max_len = 0;
	if (s.empty()) {
		return false;
	}
	if (dict.empty()) {
		return false;
	}

	for (const auto& e : dict)
	{
		max_len = max(e.size(), max_len);
	}
	vector<bool> bl(s.size() + 1, false);
	bl[0] = true;
	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (i - j>max_len)
				break;
			if (bl[j] && dict.find(s.substr(j, i - j)) != dict.end())
			{
				bl[i] = true;
				break;
			}
		}
	}
	return bl[s.size()];
}
//int fun()
//{
//	return 1;
//}
//int main()
//{
//	//int& a = fun();
//	int&& b = fun();
//	int&& c = 1;
//	//int& d = 1;
//
//	return 0;
//}
void spiralOrder(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
	{
		return;
	}
	int index = 0;
	int right = matrix[0].size() - 1;
	int left = 0;
	int front = 0;
	int back = matrix.size() - 1;

	while (left <= right && front <= back)
	{
		for (int col = left; col <= right; ++col)
			matrix[front][col] = index++ % 26 + 'A';
		for (int row = front + 1; row <= back; ++row)
			matrix[row][right] = index++ % 26 + 'A';

		if (left<right&&front<back)
		{
			for (int col = right - 1; col >= left; --col)
				matrix[back][col] = index++ % 26 + 'A';
			for (int row = back - 1; row>front; --row)
				matrix[row][left] = index++ % 26 + 'A';
		}
		++left;
		--right;
		++front;
		--back;
	}

}
bool isMatch(string s, string p) {
	vector<vector<int>> v(s.size() + 1, vector<int>(p.size() + 1, 0));
	v[0][0] = 1;
	for (int i = 1; i <= p.size(); i++)
	{
		if (i == 1)
			continue;
		v[0][i] = v[0][i - 2] && (p[i - 1] == '*');
	}
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= p.size(); j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				v[i][j] = v[i - 1][j - 1];
			else if (p[j - 1] == '*')
			{
				if (j<2)
					continue;
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
				{
					v[i][j] = v[i - 1][j] || v[i][j - 1] || v[i][j - 2];
				}
				else if (p[j - 2] != '.'&&p[j - 2] != s[i - 1])
				{
					v[i][j] = v[i][j - 2];
				}
			}
			else if (p[j - 1] == '+')
			{
				if (j < 2)
					continue;
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
				{
					v[i][j] = v[i - 1][j] || v[i][j - 1] || v[i][j - 2];
				}
			}

		}
	return v[s.size()][p.size()];
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> v(m, vector<char>(n));
		spiralOrder(v);
		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0; j < v[0].size(); ++j)
				cout << v[i][j] << " ";
			cout << endl;
		}
	}

	return 0;
}