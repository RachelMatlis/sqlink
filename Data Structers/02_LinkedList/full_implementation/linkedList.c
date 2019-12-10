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

void insert(Node** head, int data)
{
	if (*head == NULL)
	{	/*first node*/
		createNode(head, data);
	}
	else
	{
		Node* currNode = *head;
		while (currNode->next != NULL)
		{
			currNode = currNode->next;
		}
		createNode(&currNode->next, data);
		currNode = currNode->next;
	}
}

int deleteNode(Node** head, int data)
{
	if (!head) {
		return 0;
	}

	Node* currNode = *head;
	/* if head node itself holds the key to be deleted*/
	if (currNode->data == data)
	{
		*head = currNode->next; /*change head*/
		free(currNode);
		return 1;
	}

	Node* prevNode = currNode;
	currNode = currNode->next;
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

int size(Node* head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}

	return count;
}

int isEmpty(Node* head)
{
	return head == NULL;
}

int find(Node* head, int data)
{
	while (head)
	{
		if (head->data == data) {
			return 1;
		}
		head = head->next;
	}
	return 0;
}

void printList(Node* head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void freeList(Node** head)
{
	Node* tempNode;
	while (*head != NULL)
	{
		tempNode = *head;
		*head = (*head)->next;
		free(tempNode);
	}
}

void reverseList(Node** head)
{
	if (size(*head) == 1 || isEmpty(*head)) {
		return;
	}

	Node *prevNode=NULL, *currNode=*head, *nextNode=NULL;

	while (currNode != NULL) 
	{
		nextNode = currNode->next;
		currNode->next = prevNode; /* Reverse current node's pointer*/
		prevNode = currNode;
		currNode = nextNode;
	}

	*head = prevNode;
}

Node* findMiddle(Node* head)
{
	Node *slowP, *fastP;
	slowP = fastP = head;

	while (fastP && fastP->next)
	{
		slowP= slowP->next;
		fastP = fastP->next->next;
	}

	return slowP;
}

