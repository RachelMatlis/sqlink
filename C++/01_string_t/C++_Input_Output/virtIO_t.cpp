#include "virtIO_t.h"

virtIO_t::virtIO_t()
{
	m_position = 0;
	m_path = '\0';
	m_access= '\0';
	m_status = 0;
	m_fileP =0;
}

virtIO_t::virtIO_t(const string& name, const enum Access& mode)
{
	m_status= open(name,mode);
	if(m_status == ok_e)
	{
		m_path = name;
		m_access = mode;
		m_position = 0;
	}

	throw string("ERROR");

} 

virtual virtIO_t::~virtIO_t()
{
	fclose(m_fileP);
}

enum Status virtIO_t::open(const string& name, const string& mode)
{
	m_fileP = fopen(name, mode);
	if(fileP)
	{
		return ok_e;
	}

	return cant_open_file_e;
}

void virtIO_t::close()
{
	fclose(m_fileP);
}

const string& virtIO_t::getPath() const
{
	return m_path;
}

size_t virtIO_t::length() const
{
	if(m_fileP) 
	{
		  fseek(m_fileP, 0 , SEEK_END);
		  size_t fileSize = ftell(m_fileP);
		  fseek(m_fileP, 0 , SEEK_SET);// needed for next read from beginning of file

		  return fileSize;
	}

	return 0;
}






