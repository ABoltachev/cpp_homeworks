//
// Created by m.ekstrin on 02.12.2022.
//
#include <iostream>
#include <string>
#include <forward_list>
#include "employee.hpp"
#include "address_book.hpp"

namespace AddressBookModule {

    AddressBook &AddressBook::operator=(const AddressBook &old) {
        this->clear();
        for (auto &emp: old.address_book) {
            this->add(emp);
        }
        return *this;
    }

    void AddressBook::add(const Employee &emp) {
        address_book.push_front(emp);
    }

    void AddressBook::remove_by_id(uint32_t id) {
        address_book.remove(find_by_id(id));
    }

    Employee &AddressBook::find_by_id(uint32_t id) {
        for (auto &emp: address_book) {
            if (emp.id == id) {
                return emp;
            }
        }
        address_book.push_front(Employee());
        return address_book.front();
    }

    Employee &AddressBook::find_by_name(const std::string &name) {
        for (auto &emp: address_book) {
            if (emp.name == name) {
                return emp;
            }
        }
        address_book.push_front(Employee());
        return address_book.front();
    }

    void AddressBook::clear() {
        address_book.clear();
    }

    std::ostream &operator<<(std::ostream &out, const AddressBook &book) {
        for (auto &emp: book.address_book) {
            out << emp << std::endl;
        }
        return out;
    }

    void AddressBook::operator+(const Employee &emp) {
        add(emp);
    }

    void AddressBook::operator-(Employee &emp) {
        remove_by_id(emp.id);
    }

    Employee &AddressBook::operator[](int id) {
        return find_by_id(id);
    }

    Employee &AddressBook::operator[](const std::string &name) {
        return find_by_name(name);
    }

    Employee const &AddressBook::operator[](int id) const {
        for (auto &emp: address_book) {
            if (emp.id == id) {
                return emp;
            }
        }
    }

    Employee const &AddressBook::operator[](const std::string &name) const {
        for (auto &emp: address_book) {
            if (emp.name == name) {
                return emp;
            }
        }
    }
}