#include <string>
#include <list>
#include <iostream>
#include "Person.h"
#include "Book.h"

using namespace std;

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
    people.erase(people.begin(),people.end());
}

bool PhoneBook::addPerson(string namee, uint32_t idd, uint16_t gradee) {
    people.push_back(Person(namee, idd,gradee));
    return true;
}


void PhoneBook::DelPerson(uint32_t idd) {
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        if (((Person)(*it)).getId() == idd) {
            people.erase(it);
            break;
        }
    }
}

void PhoneBook::listAllPeople() {
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        cout << ((Person)(*it)).getName() << " -- " << ((Person)(*it)).getId() << endl;
    }
}

bool PhoneBook::searchByName(string name) {
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        if (((Person)(*it)).getName() == name) {
            cout<<((Person)(*it)).getName()<<" "<< ((Person)(*it)).getId() << " " << ((Person)(*it)).getGrade()<<endl;
            return 1;
        }
    }
    return 0;
}


bool PhoneBook::searchById(uint32_t id) {
    list<Person> l;
    list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        if (((Person)(*it)).getId() == id) {
            cout << ((Person)(*it)).getName() << " " << ((Person)(*it)).getId() << " " << ((Person)(*it)).getGrade() << endl;
            return 1;
        }
    }
    return 0;
}