#include<iostream>
#include "building_t.h"
#include "street_t.h"
#include "city_t.h"



int main()
{
	Building_t<int> iBuilding;
	iBuilding. setBuidingID(5);

	cout << "New Building Id:"<<iBuilding.getBuildingID()<<endl;
	return 0;
}