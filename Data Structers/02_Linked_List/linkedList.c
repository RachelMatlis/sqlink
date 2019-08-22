#include<stdio.h>
#include<stdlib.h>

#include"linkedList.h"


node_t* createList()
{
	/*Now we can use the nodes. Let's create a local variable which points to the first item of the list (called head).*/
	node_t *head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) 
	{

	    return NULL;
	}
	
	head->val =1;
	head->next = NULL;
	return head;
}

/*Adding an item to the end of the list*/
node_t* push(node_t* head, int val) 
{
    node_t* current = head;

    while (current->next != NULL) 
    {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current = current->next;
    current-> val = val;
    current->next = NULL;

    return head;
}