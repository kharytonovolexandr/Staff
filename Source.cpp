#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include "Employee.h"
using namespace std;
void main()
{
	init();
	int action = 0;
	do 
	{
		cout << "\tMENU:" << endl;
		cout << "1. Add new employee: " << endl;
		cout << "2. Show all contacts: " << endl;
		cout << "3. Edit: " << endl;
		cout << "4. Delete: " << endl;
		cout << "5. Search: " << endl;
		cout << "6. Exit" << endl;
		cout << endl;
		cout << "Select action: ";
		cin >> action;

		switch (action)
		{
		case 1:
		{
			system("cls");
			addNew();
		}break;
		case 2:
		{
			system("cls");
			ShowAll();
		}break;
		case 3:
		{
			system("cls");
			edit();
		}break;
		case 4:
		{
			system("cls");
			Delete();
		}break;
		case 5:
		{
			system("cls");
			int searchMen = 0;
			cout << "Press 1 to search staff by fragment of name:" << endl;
			cout << "Press 2 to search by age: " << endl;
			cin >> searchMen;
			if (searchMen==1)
			{
				search();
			}
			else if (searchMen == 2)
			{
				searchByAge();
			}
			else
			{
				break;
			}
			
		}break;
		case 6:
		{
			cout << "Good bye." << endl;
		}break;
		
		default:
		{

		}break;

		}
	} while (action!=6);

}