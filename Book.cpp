#include <string>
#include <list>
#include <iostream>
#include "Person.h"
#include "Book.h"





void PhoneBook::addPerson(const Person &Ppl) {
    people.push_back(Ppl);
}
void PhoneBook::clear() {
    people.clear();
}

void PhoneBook::DelPerson(uint32_t id) {
    people.remove(searchById(id));
}

void PhoneBook::listAllPeople() {
    std::list<Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        std::cout << ((Person)(*it)).getName() << " -- " << ((Person)(*it)).getId() << std::endl;
    }
}

Person &PhoneBook::searchByName(const std::string name) {
    for (auto &Ppl : people) {
        if (Ppl.name == name) {
            return Ppl;
        }
    }
    people.push_back(Person());
    return people.back();
}


Person &PhoneBook::searchById(uint32_t id) {
    std::list<Person>::iterator it;
    for (auto& Ppl : people) {
        if (Ppl.id == id) {
            return Ppl;
        }
    }
    people.push_back(Person());
    return people.back();
}

void PhoneBook::operator+(const Person &person) {
    addPerson(person);
}

void PhoneBook::operator-(const Person &person) {
    DelPerson(person.id);
}
std::ostream& operator<<(std::ostream& os, PhoneBook& person) {
    for (auto& Ppl : person.people) {
        std::cout << "Id: " << Ppl.getId() << std::endl;
        std::cout << "Name: " << Ppl.getName() << std::endl;
        std::cout << "Grade: " << Ppl.getGrade() << std::endl;
    }
    return std::cout;
}

