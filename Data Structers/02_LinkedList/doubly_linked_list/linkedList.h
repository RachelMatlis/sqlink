#pragma once

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
}Node;

typedef struct d_list
{
	Node* head;
}Doubly_List;

/*Basic operations*/
void createList(Doubly_List**);
void insert(Doubly_List** , int);
int deleteNode(Doubly_List** , int);
void freeList(Doubly_List**);

void printList(Doubly_List*);
void printListRevesly(Doubly_List*);




