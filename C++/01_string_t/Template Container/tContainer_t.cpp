#include"tContainer_t.h"
#include<iostream> 


void showMenue();

int main()
{
	int x;
	tContainer_t<int, vector<int*>> container;
	int choice = 0;

	while (choice != 12)
	{
		showMenue();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter elemnt to insert: " << endl;
			cin >> x;
			container.insert(&x);
			cout << "--> " << x<< " was inserted."<<endl;
			break;
		case 2:
			cout << "--> The container is ";
			container.isEmpty() == true ? cout << "empty." : cout << "not empty.";
			cout <<endl;
			break;
		case 3:
			cout << "--> " <<container.getSize() << " elemnts in container." <<endl;
			break;
		case 4:
			if (!container.isEmpty())
			{
				cout << "--> The first elemnt is: " << *container.getFirst() << endl;
			}
			else
			{
				cout << "--> The container is empty." << endl;
			}
			break;
		case 5:
			if (!container.isEmpty())
			{
				cout << "--> The last elemnt is: " << *(container.getLast()) << endl;
			}
			else
			{
				cout << "--> The container is empty."<<endl;
			}
			break;
		case 6:
			if (!container.isEmpty())
			{
				cout << "Enter elemnt to to find: " << endl;
				cin >> x;
				cout << "--> " << x;
				container.find(x) != 0 ? cout << " was found." : cout << " was not found.";
			}
			else
			{
				cout << "--> The container is empty.";
			}
			cout << endl;
			break;
		case 7:
			if (!container.isEmpty())
			{
				cout << "Enter elemnt to to remove: " << endl;
				cin >> x;
				if (container.remove(x)!=0)
				{
					cout << "--> " << *container.remove(x) << "has removed"<<endl;
				}
				else
				{
					cout << "Elemnt not found: " << endl;
				}
			}
			else
			{
				cout << "--> The container is empty.";
			}
			break;
		case 8:
			container.removeAll();
			cout << "--> All elemnts has removed." << endl;
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			cout << "Enter index to get value " << endl;
			cin >> x;
			cout <<"-->  container[" <<x << "] = "<<*(container[x]) << endl;
			break;

		case 12:
			cout << "GOODBYE!" << endl;
			break;
		default:
			cout << "Wrong input tre again." << endl;
			break;
		}
	}


	return 0;
}

void showMenue()
{
	cout << endl << "Choose option:" << endl;
	cout << "1. Insert new element" << endl;
	cout << "2. Is container empty" << endl;
	cout << "3. Number of elements in container" << endl;
	cout << "4. First element in container" << endl;
	cout << "5. Last element in container" << endl;
	cout << "6. Find specific element" << endl;
	cout << "7. Remove specific element" << endl;
	cout << "8. Remove all the elements" << endl;
	cout << "9. Remove and delete elemnt" << endl;
	cout << "10. Remove and delete all elemnts" << endl;
	cout << "11. Get value by index ([])" << endl;
	cout << "12. End program" << endl;
}
