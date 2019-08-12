#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include<stdlib.h>

/*Meetings Array*/
typedef struct {

	float beginT;
	float endT;
	int roomNumer;

}Meeting;

/*Appointment Diary*/
typedef struct {

	Meeting** meetings;
	int meetingsAmount;
	int index;

}AD;

/* AD* meeting */

AD* create_AD(int meetingsAmount);
Meeting* create_meeting();
int insert_appointment_into_AD(AD* calendar, Meeting* meeting); /* insertion in sorted order ( by begin hour )*/
void remove_appointment_from_AD(Meeting* meeting); 	/* by begin hour )*/
int find_appointment_in_AD(AD* calendar, float beginT);   /*by begin hour*/
void destroy_AD(AD* calendar);
void print_AD(AD* calendar);

int g_isFirstInsert = 0;

#endif
