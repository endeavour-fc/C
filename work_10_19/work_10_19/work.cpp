#include"queue.h"
void queue_init(sequeue* seq)
{
	seq->size = 8;
	seq->date = (int*)malloc(sizeof(int) * 8);
	seq->first = 0;
	seq->last = 0;
}

bool queue_full(sequeue* seq)
{
	return ((seq->last >= seq->size) ? true : false);
}
void queue_in(sequeue* seq,int x)
{
	if (queue_full(seq))
		return;
	seq->date[seq->last++] = x;
}
void queue_out(sequeue* seq)
{
	seq->first++;
}
void print_que(sequeue* seq)
{
	for (int i = seq->first; i < seq->last; i++)
		printf("%d ", seq->date[i]);
}

int seq_front(sequeue* seq)
{
	if (seq->last == 0)
		return NULL;
	return seq->date[seq->first];
}

//*************************************************
//*************************************************
bool seq_queue_full(sequeue* seq)
{
	if (seq->first == ((seq->last + 1) % 8))
		return true;
	return false;
}

bool seq_queue_empty(sequeue* seq)
{
	return seq->first == seq->last ? true : false;
}

void seq_queue_in(sequeue* seq,int x)
{
	if (seq_queue_full(seq))
		return;
	seq->date[seq->last] = x;
	seq->last = (seq->last+1) % 8;
}
void seq_queue_out(sequeue* seq)
{
	if (seq_queue_empty(seq))
		return;
	seq->first = (seq->first + 1) % 8;
}
void seq_print(sequeue* seq)
{
	for (int i = seq->first; i != seq->last;)
	{
		printf("%d ", seq->date[i]);
		i = (i + 1) % 8;
	}
}