#include<stdio.h>
#include<stdlib.h>
#include"binaryTree.h"

static void testFunc();

int main()
{
	testFunc();
	return 0;
}

void testFunc()
{
	int choice=0;
	tree* t;

	t = create();
	t = insert(t, 7);
	t = insert(t, 1);
	t = insert(t, 8);
	t = insert(t, 5);
	
	do
	{
		printf("\nChoose Function:\n");
		printf("1.\n");
		printf("2.\n");
		printf("3.\n");
		printf("4.\n");
		printf("5.Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("GoodBye!\n");
			break;
		default:
			break;
		}
	} while (choice !=5);

}





