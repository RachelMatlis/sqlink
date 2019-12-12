//#include <stdio.h>
#include"linkedList.h"
#include <stdio.h> 

#define EXIT -1

static void insertToList(Doubly_List** list);
static void showMenue();

int main()
{
	Doubly_List* list = NULL;
	int option, data, ret;;

	createList(&list);
	if (!list) {
		return 0;
	}

	showMenue();
	option = 1;
	while (option != EXIT)
	{
		printf("Choose option:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			insertToList(&list);
			break;
		case 2:
			printf("Enter data to delete:\n");
			scanf("%d", &data);
			ret = deleteNode(&list, data);
			printf("--> %d ", data);
			ret == 1 ? printf("was deleted\n") : printf("was not deleted\n");
			break;
		case 3:
			printf("--> list elements:\n");
			printList(list);
			break;
		case 4:
			printf("--> list revesly elements:\n");
			printListRevesly(list);
			break;
		case EXIT:
			printf("--> Goodbye\n");
			break;
		default:
			break;
		}
	}

	freeList(&list);
	return 0;
}

static void insertToList(Doubly_List** list)
{
	int data= 0;
	printf("Enter data (press -1 to stop):\n");
	scanf("%d", &data);
	while (data != -1)
	{
		insert(list, data);
		scanf("%d", &data);
	}
}

static void showMenue()
{
	printf("1. Insert to list\n");
	printf("2. Delete node\n");
	printf("3. Print list \n");
	printf("4. Print list reversly \n");
	printf("Press -1 to exit \n");
}
