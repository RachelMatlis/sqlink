#pragma once
#include"meeting.h"
#include<map>
#include <iterator> 
# include <algorithm>

using namespace std;

class AD
{
public:
	AD();
	~AD();
	bool insert(Meeting* m);
	bool remove(const float& begin);
	Meeting* find(const float& begin) const;
	void clean();
private:
	AD(const AD&) {};
	AD& operator=(const AD&) {};

	typedef typename map<float, Meeting*>::iterator iter;
	typedef typename map<float, Meeting*>::const_iterator iterConst;

	map<float, Meeting*> m_meetings; 
};

