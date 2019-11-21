#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int* data;
	int top;
} Stack;

Stack* init_stack()
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->data = (int*)malloc(sizeof(int) * 100);
	temp->top = 0;
	return temp;
}
void push_stack(Stack* s, int x)
{
	s->data[s->top++] = x;
}
bool empty_stack(Stack* s)
{
	return s->top == 0 ? true : false;
}
void pop_stack(Stack* s)
{
	if (empty_stack(s))
		return;
	s->top--;
}
int top_stack(Stack* s)
{
	return s->data[s->top - 1];
}

typedef struct {
	Stack* s;
	Stack* min;

} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* temp = (MinStack*)malloc(sizeof(MinStack));
	temp->s = init_stack();
	temp->min = init_stack();
	return temp;
}

void minStackPush(MinStack* obj, int x) {
	if (empty_stack(obj->s))
	{
		push_stack(obj->s, x);
		push_stack(obj->min, x);
	}
	else
	{
		push_stack(obj->s, x);
		if(top_stack(obj->min) >= top_stack(obj->s))
			push_stack(obj->min, x);
	}
}

void minStackPop(MinStack* obj) {
	if (empty_stack(obj->s))
		return;
	if (top_stack(obj->min) == top_stack(obj->s))
	{
		pop_stack(obj->min);
	}
	pop_stack(obj->s);
}

int minStackTop(MinStack* obj) {
	return top_stack(obj->s);
}

int minStackGetMin(MinStack* obj) {
	return top_stack(obj->min);
}

void minStackFree(MinStack* obj) {
	free(obj->s);
	free(obj->min);
	free(obj);
}


int main()
{
	MinStack* temp = minStackCreate();
	minStackPush(temp, -2);
	minStackPush(temp, 0);
	minStackPush(temp, -3);
	int val = minStackGetMin(temp);
	printf("%d ", val);
	minStackPop(temp);
	val = minStackTop(temp);
	printf("%d ", val);
	val = minStackGetMin(temp);
	printf("%d ", val);

	system("pause");
	return 0;
}