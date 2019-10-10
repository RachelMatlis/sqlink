#pragma once

using namespace std;

/*T- data type.
  C - container<T> -  STL container (vector or list).*/
template<class T, class C>
class  tContainer_t{
public:
	tContainer_t();
	~tContainer_t();
	bool isEmpty();
	size_t getSize();
	void insertElementToEnd(const T& value);
	T& getFirstElemnt();
	T& getLastElemnt();
	bool find(const T& value);
	T* remove(T* element);
	void removeAll();
	void removeAndDelete(T* element);
	void removeAndDeleteAll();
	T& operator[](const tContainer_t&);

private:
	tContainer_t(const tContainer_t&);
	tContainer_t& operator=(const tContainer_t&);

	C m_container;
	//size_t m_numberOfElemnts;
};

template<class T, class C>
tContainer_t<class T, class C>::tContainer_t()
{
	m_numberOfElemnts = 0
}

template<class T, class C>
tContainer_t<class T, class C>::~tContainer_t()
{

}

template<class T, class C>
bool tContainer_t<class T, class C>::isEmpty()
{
	m_container.empty();
}

template<class T, class C>
size_t tContainer_t<class T, class C>::getSize()
{
	return m_container.size()
}

template<class T, class C>
void tContainer_t<class T, class C>::insertElementToEnd(const T& value)
{
	
}