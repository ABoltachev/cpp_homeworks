//
// Created by m.ekstrin on 02.12.2022.
//
#include <iostream>
#include <string>
#include <forward_list>
#include "employee.hpp"
#include "address_book.hpp"

namespace AddressBookModule {

    AddressBook &AddressBook::operator=(const AddressBook &another) {
        this->clear();
        for (auto& emp: another.address_book){
            this->add(emp);
        }
        return *this;
    }

    void AddressBook::add(const Employee &new_record) {
        address_book.push_front(new_record);
    }

    void AddressBook::remove_by_id(uint32_t id) {
        address_book.remove(find_by_id(id));
    }

    Employee &AddressBook::find_by_id(uint32_t id) {
        for (auto &emp: address_book) {
            if (emp._id == id) {
                return emp;
            }
        }
        address_book.push_front(Employee());
        return address_book.front();
    }

    Employee &AddressBook::find_by_name(const std::string &name) {
        for (auto &emp: address_book) {
            if (emp._name == name)
                return emp;
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
        remove_by_id(emp._id);
    }

    Employee &AddressBook::operator[](const int index) {
        return find_by_id(index);
    }

    Employee &AddressBook::operator[](const std::string &index_name) {
        return find_by_name(index_name);
    }
}