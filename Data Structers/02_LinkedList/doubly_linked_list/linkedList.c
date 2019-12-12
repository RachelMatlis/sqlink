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

void createList(Doubly_List** list)
{
	(*list) = (Doubly_List*)malloc(sizeof(Doubly_List));
	if (*list){
		(*list)->head = NULL;
	}
}

void insert(Doubly_List** list, int data)
{
	/*allocate new node*/
	Node* newNode;
	createNode(&newNode,data);

	if ((*list)->head == NULL)
	{	/*first node*/
		newNode->prev = NULL;
		(*list)->head = newNode;

	}
	else
	{
		Node* currNode = (*list)->head;
		while (currNode->next != NULL)
		{
			currNode = currNode->next;
		}

		currNode->next = newNode;
		newNode->prev = currNode;
	}
}

static int deleteFirstNode(Doubly_List** list)
{
	Node* temp = (*list)->head;
	(*list)->head = temp->next; /*change head*/
	free(temp);
	return 1;
}

int deleteNode(Doubly_List** list, int data)
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
	currNode->next->prev = prevNode;

	free(currNode);
	return 1;

}

void printList(Doubly_List* list)
{
	Node* currNode = list->head;
	while (currNode)
	{
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	printf("\n");
}

void printListRevesly(Doubly_List* list)
{
	Node* currNode = list->head;
	while (currNode->next !=NULL)
	{
		currNode = currNode->next;
	}
	while (currNode != NULL)
	{
		printf("%d ", currNode->data);
		currNode = currNode->prev;
	}
	printf("\n");
}

void freeList(Doubly_List** list)
{
	Node* tempNode;
	while ((*list)->head != NULL)
	{
		tempNode = (*list)->head;
		(*list)->head = (*list)->head->next;
		free(tempNode);
	}
}



