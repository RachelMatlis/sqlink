#pragma once
#include <cstdlib>
#include <algorithm>
#include <string>
#include <typeinfo>
#include <vector>
#include <list>
#include<iostream>
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
	T* remove(const T& value);
	void removeAll();

	void removeAndDelete(const T& element);
	void removeAndDeleteAll();
	T* operator[](const unsigned int index);

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
	cout << *m_container.front();
	if (!isEmpty())
	{
		return m_container.front();
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

template<class T, class C>
T* tContainer_t<T, C>::remove(const T& value)
{
	iter_t itr = find_if(m_container.begin(), m_container.end(), Equal_t<T>::Equal_t(value));
	T* elemntP;

	if (itr == m_container.end()) /*value not found*/
	{
		return 0;
	}
	else
	{
		elemntP = *itr;
		m_container.erase(itr);
	}

	return elemntP;
}

template<class T, class C>
void tContainer_t<T, C>::removeAndDelete(const T& element)
{
	iter_t itr = find_if(m_container.begin(), m_container.end(), Equal_t<T>::Equal_t(value));
	if (itr != m_container.end()) /*value not found*/
	{
		m_container.erase(itr);
		delete *itr;
	}
}

template<class T, class C>
void tContainer_t<T, C>::removeAndDeleteAll()
{
	while (m_container.begin()++ != m_container.end())
	{
		m_container.erase(m_container.begin());
		delete m_container.begin();
	}
}

template<class T, class C>
T* tContainer_t<T, C>::operator[](const unsigned int index)
{
	if (m_container.size() > index)
	{
		if (typeid(C) == typeid(vector<T*>))
		{
			return (*(vector<T*>*)& m_container)[index];
		}
		else if (typeid(C*) == typeid(list<T*>*))
		{
			iterConst_t itr = m_container.begin();
			for (int i = 0; i < index; i++)
			{
				itr++;
			}

			return *itr;
		}
	}

	return 0;
	
}