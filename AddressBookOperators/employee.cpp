#include <string>
#include <iostream>

#include "employee.hpp"

namespace AddressBookModule {

    bool operator==(const Employee &e1, const Employee &e2) {
        return ((e1.id == e2.id) && (e1.name == e2.name) && (e1.grade == e2.grade));
    }

    bool operator!=(const Employee &e1, const Employee &e2) {
        return !((e1.id == e2.id) && (e1.name == e2.name) && (e1.grade == e2.grade));
    }

    std::ostream &operator<<(std::ostream &out, const Employee &employee) {
        return out << "Employee: (id = " << employee.id << ", name = "
                   << employee.name
                   << ", grade = " << employee.grade << ")";
    }

    std::istream &operator>>(std::istream &in, Employee &employee) {
        in >> employee.id >> employee.name >> employee.grade;
        return in;
    }
}