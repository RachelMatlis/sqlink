#include"linkedList.h"
#include <stdio.h> 
#include <stdlib.h>

static void createNode(Node** node, int data)
{
	*node = (Node*)malloc(sizeof(Node));
	if (!(*node))
	{
		printf("allocation Error\n");
		exit(1);
	}
	(*node)->data = data;
	(*node)->next = NULL;
}

void createList(List** list)
{
	(*list) = (List*)malloc(sizeof(List));
	if (*list){
		(*list)->head = NULL;
	}
}

void insert(List** list, int data)
{
	if ((*list)->head == NULL)
	{	/*first node*/
		createNode(&(*list)->head, data);
	}
	else
	{
		Node* currNode = (*list)->head;
		while (currNode->next != NULL)
		{
			currNode = currNode->next;
		}
		createNode(&currNode->next, data);
		currNode = currNode->next;
	}
}

static int deleteFirstNode(List** list)
{
	Node* temp = (*list)->head;
	(*list)->head = temp->next; /*change head*/
	free(temp);
	return 1;
}

int deleteNode(List** list, int data)
{
	if ((*list)->head ==NULL) {
		return 0;
	}

	/* if head node itself holds the key to be deleted*/
	if ((*list)->head->data == data)
	{
		return deleteFirstNode(list);
	}

	/*head node already checked*/
	Node* prevNode = (*list)->head;
	Node* currNode = (*list)->head->next;
	
	/*Search for the node to be deleted,*/
	while (currNode != NULL && currNode->data != data)
	{
		prevNode = currNode;
		currNode = currNode->next;
	}

	/*if node with data not found*/
	if (currNode == NULL) {
		return 0;
	}

	prevNode->next = currNode->next;
	free(currNode);
	return 1;

}

int size(List* list)
{
	int count = 0;
	Node* currNode = list->head;
	while (currNode)
	{
		count++;
		currNode = currNode->next;
	}

	return count;
}

int isEmpty(List* list)
{
	return list->head == NULL;
}

int find(List* list, int data)
{
	Node* currNode = list->head;
	while (currNode)
	{
		if (currNode->data == data) {
			return 1;
		}
		currNode = currNode->next;
	}
	return 0;
}

void printList(List* list)
{
	Node* currNode = list->head;
	while (currNode)
	{
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	printf("\n");
}

void freeList(List** list)
{
	Node* tempNode;
	while ((*list)->head != NULL)
	{
		tempNode = (*list)->head;
		(*list)->head = (*list)->head->next;
		free(tempNode);
	}
}

void reverseList(List** list)
{

	if (size(*list) < 2){
		return;
	}

	Node *prevNode=NULL, *nextNode=NULL;
	Node* currNode = (*list)->head;

	while (currNode != NULL) 
	{
		nextNode = currNode->next;
		currNode->next = prevNode; /* Reverse current node's pointer*/
		prevNode = currNode;
		currNode = nextNode;
	}

	(*list)->head = prevNode;
}

int findMiddle(List* list)
{
	Node* slowP = list->head;
	Node* fastP= list->head;

	while (fastP && fastP->next)
	{
		slowP= slowP->next;
		fastP = fastP->next->next;
	}

	return slowP->data;
}

