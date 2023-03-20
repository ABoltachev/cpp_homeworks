#ifndef ADDRESSBOOK_BOOK_H
#define ADDRESSBOOK_BOOK_H

#include <list>
#include <string>
#include <iostream>
#include <algorithm>

namespace AddressBookLib
{
    class Employee
    {
    private:
        friend class Book;

        uint32_t u_id {0};
        std::string u_name;
        uint16_t u_grade {0};

    public:
        Employee() = default;
        Employee(uint32_t id, std::string name, uint16_t grade) : u_id(id), u_name(std::move(name)), u_grade(grade) {};
        ~Employee() = default;

        friend std::ostream& operator<<(std::ostream &out, const Employee &obj);
        friend std::istream& operator>>(std::istream &in, Employee &obj);
        friend bool operator==(const Employee &emp_1, const Employee &emp_2);
        friend bool operator!=(const Employee &emp_1, const Employee &emp_2);

    };

    class Book
    {
    private:
        std::list<Employee> address_book;
    public:
        // Constructor
        Book();
        Book(const Book& new_book);

        Book& operator=(const Book& new_book);
        explicit Book(const Employee& empleyee);

        // Destructor
        ~Book();

        void add_user(const Employee& employee);
        void add_user(uint32_t id, const std::string& name, uint16_t grade);

        void remove_by_id(uint32_t id);

        Employee find(uint32_t id);
        Employee find(const std::string &name);

        friend std::ostream& operator<<(std::ostream &out, const Book &obj);
        Book operator+(const Employee& emp);
        Book operator-(uint32_t id);
        Employee& operator[](uint32_t) const;
        void clear();
    };
}
#endif
