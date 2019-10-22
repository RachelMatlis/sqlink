#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

enum Status { 
	ok_e, 
	cant_open_file_e, 
	bad_access_e, 
	writeErr_e, 
	readErr_es 
};

class virtIO_t{

	virtIO_t();
	virtIO_t(const string& i_path, const string& i_access);
	virtual ~virtIO_t();
	
	enum Status open(const string& name, const string& access);
	void close();

	inline const string& getPath() const; /*name*/
	inline const string& getAccess() const; /*mode*/
	inline enum Status getStatus() const; 
	inline void setStatus(const enum Status& status);

	size_t getLength() const;
	size_t getPosition() const;
	void setPosition(const size_t& position);

	virtual virtIO_t& operator<<(char c) = 0;
	virtual virtIO_t& operator>>(char& c) = 0;
	virtual virtIO_t& operator<<(unsigned char c) = 0;
	virtual virtIO_t& operator>>(unsigned char& c) = 0;
	virtual virtIO_t& operator<<(int num) = 0; /*fprintf(fp,%d,num) in ascii- need to check mode. in binary fwrite() */
	virtual virtIO_t& operator>>(int& num) = 0;
	virtual virtIO_t& operator<<(unsigned int num) = 0; 
	virtual virtIO_t& operator>>(unsigned int& num) = 0;
	virtual virtIO_t& operator<<(float num) = 0;
	virtual virtIO_t& operator>>(float& num) = 0;
	virtual virtIO_t& operator<<(short num) = 0;
	virtual virtIO_t& operator>>(short& num) = 0;
	virtual virtIO_t& operator<<(unsigned short num) = 0;
	virtual virtIO_t& operator>>(unsigned short& num) = 0;
	virtual virtIO_t& operator<<(long num) = 0;
	virtual virtIO_t& operator>>(long& num) = 0;
	virtual virtIO_t& operator<<(unsigned long num) = 0;
	virtual virtIO_t& operator>>(unsigned long& num) = 0;
	virtual virtIO_t& operator<<(double num) = 0;
	virtual virtIO_t& operator>>(double& num) = 0;

protected:
	
	FILE* m_fileP;
	
private:
	virtIO_t(const virtIO_t& v){};
	virtIO_t& operator=(const virtIO_t& v){};

	string m_path;
	string m_access;
	enum Status m_status;
	size_t m_position;
};

inline const string& virtIO_t::getPath() const
{
	return m_path;
}

inline enum Status virtIO_t::getStatus() const
{
	return m_status;
}

inline void virtIO_t::setStatus(const enum Status& status)
{
	m_status = status;
}

inline const string& virtIO_t::getAccess() const
{
	return m_access;
}






