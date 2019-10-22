#pragma once
#include"virtIO_t.h"

class asciiIO_t : public virtIO_t{
public:
	asciiIO_t();
	asciiIO_t(const string& i_path, const string& i_access);
	virtual ~asciiIO_t();

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

private:
	template <class T>
	void fPrintf(T var, const string& format);

	template <class T>
	void fScanf(T& var, const string& format);
	
};

template <class T>
void asciiIO_t::fPrintf(T var, const string& format)
{
	fprintf(m_fileP, format, var);
}

template <class T>
void asciiIO_t::fScanf(T& var, const string& format)
{
	fscanf(m_fileP, format, str1, var);
}