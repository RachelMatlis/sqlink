#include"car.h"

using namespace std;

unsigned int Car_t::s_idHelper = 1000;
size_t Car_t::s_defCap = 1500;

/*def ctor*/
Car_t::Car_t() :
	m_id(s_idHelper++), m_cap(s_defCap){}

/*ctor with param*/
Car_t::Car_t(size_t capacity) :
	m_id(s_idHelper++), m_cap(capacity){}

/*copy ctor*/
Car_t::Car_t(const Car_t& car) :
	m_id(s_idHelper++)
{
	m_name = car.m_name;
	m_cap = car.m_cap;
	m_typeOfGear = car.m_typeOfGear;
}

/*d'ctor*/
Car_t::~Car_t(){}

/*assigment operator*/
//Car_t& Car_t::operator=(const Car_t& car)
//{
//	m_name = car.m_name;
//	m_cap = car.m_cap;
//	m_typeOfGear = car.m_typeOfGear;
//}

bool Car_t::operator<(const Car_t& car) const
{
	return m_cap < car.m_cap;
}

bool Car_t::compareType(const Car_t& car)
{
	return m_name == car.m_name;
}



