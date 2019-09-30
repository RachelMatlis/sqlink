#include"bus.h"


Bus_t::Bus_t()
{
	setTypeOfGear(Standart);
	setName("bus");
	setCapacity(1800);
	m_numberOfSeats = 0;
	m_lineNumber = 0;
}

Bus_t::Bus_t(size_t i_capacity) : 
	Car_t(i_capacity)
{
	setTypeOfGear(Standart);
	setName("bus");
	m_numberOfSeats = 0;
	m_lineNumber = 0;
}

Bus_t::Bus_t(const Bus_t& bus)
{

}

Bus_t::~Bus_t()
{

}