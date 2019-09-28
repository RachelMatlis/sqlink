#ifndef STRING_T_H
#define STRING_T_H
#include<iostream>
#include <string.h>

using namespace std;
/*getString()- data member must be rturned by const ,the function returns private member (the address) */
class String_t
{
	public:
		/*-----1-----*/
		String_t(); /*default ctor*/
		String_t(const char* ); /*ctor*/
		String_t(const String_t& ); /*copy ctor*/
		~String_t(); /*d'ctor*/
		String_t& operator=(const String_t&); /*assigment operator*/

		inline int length() const;
		void setString(const char*);
		inline const char* getString() const; 
		int compare(const String_t&);
		inline void print() const;
		
		/*-----2-----*/
		char* toUpper();
		char* toLower();
		void prepend(const char* str);
		void prepend(const String_t& str);
		String_t& operator+=(const char*);
		String_t& operator+=(const String_t&);

		inline bool operator<(const String_t &) const;
		inline bool operator>(const String_t &) const;
		inline bool operator>=(const String_t &) const;
		inline bool operator<=(const String_t &) const;
		inline bool operator==(const String_t &) const;
		inline bool operator!=(const String_t &) const;	
		inline char& operator[](size_t);
		inline char& operator[](size_t) const;
		bool contains(const String_t& ) const;
		
		/*-----3-----*/
		static inline int nOfString();
		static inline void setDfltCapacity(size_t dfltCapacity);
		static inline size_t getDfltCapacity();

		static inline int setCapacityAndRetPrev(size_t);
		static inline size_t getCapacity();

		inline bool setCaseSensAndRetPrev(bool);
		static inline bool getCaseSens();

		int indexOfFirstOccurr(const String_t& , char) const;
		int indexOfLasttOccurr(const String_t& s, char c) const;

		char* operator()(int,int) const;
		
	private:
		char* m_str;
		static size_t m_dfltCapacity;
		size_t m_capacity;
		static int s_numberOfString; 
		static bool s_isCaseSens; 
		char* createString(const char*);
		size_t roundUpToPowerOf2(int );
		void stringMerge(const char* firstStr, const char* secondStr);
};

inline int String_t::nOfString()
{
	return s_numberOfString;
}

inline void String_t::setDfltCapacity(size_t dfltCapacity) 
{ 
	m_dfltCapacity = dfltCapacity;
}

inline size_t String_t::getDfltCapacity()
{
	return m_dfltCapacity;
}

inline int String_t::setCapacityAndRetPrev(size_t capacity) 
{ 
	String_t c;
	size_t temp = c.m_capacity;
	c.m_capacity = capacity;
	return temp;
}

inline size_t String_t::getCapacity()
{
	return m_dfltCapacity;
}

inline bool String_t::setCaseSensAndRetPrev(bool caseSens)
{
	bool prev = s_isCaseSens;
	s_isCaseSens = caseSens;
	return prev;
}

inline bool String_t::getCaseSens()
{
	return s_isCaseSens;
}

inline int String_t::length() const 
{
	return strlen(m_str);
}

inline const char* String_t::getString() const
{
	return m_str;
}

inline void String_t::print() const
{
	cout<<m_str;
}

inline bool String_t::operator<(const String_t &str) const
{
	return (strcmp(m_str, str.m_str) < 0);
}

inline bool String_t::operator>(const String_t &str) const
{
	return (strcmp(m_str, str.m_str) > 0);
}

inline bool String_t::operator>=(const String_t &str) const
{
	return (strcmp(m_str, str.m_str) > 0 || strcmp(m_str, str.m_str) == 0);
}

inline bool String_t::operator<=(const String_t &str) const
{
	return (strcmp(m_str, str.m_str) < 0 || strcmp(m_str, str.m_str) == 0);
}

inline bool String_t::operator==(const String_t &str) const
{
	return (strcmp(m_str, str.m_str) == 0);
}

inline bool String_t::operator!=(const String_t &str) const
{
	return (strcmp(m_str, str.m_str) != 0);
}

inline char& String_t::operator[](size_t pos)
{
	return m_str[pos];
}

inline char& String_t::operator[](size_t pos) const
{
	return m_str[pos];
}


ostream& operator<<(ostream& os, const String_t& s);
ostream& operator>>(ostream& is, String_t& s);

#endif

