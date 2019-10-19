#include"diary.h"
#include<iostream>

using namespace std;


AD::AD()
{

}

AD::~AD()
{
	iter iterator = m_meetings.begin();
	Meeting* meet;
	while (iterator != m_meetings.end())
	{
		//meet = iterator->second;
		//m_meetings.erase(iterator);
		//++iterator;
		//delete meet;
	}
}

bool AD::insert(Meeting* m)
{
	float startT = m->getBegin();
	iter iterator = m_meetings.begin();

	if (m_meetings.empty() || (--m_meetings.end())->second->getEnd() <= m->getBegin()) /*check if first/last meeting */
	{
		m_meetings[startT] = m;
		return true;
	}

	/* Meetings can’t overlap */
	while (iterator->second->getEnd() <= startT)
	{
		iterator++;
	}
	
	if (iterator->first >= m->getEnd()) 
	{
		m_meetings[startT] = m;
		return true;
	}

	return false;
}

Meeting* AD::find(const float& begin) const
{
	iterConst iterator= m_meetings.find(begin);

	return iterator == m_meetings.end() ? 0 : iterator->second;
}

bool AD::remove(const float& begin)
{
	iterConst iterator = m_meetings.find(begin);
	if (iterator != m_meetings.end())
	{
		m_meetings.erase(iterator);
		return true;
	}
	return false;
}

void AD::clean()
{
	if (!m_meetings.empty())
	{
		m_meetings.clear();
	}
}

