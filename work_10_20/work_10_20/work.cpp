#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


int main()
{
	int val = 0;
	MyQueue* temp = myQueueCreate();
	myQueuePush(temp,1);
	myQueuePush(temp, 2);
	val=myQueuePeek(temp);
	printf("%d ", val);
	val = myQueuePop(temp);
	printf("%d ", val);
	val=myQueueEmpty(temp);
	printf("%d ", val);


	system("pause");
	return 0;
}