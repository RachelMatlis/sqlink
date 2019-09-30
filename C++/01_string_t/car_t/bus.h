#pragma once

#include "car.h"

class Bus_t :public Car_t{
	public:
		Bus_t();
		Bus_t(size_t);
		Bus_t(const Bus_t& bus);
		~Bus_t();

		inline unsigned int getNumberOfSeats() const;
		inline void setNumberOfSeats(unsigned int);

		inline unsigned int getLineNumber() const;
		inline void setLineNumber(unsigned int);

	private:
		unsigned int m_numberOfSeats;
		unsigned int m_lineNumber;

};

inline unsigned int Bus_t::getNumberOfSeats() const
{ 
	return m_numberOfSeats;
}

inline void Bus_t::setNumberOfSeats(unsigned int i_numberOfSeats)
{ 
	m_numberOfSeats = i_numberOfSeats;
}

inline unsigned int Bus_t::getLineNumber() const
{ 
	return m_lineNumber;
}

inline void Bus_t::setLineNumber(unsigned int i_lineNumber)
{ 
	m_lineNumber = i_lineNumber;
}
