#include <iostream>
#include <string>
#include <forward_list>
#include "AdressBook.h"


bool Employee::operator==(const Employee &emp) const {
    if (emp.id == id && emp.name == name && emp.grade == grade) {
        return true;
    }
    return false;
}

bool Employee::operator!=(const Employee &emp) const {
    if (emp.id != id || emp.name != name || emp.grade != grade) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os << "id: "<< emp.id << ", name: " << emp.name << ", grade " << emp.grade << '\n';
    return os;
}
std::istream& operator>>(std::istream& in, Employee& emp) {
    in >> emp.id >> emp.name >> emp.grade;
    return in;
}


void AdressBook::AddEmployee(const Employee &emp_t) {
    count++;
    list.push_front(emp_t);
}

void AdressBook::AddEmployee(uint32_t id_t, std::string name_t, uint16_t grade_t) {
    AddEmployee(Employee(id_t, name_t, grade_t));
}

auto AdressBook::Find(uint32_t id_t) {
    for (auto item = list.begin(); item != list.end(); item++) {
        if (item->id == id_t) {
            return item;
        }
    }
    Employee new_emp = Employee{id_t};
    AddEmployee(new_emp);
    return list.begin();
}

auto AdressBook::Find(const std::string &name_t) {
    for (auto item = list.begin(); item != list.end(); item++) {
        if (item->name == name_t) {
            return item;
        }
    }
    Employee new_emp = Employee{name_t};
    AddEmployee(new_emp);
    return list.begin();
}
void AdressBook::DeleteEmployee(uint32_t id) {
    auto pred_item = list.before_begin(), current = list.begin();
    for (; current != list.end(); current++) {
        if (current->id == id) {
            list.erase_after(pred_item);
            break;
        }
        pred_item++;
    }
}

AdressBook operator+(AdressBook& list, const Employee &emp) {
    list.AddEmployee(emp);
    return list;
}

AdressBook operator-(AdressBook& list, const Employee &emp) {
    list.DeleteEmployee(emp.id);
    return list;
}

Employee& AdressBook::operator[](const std::string &name) {
    return *(this->Find(name));
}
Employee& AdressBook::operator[](uint32_t id) {
    return *(this->Find(id));
}
std::ostream& operator<<(std::ostream& out, const AdressBook& book) {
    for (const auto& item: book.list) {
        out << item;
    }
    return out;
}
void AdressBook::Print() {
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << (*it);
    }
}

void AdressBook::Clear() {
    list.clear();
    count = 0;
}