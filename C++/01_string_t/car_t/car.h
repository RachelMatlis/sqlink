#pragma once
#include <string>
using namespace std;

enum Gir { Standart, Automatic };

/*describes any kind of car*/
class Car_t {
	public:
		Car_t();
		Car_t(size_t capacity);
		Car_t(const Car_t& car);
		Car_t& operator= (const  Car_t& car) 
		{ 
			m_cap = car.m_cap;
		};

		inline const unsigned int getId() const;
		inline string getName() const;
		inline const Gir getTypeOfGear() const;
		inline size_t getCapacity() const;

		bool operator<(const Car_t& car) const;
		bool compareType(const Car_t& car);
		
	protected:
		~Car_t();
		
		 inline void setTypeOfGear(Gir);
		 inline void setName(string);
		 inline void setCapacity(size_t);

	private:
		const unsigned int m_id;
		static unsigned int s_idHelper;
		string m_name;
		Gir m_typeOfGear;
		size_t m_cap;
		static size_t s_defCap;
};

inline const unsigned int Car_t::getId() const
{
	return m_id;
}

inline string Car_t::getName() const
{
	return m_name;
}

inline const Gir Car_t::getTypeOfGear() const
{
	return m_typeOfGear;
}

inline void Car_t::setTypeOfGear(Gir g)
{
	m_typeOfGear = g;
}

inline size_t  Car_t::getCapacity() const
{
	return m_cap;
}

inline void Car_t::setName(string name)
{ 
	m_name = name; 
}
inline void Car_t::setCapacity(size_t capacity)
{
	m_cap = capacity;
}

