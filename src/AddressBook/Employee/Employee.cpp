#include "Employee.hpp"

std::ostream &operator<<(std::ostream &stream, const Employee &employee) {
    stream << "\t{" << employee.id << ", " << employee.name << ", " << employee.grade << "} \n";
    return stream;
}

std::istream &operator>>(std::istream &stream, Employee &employee) {
    stream >> employee.id >> employee.name >> employee.grade;
    return stream;
}

bool operator==(const Employee &lEmployee, const Employee &rEmployee) {
    return lEmployee.name == rEmployee.name && lEmployee.grade == rEmployee.grade;
}

bool operator!=(const Employee &lEmployee, const Employee &rEmployee) {
    return !(lEmployee == rEmployee);
}
