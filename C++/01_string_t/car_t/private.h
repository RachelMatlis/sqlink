#pragma once
#include "car.h"

class Private_t: public Car_t {

	public:
		Private_t();
		~Private_t();
		Private_t(size_t);
		Private_t(const Private_t&);

		inline int getSpeed() const;
		inline void accelerate();
		inline void reduceSpeed();

	private:
		int m_speed;

};

inline int Private_t::getSpeed() const
{
	return m_speed;
}

inline void Private_t::accelerate()
{
	m_speed += 10;
}

inline void Private_t::reduceSpeed()
{
	if (m_speed != 0)
	{
		m_speed -= 10;
	}
}