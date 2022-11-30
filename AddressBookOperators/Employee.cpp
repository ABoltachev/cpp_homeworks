#include <iostream>
#include "Employee.h"

namespace AddressBookLib {
    void Employee::print() {
        std::cout << *this << std::endl;
    }

    std::ostream &operator<<(std::ostream &out, const Employee &employee) {
        out << "Employee #" << employee.m_id << ": " << employee.m_name << " has " << employee.m_grade << " grade";
        return out;
    }

    std::istream &operator>> (std::istream &in, Employee &employee) {
        in >> employee.m_id >> employee.m_name >> employee.m_grade;
        return in;
    }

    bool operator== (const Employee &e1, const Employee &e2) {
        return ((e1.m_id == e2.m_id) && (e1.m_name == e2.m_name) && (e1.m_grade == e2.m_grade));
    }

    bool operator!= (const Employee &e1, const Employee &e2) {
        return !(e1 == e2);
    }
}