#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main() 
{
	Person package = Person("Kruykov", "Artem");
	package.Show(); 
	package.ShowFormal();
	return 0;
}

