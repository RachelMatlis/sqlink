#pragma once

#include"building_t.h"
#include <vector>

using namespace std;

/*Container of buildings*/
template<class TIDb, class TIDs>
class Street_t {
public:
	Street_t<TIDb, TIDs>();
	Street_t<TIDb, TIDs>(TIDs);
	Street_t<TIDb, TIDs>(const Street_t&);
	Street_t<TIDb, TIDs>& operator=(const Street_t&);

	void setStreetID(const TIDs& i_ID);
	const TIDs& getStreetID() const;

	void addBuilding2Street(const Building_t<TIDb>&);

	const Building_t<TIDb>& getBuilding(const TIDb&) const;

private:
	TIDs m_ID; /*ID of street can be of ANY type : strings "Herzl", or even integers – 42, 20..*/
	vector< Building_t<TIDb> > m_buildings;
};

template<class TIDb, class TIDs>
Street_t<TIDb, TIDs>::Street_t() {
}

template<class TIDb, class TIDs>
Street_t<TIDb, TIDs>::Street_t(TIDs i_ID)
{
	m_ID = i_ID;
}

template<class TIDb, class TIDs>
Street_t<TIDb, TIDs>::Street_t(const Street_t<TIDb, TIDs>& i_street)
{
	m_ID = i_street.m_ID;
	m_buildings = i_street.m_buildings;
}

template<class TIDb, class TIDs>
Street_t<TIDb, TIDs>& Street_t<TIDb, TIDs>::operator=(const Street_t<TIDb, TIDs>& i_street)
{
	if (this != &i_street)
	{
		m_ID = i_street.m_ID;
		m_buildings = i_street.m_buildings;
	}

	return *this;
}

template<class TIDb, class TIDs>
void Street_t<TIDb, TIDs>::setStreetID(const TIDs& i_ID)
{
	m_ID = i_ID;
}

template<class TIDb, class TIDs>
const TIDs& Street_t<TIDb, TIDs>::getStreetID() const
{
	return m_ID;
}

template<class TIDb, class TIDs>
void Street_t<TIDb, TIDs>::addBuilding2Street(const Building_t<TIDb>& i_building)
{
	m_buildings.push_back(i_building);
}

template<class TIDb, class TIDs>
const Building_t<TIDb>& Street_t<TIDb, TIDs>::getBuilding(const TIDb& i_ID) const
{
	int i = 0;
	for (; i<m_buildings.size(); ++i)
	{
		if (m_buildings[i].getBuildingID() == i_ID)
		{
			return m_buildings[i];
		}
	}

	throw i;
}

