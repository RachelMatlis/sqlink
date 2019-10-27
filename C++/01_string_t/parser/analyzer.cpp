#include"analyzer.h"


Analyzer::Analyzer()
{
	
	setPredefinedTypes();
	setkeyWords();
	setOperators();
	parenthesesCount = 0; 
	bracketsCount = 0; 
	bracesCount = 0; 

	ifFlag = false;
	isOpenParentheses = false; //(
	isOpenBrackets = false;//[
	isOpenBraces = false; //{
}

void Analyzer::setPredefinedTypes()
{
	predefinedTypes.insert("char");
	predefinedTypes.insert("short");
	predefinedTypes.insert("int");
	predefinedTypes.insert("long");
	predefinedTypes.insert("float");
	predefinedTypes.insert("double");
	predefinedTypes.insert("void");
}

void Analyzer::setkeyWords()
{
	keyWords.insert("if");
	keyWords.insert("else");
	keyWords.insert("for");
	keyWords.insert("while");
	keyWords.insert("class");
	keyWords.insert("private");
	keyWords.insert("public");
	keyWords.insert("protected");
	keyWords.insert("main");
	keyWords.insert("const");
	keyWords.insert("virtual");

}

void Analyzer::setOperators()
{
	operators.insert("++");
	operators.insert("--");
	operators.insert("==");
	operators.insert("->");
	operators.insert("(");
	operators.insert(")");
	operators.insert("[");
	operators.insert("]");
	operators.insert("{");
	operators.insert("}");
	operators.insert(";");
	operators.insert("<");
	operators.insert(">");
	operators.insert("=");
	operators.insert("+");
	operators.insert("-");
	operators.insert("*");
	operators.insert("&");
	operators.insert("<<");
	operators.insert(">>");
}

Analyzer::~Analyzer()
{
}


void Analyzer::analyzer(const vector<string> &tokens, int lineNumber)
{
	for(int i=0; i< tokens.size(); i++)
	{
		mainRule(tokens[i],i,lineNumber);
		if(tokens[i] == "(" || tokens[i] == ")" || tokens[i] == "[" || tokens[i] == "]" || tokens[i] == "{" || tokens[i] == "}")
		{
			bracesRule(tokens[i],lineNumber);
		}
		else if(tokens[i] == "if")
		{
			ifFlag = true;
		}
		else if(tokens[i] == "else")
		{
			elseRule(lineNumber);
		}
		else if(predefinedTypes.find(tokens[i]))//type check
		{

		}
		
	}
}

void Analyzer::mainRule(const string& token,int index, int lineNumber)
{
	bool isMainOk =true;

	if(index == 0 && lineNumber ==1 && token != "main")
	{
		isMainOk = false;
	}
	else if(index == 0 && lineNumber !=1 && token == "main")
	{
		isMainOk = false;
	}
	
	if(isMainOk != true)
	{
		printRule("illegal - declaration before 'main'", lineNumber);
	}
	
}

void Analyzer::bracesRule(const string& token, int lineNumber)
{
	if(token == "(")
	{
		parenthesesCount++;
		isOpenParentheses = true;
	}
	else if(token == ")")
	{
		parenthesesCount--;
		if(!isOpenParentheses)
		{
			printCloseBracesError("(", ")", lineNumber);
		}
		else
		{
			isOpenParentheses = false;
		}
	}
	else if(token == "[")
	{
		bracketsCount++;
		isOpenBrackets = true;
	}
	else if(token == "]")
	{
		bracketsCount--;
		if(!isOpenBrackets)
		{
			printCloseBracesError("[", "]", lineNumber);
		}
		else
		{
			isOpenBrackets =false;
		}

	}
	else if(token == "{")
	{
		bracesCount++;
		isOpenBraces = true;
	}
	else if(token == "}")
	{
		bracesCount--;
		if(!isOpenBraces)
		{
			printCloseBracesError("{", "}", lineNumber);
		}
		else
		{
			isOpenBraces =false;
		}
	}
}

void Analyzer::elseRule(int lineNumber)
{
	if(!ifFlag)
	{
		printElseError(lineNumber);
	}
	else
	{
		ifFlag= false;
	}
}

/*bool Analyzer::ispredefinedTypes(const string *c)
{

}*/

