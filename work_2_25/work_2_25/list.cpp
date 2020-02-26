#include<iostream>
#include<list>
#include<assert.h>
using namespace std;

namespace fc
{
	template<typename T>
	struct ListNode
	{
		ListNode(const T &val=T()):next(nullptr),pre(nullptr)
		{}
		ListNode<T> *next;
		ListNode<T> *pre;
		ListNode<T> val;
	};
	template<typename T>
	class List_iterator
	{
	public:
		List_iterator():ptr(nullptr)
		{}
		List_iterator(ListNode<T> *p):ptr(p)
		{}
		~List_iterator()
		{}
	public:
		T& operator*()
		{
			return ptr->val;
		}
		T* operator->()
		{
			return &**this;
		}
		List_iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		List_iterator operator++()
		{
			List_iterator temp = *this;
			++*this;
			return temp;
		}
		List_iterator& operator--()
		{
			ptr = ptr->pre;
			return *this;
		}
		List_iterator operator--()
		{
			List_iterator temp = *this;
			--*this;
			return temp;
		}
		bool operator==(const List_iterator& p)
		{
			return ptr == p;
		}
		bool operator!=(const List_iterator& p)
		{
			return !(p == ptr);
		}
		ListNode<T>* MyNode()
		{
			return ptr;
		}
	private:
		ListNode<T>* ptr;
	};
	template<typename T1>
	class list
	{
		typedef ListNode<T1> pNode;
	public:
		list():head(nullptr),size(0)
		{}
		list(size_t n, const T1 &value = T1()) :head(GetNode()), size(0)
		{
			while (n--)
				push_back(value);
		}
		template<typename _It>
		list(_It first, _It last) : head(GetNode()), size(0)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		list(const list<T1> &lt) :head(GetNode()), size(0)
		{
			list<T1> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
	public:
		size_t Get_size() const
		{
			return this->size;
		}
		bool List_Empty() const
		{
			return !this->size;
		}
		void push_back(const T1 &val)
		{
			insert(end(), val);
		}
		void push_front(const T1 &val)
		{
			insert(begin(), val);
		}
		T1& front()
		{
			assert(!List_Empty());
			return *begin();
		}
		const T1& front()const
		{
			assert(!List_Empty());
			return *begin();
		}

		void swap(list<T1> & lt)
		{
			std::swap(head, lt.head);
			std::swap(size, lt.size);
		}
	public:
		List_iterator<T1> begin()
		{
			return List_iterator<T1>(head->next);
		}
		List_iterator<T1> end()
		{
			return List_iterator<T1>(head);
		}
		List_iterator<T1> insert(List_iterator<T1> pos, const T1 &val)
		{
			pNode _S = new ListNode<T1>(val);
			pNode _P = pos.MyNode();

			_S->next = _P;
			_S->pre = _P->pre;
			_S->pre->next = _S;
			_P->pre = _S;

			size++;
			return List_iterator<T1>(_S);
		}
	private:
		pNode GetNode(T1 &val=T1())
		{
			pNode n1 = new ListNode<T1>(val);
			n1.val = val;
			n1.pre = NULL;
			n1.next = NULL;
			return n1;
		}
	private:
		ListNode<T1> *head;
		size_t size;
	};
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	list<int> l1(4, 10);
	list<int> l2;
	list<int> l3(l1);
	list<int> l4(arr, arr+len);
	list<int> l5(l4.begin(), l4.end());
	for (const auto&e : l5)
		cout << e << "->";
	cout << endl;
	for (list<int>::const_iterator list = l5.begin(); list != l5.end(); list++)
		cout << *list << "->";
	cout << endl;
	auto ls = l5.begin();
	for(;ls!=l5.end();++ls)
		cout << *ls << "->";
	cout << endl;
	for (list<int>::reverse_iterator list = l5.rbegin(); list != l5.rend(); list++)
		cout << *list << "->";
	cout << endl;
	//std::list<int> mylist;
	//cout << "size()=" << l5.size() << endl;
	//cout << "front()=" << l5.front() << endl;
	//cout << "back()=" << l5.back() << endl;

	//l5.push_back(11);
	//cout << "back()=" << l5.back() << endl;
	//l5.push_front(0);
	//cout << "front()=" << l5.front() << endl;
	//l5.pop_back();
	//cout << "back()=" << l5.back() << endl;
	//l5.pop_front();
	//cout << "front()=" << l5.front() << endl;
	list<int>::iterator it = find(l5.begin(), l5.end(), 101);
	l5.insert(it,14);
	for (list<int>::const_iterator list = l5.begin(); list != l5.end(); list++)
		cout << *list << "->";
	cout << endl;

	l5.erase(--l5.end());

	for (list<int>::const_iterator list = l5.begin(); list != l5.end(); list++)
		cout << *list << "->";
	cout << endl;


	//for (int i = 1; i <= 5; ++i) mylist.push_back(i);

	//std::cout << "mylist backwards:";
	//for (std::list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit)
	//	std::cout << ' ' << *rit;

	//std::cout << '\n';




	system("pause");
	return 0;
}