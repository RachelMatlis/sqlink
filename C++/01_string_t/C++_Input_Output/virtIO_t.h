#include <string>
#include <stdlib.h>

using namespace std;

enum Status
{
    ok_e,
    cant_open_file_e,
    bad_access_e,
    writeErr_e,
    readErr_es
};

enum Access
{
    r,
    w,
    r+,
    w+
};

class virtIO_t{

	virtIO_t();
	virtual ~virtIO_t();
	virtIO_t(const string& name, const enum Access& mode); 

	enum Status open(const string& name, const string& mode);
	void close(const string& name);

	const string& getPath() const;
	inline enum Access getAccess() const;

	size_t length() const;

	inline size_t getPosition() const;
	inline void setPosition(const size_t& position);

	inline int getStatus() const;
	inline void setStatus(const enum Status& status);

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



private:
	virtIO_t(const virtIO_t& v){};
	virtIO_t& operator=(const virtIO_t& v){};

	string m_path;
	string m_access;
	size_t m_position;
	Status m_status;

	FILE* m_fileP;
};

inline size_t virtIO_t::getPosition() const
{
	return m_position;
}

inline void virtIO_t::setPosition(const size_t& position)
{
	m_position = position;
}

inline int virtIO_t::getStatus() const
{
	return m_status;
}

inline void virtIO_t::setStatus(const enum Status& status)
{
	m_status = status;
}

inline enum Access virtIO_t::getAccess() const
{
	return m_access;
}






