# include <iostream>
# include <string.h>
#include "string_t.h"

using namespace std;

void checkOperators(const String_t&, const String_t&);

int main()
{   
	int choice;
	char str[] = "";
	char newStr[] = "";
	

	cout << "Enter string:";
	cin >> str;
	String_t st(str);

	cout << "Enter another string:";
	cin >> str;
	String_t st1(str);

	
	
	//cout<< String_t::nOfString()<<endl;

	//cout<< st.indexOfFirstOccurr(st, 'l')<<endl;
	//cout << st.indexOfLasttOccurr(st, 'l') << endl;

	//cout << st(1, 3) << endl;


	st.prepend("Matlis");
	st.print();
	
	st+= "Matlis";
	st.print();
	
	
	//cout<<st.contains("mat");
	
	//cout << st; 
	
	//st+= "Matlis";
	//st.prepend("Queen");
	
	
	//cout<< st[0]<<endl;
	//st[0] = 'M';
	
	cout<< st<<endl;
	
	do 
	{
		cout <<endl<< "Choose option:" << endl;
		cout << "1.Set string" << endl;
		cout << "2.Get string" << endl;
		cout << "3.Get string length" << endl;
		cout << "4.Strings compare" << endl;
		cout << "5.Print string" << endl;
		cout << "6.Convert string to upper case" << endl;
		cout << "7.Convert string to lower case" << endl;
		cout << "8.Prepend from char*" << endl;
		cout << "9.Prepend from String_t" << endl;
		cout << "10.+= from char*" << endl;
		cout << "11.+= from String_t" << endl;
		cout << "12.Check operators" << endl;
		cout << "13.Contains?" << endl;
		cout << "20.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter String: ";
			cin >> newStr;
			st.setString(newStr);
			break;
		case 2:
			cout << "-> "<< "you have got: " << st.getString()<<endl;
			break;
		case 3:
			cout << "-> "<< "The length is: " << st.length()<<endl;
			break;
		case 4:
			cout << "Enter String: ";
			cin >> newStr;
			cout <<"-> "<<"Compare(" << st.getString() << "," << newStr << ")" << "= " << st.compare(newStr)<<endl;
			break;
		case 5:
			cout <<endl<< "-> "<<"The string: ";
			st.print();
			cout << endl;
			break;
		case 6:
			st.toUpper();
			break;
		case 7:
			st.toLower();
			break;
		case 8:
			cout << "Enter String: ";
			cin >> newStr;
			st.prepend(newStr);
			break;
		case 9:
			st.prepend(st1);
			break;
		case 10:
			st += "Queen";
			break;
		case 11:
			st += st1;
			break;
		case 12:
			checkOperators(st, st1);
			break;
		case 13:
			cout << "Enter String: ";
			cin >> newStr;
			st.contains(newStr) == true ? cout<< newStr << " is in" << st.getString()<<endl : cout << newStr << " is not in " << st.getString() << endl;
			break;
		case 14:
			break;
		case 20:
			cout << "-> "<< "GoodBye!: "<<endl;
			break;
		default:
			cout << "-> "<<"Wrong choice please try again"<<endl;
			break;
		}
		
	} while (choice != 10);

}

void checkOperators(const String_t& str1, const String_t& str2)
{
	cout << str1.getString() << " < " << str2.getString() << ": " << (str1<str2) << endl;
	cout << str1.getString() << " > " << str2.getString() << ": " << (str1>str2) << endl;
	cout << str1.getString() << " <= " << str2.getString() << ": " << (str1<=str2) << endl;
	cout << str1.getString() << " >= " << str2.getString() << ": " << (str1>=str2) << endl;
	cout << str1.getString() << " != " << str2.getString() << ": " << (str1!=str2) << endl;
	cout << str1.getString() << " = " << str2.getString() << ": " << (str1==str2) << endl;
}


