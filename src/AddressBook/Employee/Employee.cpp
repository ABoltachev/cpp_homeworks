#include "Employee.hpp"

std::ostream &operator<<(std::ostream &stream, const Employee &employee) {
<<<<<<< HEAD
    stream << "\t{id: " << employee.id << ", name: " << employee.name << ", grade: " << employee.grade << "} \n";
=======
    stream << "\t{" << employee.id << ", " << employee.name << ", " << employee.grade << "} \n";
>>>>>>> hw_vvtsygankov
    return stream;
}

std::istream &operator>>(std::istream &stream, Employee &employee) {
    stream >> employee.id >> employee.name >> employee.grade;
    return stream;
}

<<<<<<< HEAD
bool operator==(const Employee &lhs, const Employee &rhs) {
    return lhs.name == rhs.name && lhs.grade == rhs.grade;
}

bool operator!=(const Employee &lhs, const Employee &rhs) {
    return !(lhs == rhs);
=======
bool operator==(const Employee &lEmployee, const Employee &rEmployee) {
    return lEmployee.name == rEmployee.name && lEmployee.grade == rEmployee.grade;
}

bool operator!=(const Employee &lEmployee, const Employee &rEmployee) {
    return !(lEmployee == rEmployee);
>>>>>>> hw_vvtsygankov
}
