#include <iostream>
#include "adressbook.h" 

int main() {
	const Friend person = Friend(2, "Nikita", 4);
	std::cout << "display test" << std::endl;
	person.disp();
	adresslist newbook;
	newbook.addperson(person);
	std::cout << "functions' test" << std::endl;
	std::string name;
	for (int i = 0; i < 2; i++){
		std::cin >> name;
		newbook.addperson(i, name, i % 5);
	}
	newbook.findperson(1);
	std::cout << std::endl;
	newbook.findperson("Nikita");
	std::cout << std::endl;
	newbook.delperson(1);
	newbook.findperson(1);
	std::cout << std::endl;
	//newbook.clearbook();
	std::cout <<std::endl<< "constructor of copying test " << std::endl;
	adresslist copybook = newbook;
	copybook.findperson("Nikita");
	copybook.delperson(2);
	copybook.findperson("Nikita");
	newbook.findperson("Nikita");
	std::cout <<std::endl<< "operator= test" << std::endl;
	adresslist copybook2;
	copybook2 = newbook;
	copybook2.findperson("Nikita");
	copybook2.delperson(2);
	copybook2.findperson("Nikita");
	newbook.findperson("Nikita");
	std::cout << std::endl << "operator<< test" << std::endl;
	std::cout<<newbook;
	std::cout << person;
	std::cout << std::endl << "operator>> test" << std::endl << "print id, name and grade" << std::endl;
	Friend person2;
	std::cin >> person2;
	person2.disp();
	std::cout << std::endl << "operator+ test"<<std::endl;
	newbook + person2;
	std::cout<< newbook;
	std::cout << std::endl << "operator- test" << std::endl;
	newbook - person2;
	std::cout << newbook;
	std::cout << std::endl << "operator!= and operator== test" << std::endl;
	Friend person3 = person2;
	newbook + person2;
	newbook + person3;
	if (person != person2) {
		std::cout << "not equal" << std::endl;
	}
	if (person3 == person2) {
		std::cout << "equal" << std::endl;
		newbook - person2;
	}
	std::cout << std::endl << "get with index test" << std::endl;
	newbook[1].disp();
}
