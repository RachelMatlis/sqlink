# include <iostream>
# include <string.h>
#include "string_t.h"

using namespace std;

int main()
{   
	int choice;
	char str[] = "";
	char newStr[] = "";

	cout << "Enter String:";
	cin >> str;
	String_t st(str);


	
	/*st.toUpper();
	st.print();
	cout<<endl;
	st.toLower();
	st.print();
	
	st.prepend("Matlis");
	st.print();
	
	st+= "Matlis";
	st.print();
	
	cout<< (st < "Rachel")<<endl;
	cout<< (st > "Rachel")<<endl;
	cout<< (st >= "Rachel")<<endl;
	cout<< (st <= "Rachel")<<endl;
	cout<< (st == "Rachel")<<endl;
	cout<< (st != "Rachel")<<endl;*/
	
	//cout<<st.contains("mat");
	
	//cout << st; 
	
	st+= "Matlis";
	
	
	//cout<< st[0]<<endl;
	//st[0] = 'M';
	
	cout<< st<<endl;
	

	cout << endl<<"Choose option:" << endl;
	do 
	{
		cout << endl;
		cout << "1.Set string" << endl;
		cout << "2.Get string" << endl;
		cout << "3.Get string length" << endl;
		cout << "4.Print string" << endl;
		cout << "5.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter String: ";
			cin >> newStr;
			st.setString(newStr);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << endl<<"The string: ";
			st.print();
			break;
		default:
			cout <<"Wrong choice please try again"<<endl;
			break;
		}
		
	} while (choice != 5);

}


