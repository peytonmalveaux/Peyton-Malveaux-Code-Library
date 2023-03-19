#include <stdlib.h>
#include <stdio.h>
#include "queue.h"




Queue *init(){

	Queue *toReturn = malloc(sizeof(Queue));
	if(toReturn == NULL){
		perror("error allocating queue");
		exit(1);
	}

	toReturn->head = NULL;
	toReturn->tail = NULL;



	return toReturn;
}


void destroy(Queue *q){
	while(!isEmpty(q)){
		dequeue(q);
	}
	free(q);
}


void enqueue(Queue *q, int data){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next  = NULL;

    if(q->tail != NULL){
	q->tail->next = newnode;
    }
    q->tail = newnode;

    if(q->head == NULL){
        q->head == newnode;
    }

}

int dequeue(Queue *q){
	if(isEmpty(q)){
		fprintf(stderr,"tried dequeueing an empty queue!\n");
		exit(0);
	}


	Node *toFree = q->head;
	int toReturn = q->head->data;

	if(q->head == q->tail){
		//only one node in queue
		q->head = NULL;
		q->tail = NULL;
	}else{
		q->head = q->head->next;
	}



	free(toFree);
	return toReturn;

}


int peek(Queue *q){
	if(isEmpty(q)){
		fprintf(stderr,"tried peeking an empty queue!\n");
		exit(0);
	}

	return q->head->data;

}

int isEmpty(Queue *q){
	return q->head == NULL;
}






