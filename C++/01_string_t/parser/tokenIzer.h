#pragma once
#include <list> 
#include <iterator> 
#include<ctype.h>
#include<iostream>
using namespace std;
extern "C"
class TokenIzer
{
public:
	TokenIzer(string line)
	{
		checkLine(line);
	}

	~TokenIzer(){}

	checkLine(string line)
	{
		string str;
		while(getline(line, str, isspace(line)))
		{
			keyWords.push_back(str);
		}

		for(int i=0;i< keyWords.size();i++)
		{
			cout<< keyWords[i]<<endl;
		}
	}

private:
	string kw = { "char", "short", "int", "long", "float", "double", "void", "if", "else", "for" , "while", "class","private", "public", "protected", "main", "const", "virtual",
					"++", "--", "==", "->" , "=", "+", "-", "*", "&" "<<”", ">>","(", ")", "[", "]" , "{" , "}" ,";" ,"<", ">"};
	vector<string> keyWords(&kw[0], &kw[sizeof(kw)/sizeof(string)]);
};









