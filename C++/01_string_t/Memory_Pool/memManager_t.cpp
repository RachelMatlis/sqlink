#include"memManager_t.h"

MemManager_t::MemManager_t() 
{
	m_actualSize = 0;
	m_currPosInMemory = 0;
	m_isEmpty = true;
	m_isFull = false;
}

MemManager_t::~MemManager_t() {
}

MemManager_t::MemManager_t(const MemManager_t& m) {
}

MemManager_t& MemManager_t::operator=(const MemManager_t& m) {
}

