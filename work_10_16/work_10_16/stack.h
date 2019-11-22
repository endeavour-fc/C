#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct seqstack
{
	int* data;
	size_t size;
	int top;
};

void stack_init(seqstack* stack);
void stack_push(seqstack* stack,int num);
bool stack_pull(seqstack* stack);
bool stack_empty(seqstack* stack);
void stack_show(seqstack* stack);