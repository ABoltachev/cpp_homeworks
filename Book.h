#pragma once
#include <string>
#include <list>
#include "person.h"

using namespace std;

class PhoneBook {
    list<Person> people;
public:
    PhoneBook();
    ~PhoneBook();

    bool addPerson(string, uint32_t, uint16_t);
    void DelPerson(uint32_t);

    bool searchById(uint32_t);
    bool searchByName(string);
    void listAllPeople();
};