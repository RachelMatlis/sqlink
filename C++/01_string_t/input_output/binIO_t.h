#pragma once
#include"virtIO_t.h"

class binIO_t : public virtIO_t{
	binIO_t();
	binIO_t(const string& i_path, const string& i_access);
	~binIO_t();

	virtual virtIO_t& operator<<(char c);
	virtual virtIO_t& operator >> (char& c);
	virtual virtIO_t& operator<<(unsigned char c);
	virtual virtIO_t& operator >> (unsigned char& c);
	virtual virtIO_t& operator<<(int num);
	virtual virtIO_t& operator >> (int& num);
	virtual virtIO_t& operator<<(unsigned int num);
	virtual virtIO_t& operator >> (unsigned int& num);
	virtual virtIO_t& operator<<(float num);
	virtual virtIO_t& operator >> (float& num);
	virtual virtIO_t& operator<<(short num);
	virtual virtIO_t& operator >> (short& num);
	virtual virtIO_t& operator<<(unsigned short num);
	virtual virtIO_t& operator >> (unsigned short& num);
	virtual virtIO_t& operator<<(long num);
	virtual virtIO_t& operator >> (long& num);
	virtual virtIO_t& operator<<(unsigned long num);
	virtual virtIO_t& operator >> (unsigned long& num);
	virtual virtIO_t& operator<<(double num);
	virtual virtIO_t& operator >> (double& num);
};