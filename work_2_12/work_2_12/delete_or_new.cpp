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
	std::list<int> l1;                         // ����յ�l1
	std::list<int> l2(4, 100);                 // l2�з�4��ֵΪ100��Ԫ��
	std::list<int> l3(l2.begin(), l2.end());  // ��l2��[begin(), end()������ҿ������乹��l3
	std::list<int> l4(l3);                    // ��l3��������l4
												  // ������Ϊ���������乹��l5
	int array[] = { 16,2,77,29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));

		// �õ�������ʽ��ӡl5�е�Ԫ��
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;
	// C++11��Χfor�ķ�ʽ����
	for (auto& e : l5)
		std::cout << e << " ";
	std::cout << endl;

	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array2, array2 + sizeof(array2) / sizeof(array2[0]));
	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	system("pause");
	return 0;
}