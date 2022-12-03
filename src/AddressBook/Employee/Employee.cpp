#include "Employee.hpp"

std::ostream &operator<<(std::ostream &stream, const Employee &employee) {
    stream << "\t{id: " << employee.id << ", name: " << employee.name << ", grade: " << employee.grade << "} \n";
    return stream;
}

std::istream &operator>>(std::istream &stream, Employee &employee) {
    stream >> employee.id >> employee.name >> employee.grade;
    return stream;
}

bool operator==(const Employee &lhs, const Employee &rhs) {
    return lhs.name == rhs.name && lhs.grade == rhs.grade;
}

bool operator!=(const Employee &lhs, const Employee &rhs) {
    return !(lhs == rhs);
}
