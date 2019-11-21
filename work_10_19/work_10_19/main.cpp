#include"queue.h"

int main()
{
	sequeue Q;
	queue_init(&Q);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_queue_in(&Q, 2);
	seq_print(&Q);
	seq_queue_out(&Q);
	seq_queue_out(&Q);
	seq_queue_out(&Q);
	seq_queue_out(&Q);
	printf("\n");
	seq_print(&Q);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//queue_in(&Q, 2);
	//print_que(&Q);
	//queue_out(&Q);
	//queue_out(&Q);
	//queue_out(&Q);
	//queue_out(&Q);
	//printf("\n");
	//print_que(&Q);

	system("pause");
	return 0;
}