#include "private.h"

Private_t::~Private_t()
{}

Private_t::Private_t()
{
	m_speed = 0;
	setTypeOfGear(Automatic);
	setName("private");
	setCapacity(1500);
}

Private_t::Private_t(size_t capacity) :
	Car_t(capacity)
{
	m_speed = 0;
	setTypeOfGear(Automatic);
	setName("private");
}

Private_t::Private_t(const Private_t& p)
{
	m_speed = p.m_speed;
}



