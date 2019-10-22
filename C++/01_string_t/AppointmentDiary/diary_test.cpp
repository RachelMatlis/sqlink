#include "diary.h"
#include<iostream>

using namespace std;

void addMeeting(AD* diary);
void removeMeeting(AD* diary);
void findMeeting(AD* diary);

int main()
{
	int choice=0;
	AD diary;

	while (choice != 5)
	{
		cout << "Choose option:" << endl;
		cout << "1. Add meeting" << endl;
		cout << "2. Remove meeting" << endl;
		cout << "3. Find meeting" << endl;
		cout << "4. Clean diary" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			addMeeting(&diary);
			break;
		case 2:
			removeMeeting(&diary);
			break;
		case 3:
			findMeeting(&diary);
			break;
		case 4:
			diary.clean();
			cout << "--> Diary has cleaned!" << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}

void addMeeting(AD* diary)
{
	float start, end;
	string subject;
	bool isInserted;

	cout << "Start: ";
	cin >> start;
	cout << "End: ";
	cin >> end;
	cout << "Subject: ";
	cin >> subject;
	cout << endl;

	try
	{
		Meeting m(start, end, subject);
		isInserted = (*diary).insert(&m);
		if (isInserted)
		{
			cout << "--> Meeting has inserted!" << endl;
		}
		else
		{
			cout << "--> Meetings can’t overlap!" << endl;
		}

	}
	catch (string s)
	{
		cout << "ERROR! -" << s << endl;
	}
}

void removeMeeting(AD* diary)
{
	float startT;
	bool isRemoved;

	cout << "Enter start time: ";
	cin >> startT;
	isRemoved = diary->remove(startT);
	if (isRemoved)
	{
		cout << "--> Meeting has Removed!" << endl;
	}
	else
	{
		cout << "--> Meeting not found" << endl;
	}

}

void findMeeting(AD* diary)
{
	float startT;
	cout << "Enter start time: ";
	cin >> startT;
	string yesOrNo;

	Meeting* meeting = diary->find(startT);
	cout << "--> Meeting has ";
	meeting != 0 ? cout << "found!" : cout << "not found!";
	cout<< endl;
}