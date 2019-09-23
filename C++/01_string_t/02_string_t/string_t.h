#ifndef STRING_T_H
#define STRING_T_H
#include<iostream>

using namespace std;

class String_t
{
	public:
		String_t(); /*default ctor*/
		String_t(const char* ); /*ctor*/
		String_t(const String_t& ); /*copy ctor*/
		~String_t(); /*d'ctor*/
		String_t& operator=(const String_t&); /*assigment operator*/
		int length() const;
		void setString(const char*);
		char* getString() const;
		int compare(const String_t&);
		void print() const;
		char* toUpper();
		char* toLower();
		char* prepend(const char* str);
		String_t& operator+=(const String_t &);
		bool operator<(const String_t &);
		bool operator>(const String_t &);
		bool operator>=(const String_t &);
		bool operator<=(const String_t &);
		bool operator==(const String_t &);
		bool operator!=(const String_t &);
		char& operator[](size_t );
		bool contains(const String_t &);
	private:
		char* m_str;
		int size; 
		char* createString(const char*);
};

ostream& operator<<(ostream& os,const String_t& s);
ostream& operator>>(ostream& is, String_t& s);

#endif

