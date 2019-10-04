#pragma once

#include"street_t.h"
#include <vector>

using namespace std;

/*container of streets */
template<class TIDb, class TIDs, class TIDc>
class City_t {
public:
	City_t<TIDb, TIDs,TIDc>();
	City_t<TIDb, TIDs,TIDc>(const City_t&);
	City_t<TIDb, TIDs,TIDc>& operator=(const City_t&);

	void setCityID(const TIDc&);
	TIDc getCityID() const;

	void AddStreet(const Street_t<TIDb, TIDs>& );

	Street_t<TIDb, TIDs>getStreet(TIDs i_ID) const;

private:

	void updateStreetVec(const City_t<TIDb, TIDs, TIDc>& i_city);

	TIDc m_ID; /*ID of City can be of ANY type : strings "Herzl", or any another type*/
	vector<City_t<TIDb, TIDs, TIDc> > m_streetVec;
};

template<class TIDb, class TIDs, class TIDc>
City_t<TIDb, TIDs,TIDc>::City_t() {
}

template<class TIDb, class TIDs, class TIDc>
City_t<TIDb, TIDs,TIDc>::City_t(const City_t& i_city)
{
	m_ID = i_city.m_ID;
	updateStreetVec(i_city);
}

template<class TIDb, class TIDs, class TIDc>
City_t<TIDb, TIDs,TIDc>& City_t<TIDb, TIDs,TIDc>::operator=(const City_t<TIDb, TIDs,TIDc>& i_city)
{
	if (this != &i_city)
	{
		m_ID = i_city.m_ID;
		updateStreetVec(i_city);
	}

	return *this;
}

template<class TIDb, class TIDs, class TIDc>
void City_t<TIDb, TIDs,TIDc>::setCityID(const TIDc& i_ID)
{
	m_ID = i_ID;
}

template<class TIDb, class TIDs, class TIDc>
TIDc City_t<TIDb, TIDs,TIDc>::getCityID() const
{
	return m_ID;
}

template<class TIDb, class TIDs, class TIDc>
void City_t<TIDb, TIDs,TIDc>::AddStreet(const Street_t<TIDb, TIDs>& i_street)
{
	m_streetVec.puch_back(i_street);
}

template<class TIDb, class TIDs, class TIDc>
Street_t<TIDb,TIDs>City_t<TIDb, TIDs,TIDc>::getStreet(TIDs i_ID) const
{
	for (int i = 0; i<m_streetVec.size(); ++i)
	{
		if (m_streetVec[i].getStreetID() == i_ID)
		{
			return m_streetVec[i];
		}
	}

	return 0;
}

template<class TIDb, class TIDs, class TIDc>
void City_t<TIDb, TIDs,TIDc>::updateStreetVec(const City_t<TIDb, TIDs, TIDc>& i_city)
{
	for (int i = 0; i<m_streetVec.size(); ++i)
	{
		delete m_streetVec[i];
	}

	for (int i = 0; i<i_city.m_streetVec.size(); ++i)
	{
		m_streetVec[i] = i_city.m_streetVec[i];
	}
}