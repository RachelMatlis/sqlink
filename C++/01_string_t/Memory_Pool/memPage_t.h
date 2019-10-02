#pragma once
#include"memManager_t.h"

/*hold any data as a stream of bytes*/
class MemPage_t : public MemManager_t {
	public:
		MemPage_t();
		MemPage_t(size_t);
		virtual ~MemPage_t();

		inline size_t getCapacity() const;

		inline static size_t getDefCapacity();
		inline static size_t setDefCapacity(size_t cap);

		virtual size_t read(void* , size_t);
		virtual size_t read(void*, size_t, size_t);
		virtual size_t  write(void*, size_t);
		virtual size_t  write(void*, size_t, size_t);

	private:
		MemPage_t(const MemPage_t&) {}
		MemPage_t& operator=(const MemPage_t&) {}

		char* m_stream;
		size_t m_capacity; /*length*/
		static size_t m_defCapacity;
};

inline size_t MemPage_t::getCapacity() const
{
	return m_capacity;
}

inline size_t MemPage_t::getDefCapacity() 
{
	return m_defCapacity;
}

inline size_t MemPage_t::setDefCapacity(size_t i_cap)
{ 
	m_defCapacity = i_cap;
}
