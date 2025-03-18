#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
	lastName = "";
	firstName = "";
	patronymic = "";
}

Person::Person(const string& ln, const string& fn, const string& pn)
{
	lastName = ln;
	firstName = fn;
	patronymic = pn;
}

void Person::Show()
{
	cout << "lastName " << lastName << endl;
	cout << "firstName " << firstName << endl << endl;
}

void Person::ShowFormal()
{
	cout << "lastName " << lastName << endl;
	cout << "firstName " << firstName << endl;
	cout << "patronymic: " << patronymic << endl;
}