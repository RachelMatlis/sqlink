#pragma once
#include"memManager_t.h"
#include"memPage_t.h"
#include <vector>

using namespace std;

/*control placement of data in vector of memory pages*/
class MemPool_t: public MemManager_t {

public:
	MemPool_t();
	virtual ~MemPool_t();

	inline static size_t getDefCapacity() { return MemPage_t::getDefCapacity(); }
	inline static size_t setDefCapacity(size_t cap) { MemPage_t::setDefCapacity(cap); }

	virtual size_t read(void*, size_t);
	virtual size_t read(void*, size_t, size_t);
	virtual size_t  write(void*, size_t);
	virtual size_t  write(void*, size_t, size_t);

private:
	MemPool_t(const MemPool_t&);
	MemPool_t& operator=(const MemPool_t&);

	vector<MemPage_t*> m_pool;
	size_t m_pageSize;
};

inline size_t MemPool_t::getDefCapacity()
{ 
	return MemPage_t::getDefCapacity(); 
}

inline size_t MemPool_t::setDefCapacity(size_t i_cap)
{ 
	MemPage_t::setDefCapacity(i_cap);
}


