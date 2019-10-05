#include<iostream>
#include<string>
#include "building_t.h"
#include "street_t.h"
#include "city_t.h"


int main()
{
	int buildingID;
	string streetID, cityID;
	cout << "Welcome to my CITY application" << endl << endl;

	cout << "Enter new building ID: ";
	Building_t<int> iBuilding;
	cin >> buildingID;
	iBuilding.setBuidingID(buildingID);

	cout << "Enter new Street ID: ";
	Street_t<int, string> sStreet;
	cin >> streetID;
	sStreet.setStreetID(streetID);
	sStreet.addBuilding2Street(iBuilding);

	try
	{
		sStreet.getBuilding(10);
	}
	catch (int error)
	{
		cout << "Building ID not found"<<endl;
	}


	cout << "Enter new City ID: ";
	City_t<int, string, string> sCity;
	cin >> cityID;
	sCity.setCityID(cityID);
	sCity.AddStreet(sStreet);

	try
	{
		sCity.getStreet("Habika");
	}
	catch (int error)
	{
		cout << "Street ID not found" << endl;
	}

	cout << "--->" << sStreet.getStreetID() << ", " << iBuilding.getBuildingID() << ", " << sCity.getCityID() << " was added." << endl;

}



