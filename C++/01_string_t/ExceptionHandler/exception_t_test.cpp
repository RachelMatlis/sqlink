#include"exception_t .h"
#include <iostream>

int main()
{
	try
	{
		throw Exception_t<string>("Error 123", "Division by zero", __FILE__, __LINE__);
	}
	catch (const Exception_t<string> &e)
	{
		cerr << e.getException() << endl
			<< e.descriptionOfException() << endl
			<< e.getFileName() << endl
			<< e.getFileLineNumer() << endl;
	}

	try
	{
		throw Exception_t<int>(876, "NULL pointer", __FILE__, __LINE__);
	}
	catch (const Exception_t<int> &e)
	{
		cerr << e.getException() << endl
			<< e.descriptionOfException() << endl
			<< e.getFileName() << endl
			<< e.getFileLineNumer() << endl;
	}

	return 0;
}