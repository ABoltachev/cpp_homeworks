#ifndef HOMEWORK_ADRESSBOOK_H
#define HOMEWORK_ADRESSBOOK_H

#include <iostream>
#include <string>
#include <forward_list>



class Employee {
    friend class AdressBook;
    friend class AdressBook operator+(AdressBook& list, const Employee &emp);
    friend class AdressBook operator-(AdressBook& list, const Employee &emp);
private:
    uint32_t id = 0;
    std::string name;
    uint16_t grade = 0;
public:
    Employee(const uint32_t id_t, const std::string &name_t, const uint16_t grade_t) {
        id = id_t;
        name = name_t;
        grade = grade_t;
    }
    Employee(const uint32_t id_t) {
        id = id_t;
    }
    Employee(const std::string &name_t) {
        name = name_t;
    }
    Employee() = default;

    bool operator==(const Employee &emp) const;

    bool operator!=(const Employee &emp) const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);

    friend std::istream& operator>>(std::istream& in, Employee& emp);
};



class AdressBook {
    std::forward_list<Employee> list;
    uint32_t count = 0;
public:
    AdressBook(const Employee &emp_t) {
        list.push_front(emp_t);
        count++;
    }
    AdressBook(uint32_t id_t, std::string name_t, uint16_t grade_t) {
        list.push_front(Employee(id_t, name_t, grade_t));
        count++;
    }
    AdressBook(const AdressBook &book) {
        list = book.list;
        count = book.count;
    }
    AdressBook() = default;

    void AddEmployee(const Employee &emp_t);

    void AddEmployee(uint32_t id_t, std::string name_t, uint16_t grade_t);

    auto Find(uint32_t id_t);

    auto Find(const std::string &name_t) ;

    void DeleteEmployee(uint32_t id);

    friend AdressBook operator+(AdressBook& list, const Employee &emp);

    friend AdressBook operator-(AdressBook& list, const Employee &emp);

    Employee& operator[](const std::string &name);

    Employee& operator[](uint32_t id);

    friend std::ostream& operator<<(std::ostream& out, const AdressBook& book);


    void Print();

    void Clear();

};


#endif //HOMEWORK_ADRESSBOOK_H
