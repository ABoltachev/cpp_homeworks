#pragma once

#include <forward_list>
#include <functional>
#include <iostream>
#include <optional>
#include <vector>

#include "Employee/Employee.hpp"

class AddressBook {
private:
    std::forward_list<Employee> employees;

public:
    void clear();
    bool del(uint32_t id);
    void add(const Employee &employee);
    void add(const AddressBook &addressBook);
    [[nodiscard]] std::optional<Employee> find(uint32_t id);
    [[nodiscard]] std::forward_list<Employee> getEmployers();
    [[nodiscard]] std::forward_list<Employee> find(const std::string &name);
    void update(uint32_t id, const Employee &data);

    friend std::ostream &operator<<(std::ostream &stream, const AddressBook &addressBook);
    const Employee &operator[](uint32_t id) const;
    const Employee &operator[](const std::string &name) const;
    AddressBook &operator+=(const Employee &employee);
    AddressBook &operator+=(const AddressBook &addressBook);
    friend AddressBook operator+(AddressBook lhs, const Employee &rhs);
    friend AddressBook operator+(const AddressBook &lhs, const AddressBook &rhs);
    AddressBook &operator-=(uint32_t id);
    friend AddressBook operator-(AddressBook addressBook, uint32_t id);
};
