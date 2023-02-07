#include <iostream>
#include <fstream>
#include <string>

#include "Employee.h"

namespace AddressBookLib {
    void Employee::print() const {
        std::cout << *this << std::endl;
    }

    const uint32_t Employee::getID() const {
        return id;
    }
    const std::string Employee::getName() const{
        return name;  
    }
    const uint16_t Employee::getGrade() const{
        return grade;  
    }

    void Employee::setID(uint32_t id){
        this->id = id;
    }
    void Employee::setName(std::string &name){
        this->name = name;
    }
    void Employee::setGrade(uint16_t grad){
        this->grade = grade;
    }
    std::ostream &operator<<(std::ostream &os, const Employee &emp) {
        os << "Employee " << emp.getID() << "\n" << emp.getName() << "\n"  << "Grade " << emp.getGrade() << "\n";
        return os;
    }

    std::istream &operator>> (std::istream &is, Employee &emp) {
        uint32_t id;
        std::string name;
        uint16_t grade;
        is >> id >> name >> grade;
        emp.setID(id);
        emp.setName(name);
        emp.setGrade(grade);
        return is;
    }
    bool operator== (const Employee &emp1, const Employee &emp2) {
        return ((emp1.getID() == emp2.getID()) && (emp1.getName() == emp2.getName()) && (emp1.getGrade() == emp2.getGrade()));
    }

    bool operator!= (const Employee &emp1, const Employee &emp2) {
        return !(emp2 == emp2);
    }
    bool operator< (const Employee &emp1, const Employee &emp2){
        return (emp1.getGrade() < emp2.getGrade()); //for grade-wise sort by std::sort
    }
    bool operator> (const Employee &emp1, const Employee &emp2){
        return operator<(emp2,emp1);
    }
    bool operator<= (const Employee &emp1, const Employee &emp2){
        return !operator> (emp1,emp2);
    }
    bool operator>= (const Employee &emp1, const Employee &emp2){
        return !operator< (emp1,emp2);
    }

}