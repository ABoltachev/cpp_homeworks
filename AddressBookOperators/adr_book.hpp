#include <stdint.h>
#include <iostream>
#include <list>

class AddressBook;

class AddressBook
{
public:
    struct Employee
    {
        uint32_t id;
        std::string name;
        uint16_t grade;
        Employee(uint32_t id,std::string name,uint16_t grade);
        Employee() = default;
        uint32_t getId() const;
        std::string getName() const;
        uint16_t getGrade() const;

        friend bool operator==(const Employee& a, const Employee& b);
        friend bool operator!=(const Employee& a, const Employee& b);
        friend std::ostream& operator<<(std::ostream& cout,const Employee& book);
        friend AddressBook;
    };
private:
    std::list<Employee> book;
public:
    AddressBook() = default;
    void addEmployee(uint32_t id,std::string name,uint16_t grade);
    void addEmployee(Employee);
    Employee findEmpl(uint32_t id);
    Employee findEmpl(std::string name);
    bool empty() const;
    Employee& operator[](std::string name);
    Employee& operator[](uint32_t id);
    AddressBook operator+(Employee e) const;
    AddressBook operator-(uint32_t id) const;
    friend std::istream& operator>>(std::istream& cin,AddressBook& book);
    friend std::ostream& operator<<(std::ostream& cout,const AddressBook& book);
};