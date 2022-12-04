#include <string>
#include <iostream>

#include "employee.hpp"

namespace AddressBookModule {

    bool operator==(const Employee &e1, const Employee &e2) {
        return ((e1._id == e2._id) && (e1._name == e2._name) && (e1._grade == e2._grade));
    }

    bool operator!=(const Employee &e1, const Employee &e2) {
        return !((e1._id == e2._id) && (e1._name == e2._name) && (e1._grade == e2._grade));
    }

    std::ostream &operator<<(std::ostream &out, const Employee &employee) {
        return out << std::string("Employee: (_id = ") << std::to_string(employee._id) << std::string(", _name = ")
                   << std::string(employee._name)
                   << std::string(", _grade = ") << std::to_string(employee._grade) << std::string(")");
    }

    std::istream &operator>>(std::istream &in, Employee &employee) {
        in >> employee._id >> employee._name >> employee._grade;
        return in;
    }
}