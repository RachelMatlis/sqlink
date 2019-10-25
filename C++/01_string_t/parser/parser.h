#pragma once
#include<string>
#include <fstream>
#include"tokenIzer.h"

using namespace std;

class Parser{
public:
	Parser() { m_lineNumber = 1; };
	void parse(const string& i_path);
	~Parser() { m_file.close(); };

private:
	Parser(const Parser& p) {};
	Parser& operator=(const Parser& p) {};

	ifstream m_file; 
	int m_lineNumber;
	TokenIzer m_tokenizer;
	//Analyzer m_analyzer;

};

void Parser::parse(const string& i_path)
{
	m_file.open(i_path);
	if (m_file)
	{
		string line;
		while (getline(m_file, line))
		{
			m_tokenizer.tokenIzer(line);
			//m_analyzer.analyzer(m_tokenizer.getTokens(),line);
		}

		m_tokenizer.printTokens();
	}
}