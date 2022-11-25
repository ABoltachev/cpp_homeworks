#include "AdressBook.hpp"
#include <iostream>
using namespace std;

int main() 
{
	AdressBook ab;
	ab.push(7, "AA", 7);
	ab.push(6, "BB", 6);
	ab.push(5, "CC", 5);
	cout << ab;
	AdressBook ba = ab;
	ab.clear();
	ba.erase(7);
	cout << ba["AA"];
	return 0;
}