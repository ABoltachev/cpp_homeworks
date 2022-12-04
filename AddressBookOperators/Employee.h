#ifndef HOMEWORKS_TESTS_EMPLOYEE_H
#define HOMEWORKS_TESTS_EMPLOYEE_H

#include <cstdint>
#include <string>

namespace AddressBookLib {
    class Employee {
        uint32_t m_id = 0;
        std::string m_name = "";
        uint16_t m_grade = 0;
        friend class AddressBook;
    public:
        Employee() = default;
        Employee(uint32_t id, const std::string &name, uint16_t grade): m_id(id), m_name(name), m_grade(grade)
        {
        }

        void print() const;

        friend std::ostream& operator<< (std::ostream &out, const Employee &employee);
        friend std::istream& operator>> (std::istream &in, Employee &employee);
        friend bool operator== (const Employee &e1, const Employee &e2);
        friend bool operator!= (const Employee &e1, const Employee &e2);
    };
}

#endif //HOMEWORKS_TESTS_EMPLOYEE_H
