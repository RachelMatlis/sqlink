#include"stack.h"
#include <stdio.h> 
#include <stdlib.h>

void createStack(Stack** stack)
{
	*stack = (Stack*)malloc(sizeof(Stack));
	(*stack)->top = NULL;
}

void push(Stack** stack, int data)
{
	StackNode* newtop = (StackNode*)malloc(sizeof(StackNode));
	if (!newtop) {
		return;
	}

	newtop->data = data;

	if ((*stack)->top == NULL)
	{
		/*empty stack*/
		newtop->next = NULL;
	}
	else
	{
		/*new top*/
		newtop->next = (*stack)->top;
	}

	(*stack)->top = newtop;
}

int pop(Stack** stack)
{
	if ((*stack)->top)
	{
		StackNode* currtop = (*stack)->top;
		int data = currtop->data;
		(*stack)->top = currtop->next;
		free(currtop);
		return data;
	}

	return -1;
}

int top(Stack* stack)
{
	if (stack->top)
	{
		return stack->top->data;
	}

	return -1;
}

int isEmpty(Stack* stack)
{
	return stack->top == NULL;
}

void printStack(Stack* stack)
{
	StackNode* currtop = stack->top;
	while (currtop)
	{
		printf("%d ", currtop->data);
		currtop = currtop->next;
	}
	printf("\n");
}

void freeStack(Stack** stack)
{
	StackNode* currtop = (*stack)->top;
	while (currtop)
	{
		(*stack)->top= (*stack)->top->next;
		free(currtop);
		currtop = (*stack)->top;
	}
}