#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<list>
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
int main()
{
	/*test* t1 = new test(1,2);
	delete t1;*/
	std::list<int> l1;                         // 构造空的l1
	std::list<int> l2(4, 100);                 // l2中放4个值为100的元素
	std::list<int> l3(l2.begin(), l2.end());  // 用l2的[begin(), end()）左闭右开的区间构造l3
	std::list<int> l4(l3);                    // 用l3拷贝构造l4
												  // 以数组为迭代器区间构造l5
	int array[] = { 16,2,77,29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));

		// 用迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;
	// C++11范围for的方式遍历
	for (auto& e : l5)
		std::cout << e << " ";
	std::cout << endl;

	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array2, array2 + sizeof(array2) / sizeof(array2[0]));
	// 使用正向迭代器正向list中的元素
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// 使用反向迭代器逆向打印list中的元素
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	system("pause");
	return 0;
}