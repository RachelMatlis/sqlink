#pragma once

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct list
{
	Node* head;
}List;

/*Basic operations*/
void createList(List**);
void insert(List** , int);
int deleteNode(List** , int);
int find(List*, int);
int size(List*);
int isEmpty(List*);
void freeList(List**);

void printList(List*);

/*Advanced operations */
void reverseList(List**);
int findMiddle(List*);
