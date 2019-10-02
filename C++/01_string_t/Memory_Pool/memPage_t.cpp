#include"memPage_t.h"
#include <cstring>

size_t MemPage_t::m_defCapacity = 6;

MemPage_t::MemPage_t()
{
	m_stream = new char[m_defCapacity];
	m_capacity = m_defCapacity;
}

MemPage_t::MemPage_t(size_t i_cap)
{
	m_stream = new char[i_cap];
	m_capacity = i_cap;
}

MemPage_t::~MemPage_t() 
{
	delete[] m_stream;
}

MemPage_t::MemPage_t(const MemPage_t&) {
}

MemPage_t& MemPage_t::operator=(const MemPage_t&) {
}

size_t MemPage_t::read(void* buffer, size_t size)
{
	read(buffer,size, getCurrPos());
}

size_t MemPage_t::read(void* buffer, size_t i_size, size_t i_pos)
{
	if (buffer == 0 || i_size == 0)
	{
		return 0;
	}

	setCurrPos(i_pos);

	if (getActualSize() - getCurrPos() < i_size)
	{
		i_size = getActualSize() - getCurrPos();
	}

	memcpy(buffer, m_stream + getCurrPos(), i_size);
	setCurrPos(getCurrPos() + i_size);

	return i_size;
}

size_t  MemPage_t::write(void* buffer, size_t i_size)
{
	write(buffer, i_size, getCurrPos());
}

size_t  MemPage_t::write(void* buffer, size_t i_size, size_t i_pos)
{
	if (buffer == 0 || i_size == 0)
	{
		return 0;
	}

	setCurrPos(i_pos);

	if (i_size > m_capacity - getCurrPos())
	{
		i_size = m_capacity - getCurrPos();
	}

	memcpy(m_stream + getCurrPos(), buffer, i_size);
	setActualSize(i_size);
	setCurrPos(getCurrPos() + i_size);

	if (getActualSize() == m_capacity)
	{
		m_isFull = true;
	}

	return i_size;
}