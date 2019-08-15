#include "functions.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{
	int choice = 0;
	BitMap* bm;
	int nf;
	int n = 60;

	do
	{
		printf("\nChoose option or quite:\n");
		printf("1. Crate Bit\n");
		printf("2. Bit on\n");
		printf("3. Bit off\n");
		printf("4. Bit status\n");
		printf("5. Print date\n");
		printf("6. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter number of features:\n");
			scanf("%d", &nf);
			bm = crateBitMap(nf);
			break;
		case 2:
			bitOn(bm, n);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 6);
	return 0;
}


