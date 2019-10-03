#pragma once
#include"street_t.h"
#include <vector>

using namespace std;

/*container of streets */
template<class TID>
class City_t {
public:
	City_t(); 
	City_t(const City_t&);
	City_t& operator=(const City_t&);

	void setCityID(const TID i_ID);
	TID getCityID() const;

	void AddStreet(const City_t<TID>);

	City_t<TID>getStreet(TID i_ID) const;

private:

	void updateStreetVec(const City_t& i_city);

	TID m_ID; /*ID of City can be of ANY type : strings "Herzl", or any another type*/
	vector<City_t<TID> > m_streetVec;
};

template<class TID>
City_t<TID>::City_t(){
}

template<class TID>
City_t<TID>::City_t(const City_t& i_city)
{
	m_ID = i_city.m_ID;
	updateStreetVec(i_city);
}

template<class TID>
City_t<TID>& City_t<TID>::operator=(const City_t<TID>& i_city)
{
	if (this != &i_city)
	{
		m_ID = i_city.m_ID;
		updateStreetVec(i_city);
	}

	return *this;
}

template<class TID>
void City_t<TID>::setCityID(const TID i_ID)
{
	m_ID = i_ID;
}

template<class TID>
TID City_t<TID>::getCityID() const
{
	return m_ID;
}

template<class TID>
void City_t<TID>::AddStreet(const City_t<TID> i_city)
{
	m_streetVec.puch_back(i_city);
}

template<class TID>
City_t<TID>City_t<TID>::getStreet(TID i_ID) const
{
	for(int i=0;i<m_streetVec.size();++i)
	{
       if(m_streetVec[i].getStreetID() == i_ID)
       {
       		return m_streetVec[i];
       }
    }

    return 0;
}

template<class TID>
void City_t<TID>::updateStreetVec(const City_t& i_city)
{
	for(int i=0;i<m_streetVec.size();++i)
	{
    	delete m_streetVec[i];
    }

    for(int i=0;i<i_city.m_streetVec.size();++i)
	{
    	m_streetVec[i] = i_city.m_streetVec[i];
    }
}
