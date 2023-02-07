#ifndef Employee_H
#define Employee_H

#include <iostream>
#include <string>

namespace AddressBookLib {
    class Employee {
    private:
        uint32_t id = 0;
        std::string name = "";
        uint16_t grade = 0;
        friend class AddressBook;
    public:
        Employee() = default;
        Employee(uint32_t id, const std::string &name, uint16_t grade): id(id), name(name), grade(grade){}

        //getters
        const uint32_t getID() const;
        const std::string getName() const;
        const uint16_t getGrade() const;
        
        //setters
        void setID(uint32_t id);
        void setName(std::string &name);
        void setGrade(uint16_t grade);

        void print() const;
        
    };

    std::ostream &operator<< (std::ostream &os, const Employee &emp);
    std::istream &operator>> (std::istream &is, Employee &emp);        

    bool operator== (const Employee &emp1, const Employee &emp2);
    bool operator!= (const Employee &emp1, const Employee &emp2);
    bool operator< (const Employee &emp1, const Employee &emp2);
    bool operator> (const Employee &emp1, const Employee &emp2);
    bool operator<= (const Employee &emp1, const Employee &emp2);
    bool operator>= (const Employee &emp1, const Employee &emp2);

}

#endif