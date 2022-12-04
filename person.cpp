#include <string>
#include "person.h"
#include <iostream>


Person::Person(std::string namee, uint32_t idd, uint16_t gradee) {
    name = namee;
    id = idd;
    grade = gradee;
}

std::string Person::getName() {
    return name;
}

uint32_t Person::getId() {
    return id;
}

uint16_t Person::getGrade() {
    return grade;
}

void Person::setId(uint32_t new_id) {
    id = new_id;
}
void Person::setName(const std::string& new_name) {
    name = new_name;
}
void Person::setGrade(uint16_t new_grade) {
    grade = new_grade;
}

void Person::PrintPerson() {
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Grade: " << this->grade << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Person &person) {
    std::cout << "id: " << person.id << std::endl;
    std::cout << "name: " << person.name << std::endl;
    std::cout << "grade: " << person.grade << std::endl;
    return std::cout;
}
std::istream& operator>>(std::istream &is, Person &person) {
    uint32_t id;
    std::string name;
    uint16_t grade;
    std::cin >> id >> name >> grade;
    person.setId(id);
    person.setName(name);
    person.setGrade(grade);
    return std::cin;
}


bool operator==(const Person &person1,const Person &person2) {
    if (person1.name == person2.name && person1.id == person2.id && person1.grade == person2.grade) {
        return true;
    }
    else {
        return false;
    }
}
bool operator!=(const Person &person1, const Person &person2) {
    if (person1.name != person2.name or person1.id != person2.id or person1.grade != person2.grade) {
        return true;
    }
    else {
        return false;
    }
}