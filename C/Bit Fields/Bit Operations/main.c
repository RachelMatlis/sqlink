#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int choice=0;
	
	do
	{
		printf("\n\nChoose option or quite:\n");
		printf("1.Bits Inverts\n");
		printf("2 Rotate To Right.\n");
		printf("3.\n");
		printf("4. Quite\n");
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
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 4);
	
	
	return 0;
}
