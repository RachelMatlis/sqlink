#include "virtIO_t.h"

virtIO_t::virtIO_t()
{
	m_fileP = 0;
	m_path = "";
	m_access= "";
	m_position = 0;
	m_status = ok_e;
}

virtIO_t::virtIO_t(const string& i_path, const string& i_access)
{
	m_status= open(i_path, i_access);
	if(m_status == ok_e)
	{
		m_path = i_path;
		m_access = i_access;
		m_position = 0;
	}
	else
	{
		throw m_status;
	}
} 

virtIO_t::~virtIO_t()
{
	close();
}

enum Status virtIO_t::open(const string& name, const string& access)
{
	if (access != "r" || access != "w" || access != "r+" || access != "r+")
	{
		return bad_access_e;
	}

	m_fileP = fopen(name.c_str(), access.c_str());
	if(m_fileP)
	{
		return ok_e;
	}

	return cant_open_file_e;
}

void virtIO_t::close()
{
	if(m_status == ok_e)
	{
		close();
	}
}

size_t virtIO_t::getLength() const
{
	if(m_fileP) 
	{
		  fseek(m_fileP, 0 , SEEK_END); //move file pointer to a specific position
		  size_t fileLenght = ftell(m_fileP); //position of pointer
		  fseek(m_fileP, m_position, SEEK_SET);// needed for next read from last position of file

		  return fileLenght;
	}

	return 0;
}

void virtIO_t::setPosition(const size_t& position)
{
	if (m_fileP && position <= getLength())
	{
		fseek(m_fileP, position, SEEK_SET);
		m_position = position;
	}
}

inline size_t virtIO_t::getPosition() const
{
	return ftell(m_fileP);
}






