#pragma once
#include<string>


using namespace std;

class Meeting
{
public:
	Meeting(const float &b, const float &e, const string& s);
	~Meeting();
	float getBegin() const {return m_begin};
	float getEnd() const {return m_end};
	string getSubject() const {return m_subject};
	
private:
	void createMeeting(const float &b, const float &e, const string& s);

	float m_begin;
	float m_end;
	string m_subject;
};

Meeting::Meeting(const float &b, const float &e, const string& s):
{
	createMeeting(b, e, s);
}

void Meeting::createMeeting(const float &b, const float &e, const string& s)
{
	/*0- 24 */
	if(b < e  && b > 0  && b < 24 && e < 24 && e > 0)
	{
		m_begin = b;
		m_end = e;
		m_subject = s;
	}
	else
	{
		throw string("Invalid input");
	}
}


