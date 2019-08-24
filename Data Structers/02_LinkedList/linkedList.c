#include<stdio.h>
#include<stdlib.h>

#include"linkedList.h"


static int getListSize(node_t* head)
{
	int size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}

	return size;
}

/*Adding an item to the end of the list*/
node_t* pushToLinkedList(node_t* head, int val)
{
	node_t* current = NULL;

	/*first node*/
	if (head==NULL)
	{
		head = malloc(sizeof(node_t));
		head->val = val;
		head->next = NULL;
	}
	else
	{
		current = head;
		/*find the last elemnt*/
		while (current->next != NULL)
		{
			current = current->next;
		}

		/* add a new node to the end */
		current->next = malloc(sizeof(node_t));
		current = current->next;
		current->val = val;
		current->next = NULL;
	}

	return head;
}

node_t* flipLinkedList(node_t* head)
{
	node_t *prevNode = NULL, *currNode = NULL, *nextNode;
	currNode = head;

	while (currNode)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;  /* Reverse current node's pointer*/
		prevNode = currNode;
		currNode = nextNode;
	}

	head = prevNode;
}

node_t* findMiddleOfLinkedList(node_t* head)
{
	node_t* oneStepP = head;
	node_t* twoStepsP = head;

	if (head)
	{
		while (twoStepsP && twoStepsP->next)
		{
			twoStepsP = twoStepsP->next->next;
			oneStepP = oneStepP->next;
		}
	}

	return oneStepP;
}

int isALoopInALinkedList(node_t* head)
{
	node_t* oneStepP = head;
	node_t* twoStepsP = head;
	int isLoopFound = 0;

	if (head)
	{
		while (twoStepsP && twoStepsP->next && oneStepP)
		{
			twoStepsP = twoStepsP->next->next;
			oneStepP = oneStepP->next;

			/* If oneStepP and twoStepsP meet then there
			is a loop */
			if (twoStepsP == oneStepP)
			{
				isLoopFound = 1;
				break;
			}
		}
	}

	return isLoopFound;
}

node_t* FindComminNode(node_t* lst1, node_t* lst2)
{
	node_t *longerListP =NULL, *shorterListP = NULL;
	int sizeList1=0, sizeList2=0, diff=0, counter=0;

	sizeList1 = getListSize(lst1); /*calculate lists length*/
	sizeList2 = getListSize(lst2);

	if (sizeList1 > sizeList2) /*find the longer linked list*/
	{
		longerListP = lst1;
		shorterListP = lst2;
		diff = sizeList1 - sizeList2;
	}
	else
	{
		longerListP = lst2;
		shorterListP = lst1;
		diff = sizeList2 - sizeList1;
	}

	while (counter<diff) /*move diff nodes in longer linked list*/
	{
		longerListP = longerListP->next;
		counter++;
	}

	while (longerListP != shorterListP && shorterListP)
	{
		longerListP = longerListP->next;
		shorterListP = shorterListP->next;
	}

	return longerListP;

}