#include "functions.h"


AD* create_AD(int meetingsAmount)
{
	AD* calendar = (AD*)malloc(sizeof(AD));

	if (calendar)
	{
		calendar->meetings = (int **)malloc(meetingsAmount * sizeof(int*)); /*array of meetings*/
		if (calendar->meetings == NULL)
		{
			free(calendar);
		}
		else
		{
			calendar->index = 0;
			calendar->meetingsAmount = meetingsAmount;
			return calendar;
		}
	}

	return NULL;
}

Meeting* create_meeting()
{
	float beginT = 0, endT = 0;
	int roomNumer = 0;
	Meeting* meeting;
	meeting = (Meeting*)malloc(sizeof(Meeting));

	if (meeting)
	{

		while (beginT >= endT || beginT> 23 || endT <= 1 || endT >24 || beginT < 0)
		{
			printf("Enter begin time: \n");
			scanf("%f", &beginT);
			if (beginT <  23 && beginT >0)
			{
				printf("Enter end time: \n");
				scanf("%f", &endT);
				if (beginT < endT && endT > 1 && endT <24)
				{
					break;
				}
			}

			printf("Invalid Input. Please try again\n");

		}

		printf("Enter room number: \n");
		scanf("%d", &roomNumer);

		meeting->beginT = beginT;
		meeting->endT = endT;
		meeting->roomNumer = roomNumer;
	}

	return meeting;
}

int insert_appointment_into_AD(AD* calendar, Meeting* meeting) /* insertion in sorted order ( by begin hour )*/
{
	int isAppointFound = 0, count = 0, i = 0, newLocation = 0, prevIndex=0;

	if (calendar && meeting && calendar->meetings)
	{
		prevIndex = calendar->index - 1;
		isAppointFound = find_appointment_in_AD(calendar, meeting->beginT); 
		if (isAppointFound ==0) /*if start time not used*/
		{
			if (calendar->index <= calendar->meetingsAmount) /*if enough space in array*/
			{
				if (!g_isFirstInsert) /*first insert*/
				{
					calendar->meetings[calendar->index] = meeting;
					calendar->index++;
					g_isFirstInsert = 1;
				}
				else
				{
					if (meeting->beginT > calendar->meetings[calendar->index - 1]->endT) /*new start time is bigger than prev end time*/
					{
						/*insert to the curr index*/
						calendar->meetings[calendar->index] = meeting;
						calendar->index++;
					}
					else if(meeting->beginT < calendar->meetings[prevIndex]->endT) /*new start time is smaller than prev end time*/
					{
						while (meeting->beginT < calendar->meetings[prevIndex]->endT && prevIndex > 0) 
						{
							count++; /*count how many prev ends time is smaller than new start time */
							prevIndex--; /*save the index when start time is bigger than end time founded*/
						}
						i = calendar->index - count; /*  2-1 =1 */
						newLocation = i;
						for (i; i <= calendar->index; i++)
						{
							calendar->meetings[i+1] = calendar->meetings[i]; /*shift right*/
						}

						calendar->meetings[newLocation] = meeting;
						calendar->index++;

					}
				}
			}
			else
			{
				calendar->meetings = realloc(calendar->meetingsAmount * 2, sizeof(int**));
				/*chek is calnder->meeting !=NULL*/
				calendar->meetingsAmount *= 2;
				/* insert:  calendar->meetings[..]  =   meeting  */
				calendar->index++;

			}
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

void remove_appointment_from_AD(Meeting* meeting) /* by begin hour )*/
{

}

int find_appointment_in_AD(AD* calendar, float beginT) /*by begin hour*/
{
	int i = 0;
	if (calendar && calendar->meetings)
	{
		for (i; i< calendar->index; i++)
		{
			if (calendar->meetings[i]->beginT == beginT)
			{
				return 1;
			}
		}
	}

	return 0;
}

void destroy_AD(AD* calendar)
{
	int i = 0;
	if (calendar)
	{
		if (calendar->meetings)
		{
			for (i; i < calendar->index; i++)
			{
				free(calendar->meetings[i]);
			}
		}

		free(calendar);
	}
}

void print_AD(AD* calendar)
{
	int i = 0;
	if (calendar && calendar->meetings)
	{
		for (i; i < calendar->index; i++)
		{
			printf("Appointment #%d :\n", i + 1);
			printf("Begin Time: %f\n", calendar->meetings[i]->beginT);
			printf("End Time: %f\n", calendar->meetings[i]->endT);
			printf("Room Number: %d\n", calendar->meetings[i]->roomNumer);
			printf("\n");
		}
	}
}



