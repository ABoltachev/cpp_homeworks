#include <iostream>
#include <string>
#include <forward_list>

#include "AddressBook.h"
#include "Employee.h"


namespace AddressBookLib {

    const std::forward_list<Employee> AddressBook::getAddrBook() const{
        return AddrBook;
    }

    std::ostream &operator<<(std::ostream &os, const AddressBook &book) {
        if (book.getAddrBook().empty())
            os << "The book is empty\n";
        else {
            for (auto &emp: book.getAddrBook())
                os << emp << std::endl;
        }
        return os;
    }

    AddressBook &AddressBook::operator=(const AddressBook &rAdBook) {
        if (this != &rAdBook)
            *this = rAdBook;
        return *this;
    }

    void AddressBook::addEmp(uint32_t id, const std::string &name, uint16_t grade) {
        AddrBook.push_front(Employee(id, name, grade));
    }

    void AddressBook::addEmp(const Employee &emp) {
        AddrBook.push_front(emp);
    }

    Employee& AddressBook::lookupID(uint32_t id) {
        for (Employee &emp: AddrBook) {
            if (emp.id == id)
                return emp;
        }
        AddrBook.push_front(Employee());
        return AddrBook.front();
    }
    Employee& AddressBook::lookupName(const std::string &name) {
        for (Employee &emp: AddrBook) {
            if (emp.name == name)
                return emp;
        }
        AddrBook.push_front(Employee());
        return AddrBook.front();
    }

    void AddressBook::rmEmpByID(uint32_t id) {
        AddrBook.remove(lookupID(id));
    }

    AddressBook& AddressBook::operator+=(const Employee &emp) {
        addEmp(emp);
        return *this;
    }

    AddressBook& AddressBook::operator-=(const Employee &emp) {
        rmEmpByID(emp.id);
        return *this;
    }

    Employee& AddressBook::operator[](const int id) {
        return lookupID(id);
    }
    Employee& AddressBook::operator[](const std::string& name) {
        return lookupName(name);
    }

    void AddressBook::clear() {
        AddrBook.clear();
    }

    void AddressBook::print() const {
        std::cout << *this << '\n';
    }

    AddressBook operator+ (AddressBook lAdBook, const Employee &rEmp){
        lAdBook += rEmp;
        return lAdBook;
    }

    AddressBook operator- (AddressBook lAdBook, const Employee &rEmp){
        lAdBook -= rEmp;
        return lAdBook;
    }

}