#include"tContainer_t.h"
#include<iostream> 


void vectorContainerTest();
void ListContainerTest();

int main()
{
	int x;
	tContainer_t<int, vector<int*>> container;
	int choice = 0;

	while (choice != 10)
	{
		cout << endl<<"Choose option:" << endl;
		cout << "1. Insert new element" << endl;
		cout << "2. Is container empty" << endl;
		cout << "3. Number of elements in container" << endl;
		cout << "4. First element in container" << endl;
		cout << "5. Last element in container" << endl;
		cout << "6. Find specific element" << endl;
		cout << "7. Remove specific element" << endl;
		cout << "8. Remove all the elements" << endl;
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
				cout << "--> The first elemnt is: " << *(container.getFirst()) << endl;
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
			cout << "Enter elemnt to to find: " << endl;
			cin >> x;
			cout << "--> " << x;
			container.find(x) != 0 ?  cout << " was found." : cout << " was not found.";
			cout << endl;
			break;
		case 7:
			break;
		case 8:
			container.removeAll();
			cout << "--> All elemnts has removed." << endl;
			break;
		case 10:
			cout << "GOODBYE!" << endl;
			break;
		default:
			cout << "Wrong input tre again." << endl;
			break;
		}
	}


	return 0;
}

