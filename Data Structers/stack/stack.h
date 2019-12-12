#pragma once

typedef struct stack_node
{
	int data;
	struct node* next;
}StackNode;

typedef struct stack
{
	StackNode* top;
}Stack;


/*Basic operations*/
void createStack(Stack**);
void push(Stack**);
/*Removes and returns the top elemnt of stack*/
int pop(Stack**);
/*Returns top element of stack*/
int top(Stack*);
int isEmpty(Stack*);


void freeStack(Stack**);
void printStack(Stack*);


