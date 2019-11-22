#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int* data;
	int first;
	int last;
	int size;

} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* temp = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	temp->data = (int*)malloc(sizeof(int)*(k + 1));
	temp->last = temp->first = 0;
	temp->size = k + 1;
	return temp;
}
/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj->first == ((obj->last + 1) % obj->size))
		return true;
	return false;
}
/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->last == obj->first ? true : false;
}



/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	obj->data[obj->last] = value;
	obj->last = (obj->last+1)%obj->size;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->first = (obj->first + 1) % obj->size;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[obj->first];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->data[(obj->last - 1 + obj->size) % obj->size];
}


void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}

int main()
{
	MyCircularQueue*temp = myCircularQueueCreate(3);
	myCircularQueueEnQueue(temp, 1);
	myCircularQueueEnQueue(temp, 2);
	myCircularQueueEnQueue(temp, 3);
	myCircularQueueEnQueue(temp, 4);
	int val=myCircularQueueRear(temp);
	printf("%d", val);
	val = myCircularQueueIsFull(temp);
	printf("%d", val);
	val = myCircularQueueDeQueue(temp);
	printf("%d", val);
	myCircularQueueEnQueue(temp, 4);
	val = myCircularQueueRear(temp);
	printf("%d", val);
	
	system("pause");
	return 0;
}