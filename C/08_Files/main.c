/* To use the functions defined in Functions.c I need to #include Functions.h */
#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{

	int choice = 0;
	char fileName[100];

	do
	{
		printf("\nChoose function or quite:\n");
		printf("1. printLastN()()\n");
		printf("2. findFreqOfChar()\n");
		printf("3. findFreqOfword()\n");
		printf("4. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			break;
		case 2:
			printf("Enter file name: ");
			scanf("%s", fileName);
			findFreqOfChar(fileName);
			break;
		case 3:
			printf("Enter file name: ");
			scanf("%s", fileName);
			findFreqOfword(fileName);
			break;
		case 4:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 4);
	

	return 0;

}

