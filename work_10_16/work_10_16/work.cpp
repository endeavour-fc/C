#include"stack.h"
void move(int* nums, int len, int size)
{
	int i = len;
	for (i = len; i<size - 1; i++)
		nums[i] = nums[i + 1];
}
int removeDuplicates(int nums[], int numsSize)
{
	int len = 0;
	int size = numsSize;
	int i = 0;
	int j = 0;
	while (i<numsSize - 1&&size>0)
	{
		if (nums[i] == nums[i + 1])
		{
			move(nums, i, size--);
			continue;
		}
		i++;
	}
	
	return i+1;
}
void stack_init(seqstack* stack)
{
	stack->size = 8;
	stack->top = 0;
	stack->data = (int*)malloc(sizeof(int) * 8);
}

void stack_push(seqstack* stack,int num)
{
	if (stack_pull(stack))
		return;
	stack->data[stack->top++] = num;
}

bool stack_pull(seqstack* stack)
{
	return stack->top >= stack->size;
}
bool stack_empty(seqstack* stack)
{
	return stack->top == 0;
}


void stack_show(seqstack* stack)
{
	for (int i = 0; i < stack->top; i++)
		printf("%d ", stack->data[i]);
}