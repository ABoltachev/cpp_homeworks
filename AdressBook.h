#pragma once

#include <iostream>
#include <ostream>
#include <cstdint>
#include <string>
#include <forward_list>
#include <cstdlib>


class Employee
{
public:
    uint32_t id;
    std::string name;
    uint16_t grade;
    bool operator==(const Employee& b) const;
    bool operator!=(const Employee& b) const;
    friend std::ostream& operator<<(std::ostream& out, const Employee& emp);
    friend std::istream& operator>>(std::istream& in, Employee& emp);
};

class AdressBook{
public:
    std::forward_list<Employee> employees;
public:
    AdressBook() = default;
    AdressBook(const AdressBook& address_book);
    void add(const Employee &emp);
    void clear();
    void del(const uint32_t &id);
    Employee& find(const uint32_t id);
    Employee& find(const std::string& name);
    friend std::ostream& operator<<(std::ostream& out, const AdressBook& ad);
    void operator+=(const Employee& emp);
    void operator-(const uint32_t &id);
    Employee& operator[](const uint32_t id);
    Employee& operator[](const std::string &name);
    friend class Employee;

};