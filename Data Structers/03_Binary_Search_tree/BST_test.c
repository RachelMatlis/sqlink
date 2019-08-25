#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

static void testFunc();

void printBST(Tree* t, TreeWalk order);

int main()
{
	testFunc();
	return 0;
}

void testFunc()
{
	int choice = 0;
	Tree* t;
	int isDataInTree = 0;

	t = createTree();
	insert(&t,7);
	insert(&t, 2);
	insert(&t, 8);
	insert(&t, 1);
	insert(&t, 5);

	isDataInTree = search(t, 15);

	walk(t, printBST, Preorder);

	destroy(&t);

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
	} while (choice != 5);

}

void printBST(Tree* t, TreeWalk order)
{
	switch (order)
	{
	case Preorder:
		break;
	case Inorder:
		break;
	case Postorder:
		break;
	default:
		break;
	}
}

