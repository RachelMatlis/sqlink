#pragma once
#include"memManager_t.h"

/*hold any data as a stream of bytes*/
class MemPage_t : public MemManager_t {
	public:
		MemPage_t();
		MemPage_t(size_t i_cap);
		~MemPage_t();

		inline bool isEmpty() const;
		inline bool isFool() const;

		inline size_t getCapacity() const;

		virtual size_t readDataFromMemory(void* buffer, size_t size);
		virtual size_t readDataFromMemory(void* buffer, size_t size, size_t startPos);
		virtual size_t  writeDataIntoMemory(void* buffer, size_t size);
		virtual size_t  writeDataIntoMemory(void* buffer, size_t size, size_t startPos);

	private:
		MemPage_t(const MemPage_t&) {}
		MemPage_t& operator=(const MemPage_t&) {}

		char* stream;
		bool m_isPageFool;
		size_t m_capacity; /*length*/
};

inline bool MemPage_t::isFool() const
{
	return m_isPageFool;
}

inline size_t MemPage_t::getCapacity() const
{
	return m_capacity;
}