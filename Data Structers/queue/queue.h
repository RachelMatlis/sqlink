#pragma once

typedef struct queue_node
{
	int data;
	struct node* next;
}QueueNode;

typedef struct queue
{
	QueueNode* first;
}Queue;

/*Basic queue operations */

void createQueue(Queue**);
/*add (store) an item to the queue*/
void enqueue(Queue**, int);
/*remove(access) an item from the queue.*/
int dequeue(Queue**);
/* Gets the element at the front of the queue without removing it.*/
int peek(Queue*);
/* Checks if the queue is empty.*/
int isempty(Queue*);


void freeQueue(Queue**);
void printQueue(Queue*);


