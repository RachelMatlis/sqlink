# include <iostream>
# include <string>
#include "car.h"
#include "bus.h"
#include "private.h"
using namespace std;

void defCtor();
void ctorWithParams();
void assign();
void opSmall();
void compType();
void getid();

int main()
{
	int option = 0;

	while (option!=6)
	{
		cout << "Please choose an option:" << endl;
		cout << "1. Default constructor " << endl;
		cout << "2. Constructor with params" << endl;
		cout << "3. Operator =" << endl;
		cout << "4. Operator <" << endl;
		cout << "5. Compare type by name " << endl;
		cout << "6. Get Id" << endl;
		cout << "10. Exit" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			defCtor();
			break;
		case 2:
			ctorWithParams();
			break;
		case 3:
			assign();
			break;
		case 4:
			opSmall();
			break;
		case 5:
			compType();
			break;
		case 6:
			getid();
			break;

		default:
			cout << "Goodbye!<<endl";
			break;
		}
	}
}

void defCtor() 
{
	Bus_t bus;
	Private_t car;

	cout << "New "<<bus.getName() << endl;
	cout << "New" <<car.getName() << endl;
}

void ctorWithParams() 
{
	size_t capacity;

	cout << "Enter a capacity for car: ";
	cin >> capacity;
	Private_t car(capacity);
	cout << "New " << car.getName() << " with capacity of" << car.getCapacity() << endl;

	cout << "Enter a capacity for bus: ";
	cin >> capacity;
	Bus_t bus(capacity);
	cout << "New " << bus.getName() << " with capacity of" << bus.getCapacity() << endl;
}

void assign() 
{
	Private_t car1(1200);
	Private_t car2(1400);

	cout << "first car" << car1.getCapacity() << endl;
	cout << "second car" << car2.getCapacity() << endl;
	//car1 = car2;

	cout << "first car" << car1.getCapacity() << endl;

}

void opSmall() {
	Private_t car1(1500);
	Private_t car2(1800);
	cout << "car 1 capacity: " << car1.getCapacity()<<", car 2 capacity: " << car2.getCapacity() << endl;
	cout << "car 1 capacity < car 2 capacity ? - " << (car1 < car2) << endl;
}

void compType() {
	Bus_t bus1, bus2;
	Private_t private1, private2; 

	cout << "bus1 compare bus2: " << (bus1.compareType(bus2)) << endl;
	cout << "bus1 compare private1: " << (bus1.compareType(private1)) << endl;
	cout << "private1 compare private1: " << (private1.compareType(private2)) << endl;
}

void getid()
{
	Bus_t b1;
	cout << "Create First bus. " << endl << "ID: " << b1.getId() << endl;

	Bus_t b2;
	cout << "Create Second bus. " << endl << "ID: "<< b2.getId() << endl;

	Private_t p1;
	cout << "Create First car. " << endl << "ID: "<< p1.getId() << endl;

}