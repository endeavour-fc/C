#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

typedef struct {
	int* data;
	int top;
}stack;
bool empty_stack(stack* sta)
{
	if (sta == NULL)
		return false;
	return sta->top == 0 ? true : false;
}
void push_stack(stack* sta, int x)
{
	sta->data[sta->top++] = x;
}
void pop_stack(stack* sta)
{
	if (empty_stack(sta))
		return;
	sta->top--;
}
int peek_stack(stack* sta)
{
	return sta->data[sta->top - 1];

}


typedef struct {
	stack* s1;
	stack* s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* temp = (MyQueue*)malloc(sizeof(MyQueue));
	temp->s1 = (stack*)malloc(sizeof(stack));
	temp->s2 = (stack*)malloc(sizeof(stack));
	temp->s1->data = (int*)malloc(sizeof(int) * 100);
	temp->s2->data = (int*)malloc(sizeof(int) * 100);
	temp->s1->top = temp->s2->top = 0;
	return temp;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	if (empty_stack(obj->s1))
	{
		push_stack(obj->s2, x);
	}
	else
	{
		push_stack(obj->s1, x);
	}
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int val = 0;
	if (empty_stack(obj->s1))
	{
		while (!empty_stack(obj->s2))
		{
			push_stack(obj->s1, peek_stack(obj->s2));
			val = peek_stack(obj->s2);
			pop_stack(obj->s2);
		}
		pop_stack(obj->s1);

		while (!empty_stack(obj->s1))
		{
			push_stack(obj->s2, peek_stack(obj->s1));
			pop_stack(obj->s1);
		}
	}
	else
	{
		while (!empty_stack(obj->s1))
		{
			push_stack(obj->s2, peek_stack(obj->s1));
			val = peek_stack(obj->s1);
			pop_stack(obj->s1);
		}
		pop_stack(obj->s2);

		while (!empty_stack(obj->s2))
		{
			push_stack(obj->s1, peek_stack(obj->s2));
			pop_stack(obj->s2);
		}
	}
	return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	int val = 0;
	if (empty_stack(obj->s1))
	{
		while (!empty_stack(obj->s2))
		{
			push_stack(obj->s1, peek_stack(obj->s2));
			val = peek_stack(obj->s2);
			pop_stack(obj->s2);
		}
		while (!empty_stack(obj->s1))
		{
			push_stack(obj->s2, peek_stack(obj->s1));
			pop_stack(obj->s1);
		}
	}
	else
	{
		while (!empty_stack(obj->s1))
		{
			push_stack(obj->s2, peek_stack(obj->s1));
			val = peek_stack(obj->s1);
			pop_stack(obj->s1);
		}
		while (!empty_stack(obj->s2))
		{
			push_stack(obj->s1, peek_stack(obj->s2));
			pop_stack(obj->s2);
		}
	}
	return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return empty_stack(obj->s1) && empty_stack(obj->s2) ? true : false;
}

void myQueueFree(MyQueue* obj) {
	free(obj->s1);
	free(obj->s2);
	free(obj);
}


//typedef string State;
//class Observer;
//class ConcreteObserverA;
//class ConcreteObserverB;
//class Subject
//{
//public:
//	virtual ~Subject();
//	virtual void Attach(Observer* obv);
//	virtual void Detach(Observer* obv);
//	virtual void Notify();
//	virtual void SetState(const State& st) = 0;
//	virtual State GetState() = 0;
//protected:
//	Subject();
//private:
//	list<Observer* >* _obvs;
//};
//class ConcreteSubject :public Subject
//{
//public:
//	ConcreteSubject();
//	~ConcreteSubject();
//	State GetState();
//	void SetState(const State& st);
//protected:
//
//private:
//	State _st;
//};
//
//Subject::Subject()
//{
//	//****在模板的使用之前一定要 new，创建
//	_obvs = new list<Observer*>;
//}
//Subject::~Subject()
//{
//
//}
//void Subject::Attach(Observer* obv)
//{
//
//	_obvs->push_front(obv);
//}
//void Subject::Detach(Observer* obv)
//{
//	if (obv != NULL)
//		_obvs->remove(obv);
//}
//void Subject::Notify()
//{
//	list<Observer*>::iterator it;
//	it = _obvs->begin();
//	for (; it != _obvs->end(); it++)
//	{
//		//关于模板和 iterator 的用法
//		(*it)->Update(this);
//	}
//}
//ConcreteSubject::ConcreteSubject()
//{
//	_st = '\0';
//}
//ConcreteSubject::~ConcreteSubject()
//{
//
//}
//State ConcreteSubject::GetState()
//{
//	return _st;
//}
//void ConcreteSubject::SetState(const State& st)
//{
//	_st = st;
//}
//
//class Observer
//{
//public:
//	virtual ~Observer();
//	virtual void Update(Subject* sub) = 0;
//	virtual void PrintInfo() = 0;
//protected:
//	Observer();
//	State _st;
//private:
//};
//class ConcreteObserverA :public Observer
//{
//public:
//	virtual Subject* GetSubject();
//
//	ConcreteObserverA(Subject* sub);
//	virtual ~ConcreteObserverA();
//	//传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
//	void Update(Subject* sub);
//	void PrintInfo();
//protected:
//private:
//	Subject * _sub;
//};
//class ConcreteObserverB :public Observer
//{
//public:
//	virtual Subject* GetSubject();
//	ConcreteObserverB(Subject* sub);
//
//	virtual ~ConcreteObserverB();
//	//传入 Subject 作为参数，这样可以让一个 View 属于多个的 Subject。
//	void Update(Subject* sub);
//	void PrintInfo();
//protected:
//private:
//	Subject * _sub;
//};
//
//Observer::Observer()
//{
//	_st = '\0';
//}
//Observer::~Observer()
//{
//}
//ConcreteObserverA::ConcreteObserverA(Subject* sub)
//{
//	_sub = sub;
//	_sub->Attach(this);
//}
//ConcreteObserverA::~ConcreteObserverA()
//{
//	_sub->Detach(this);
//	if (_sub != 0)
//	{
//		delete _sub;
//	}
//}
//Subject* ConcreteObserverA::GetSubject()
//{
//	return _sub;
//}
//void ConcreteObserverA::PrintInfo()
//{
//	cout << "ConcreteObserverA observer...." << _sub->GetState() << endl;
//}
//void ConcreteObserverA::Update(Subject* sub)
//{
//	_st = sub->GetState();
//	PrintInfo();
//}
//ConcreteObserverB::ConcreteObserverB(Subject* sub)
//{
//	_sub = sub;
//	_sub->Attach(this);
//}
//ConcreteObserverB::~ConcreteObserverB()
//{
//	_sub->Detach(this);
//	if (_sub != 0)
//	{
//		delete _sub;
//	}
//}
//Subject* ConcreteObserverB::GetSubject()
//{
//	return _sub;
//}
//void ConcreteObserverB::PrintInfo()
//{
//	cout << "ConcreteObserverB observer...." << _sub->GetState() << endl;
//}
//void ConcreteObserverB::Update(Subject* sub)
//{
//	_st = sub->GetState();
//	PrintInfo();
//}
vector<int> sort11(int* a, int aLen, int* b, int bLen) {
	// write code here
	vector<int> v;
	int ai = 0;
	//int bi=0;
	bLen--;
	while (ai<aLen&&bLen >= 0)
	{
		if (a[ai] < b[bLen - 1])
			v.push_back(a[ai++]);
		else
			v.push_back(b[bLen--]);
	}
	while (ai<aLen)
		v.push_back(a[ai++]);
	while (bLen>=0)
		v.push_back(b[bLen--]);
	return v;
}
int match_str_in_sentence(string s, string x) {
	// write code here
	int i = 0;
	int j = 0;
	int ret = 1;
	while (i<s.size())
	{
		while (i<s.size() && s[i] != ' ')
			++i;
		string temp = s.substr(j, i - j + 1);
		if (temp.find(x) != string::npos)
			return ret;
		while (i<s.size() && s[i] == ' ')
			++i;
		j = i;
		++ret;
	}
	return -1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		unordered_map<int, int> mp;
		int len = A.size();
		for (int i = 0; i<A.size(); ++i)
		{
			mp[A[i]] = i;
		}
		int ret = 0;
		unordered_map<int, int> longest;
		for (int i = 2; i<len; ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (A[i] - A[j]<A[j] && mp.count(A[i] - A[j]))
				{
					int temp = mp[A[i] - A[j]];
					longest[j*len + i] = longest[temp*len + j] + 1;
					ret = max(ret, longest[j*len + i] + 2);
				}
			}
		}
		return ret >= 3 ? ret : 0;

	}
};

int main()
{
	int a[] = { 1,2,3 };
	int b[] = { 6,5,4 };
	//vector<int> v = sort11(a, 3, b, 3);
	cout << match_str_in_sentence("this is an easy problem.", "eas") << endl;

	system("pause");
	return 0;
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