#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	cTime_t *time1,*time2;
	cDate_t *date;
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
				if(time1)
				{
					time1 = set_new_time_to_existing_object(time1);
				}
			break;
		case 2:
			print_time(time1);
			break;
		case 3:
			time2 = (cTime_t*)malloc(sizeof(cTime_t));
			if(time2)
			{
					time2 = set_new_time_to_existing_object(time2);
					addition_times(time1, time2);
			}
			break;
		case 4:
			date= (cDate_t*)malloc(sizeof(cDate_t));
			if(date)
			{
				date = change_date_of_existing_object(date);
			}
			break;
		case 5:
			print_date(date);
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



