#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sequeue
{
	int* date;
	int size;
	int last;
	int first;
};

void queue_init(sequeue* seq);
void queue_in(sequeue* seq,int x);
bool queue_full(sequeue* seq);
void print_que(sequeue* seq);
int seq_front(sequeue* seq);
void queue_out(sequeue* seq);

//*************************************************
//*************************************************

void seq_queue_in(sequeue* seq, int x);
bool seq_queue_full(sequeue* seq);
bool seq_queue_empty(sequeue* seq);
void seq_queue_out(sequeue* seq);
void seq_print(sequeue* seq);