#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include "Employee.h"
using namespace std;
int sizeArr = 0;
staff* staffArr=new staff;
const string fileName = "Staff.txt";

void addNew()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		staff* NewStaffArr = new staff[sizeArr + 1];
		for (int i = 0; i < sizeArr; i++)
		{
			NewStaffArr[i].name = staffArr[i].name;
			NewStaffArr[i].lastname = staffArr[i].lastname;
			NewStaffArr[i].age = staffArr[i].age;
		}
			staff NewStaff;
			cout << "Enter new employee name:" << endl;
			cin>>NewStaff.name;
			cout << "Enter new employee last name:" << endl;
			cin>> NewStaff.lastname;
			cout << "Enter new employee age:" << endl;
			cin >> NewStaff.age;

			NewStaffArr[sizeArr] = NewStaff;
			sizeArr++;
			staffArr = new staff[sizeArr];
			for (int i = 0; i < sizeArr; i++)
			{
				staffArr[i] = NewStaffArr[i];
			}
			delete[]NewStaffArr;

			fout << NewStaff.name << endl;
			fout << NewStaff.lastname << endl;
			fout << NewStaff.age << endl;

		
		fout.close();
	}
	else
	{
		cout << "ERROR! Application can't connect to database file!" << endl;
	}
}

void edit()
{
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		string text;
		staff* NewStaffArr = new staff[sizeArr];
		cout << "Enter employee name you want to edit:" << endl;
		cin >> text;
		staff NewStaff;
		for (int i = 0; i < sizeArr; i++)
		{
			NewStaffArr[i].name = staffArr[i].name;
			NewStaffArr[i].lastname = staffArr[i].lastname;
			NewStaffArr[i].age = staffArr[i].age;


			if (staffArr[i].name == text || staffArr[i].lastname == text)
			{
				cout << "Enter new employee name:" << endl;
				cin >> NewStaff.name;
				cout << "Enter new employee last name:" << endl;
				cin >> NewStaff.lastname;
				cout << "Enter new employee age:" << endl;
				cin >> NewStaff.age;
				NewStaffArr[i]=NewStaff;
				
			}
		}
		delete[]staffArr;

		
		staffArr = new staff[sizeArr];
		for (int i = 0; i < sizeArr; i++)
		{
				staffArr[i].name = NewStaffArr[i].name;
				staffArr[i].lastname = NewStaffArr[i].lastname;
				staffArr[i].age = NewStaffArr[i].age;
			
		}

		delete[]NewStaffArr;
		for (int i = 0; i < sizeArr; i++)
		{
			fout << staffArr[i].name << endl;
			fout << staffArr[i].lastname << endl;
			fout << staffArr[i].age << endl;
		}



		fout.close();
	}
	else
	{
		cout << "ERROR! Application can't connect to database file!" << endl;
	}
}

void searchByAge()
{
	int age=0;
	cout << "Enter co-worker's age: " << endl;
	cin >> age;
	for (int i = 0; i < sizeArr; i++)
	{
		if (staffArr[i].age==age)
		{
			cout << "Employee name: " << staffArr[i].name << endl;
			cout << "Employee lastname: " << staffArr[i].lastname << endl;
			cout << "Employee age: " << staffArr[i].age << endl;

		}
	}
}

void search()
{
	string text;
	cout << "Enter text for search: " << endl;
	cin >> text;
	for (int i = 0; i < sizeArr; i++)
	{
		if (staffArr[i].name.find(text)!=string::npos||staffArr[i].lastname.find(text)!=string::npos)
		{
			cout << "Employee name: " << staffArr[i].name << endl;
			cout << "Employee lastname: " << staffArr[i].lastname << endl;
			cout << "Employee age: " << staffArr[i].age << endl;

		}
	}

}

void ShowAll()
{
	
		for (int i = 0; i < sizeArr; i++)
		{
			cout << i + 1 << ')' << "Name: " << staffArr[i].name << endl;
			cout << "Last name: " << staffArr[i].lastname << endl;
			cout << "Age: " << staffArr[i].age << endl;
		}
	
}

void Delete()
{
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		string text;
		staff* NewStaffArr = new staff[sizeArr];
		cout << "Enter employee name you want to delete:" << endl;
		cin >> text;
		for (int i = 0; i < sizeArr; i++)
		{
			NewStaffArr[i].name = staffArr[i].name;
			NewStaffArr[i].lastname = staffArr[i].lastname;
			NewStaffArr[i].age = staffArr[i].age;


			if (staffArr[i].name==text||staffArr[i].lastname == text) 
			{
				NewStaffArr[i].name = "";
				NewStaffArr[i].lastname = "";
				NewStaffArr[i].age = NULL;
			}
		}
		delete[]staffArr;
			
			sizeArr--;
			staffArr = new staff[sizeArr];
			for (int i = 0; i < sizeArr; i++)
			{
				if (NewStaffArr[i].name == ""|| NewStaffArr[i].lastname=="") 
				{
					continue;
				}
				else
				{
					staffArr[i].name = NewStaffArr[i].name;
					staffArr[i].lastname = NewStaffArr[i].lastname;
					staffArr[i].age = NewStaffArr[i].age;
				}
			}
			
			delete[]NewStaffArr;
			for (int i = 0; i < sizeArr; i++)
			{
				fout << staffArr[i].name << endl;
				fout << staffArr[i].lastname << endl;
				fout << staffArr[i].age << endl;
			}
			

		
		fout.close();
	}
	else
	{
		cout << "ERROR! Application can't connect to database file!" << endl;
	}
}

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOPen = fin.is_open();

	if (isOPen == false)
	{
		cout << "Error opening file" << endl;
	}
	else {
		staff temp;
		while (!fin.eof())
		{
			//fin.ignore();
				fin >> temp.name;
				if (temp.name != "") 
				{
					fin>> temp.lastname;
					fin>> temp.age;

					staff* NewStaffArr = new staff[sizeArr + 1];
					for (int i = 0; i < sizeArr; i++)
					{
						NewStaffArr[i] = staffArr[i];
					}
					NewStaffArr[sizeArr] = temp;
					sizeArr++;
					staffArr = new staff[sizeArr];
					for (int i = 0; i < sizeArr; i++)
					{
						staffArr[i] = NewStaffArr[i];
					}
					delete[]NewStaffArr;
					temp.name = "";
				}
				else 
				{ 
					break; 
				}
				
		}
		
	}

//fin.close();
}
