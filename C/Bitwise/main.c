#include "functions.h"
#include <stdio.h>
#include<stdlib.h>


int main()
{
	int choice = 0, nf =0,bitNumber=0;
	BitMap* bm;
	int bOn =0, bOf =0, bStatus =0;

	printf("Enter number of features:\n");
	scanf("%d", &nf);
	bm = crateBitMap(nf);
	printf("The Bit Map Array:\n");
	printArr(bm->m_arr, bm->m_size);

	do
	{
		printf("\n\nChoose option or quite:\n");
		printf("1. Bit on\n");
		printf("2. Bit off\n");
		printf("3. Bit status\n");
		printf("4. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter Bit number:\n");
			scanf("%d", &bitNumber);
			bOn= bitOn(bm, bitNumber);
			printf("value after Bit On: %d\n", bOn);
			break;
		case 2:
			printf("Enter Bit number:\n");
			scanf("%d", &bitNumber);
			bOf= bitOff(bm, bitNumber);
			printf("value after Bit Off: %d\n", bOn);
			break;
		case 3:
			printf("Enter Bit number:\n");
			scanf("%d", &bitNumber);
			bStatus = bitStatus(bm, bitNumber);
			bStatus == 1 ? printf("Bit %d is on.\n", bitNumber) : printf("Bit %d is off.\n", bitNumber);
			break;
		case 4:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 4);

	destroyBitMap(bm);
	return 0;
}


