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

Person::Person(const string& ln, const string& fn)
{
	lastName = ln;
	firstName = fn;
	patronymic = "";
}

void Person::Show()
{
	if (patronymic == "") {
		cout << "lastName " << lastName << endl;
		cout << "firstName " << firstName << endl << endl;
	}
}

void Person::ShowFormal()
{
	if (patronymic != "") {
		cout << "lastName " << lastName << endl;
		cout << "firstName " << firstName << endl;
		cout << "patronymic: " << patronymic << endl;
	}
}