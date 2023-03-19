#ifndef QUEUE_H
#define QUEUE_H



typedef struct node{
	int data;
	struct node *next;
}Node;


typedef struct queue{
	Node *head;//dequeue from the head
	Node *tail;//enqueue from the tail
}Queue;


Queue *init();
void destroy(Queue *q);

void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int peek(Queue *q);
int isEmpty(Queue *q);








#endif
