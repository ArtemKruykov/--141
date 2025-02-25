#pragma once
#include <string>
using namespace std;
class Person
{
private:
	string lastName;
	string firstName;
	string patronymic;
public:
	Person();
	Person(const string& ln, const string& fn, const string& pn = "");
	void Show();//firstName + lastName 
	void ShowFormal();//ิศฮ
};
