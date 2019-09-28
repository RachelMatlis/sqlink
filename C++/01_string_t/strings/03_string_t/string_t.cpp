# include <iostream>
#include <string.h>
#include "string_t.h"
#include "math.h"

using namespace std;

int String_t:: s_numberOfString = 0; 
size_t String_t:: m_dfltCapacity = 2;
bool String_t::s_isCaseSens = true;

/*ctor*/
String_t::String_t() 
{
	 ++s_numberOfString;
	 createString(0);
} 

/*ctor with params*/
String_t::String_t(const char* s) 
{	
	++s_numberOfString;
	createString(s);
}

/*copy ctor*/
String_t::String_t(const String_t& s) 
{
	createString(s.m_str);
}

/*d'ctor*/
String_t::~String_t() 
{
	--s_numberOfString;
	delete[] m_str;
}

/*assigment operator*/
String_t& String_t:: operator=(const String_t& s) 
{
	if (this != &s)
	{
		delete[]  m_str;
		createString(s.m_str);
	}

	return *this;
}

void String_t::setString(const char* s) 
{
	delete[]  m_str;
	createString(s);
}

int String_t::compare(const String_t& s)
{
	int res = strcmp(m_str, s. m_str);

	if (res == 0)
	{
		return 0;
	}

	return res > 0 ? 1 : 2;
}

char* String_t::toUpper()
{
	unsigned int i=0;
	char c;
	int sub = 'a' - 'A'; /*32*/
	for(i=0;i<strlen(m_str);i++)
	{
		c= m_str[i];
		if(c >= 'a' && c <= 'z')
		{
			m_str[i] = c - sub;
		}
	}
	
	return m_str;
}

char* String_t::toLower()
{
	unsigned int i=0;
	char c;
	int sub = 'a' - 'A'; /*32*/
	for(i=0;i<strlen(m_str);i++)
	{
		c= m_str[i];
		if(c >= 'A' && c <= 'Z')
		{
			m_str[i] = c + sub;
		}
	}
	
	return m_str;
}

void String_t::prepend(const char* str)
{
	stringMerge(str, m_str);
}

void String_t::prepend(const String_t& str)
{
	stringMerge(str.m_str, m_str);
}

String_t& String_t::operator+=(const String_t& str)
{

	stringMerge(m_str ,str.m_str);
	
	return *this;
}

String_t& String_t::operator+=(const char* str)
{

	stringMerge(m_str, str);

	return *this;
}

char* String_t::operator()(int start,int len) const
{
	int i = 0;
	char* sub = new char[len+1];

	if (len == 0 || start + len > sizeof(m_str))
	{
		return NULL;
	}

	for (i; i < len; i++)
	{
		sub[i] = m_str[start++];
	}
	sub[--start] = '\0';

	return sub;
}

bool String_t::contains(const String_t& str) const
{
	unsigned int i = 0, j = 0;

	for (i; i<strlen(m_str); i++)
		{
			if (m_str[i] == str.m_str[j])
			{
				while (m_str[i] == str.m_str[j]) /*checks if all s2 is in s1*/
				{
					i++;
					j++;
				}

				if (str.m_str[j] == '\0') /*all s2 is in s1*/
				{
					return true;
				}
				else /*not all s2 is in s1*/
				{
					j = 0;
				}
			}
		}

	return false;
}


int String_t::indexOfFirstOccurr(const String_t& s, char c) const
{
	unsigned int i=0;
	int index = -1;
	for(i;i<strlen(s.m_str);i++)
	{
		if(s.m_str[i] == c)
		{
			index = i;
			break;
		}
	}

	return index;
} 

int String_t::indexOfLasttOccurr(const String_t& s, char c) const
{
	int index = -1;
	int i = indexOfFirstOccurr(s, c);

	for (i; i<strlen(s.m_str); i++)
	{
		if (s.m_str[i] == c)
		{
			index = i;
		}
	}

	return index;
}

/*private*/
char* String_t::createString(const char* str)
{
	if (str == 0)
	{
		m_capacity = m_dfltCapacity;
		m_str = new char[m_capacity];
		m_str[0] = '\0';
	}
	else
	{
		if (strlen(str) + 1 > m_dfltCapacity)
		{
			m_dfltCapacity = roundUpToPowerOf2(strlen(str)+1);
		}
		//copy ctor
		m_capacity = m_dfltCapacity;
		m_str = new char[m_capacity];
		strcpy(m_str, str);
	}

	return m_str;
}

void String_t::stringMerge(const char* firstStr, const char* secondStr)
{
	char* temp = new char[strlen(firstStr) + strlen(secondStr) + 1];
	strcpy(temp, firstStr);
	strcat(temp, secondStr);
	delete [] m_str;
	createString(temp);
	delete[] temp;
}

size_t String_t::roundUpToPowerOf2(int strLen)
{
	int power = 1;
	while (power < strLen)
	{
		power *= 2;
	}
	return power;
}

/*not a class members*/
ostream& operator<<(ostream& os, const String_t& s)
{
	os << s.getString();

	return os;
}

istream& operator >> (istream& is, String_t& s)
{
	char str[128];
	is >> str;
	s.setString(str);

	return is;
}













