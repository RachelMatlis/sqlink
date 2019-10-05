#pragma once
#include<string>

using namespace std;

template<class T>
class Exception_t
{
public:
	Exception_t<T>(T exception, string description, string sourceFileName, int sourceFileLineNum) :
		m_exception(exception), m_description(description),
		m_sourceFileName(sourceFileName), m_sourceFileLineNum(sourceFileLineNum) {};

		const T& getException() const 
		{ 
			return m_exception; 
		}

		string descriptionOfException() const
		{ 
			return m_description;
		}

		string getFileName() const
		{ 
			return m_sourceFileName;
		}

		int getFileLineNumer() const
		{ 
			return m_sourceFileLineNum;
		}

private:
	T m_exception;
	string m_description;
	string m_sourceFileName;
	int m_sourceFileLineNum;
};

