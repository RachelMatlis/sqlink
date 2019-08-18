#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
	char s1[] = "abcdefghijklmnop";
	char s2[] = "abcdefghijklmnop";
	int choice=0;
	
	do
	{
		printf("\n\nExercise Packing:\n");
		printf("1.Without bit field\n");
		printf("2. With bit field\n");
		printf("3. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			packWithoutBitField(s1);
			break;
		case 2:
			packWithBitField(s2);
			break;
		case 3:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 3);
	
	
	return 0;
}
