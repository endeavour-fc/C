#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template<class T>
class print
{
public:
	void operator()(const T& elem)
	{
		cout << elem << " ";
	}
};

template<class T>
class testClass
{
public:
	static const int _datai = 5;
	static const int _datal = 3L;
	static const char _datac = 'c';
};

class INT
{
	friend ostream& operator<<(ostream& os, const INT& i);
public:
	INT(int i) :m_i(i) {};
	INT& operator++()
	{
		++(this->m_i);
		return *this;
	}
	const INT operator++(int)
	{
		INT temp = *this;
		++(*this);
		return temp;
	}
	INT& operator--()
	{
		--(this->m_i);
		return *this;
	}
	INT operator--(int)
	{
		INT temp = *this;
		--(*this);
		return temp;
	}
	int& operator*()const
	{
		return (int&)m_i;
	}
private:
	int m_i;
};
ostream& operator<<(ostream& os, const INT& i)
{
	os << "[" << i.m_i << "]";
	return os;
}
//template<class InputIterator,class T>
//InputIterator find(InputIterator first, InputIterator last, const T& value)
//{
//	while (first != last && *first != value)++first;
//	return first;
//}
//
//template<class InputIterator, class Function>
//Function for_each(InputIterator first, InputIterator last, Function f)
//{
//	for (; first != last; ++first)
//		f(*first);
//	return first;
//}

#ifndef _JJALLOC_
#define _JJALLOC_
#include<new>
#include<cstddef>
#include<cstdlib>
#include<climits>
namespace JJ
{
	template<class T>
	inline T* _allocate(ptrdiff_t size, T*)
	{
		set_new_handler(0);//强制抛出异常，而不是调用系统异常处理函数
		T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
		if (temp == 0)
		{
			cerr << "out of memory" << endl;
			exit(1);
		}
		return temp;
	}

	template<class T>
	inline void _deallocate(T* buffer)
	{
		::operator delete(buffer);
	}

	template<class T1,class T2>
	inline void _construct(T1* p, const T2& value)
	{
		new(p) T1(value);
	}
	template <class T>
	inline void _destroy(T* ptr)
	{
		ptr->~T();
	}
	template<class T>
	class allocator
	{
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& referenece;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		template<class U>
		struct rebind
		{
			typedef allocator<U> other;
		};
		pointer allocate(size_type n, const void* hint = 0)
		{
			return _allocate((difference_type)n, (pointer)0);
		}
		void deallocate(pointer p, size_type n) { _deallocate(p); }
		void construct(pointer p.const T& value)
		{
			_construct(p, value);
		}
		void destroy(pointer p)
		{
			_destroy(p);
		}
		pointer address(referenece x)
		{
			return (pointer)&x;
		}
		const_pointer address(const_reference x)
		{
			return (const_pointer)&x;
		}
		size_type max_size()const
		{
			return size_type(UINT_MAX / sizeof(T));
		}
	};
}



#endif

int main()
{
	vector<int> v = { 0,1,2,3,4,5,6 };
	for_each(v.begin(), v.end(), print<int>());
	
	system("pause");
	return 0;
}