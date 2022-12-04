//
// Created by m.ekstrin on 02.12.2022.
//
#include <forward_list>
#include "employee.hpp"

#ifndef HW1_ADDRESS_BOOK_HPP
#define HW1_ADDRESS_BOOK_HPP


namespace AddressBookModule {

    class AddressBook {
        std::forward_list<Employee> address_book;
    public:
        AddressBook() = default;


        void add(const Employee &emp);

        void remove_by_id(uint32_t id);

        Employee &find_by_id(uint32_t id);

        Employee & find_by_name(const std::string &name);

        void clear();

        friend std::ostream &operator<<(std::ostream &out, const AddressBook &book);

        void operator+(const Employee &emp);

        void operator-(Employee &emp);

        Employee &operator[](int id);

        Employee &operator[](const std::string &name);

        Employee const &operator[](int id) const;

        Employee const &operator[](const std::string &name) const;

        AddressBook &operator=(const AddressBook &old);

    };
};
#endif //HW1_ADDRESS_BOOK_HPP
