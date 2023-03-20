#pragma once
#include <string>
#include <list>
#include "person.h"



class PhoneBook {
    std::list<Person> people;
public:
    
    PhoneBook()=default;
    void clear();

    void addPerson(const Person &Ppl);
    void DelPerson(uint32_t);

    Person &searchById(uint32_t);
    Person &searchByName(const std::string);
    void listAllPeople();

    void operator+(const Person &person);

    void operator-(const Person &person);

    PhoneBook &operator=(const PhoneBook& other);
    

    friend std::ostream& operator<<(std::ostream& os, PhoneBook& person);
};



