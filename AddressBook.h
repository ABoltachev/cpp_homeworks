#ifndef Address_H
#define Address_H

#include <iostream>
#include <string>
#include <forward_list>
#include "Employee.h"


namespace AddressBookLib {

    using std::forward_list;
    class Employee;

    class AddressBook {
    private:
        std::forward_list<Employee> AddrBook;
    public:
        AddressBook() = default;
        
        AddressBook(const AddressBook &book) = default;
        AddressBook& operator= (const AddressBook &another);

        //getters
        const std::forward_list<Employee> getAddrBook() const;

        void addEmp();
        void addEmp(uint32_t id, const std::string &name, uint16_t grade);
        void addEmp(const Employee &emp);
        void rmEmpByID(uint32_t id);
        Employee& lookupID(uint32_t id);
        Employee& lookupName(const std::string &name);


        AddressBook& operator+= (const Employee &emp);
        AddressBook& operator-= (const Employee &emp);

        Employee& operator[] (const int id);
        Employee& operator[] (const std::string& name);

        void clear();
        void print() const;

    };

    std::ostream& operator<< (std::ostream &os, const AddressBook &book);

    AddressBook operator+ (AddressBook lAdBook, const Employee &rEmp);
    AddressBook operator- (AddressBook lAdBook, const Employee &rEmp);

}

#endif