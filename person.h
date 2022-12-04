#pragma once
#include <string>


class Person {
    friend class PhoneBook;
protected:
    std::string name;
    uint32_t id=0;
    uint16_t grade=0;
public:
    Person(std::string, uint32_t, uint16_t);
    Person() = default;
    std::string getName();
    uint32_t getId();
    uint16_t getGrade();
    void setName(const std::string&);
    void setId(uint32_t);
    void setGrade(uint16_t);
    void PrintPerson();
    friend bool operator==(const Person& person1, const Person& person2);
    friend bool operator!=(const Person& person1, const Person& person2);
    friend std::ostream &operator<<(std::ostream &os, const Person& person);
    friend std::istream &operator>>(std::istream &is, const Person& person);
};

