#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

static char* months[12] = { "January","February" ,"March" ,"April" ,"May","June","July","August","September","October","November","December" };
static int daysInM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

cTime_t* set_new_time_to_existing_object(cTime_t *time)
{
	int minutes, seconds, hours;

	if (!time) {
		return NULL;
	}

	printf("Enter hours:\n");
	scanf("%d", &hours);
	printf("Enter minutes:\n");
	scanf("%d", &minutes);
	printf("Enter seconds:\n");
	scanf("%d", &seconds);

	time->hours = hours;
	time->minutes = minutes;
	time->seconds = seconds;


	return time;
}

void print_time(cTime_t *time)
{
	if (time)
	{
		if (time->hours >= 0 && time->hours <= 11)
		{
			printf("a) %d:%d:%d\n", time->hours +12, time->minutes, time->seconds);
			printf("b) %d:%d:%d PM\n", time->hours, time->minutes, time->seconds);
		}
		else if (time->hours >= 12 && time->hours <= 23);
		{
			printf("a) %d:%d:%d\n", time->hours, time->minutes, time->seconds);
			printf("b) %d:%d:%d PM\n", time->hours-12, time->minutes, time->seconds);
		}
	}
}

int retrieve_minutes(cTime_t *time)
{
	if (time)
	{
		return time->minutes;
	}

	return 0;
}

int retrieve_seconds(cTime_t *time)
{
	if (time)
	{
		return time->seconds;
	}

	return 0;
}

int retrieve_hours(cTime_t *time)
{
	if (time)
	{
		return time->hours;
	}

	return 0;
}

cTime_t* addition_times(cTime_t *time1, cTime_t *time2)
{
	int h, m, s, h1, m1, s1, h2, m2, s2, day;
	s = h = m = day = 0;
	s = time1->seconds + time2->seconds;
	if (s>60)
	{
		m = s / 60;
		s = s % 60;
	}

	m = m + time1->minutes + time2->minutes;

	if (m>60)
	{
		h = m / 60;
		m = m % 60;
	}

	h = h + time1->hours + time2->hours;

	if (h>24)
	{
		day = 1;
		h = h % 24;
	}

	printf("\n");
	print_time(time1);
	printf(" + ");
	print_time(time2);
	printf(" = ");


	if (day == 0)
	{
		printf("%d:%d:%d\n", h, m, s);
	}

	else
	{
		printf("%d day", day);
		printf("%d:%d:%d\n", h, m, s);
	}
}



cDate_t* change_date_of_existing_object(cDate_t *date)
{
	int day, month, year;
	char *nameOfMonth[10];

	if (!date) {
		return NULL;
	}

	printf("Enter day:\n");
	scanf("%d", &day);
	printf("Enter month:\n");
	scanf("%d", &month);
	printf("Enter year:\n");
	scanf("%d", &year);

	date->day = day;
	date->month = month;
	date->year = year;
	date->dayInYear = retrieve_day_of_year(date);
	date->isLeap = is_leap(date);

	return date;
}

void print_date(cDate_t *date)
{
	if (date)
	{
		printf("a) dd:%d,  mon:%d,  year:%d - %d/%s/%d\n", date->day, date->month, date->year, date->day, months[(date->month) - 1], date->year);


		printf("b) dd:%d,  mon:%d,  year:%d - %d/%d/%d   ", date->day, date->month, date->year, date->day, date->month, date->year);

		printf("European\n");

		printf("c) mon:%d,  dd:%d,  year:%d - %d/%d/%d   ", date->month, date->day, date->year, date->month, date->day, date->year);

		printf("American\n");
	}
}

int retrieve_day(cDate_t *date)
{
	if (date)
	{
		return date->day;
	}

	return 0;
}
int retrieve_month(cDate_t *date)
{
	if (date)
	{
		return date->month;
	}

	return 0;
}
int retrieve_year(cDate_t *date)
{
	if (date)
	{
		return date->year;
	}

	return 0;
}

/*Day of year is a number between 1 and 365 (or 366, if leap year).
To calculate the day of year we simply add days in the given month to the days in the previous months.*/
int retrieve_day_of_year(cDate_t *date)
{
	int day, mon, year, days_in_feb = 28;
	int doy;    // day of year

	day = date->day;
	mon = date->month;
	year = date->year;

	doy = date->day;

	if (is_leap(date)) /* check for leap year*/
	{
		days_in_feb = 29;
	}

	switch (mon)
	{
	case 2:
		doy += 31;
		break;
	case 3:
		doy += 31 + days_in_feb;
		break;
	case 4:
		doy += 31 + days_in_feb + 31;
		break;
	case 5:
		doy += 31 + days_in_feb + 31 + 30;
		break;
	case 6:
		doy += 31 + days_in_feb + 31 + 30 + 31;
		break;
	case 7:
		doy += 31 + days_in_feb + 31 + 30 + 31 + 30;
		break;
	case 8:
		doy += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31;
		break;
	case 9:
		doy += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10:
		doy += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11:
		doy += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12:
		doy += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		break;
	}

	return doy;
}

int is_leap(cDate_t *date)
{
	return date->year % 4 == 0 ? 1 : 0;

}

char* name_of_month(int month)
{
	return months[month - 1];
}

cDate_t* addition_date(cDate_t* date1, cDate_t* date2)
{
	int dayF, monthF;
	dayF = (date1->day + date2->day) > daysInM[(date1->month) - 1] ? 1 : 0;
	monthF = (date1->month + dayF) / 12;
	date1->day = (date1->day + date2->day) % (daysInM[(date1->month) - 1]);
	date1->month = (date1->month + dayF) % 12;
	date1->year = (date1->year + monthF);
}



