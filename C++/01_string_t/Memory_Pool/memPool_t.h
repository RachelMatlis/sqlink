#pragma once
#include"memManager_t.h"
#include"memPage_t.h"
#include <vector>

/*control  placement of data in vector of memory pages*/
class MemPool_t: public MemManager_t {

public:
	MemPool_t()
	{
		MemPage_t::MemPage_t();
	}
	~MemPool_t();

	virtual size_t readDataFromMemory(void* buffer, size_t size);
	virtual size_t readDataFromMemory(void* buffer, size_t size, size_t startPos);
	virtual size_t  writeDataIntoMemory(void* buffer, size_t size);
	virtual size_t  writeDataIntoMemory(void* buffer, size_t size, size_t startPos);

private:
	MemPool_t(const MemPool_t&) {};
	MemPool_t& operator=(const MemPool_t&) {};

	vector<MemPage_t*> pool;

};

