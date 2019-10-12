#pragma once
#include <cstdlib>
#include <algorithm>
#include <string>
#include <typeinfo>
#include <vector>
#include <list>
#include"Equal_t.h"

using namespace std;

/*T- data type.
  C - container<T> -  STL container (vector or list).*/
template<class T, class C>
class  tContainer_t { /* tContainer_t contains pointers to any type of objects*/
public:
	tContainer_t<T,C>() {};
	~tContainer_t<T,C>() {};
	bool isEmpty() const { return m_container.empty(); };
	size_t getSize() const { return m_container.size(); };
	void insert(const T* value) { m_container.push_back((T*)value); };

	T* getFirst() const;
	T* getLast() const;

	T* find(const T& value) const;
	//T* remove(T* element);

	void removeAll();
	//void removeAndDelete(T* element);
	//void removeAndDeleteAll();
	//T& operator[](const tContainer_t&);

private:
	/*not allow copy*/
	tContainer_t<T,C>(const tContainer_t& con) {};
	tContainer_t<T,C>& operator=(const tContainer_t& con) {};

	/*iterator type that points to instance*/
	typedef typename C::iterator iter_t; 
	typedef typename C::const_iterator iterConst_t; 

	C m_container;
};

template<class T, class C>
T* tContainer_t<T, C>::getFirst() const
{ 
	if (!isEmpty())
	{
		return *(m_container.begin());
	}

	return 0;
}

template<class T, class C>
T* tContainer_t<T,C>::getLast() const
{ 
	if (!isEmpty())
	{
		return m_container.back();
	}

	return 0; 
}

template<class T, class C>
T* tContainer_t<T, C>::find(const T& value) const
{
	iterConst_t itr = find_if(m_container.begin(), m_container.end(), Equal_t<T>::Equal_t(value));
	return (itr == m_container.end()) ? 0 : *itr;
}

template<class T, class C>
void tContainer_t<T, C>::removeAll()
{
	if (!isEmpty())
	{
		m_container.clear();
	}
}