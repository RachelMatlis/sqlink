//#include <stdio.h>
#include"linkedList.h"
#include <stdio.h> 

#define EXIT -1

static void createList(Node** head);
static void showMenue();

int main()
{
	Node* head = NULL;
	int option =1;
	int data;
	int ret;

	showMenue();
	while (option != EXIT)
	{
		printf("Choose option:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 0:
			showMenue();
			break;
		case 1:
			createList(&head);
			break;
		case 2:
			printf("Enter data to find:\n");
			scanf("%d", &data);
			ret = find(head, data);
			printf("--> %d was", data);
			ret == 1 ? printf("found\n", data) : printf("not found\n", data);
			break;
		case 3:
			printf("Enter data to delete:\n");
			scanf("%d", &data);
			ret = deleteNode(&head, data);
			printf("--> %d ", data);
			ret == 1 ? printf("was deleted\n") : printf("was not deleted\n");
			break;
		case 4:
			printf("size of list:%d\n", size(head));
			break;
		case 5:
			ret = isEmpty(head);
			printf("--> list is ");
			ret == 1 ? printf("empty\n") : printf("not empty\n");
			break;
		case 6:
			reverseList(&head);
			break;
		case 7:
			printf("--> middle node data is: %d\n", findMiddle(head)->data);
			break;
		case 8:
			printf("--> list Elements:\n");
			printList(head);
			break;
		case EXIT:
			printf("--> Goodbye\n");
			break;
		default:
			break;
		}
	}

	freeList(&head);
	return 0;
}

static void createList(Node** head)
{
	int data= 0;
	printf("Enter data (press -1 to stop):\n");
	scanf("%d", &data);
	while (data != -1)
	{
		insert(head, data);
		scanf("%d", &data);
	}
}

static void showMenue()
{
	printf("0. Show menue\n");
	printf("1. Insert to list\n");
	printf("2. Find node\n");
	printf("3. Delete node\n");
	printf("4. Get list size\n");
	printf("5. Is list empty ?\n");
	printf("6. Reverse list \n");
	printf("7. Get middle node \n");
	printf("8. Print list \n");
	printf("Press -1 to exit \n");
}
