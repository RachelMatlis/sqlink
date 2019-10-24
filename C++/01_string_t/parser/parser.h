#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"tokenIzer.h"

using namespace std;

class Analz;
class Token;

class Parser{
public:
	Parser()
	{
		m_lineNumber = 1;
	}

	void parse(const string& i_path)
	{
		open(i_path);

		string str;
		while (getline(m_file, str)) 
		{
   			 m_tokenizer.checkLine(str);
   			 //m_a.analyzer(m_lineNumber);
   			 break;
   		}
	}

	void open(const string& i_path)
	{
   		m_file.open("test.txt"); 
		if(m_file)
		{
			cout<<"OK"<<endl;
		}
	}

	~Parser()
	{
		m_file.close();
	}



private:
	Parser(const Parser& p) {};
	Parser& operator=(const Parser& p) {};

	ifstream m_file; 
	int m_lineNumber;
	TokenIzer *m_tokenizer;// better cause we dont need include""
	//Analyzer *m_a;

};