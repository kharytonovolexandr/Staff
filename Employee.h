#pragma once
#include<iostream>
#include<string>
#include<list>
#include<fstream>
using namespace std;

struct staff
{
	string name;
	string lastname;
	int age;

};
void addNew();
void edit();
void searchByAge();
void search();
void ShowAll();
void Delete();
void init();