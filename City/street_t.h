#pragma once
#include"building_t.h"
#include <vector>

using namespace std;

/*Container of buildings*/
template<class TID>
class Street_t {
public:
	Street_t(); 
	Street_t(const Street_t&);
	Street_t& operator=(const Street_t&);

	void setStreetID(const TID i_ID);
	TID getStreetID() const;

	void AddBuilding2Street(const Building_t<TID>);

	Building_t<TID> getBuilding(TID i_ID) const;

private:

	void updatebuildingsVec(const Street_t&);

	TID m_ID; /*ID of street can be of ANY type : strings "Herzl", or even integers – 42, 20..*/
	vector< Building_t<TID> >m_buildingsVec; 
};

template<class TID>
Street_t<TID>::Street_t(){
}

template<class TID>
Street_t<TID>::Street_t(const Street_t& i_street)
{
	m_ID = i_street.m_ID;
	updatebuildingsVec(i_street);
}

template<class TID>
Street_t<TID>& Street_t<TID>::operator=(const Street_t<TID>& i_street)
{
	if (this != &i_street)
	{
		m_ID = i_street.m_ID;
		updatebuildingsVec(i_street);
	}

	return *this;
}

template<class TID>
void Street_t<TID>::setStreetID(const TID i_ID)
{
	m_ID = i_ID;
}

template<class TID>
TID Street_t<TID>::getStreetID() const
{
	return m_ID;
}

template<class TID>
void Street_t<TID>::AddBuilding2Street(const Building_t<TID> i_building)
{
	m_buildingsVec.puch_back(i_building);
}

template<class TID>
Building_t<TID> Street_t<TID>::getBuilding(TID i_ID) const
{
	for(int i=0;i<m_buildingsVec.size();++i)
	{
           if(m_buildingsVec[i].getBuildingID() == i_ID)
           {
           		return m_buildingsVec[i];
           }
    }

    return 0;
}

template<class TID>
void Street_t<TID>::updatebuildingsVec(const Street_t& i_street)
{
	for(int i=0;i<m_buildingsVec.size();++i)
	{
    	delete m_buildingsVec[i];
    }

    for(int i=0;i<i_street.m_buildingsVec.size();++i)
	{
    	m_buildingsVec[i] = i_street.m_buildingsVec[i];
    }
}