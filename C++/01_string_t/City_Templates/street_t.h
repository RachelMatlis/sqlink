#pragma once

#include"building_t.h"
#include <vector>

using namespace std;

/*Container of buildings*/
template<class TIDb, class TIDs>
class Street_t {
public:
	Street_t<TIDb,TIDs>();
	Street_t<TIDb,TIDs>(TIDs);
	Street_t<TIDb,TIDs>(const Street_t&);
	Street_t<TIDb,TIDs>& operator=(const Street_t&);

	void setStreetID(const TIDs& i_ID);
	TIDs getStreetID() const;

	void AddBuilding2Street(const Building_t<TIDb>&);

	Building_t<TIDb> getBuilding(const TIDb&) const;

private:

	void updateBuildingsVec(const Street_t<TIDb, TIDs>&);

	TIDs m_ID; /*ID of street can be of ANY type : strings "Herzl", or even integers – 42, 20..*/
	vector< Building_t<TIDb> >m_buildingsVec;
};

template<class TIDb, class TIDs>
Street_t<TIDb,TIDs>::Street_t() {
}

template<class TIDb, class TIDs>
Street_t<TIDb,TIDs>::Street_t(TIDs i_ID) 
{
	m_ID = i_ID;
}

template<class TIDb, class TIDs>
Street_t<TIDb,TIDs>::Street_t(const Street_t<TIDb, TIDs>& i_street)
{
	m_ID = i_street.m_ID;
	updateBuildingsVec(i_street);
}

template<class TIDb, class TIDs>
Street_t<TIDb,TIDs>& Street_t<TIDb,TIDs>::operator=(const Street_t<TIDb,TIDs>& i_street)
{
	if (this != &i_street)
	{
		m_ID = i_street.m_ID;
		updateBuildingsVec(i_street);
	}

	return *this;
}

template<class TIDb, class TIDs>
void Street_t<TIDb,TIDs>::setStreetID(const TIDs& i_ID)
{
	m_ID = i_ID;
}

template<class TIDb, class TIDs>
TIDs Street_t<TIDb,TIDs>::getStreetID() const
{
	return m_ID;
}

template<class TIDb, class TIDs>
void Street_t<TIDb,TIDs>::AddBuilding2Street(const Building_t<TIDb>& i_building)
{
	m_buildingsVec.puch_back(i_building);
}

template<class TIDb, class TIDs>
Building_t<TIDb> Street_t<TIDb,TIDs>::getBuilding(const TIDb& i_ID) const
{
	for (int i = 0; i<m_buildingsVec.size(); ++i)
	{
		if (m_buildingsVec[i].getBuildingID() == i_ID)
		{
			return m_buildingsVec[i];
		}
	}

	return 0;
}

template<class TIDb, class TIDs>
void Street_t<TIDb,TIDs>::updateBuildingsVec(const Street_t<TIDb, TIDs>& i_street)
{
	for (int i = 0; i<m_buildingsVec.size(); ++i)
	{
		delete m_buildingsVec[i];
	}

	for (int i = 0; i<i_street.m_buildingsVec.size(); ++i)
	{
		m_buildingsVec[i] = i_street.m_buildingsVec[i];
	}
}
