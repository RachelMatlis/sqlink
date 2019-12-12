#include"queue.h"
#include <stdio.h> 
#include <stdlib.h>

void createQueue(Queue** queue)
{
	*queue = (Queue*)malloc(sizeof(Queue));
	(*queue)->first = NULL;
}

void enqueue(Queue** queue, int data)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if ((*queue)->first == NULL)
	{
		(*queue)->first = newNode;
	}
	else
	{
		QueueNode* currNode = (*queue)->first;
		while (currNode->next)
		{
			currNode = currNode->next;
		}

		currNode->next = newNode;
	}
}

int dequeue(Queue** queue)
{
	int data = -1;
	if ((*queue)->first)
	{
		QueueNode* currFirst = (*queue)->first;
		data = currFirst->data;
		(*queue)->first = currFirst->next;/*change first pointer*/
		free(currFirst);
	}

	return data;
}

int peek(Queue* queue)
{
	return queue->first != NULL ? queue->first->data : -1;
}

int isempty(Queue* queue)
{
	return queue->first == NULL;
}

void printQueue(Queue* queue)
{
	QueueNode* cuurNode = queue->first;
	while (cuurNode)
	{
		printf("%d ", cuurNode->data);
		cuurNode = cuurNode->next;
	}
	printf("\n");
}

void freeQueue(Queue** queue)
{
	QueueNode* cuurNode = (*queue)->first;
	while (cuurNode)
	{
		(*queue)->first = (*queue)->first->next;
		free(cuurNode);
		cuurNode = (*queue)->first;
	}
}

