#ifndef STRING_T_H
#define STRING_T_H

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
	private:
		char* str;
		int size; 
};

#endif

