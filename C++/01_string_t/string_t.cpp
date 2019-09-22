# include <iostream>
# include <string.h>
#include "string_t.h"

using namespace std;

/*default ctor*/
String_t::String_t() 
{} 

/*overload constructor*/
String_t::String_t(const char* s) 
{
	size = strlen(s); 
	this->str = new char[size+1];
	strcpy(this->str, s);
}

/*copy constructor*/
String_t::String_t(const String_t& s) 
{
	this->str = s.str;
}

/*d'ctor*/
String_t::~String_t() 
{
	delete[] (this->str);
}

/*assigment operator*/
String_t& String_t:: operator=(const String_t& s) 
{
	if(this!= &s)
	{
		delete[] str;
		this->str = new char [strlen(s.str)+1];
		strcpy(this->str, s.str);
	}
	
	return *this;
}

int String_t::length() const 
{
	return strlen(this->str);
}

void String_t::setString(const char* s) 
{
	delete[] str;
	this->str = new char[strlen(s)+1];
	strcpy(this->str, s);
}

char* String_t::getString() const
{
	return str;
}

int String_t::compare(const String_t& s)
{
	return strcmp(this->str, s.str);
}

void String_t::print() const
{	
	cout<<this->str<<endl;
}













