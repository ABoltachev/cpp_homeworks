#include <cstdint>
#include <string>

#ifndef HW1_EMPLOYEE_H
#define HW1_EMPLOYEE_H

namespace AddressBookModule {
    class Employee {
        friend class AddressBook;

    public:
        Employee() = default;

        Employee(uint32_t id, const std::string &name, uint16_t grade) : id(id), name(name), grade(grade) {};

        friend std::ostream &operator<<(std::ostream &out, const Employee &employee);

        friend std::istream &operator>>(std::istream &in, Employee &employee);

        friend bool operator==(const Employee &e1, const Employee &e2);

        friend bool operator!=(const Employee &e1, const Employee &e2);

    private:
        uint32_t id = 0;
        std::string name;
        uint16_t grade = 0;
    };
}

#endif //HW1_EMPLOYEE_H
