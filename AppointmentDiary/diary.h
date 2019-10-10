#pragma once
#include"meeting.h"
#include<map>
using namespace std;

template<class C>
class AD
{
public:
	AD();
	~AD();
	void insert(const Meeting* m);
	void remove(const Meeting* m);
	Meeting* find(const float& hour) const;
	void clean();
private:
	//C m_meetings; /*meetings container*/ 
	map<float,<Meeting*> > m_meetings;  
};


void AD::insert(const Meeting* m)
{
	/*Container of meetings has to be sorted by begin hour during insertion*/
	m_meetings[getBegin()] = m];
}




