#include <stdio.h>
#include<stdlib.h>
#include "functions.h"

int main(void)
{
	int meetingsAmount =0,isFirstInsert =1;
	AD* calendar = NULL;
	Meeting* meeting =NULL;

	do
	{
		printf("\nChoose function or quite:\n");
		printf("1. create_AD()\n");
		printf("2. create_meeting()\n");
		printf("3. insert_appointment_into_AD()\n");
		printf("4. remove_appointment_from_AD()\n");
		printf("5. find_appointment_in_AD()\n");
		printf("6. destroy_AD()\n");
		printf("7. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the amount of meetings: ");
			scanf("%d", &meetingsAmount);
			calendar = create_AD(meetingsAmount);	
			break;
		case 2:
			meeting = create_meeting();
			break;
		case 3:
			insert_appointment_into_AD(calendar,meeting, &isFirstInsert);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 7);
	
  return 0;
}
