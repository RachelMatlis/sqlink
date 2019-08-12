#include "functions.h"


AD* create_AD(int meetingsAmount)
{
	AD* calendar = (AD*)malloc(sizeof(AD)); 
	
	if(calendar)
    {
        calendar->meetings = (int **)malloc(meetingsAmount* sizeof(int*)); /*array of meetings*/
        if(calendar->meetings == NULL)
        {
        	free(calendar);
        }
        else
        {
        	calendar->index = 0;
			calendar-> meetingsAmount = meetingsAmount;
			return calendar;
        } 
	}

	return NULL;
}

Meeting* create_meeting()
{
	float beginT=0, endT=0;
	int roomNumer=0; 
	Meeting* meeting;
	meeting = (Meeting*)malloc(sizeof(Meeting));
	
	if(meeting)
	{
		printf("Enter begin time: \n");
		scanf("%d",&begin);
		printf("Enter end time: \n");
		scanf("%d",&endT);
		printf("Enter room number: \n");
		scanf("%d",&roomNumer);
					
		meeting->beginT = beginT;
		meeting->endT = endT;
		meeting->roomNumer = roomNumer;	
	}
	
	return meeting;
}

int insert_appointment_into_AD(AD* calendar, Meeting* meeting, int* isFirstInsert) /* insertion in sorted order ( by begin hour )*/
{
	if(calendar && meeting && calendar->meetings)
	{
		if(isFirstInsert)
		{
			calendar->meetings[index] = meeting;
			*isFirstInsert= 0;
			calendar->index++;	
		}
		else
		{
			if(meeting -> endT < calendar -> meetings[index-1] -> beginT)
			{
				
			}
			else if(meeting -> beginT > calendar -> meetings[index-1] -> endT)
			{
				
			}
		}
		
		if(calendar -> index => calendar -> meetingsAmount)
		{
			calendar->meetings = realloc(calendar->meetingsAmount*2, sizeof(int**));
/*chek is calnder->meeting !=NULL*/
			calendar->meetingsAmount*=2;
			/* insert:  calendar->meetings[..]  =   meeting  */
			calendar->index++;
				
		}
	}
}
 	
void remove_appointment_from_AD() /* by begin hour )*/
{

} 	

AD* find_appointment_in_AD(AD* calendar, float beginT) /*by begin hour*/
{
	int i=0;
	if(calendar)
	{
		for(i; i< calendar->index;i++)
		{
			if(calendar -> meetings[i] -> beginT == beginT)
			{
				return calendar -> meetings[i];
			}
		}
	}
	
	return NULL;
}
 		
void destroy_AD()
{
}

void print_AD()
{
}




