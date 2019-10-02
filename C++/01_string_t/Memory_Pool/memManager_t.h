#pragma once

/*base clas- ABC*/
class MemManager_t {
	/*object of type memManager_t  can 't be constructed*/
public:
	MemManager_t(); 
	virtual ~MemManager_t();

	inline size_t getCurrPos() const;
	inline void setCurrPos(const size_t);
	inline size_t getActualSize() const;
	inline void setActualSize(const size_t);
	inline bool isEmpty() const;
	inline bool isFull() const;

	virtual size_t read(void* , size_t) = 0; /*read data from memory*/
	virtual size_t read(void* , size_t , size_t) = 0;
	virtual size_t  write(void*, size_t) = 0; /*write data into memory*/
	virtual size_t  write(void*, size_t , size_t) = 0;

protected:
	bool m_isEmpty; /*?*/
	bool m_isFull;
private:
	
	MemManager_t(const MemManager_t&);
	MemManager_t& operator=(const MemManager_t&);

	size_t m_actualSize; /*how many bytes really written in memory*/
	size_t m_currPosInMemory;
};

inline size_t MemManager_t::getCurrPos() const
{
	return m_currPosInMemory;
}

inline void MemManager_t::setCurrPos(const size_t i_pos)
{
	m_currPosInMemory = i_pos;
}

inline bool MemManager_t::isEmpty() const
{
	return m_isEmpty;
}

inline bool MemManager_t::isFull() const
{
	return m_isFull;
}

inline size_t MemManager_t::getActualSize() const
{
	return m_actualSize;
}

inline void MemManager_t::setActualSize(const size_t i_size)
{
	m_actualSize = i_size;
}


