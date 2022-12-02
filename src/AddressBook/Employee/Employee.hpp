#pragma once

#include <cstdint>
#include <iostream>
#include <string>

struct Employee {
    uint32_t id;
    std::string name;
    uint16_t grade;

    friend class AddressBook;
    friend std::ostream &operator<<(std::ostream &stream, const Employee &employee);
    friend std::istream &operator>>(std::istream &stream, Employee &employee);
    friend bool operator==(const Employee &lEmployee, const Employee &rEmployee);
    friend bool operator!=(const Employee &lEmployee, const Employee &rEmployee);
};
