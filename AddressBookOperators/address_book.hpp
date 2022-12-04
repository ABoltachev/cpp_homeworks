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


        void add(const Employee &new_record);

        void remove_by_id(uint32_t id);

        Employee &find_by_id(uint32_t id);

        Employee &find_by_name(const std::string &name);

        void clear();

        friend std::ostream &operator<<(std::ostream &out, const AddressBook &book);

        void operator+(const Employee &emp);

        void operator-(Employee &emp);

        Employee &operator[](const int index);

        Employee &operator[](const std::string &index_name);


        AddressBook &operator=(const AddressBook &another);

    };
};
#endif //HW1_ADDRESS_BOOK_HPP
