#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/*describes time objects*/
typedef struct{
	int minutes;
	int seconds;
	int hours;
}cTime_t;

/*describes date objects*/
typedef struct{
	int day; 
	int month; 
	int year;
	int dayInYear; 
	int isLeap;
	char nameOfMonth[20];
	

}cDate_t;

cTime_t* set_new_time_to_existing_object(cTime_t *time); 
void print_time(cTime_t *time); /*13:23:12*/
int retrieve_minutes(cTime_t *time);
int retrieve_seconds(cTime_t *time);
int retrieve_hours(cTime_t *time);
cTime_t* addition_times(cTime_t *time1, cTime_t *time2);


cDate_t* change_date_of_existing_object(cDate_t *date);
void print_date(cDate_t *date);
int retrieve_day(cDate_t *date);
int retrieve_month(cDate_t *date);
int retrieve_year(cDate_t *date);


#endif

