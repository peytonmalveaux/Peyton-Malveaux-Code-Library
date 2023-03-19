#include <stdio.h>
#include "queue.h"



int main(int argc, char *argv[]){

	Queue *q = init();


	enqueue(q, 5);
	printf("enqueue'd 5\n");
	enqueue(q,8);
	printf("enqueue'd 8\n");
	enqueue(q,11);
	printf("enqueue'd 11\n");
	printf("dequeued :%d\n", dequeue(q));
	printf("dequeued :%d\n", dequeue(q));

	enqueue(q,4);
	printf("enqueue'd 4\n");
	enqueue(q,2);
	printf("enqueue'd 2\n");
	enqueue(q,5);
	printf("enqueue'd 5\n");
	enqueue(q,1);
	printf("enqueue'd 1\n");
	enqueue(q,9);
	printf("enqueue'd 9\n");

	printf("dequeued :%d\n", dequeue(q));
	printf("dequeued :%d\n", dequeue(q));
	printf("dequeued :%d\n", dequeue(q));
	printf("dequeued :%d\n", dequeue(q));

	destroy(q);


}
