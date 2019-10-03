#pragma once

using namespace std;

/*template clas*/
template<class TID>
class Building_t {
public:
	Building_t(); 
	Building_t(const Building_t&);
	Building_t& operator=(const Building_t&);

	void setBuidingID(const TID i_ID);
	TID getBuildingID() const;

private:
	TID m_ID; /*IDs can be integers (1,3,5,...) or even strings "A10" , "17Bet"..*/
};

template <class TID>
Building_t<TID>:: Building_t(){
}

template <class TID>
Building_t<TID>::Building_t(const Building_t<TID>& i_building)
{
	m_ID = i_building.m_ID;
}

template <class TID>
Building_t<TID>& Building_t<TID>::operator=(const Building_t<TID>& i_building)
{
	if (this != &i_building)
	{
		m_ID = i_building.m_ID;
	}

	return *this;
}

template <class TID>
void Building_t<TID>::setBuidingID(const TID i_ID)
{
	m_ID = i_ID;
}

template <class TID>
TID Building_t<TID>::getBuildingID() const
{
	return m_ID;
}