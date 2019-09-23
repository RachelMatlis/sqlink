# include <iostream>
# include <string.h>
#include "string_t.h"

using namespace std;

/*default ctor*/
String_t::String_t() 
{
	 createString(0);
} 

/*overload constructor*/
String_t::String_t(const char* s) 
{
	/*size = strlen(s); 
	this-> m_str = new char[size+1];
	strcpy( m_str, s);*/
	
	createString(s);
}

/*copy constructor*/
String_t::String_t(const String_t& s) 
{
	createString(s.m_str);
}

/*d'ctor*/
String_t::~String_t() 
{
	delete[] m_str;
}

/*assigment operator*/
String_t& String_t:: operator=(const String_t& s) 
{
	if(this!= &s)
	{
		delete[]  m_str;
		createString(s.m_str);
	}
	
	return *this;
}

int String_t::length() const 
{
	return strlen(m_str);
}

void String_t::setString(const char* s) 
{
	delete[]  m_str;
	createString(s);
}

char* String_t::getString() const
{
	return  m_str;
}

int String_t::compare(const String_t& s)
{
	return strcmp(m_str, s. m_str);
}

void String_t::print() const
{	
	cout<<m_str;
}

char* String_t::toUpper()
{
	int i=0;
	char c;
	int sub = 'a' - 'A'; /*32*/
	for(i=0;i<size;i++)
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
	int i=0;
	char c;
	int sub = 'a' - 'A'; /*32*/
	for(i=0;i<size;i++)
	{
		c= m_str[i];
		if(c >= 'A' && c <= 'Z')
		{
			m_str[i] = c + sub;
		}
	}
	
	return m_str;
}

char* String_t::prepend(const char* str)
{
	int newSize = strlen(str) + size +1;
	char* newStr = new char [newSize];
	
	int i= 0; 
	for(i; i< strlen(str); i++)
	{
		newStr[i] = str[i];
	}
	newStr[i] = ' ';
	
	strcat(newStr, m_str);	
	strcpy(m_str,newStr);
	
	return m_str;
}

String_t& String_t::operator+=(const String_t& str)
{
	if(size < size + strlen(str.m_str))
	{
		char *tempSt = new char[size+1];
		tempSt = strcpy(tempSt,m_str);
		
		delete[] m_str;
		size = size + strlen(str.m_str)+1;
		m_str= new char[size];
		strcpy(m_str,tempSt);
		delete [] tempSt;
	}

	strcat(m_str, str.m_str);	
	
	return *this;
}

bool String_t::operator<(const String_t& str)
{
	if(strcmp(m_str, str.m_str) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String_t::operator>(const String_t& str)
{
	if(strcmp(m_str, str.m_str) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String_t::operator>=(const String_t& str)
{
	if(strcmp(m_str, str.m_str) > 0 || strcmp(m_str, str.m_str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String_t::operator<=(const String_t& str)
{
	if(strcmp(m_str, str.m_str) < 0 || strcmp(m_str, str.m_str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String_t::operator==(const String_t& str)
{
	if(strcmp(m_str, str.m_str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String_t::operator!=(const String_t& str)
{
	if(strcmp(m_str, str.m_str) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String_t::contains(const String_t& str)
{
	
	int i = 0, j = 0;

	for (i; i<size; i++)
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

/*private func*/
char* String_t::createString(const char* str)
{
	if(str == 0)
	{
		m_str= new char[4];
	 	m_str[0] = '\0';
	}
	else
	{
		//copy ctor
		size = strlen(str);
		m_str= new char[size+1];
		strcpy(m_str,str);
	}
	 
	 return m_str;
}

char& String_t::operator[](size_t pos)
{
	
	return m_str[pos];
}

ostream& operator<<(ostream& os,const String_t& s)
{
	os << s.getString();
	
	return os;
}

istream& operator>>(istream& is, String_t& s)
{
	char str[128];
	is>> str;
	s.setString(str);
		
	return is;
}













