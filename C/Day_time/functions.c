#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


cTime_t* set_new_time_to_existing_object(cTime_t *time)
{
	int minutes, seconds, hours;
	
	if(!time){
		return NULL;
	}
	
	printf("Enter hours:\n");
	scanf("%d", &hours);
	printf("Enter minutes:\n");
	scanf("%d", &minutes);
	printf("Enter seconds:\n");
	scanf("%d", &seconds);

	time->hours= hours;
	time->minutes = minutes;
	time->seconds = seconds;

	
	return time;
}

void print_time(cTime_t *time)
{
	if(time)
	{
		if(time-> hours >=0 && time-> hours <=11)
		{
			printf("%d:%d:%d PM\n",time->hours, time->minutes, time->seconds);
		}
		else if(time-> hours >=12 && time-> hours <=23 );
		{
			printf("%d:%d:%d AM\n",time->hours, time->minutes, time->seconds);
		}
	}
}

int retrieve_minutes(cTime_t *time)
{
	if(time)
	{
		return time->minutes;
	}
	
	return 0;
}

int retrieve_seconds(cTime_t *time)
{
	if(time)
	{
		return time->seconds;
	}
	
	return 0;
}

int retrieve_hours(cTime_t *time)
{
	if(time)
	{
		return time->hours;
	}
	
	return 0;
}

cTime_t* addition_times(cTime_t *time1, cTime_t *time2)
{
	int h,m,s,h1,m1,s1,h2,m2,s2,day;
	s=h=m=day=0;
	s = time1->seconds + time2->seconds;
	if(s>60)
	{
		m = s/60;
		s = s%60;
	}
	
	m = m + time1->minutes + time2->minutes;
	
	if(m>60)
	{
		h=m/60;
		m=m%60;
	}
	
	h = h + time1->hours + time2->hours;
	
	if(h>24)
  	{
  		day=1;
  		h=h%24;
  	}
  	
  	printf("\n");
  	print_time(time1);
  	printf(" + ");
  	print_time(time2);
  	printf(" = ");
  	
  	
  	if(day==0)
  	{
  		printf("%d:%d:%d\n",h,m,s);
  	}
 	
	else
	{
		printf("%d day",day);
		printf("%d:%d:%d\n",h,m,s);
	}
}



cDate_t* change_date_of_existing_object(cDate_t *date)
{
	int day, month, year;
	
	if(!date){
		return NULL;
	}
	
	printf("Enter day:\n");
	scanf("%d", &day);
	printf("Enter month:\n");
	scanf("%d", &month);
	printf("Enter year:\n");
	scanf("%d", &year);

	date->day= day;
	date->month = month;
	date->year = year;
	
	date->nameOfMonth[0] = "Jan";
	
	return date;
}

void print_date(cDate_t *date)
{
	if(date)
	{
		printf("a) dd:%d,  mon:%d,  year:%d - %d/%s/%d\n",date->day, date->month, date->year,date->day, date->nameOfMonth, date->year);
													     
													    
		printf("b) dd:%d,  mon:%d,  year:%d - %d/%s/%d   ",date->day, date->month, date->year,date->day, date->month, date->nameOfMonth);
											     		  
		printf("European\n");
		
		printf("c) mon:%d,  dd:%d,  year:%d - %d/%s/%d   ",date->month, date->day, date->year,date->month, date->day, date->nameOfMonth);
									     		           
		printf("American\n");
	}
}
















