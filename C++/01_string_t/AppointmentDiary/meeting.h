#pragma once
#include<string>


using namespace std;

class Meeting
{
public:
	Meeting(const float &b, const float &e, const string& s);
	inline float getBegin() const;
	inline float getEnd() const;
	inline string getSubject() const;

private:
	Meeting(const Meeting&) {};
	Meeting& operator=(const Meeting&) {};

	void createMeeting(const float &b, const float &e, const string& s);
	string checkInput(const float &b, const float &e);

	float m_begin;
	float m_end;
	string m_subject;
};

inline float Meeting::getBegin() const
{
	return m_begin;
}

inline float Meeting::getEnd() const
{ 
	return m_end; 
}

inline string Meeting::getSubject() const
{
	return m_subject;
}


