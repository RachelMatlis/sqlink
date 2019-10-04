#pragma once

using namespace std;

/*template clas*/
template<class TIDb>
class Building_t {
public:
	Building_t<TIDb>();
	Building_t<TIDb>(TIDb);
	Building_t<TIDb>(const Building_t&);
	Building_t<TIDb>& operator=(const Building_t&);

	void setBuidingID(const TIDb& i_ID);
	TIDb getBuildingID() const;

private:
	TIDb m_ID; /*IDs can be integers (1,3,5,...) or even strings "A10" , "17Bet"..*/
};

template <class TIDb>
Building_t<TIDb>::Building_t() {
}

template <class TIDb>
Building_t<TIDb>::Building_t(TIDb i_ID) 
{
	m_ID = i_ID;
}

template <class TIDb>
Building_t<TIDb>::Building_t(const Building_t<TIDb>& i_building)
{
	m_ID = i_building.m_ID;
}

template <class TIDb>
Building_t<TIDb>& Building_t<TIDb>::operator=(const Building_t<TIDb>& i_building)
{
	if (this != &i_building)
	{
		m_ID = i_building.m_ID;
	}

	return *this;
}

template <class TIDb>
void Building_t<TIDb>::setBuidingID(const TIDb& i_ID)
{
	m_ID = i_ID;
}

template <class TIDb>
TIDb Building_t<TIDb>::getBuildingID() const
{
	return m_ID;
}
