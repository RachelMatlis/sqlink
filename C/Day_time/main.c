#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	cTime_t *time1, *time2;
	cDate_t *date1;
	int choice;

	do
	{
		printf("\nChoose option or quite:\n");
		printf("1. Set new time\n");
		printf("2. Print time\n");
		printf("3. Addition times\n");
		printf("4. Set date\n");
		printf("5. Print date\n");
		printf("6. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			time1 = (cTime_t*)malloc(sizeof(cTime_t));
			if (time1)
			{
				time1 = set_new_time_to_existing_object(time1);
			}
			break;
		case 2:
			print_time(time1);
			break;
		case 3:
			time2 = (cTime_t*)malloc(sizeof(cTime_t));
			if (time2)
			{
				time2 = set_new_time_to_existing_object(time2);
				addition_times(time1, time2);
			}
			break;
		case 4:
			date1 = (cDate_t*)malloc(sizeof(cDate_t));
			if (date1)
			{
				date1 = change_date_of_existing_object(date1);
			}
			break;
		case 5:
			if (date1)
			{
				print_date(date1);
			}
			break;
		case 6:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 6);

	free(time1);
	free(time2);
	free(date1);

	return 0;
}
