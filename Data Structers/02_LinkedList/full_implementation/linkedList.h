#pragma once

typedef struct node
{
	int data;
	struct node* next;
}Node;

/*Basic functions*/
void insert(Node**, int);
int deleteNode(Node** , int);
int size(Node*);
int isEmpty(Node*);
int find(Node* , int);
void printList(Node*);
void freeList(Node**);

/*Advanced functions */
void reverseList(Node**);
Node* findMiddle(Node*);
