#include <iostream>
#include <vector>
#include "addressbook.hpp"

using namespace std;

int main() {
	Employee e;
	cin >> e;
	cout << "YA EMPLOYEE WITH THIS DATTAAAA!!!! UAAA:: " << e << endl;

	Employee e2;
	cin >> e2;
	cout << (e != e2) << endl;

	AddressBook ab;
	ab.add(e);
	ab.add(e2);
	cout << *ab.find("Dima") << endl;
	cout << ab << endl << endl;

	ab.delete_by_id(3);

	cout << ab << endl << endl;

	AddressBook ab1;
	ab1 = ab;
	cout << ab1 << endl;

	cout << (ab1.find("Ksusha") != ab.find("Ksusha")) << endl;

	AddressBook ab2(ab1);

	cout << ab2 << endl;
	cin >> e;
	ab2 += e;
	cout << ab2 << endl;
	cin >> e;
	cout << ab2 + e << endl;

	ab2 -= 1;
	cout << ab2;

	cout << ab2[4] << endl;
	cout << ab2["Ksusha"] << endl;
	return 0;
}