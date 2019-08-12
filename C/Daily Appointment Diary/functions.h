#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/*Appointment Diary”*/
typedef struct{ 
	
	Meeting** meetings;
	int meetingsAmount;
	int index;
	
}AD;

typedef struct{ 
	
	float beginT;
	float endT;
	int roomNumer; 
	
}Meeting;

/* AD* meeting */

AD* create_AD(int meetingsAmount); 
Meeting* create_meeting();
int insert_appointment_into_AD(AD* calendar, Meeting* meeting, int* isFirstInsert); /* insertion in sorted order ( by begin hour )*/

void remove_appointment_from_AD(Meeting* meeting); 	/* by begin hour )*/
AD* find_appointment_in_AD(AD* calendar, float beginT); 		    /*by begin hour*/
void destroy_AD();
void print_AD();

#endif
