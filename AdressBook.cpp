#include "AdressBook.h"


void AdressBook::add(const Employee &emp) {
    employees.push_front(emp);
}

bool Employee::operator==(const Employee& b) const{
    return ((id == b.id) && (name == b.name) && (grade == b.grade));
}

bool Employee::operator!=(const Employee& b) const{
    return !((id == b.id) && (name == b.name) && (grade == b.grade));
}

Employee& AdressBook::find(const uint32_t id) {
    for (Employee &emp: employees) {
        if (emp.id == id)
            return emp;
    }
    employees.push_front(Employee());
    return employees.front();
}

Employee& AdressBook::find(const std::string& name) {
    for (Employee &emp: employees) {
        if (emp.name == name)
            return emp;
    }
    employees.push_front(Employee());
    return employees.front();
}

void AdressBook::clear() {
    employees.clear();
}

void AdressBook::del(const uint32_t &id) {
    employees.remove(find(id));
    if(employees.empty())
        std::cout << "There is no such employee" << '\n';
}

AdressBook::AdressBook(const AdressBook& address_book){
    std::forward_list<Employee> participants;
    for(const auto &emp : employees){
        participants.push_front(emp);
    }
}

void AdressBook::operator+=(const Employee& emp){
    add(emp);
}

void AdressBook::operator-(const uint32_t &id){
    del(id);
}

Employee& AdressBook::operator[](const uint32_t id)
{
    return find(id);
}

Employee& AdressBook::operator[](const std::string &name)
{
    return find(name);
}

std::istream& operator>>(std::istream& in, Employee& emp){
    in >> emp.id;
    in >> emp.name;
    in >> emp.grade;
    return in;
}

std::ostream& operator<<(std::ostream& out, const AdressBook& ad){
    for (auto& e: ad.employees) {
        out << e << '\n';
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Employee& emp){
    out << "(" << "id: " << emp.id << ")" << ' ';
    out << "(" << "name: " << emp.name << ")" << ' ';
    out << "(" << "grade: " << emp.grade << ")" << ' ';
    return out;
}

