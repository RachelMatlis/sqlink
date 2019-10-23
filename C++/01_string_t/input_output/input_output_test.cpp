#include "virtIO_t.h"
#include"asciiIO_t.h"
#include"binIO_t.h"
#include<iostream>

using namespace std;

typedef enum{ Ascii =1, Binary=2, Else =3} FileType;

void testIO(FileType fType);
void showOpenError(virtIO_t::Status error);
void showMenue();
void showStatus(virtIO_t::Status status);

void read(virtIO_t& virtIO);
void write(virtIO_t& virtIO);

int main()
{
	FileType fType = Else;
	int choice;

	while (fType != Ascii && fType != Binary)
	{
		cout << "Choose test:" << endl;
		cout << "1. Ascii" << endl;
		cout << "2. Binary" << endl;
		cin >> choice;
		if (choice == 1)
		{
			fType = Ascii;
		}
		else if (choice == 2)
		{
			fType = Binary;
		}
	}

	testIO(fType);

}

void testIO(FileType fType)
{
	virtIO_t* virtIO = 0;
	string path, mode;

	cout << endl << "Enter path: ";
	cin >> path;
	cout << "Enter mode: ";
	cin >> mode;

	switch (fType)
	{
	case Ascii:
		try 
		{
			virtIO = new asciiIO_t(path.c_str(), mode.c_str());
		}
		catch (virtIO_t::Status error)
		{
			showOpenError(error);
			return;
		}
		break;
	case Binary:
		try
		{
			virtIO = new binIO_t(path.c_str(), mode.c_str());
		}
		catch (virtIO_t::Status error)
		{
			showOpenError(error);
			return;
		}
		break;
	default:
		break;
	}

	int option=0;
	size_t pos;
	while (option !=9)
	{
		showMenue();
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "---> Path: " << virtIO->getPath()<<endl;
			break;
		case 2:
			cout << "---> Access: " << virtIO->getAccess() << endl;
			break;
		case 3:
			showStatus(virtIO->getStatus());
			break;
		case 4:
			cout << "---> Length: " << virtIO->getLength() << endl;
			break;
		case 5:
			//cout << "---> Position: " << virtIO->getPosition() << endl;
			//break;
		case 6:
			cout << "Enter position: ";
			cin >> pos;
			virtIO->setPosition(pos);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			cout << "GoodBye!"<<endl;
			break;
		default:
			break;
		}
	}
}

void showOpenError(virtIO_t::Status error)
{
	switch (error)
	{
	case 1:
		cout << "Cant open file" << endl;
		break;
	case 2:
		cout << "Bad access " << endl;
		break;
	default:
		break;
	}
}

void showMenue()
{
	cout << endl;
	cout << "Choose option:" << endl;
	cout << "1. Get path" << endl;
	cout << "2. Get access" << endl;
	cout << "3. Get status" << endl;
	cout << "4. Get length" << endl;
	cout << "5. Get position" << endl;
	cout << "6. Set position" << endl;
	cout << "7. Read from file ( >> )" << endl;
	cout << "8. Write to file ( << )" << endl;	
}

void showStatus(virtIO_t::Status status)
{
	cout << "---> Status: ";
	switch (status)
	{
	case 0:
		cout << "ok";
		break;
	case 1:
		cout << "cant open file";
		break;
	case 2:
		cout << " bad access";
		break;
	case 3:
		cout << "write Err";
		break;
	case 4:
		cout << "read Err";
		break;
	default:
		break;
	}
	cout << endl;
}

void write(virtIO_t& virtIO)
{

}