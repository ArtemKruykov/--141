#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main() 
{
	Person package = Person("Kruykov", "Artem", "Aleksandrovich");
	package.Show(); 
	package.ShowFormal();
	return 0;
}