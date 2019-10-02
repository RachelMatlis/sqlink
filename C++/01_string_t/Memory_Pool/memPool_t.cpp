#include"memPool_t.h"


MemPool_t::MemPool_t()
{
	MemPage_t* page = new MemPage_t;
	m_pool.push_back(page);
	m_pageSize = page->getCapacity();
}

MemPool_t::~MemPool_t()
{
	for (int i = 0; i < m_pool.size(); ++i)
	{
		delete m_pool[i];
	}
}

MemPool_t::MemPool_t(const MemPool_t& m) {
}

MemPool_t& MemPool_t::operator=(const MemPool_t& m) {
}

size_t MemPool_t::read(void* buffer, size_t i_size)
{
	read(buffer, i_size, getCurrPos());
}

size_t MemPool_t::read(void* buffer, size_t i_size, size_t i_pos)
{
	if (buffer == 0 || i_size == 0)
	{
		return 0;
	}
}

size_t  MemPool_t::write(void* buffer, size_t i_size)
{
	write(buffer, i_size, getCurrPos());
}

size_t  MemPool_t::write(void* buffer, size_t i_size, size_t i_pos)
{

}