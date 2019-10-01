#pragma once

/*base clas*/
class MemManager_t {

public:
	~MemManager_t();
	MemManager_t(); /*object of type memManager_t  can 't be constructed*/

	inline size_t getCurrPos() const;
	inline void setCurrPos(const size_t i_memoryPos);
	inline bool isEmpty() const;
	inline size_t getActualSize() const;

	virtual size_t readDataFromMemory(void* buffer, size_t size);
	virtual size_t readDataFromMemory(void* buffer, size_t size, size_t startPos);
	virtual size_t  writeDataIntoMemory(void* buffer, size_t size);
	virtual size_t  writeDataIntoMemory(void* buffer, size_t size, size_t startPos);

private:
	MemManager_t(const MemManager_t& m) {};
	MemManager_t& operator=(const MemManager_t& m){};

	size_t m_currPosInMemory;
	bool m_isMemoeyEmpty;
	size_t m_actualSize; /*how many bytes really written in memory*/
};

inline size_t MemManager_t::getCurrPos() const
{
	return m_currPosInMemory;
}

inline void MemManager_t::setCurrPos(const size_t i_MemoryPos)
{
	m_currPosInMemory = i_MemoryPos;
}

inline bool MemManager_t::isEmpty() const
{
	return m_isMemoeyEmpty;
}

inline size_t MemManager_t::getActualSize() const
{
	return m_actualSize;
}