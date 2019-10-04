#pragma once

#include"street_t.h"
#include <vector>

using namespace std;

/*container of streets */
template<class TIDb, class TIDs, class TIDc>
class City_t {
public:
	City_t<TIDb, TIDs, TIDc>();
	City_t<TIDb, TIDs, TIDc>(const City_t&);
	City_t<TIDb, TIDs, TIDc>& operator=(const City_t&);

	void setCityID(const TIDc&);
	const TIDc& getCityID() const;

	void AddStreet(const Street_t<TIDb, TIDs>&);

	const Street_t<TIDb, TIDs>& getStreet(TIDs i_ID) const;

private:
	TIDc m_ID; /*ID of City can be of ANY type : strings "Herzl", or any another type*/
	vector<Street_t<TIDb, TIDs> > m_streets;
};

template<class TIDb, class TIDs, class TIDc>
City_t<TIDb, TIDs, TIDc>::City_t() {
}

template<class TIDb, class TIDs, class TIDc>
City_t<TIDb, TIDs, TIDc>::City_t(const City_t& i_city)
{
	m_ID = i_city.m_ID;
	m_streets = i_city.m_streets;
}

template<class TIDb, class TIDs, class TIDc>
City_t<TIDb, TIDs, TIDc>& City_t<TIDb, TIDs, TIDc>::operator=(const City_t<TIDb, TIDs, TIDc>& i_city)
{
	if (this != &i_city)
	{
		m_ID = i_city.m_ID;
		m_streets = i_city.m_streets;
	}

	return *this;
}

template<class TIDb, class TIDs, class TIDc>
void City_t<TIDb, TIDs, TIDc>::setCityID(const TIDc& i_ID)
{
	m_ID = i_ID;
}

template<class TIDb, class TIDs, class TIDc>
const TIDc& City_t<TIDb, TIDs, TIDc>::getCityID() const
{
	return m_ID;
}

template<class TIDb, class TIDs, class TIDc>
void City_t<TIDb, TIDs, TIDc>::AddStreet(const Street_t<TIDb, TIDs>& i_street)
{
	m_streets.push_back(i_street);
}

template<class TIDb, class TIDs, class TIDc>
const Street_t<TIDb, TIDs>& City_t<TIDb, TIDs, TIDc>::getStreet(TIDs i_ID) const
{
	for (int i = 0; i<m_streets.size(); ++i)
	{
		if (m_streets[i].getStreetID() == i_ID)
		{
			return m_streets[i];
		}
	}

	throw string("Street ID not found");
}

