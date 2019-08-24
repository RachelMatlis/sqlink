#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"
#define SIZE 10

static void testFunc();

static node_t* setList(node_t* list);
static void printLinkedList(node_t* list);


int main()
{
	testFunc();
	return 0;
}

void testFunc()
{
	node_t* list = NULL;
	node_t* MidList = NULL;
	int choice=0;
	int isLoopFound = 0;

	printf("Linked List:\n");
	list = setList(list);
	printLinkedList(list);

	do
	{
		printf("\nChoose Function:\n");
		printf("1.Flip List\n");
		printf("2.Find Middle\n");
		printf("3.Find Loop\n");
		printf("4.Find Commin Node\n");
		printf("5.Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nFliped List:\n");
			list = flipLinkedList(list);
			printLinkedList(list);
			break;
		case 2:
			MidList = list;
			printf("Find Middle:\n");
			MidList = findMiddleOfLinkedList(list);
			printf("The middle element is <%d>\n", MidList->val);
			break;
		case 3:
			isLoopFound = isALoopInALinkedList(list);
			isLoopFound == 1 ? printf("Loop found!\n") : printf("Loop not found!\n");
			break;
		case 4:
			break;
		case 5:
			printf("GoodBye!\n");
			exit(1);
			break;
		default:
			break;
		}
	} while (1);

}


static node_t* setList(node_t* list)
{
	int i = 0;
	for (i; i < SIZE; i++)/*create some list*/
	{
		list = pushToLinkedList(list, i + 1);
	}

	return list;
}

static void printLinkedList(node_t* list)
{
	while (list->next)
	{
		printf("%d -> ", list->val);
		list = list->next;
	}

	printf("%d -> NULL\n", list->val);
}