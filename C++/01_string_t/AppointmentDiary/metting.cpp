#include"meeting.h"

Meeting::Meeting(const float &b, const float &e, const string& s)
{
	createMeeting(b, e, s);
}

void Meeting::createMeeting(const float &b, const float &e, const string& s)
{
	string checkInputRes = checkInput(b, e);
	if (checkInputRes == "OK")
	{
		m_begin = b;
		m_end = e;
		m_subject = s;
	}
	else
	{
		throw checkInputRes;
	}
}

string Meeting::checkInput(const float &b, const float &e)
{
	/*00:00 - 23:00 */
	if (b >= e)
	{
		return "Begin hour must be smaller than End hour.";
	}
	else if (b < 0 || b > 22)
	{
		return "Begin hour must be between (00:00 - 22:00).";
	}
	else if (e> 23 || e < 1)
	{
		return "End hour must be between (01:00 - 23:00).";
	}
	else
	{
		return "OK";
	}
}