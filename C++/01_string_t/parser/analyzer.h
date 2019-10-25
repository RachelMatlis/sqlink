#pragma once
#include <vector> 
#include<string>
#include<iostream>
using namespace std;

class Analyzer {
public:
	Analyzer();
	~Analyzer() {};

	void analyzer(const vector<string> &tokens, int lineNumber);
	

private:
	/*Functions*/
	Analyzer(const Analyzer& ap) {}; 
	Analyzer& operator=(const Analyzer& a) {};
	void printRule(const string &s, int lineNumber) const;

	/*Rules*/
	void mainRule(const string& token, int lineNumber);
	void bracesRule(const string& token);
	void elseRule(const string& token);
	void predefinedTypesRule(const string& token, int lineNumber);
	void plusRule(const string& token, int lineNumber);
	void minusRule(const string& token, int lineNumber);
	void varNameRule(const string& token, int lineNumber);
	void declareRule(const string& token, int lineNumber);

	/*counters*/
	int openParenthesesCount , closeParenthesesCount; //(
	int openBracketsCount, closeBracketsCount; //[
	int openBracesCount, closeBracesCount; //{
	int operatorPlusCount, operatorMinusCount; // + -

	/*flags*/
	bool ifFlag;

	/*Language words*/
	const char* predefinedTypes[7] =
	{
		"char", "short", "int", "long", "float", "double", "void"
	};
	const char* keyWords[11] =
	{
		"if", "else","for" , "while", "class","private", "public", "protected", "main", "const", "virtual"
	};
	const char* operators[19] =
	{
		"++", "--", "==", "->" , "(", ")", "[", "]" , "{" , "}" ,";" ,"<", ">", "=", "+", "-", "*", "&" "<<”", ">>"
	};

	vector<string> declaredVariables;
};

Analyzer::Analyzer()
{
	openParenthesesCount = 0; 
	closeParenthesesCount = 0;
	openBracketsCount = 0; 
	closeBracketsCount = 0;
	openBracesCount = 0; 
	closeBracesCount = 0;
	ifFlag = false;
}
void Analyzer::analyzer(const vector<string> &tokens, int lineNumber)
{
	mainRule(tokens[0], lineNumber);
}


void Analyzer::printRule(const string &s, int lineNumber) const
{
	cout << "line "<<lineNumber<<":  error, "<< s<<endl;
}

void Analyzer::mainRule(const string& token, int lineNumber)
{
	if (token != "main")
	{
		printRule("illegal - declaration before 'main'", lineNumber);
	}
}