#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

class Employee
{
private:
    uint32_t m_id = 0;
    std::string m_name = std::string();
    uint16_t m_grade = 0;
public:
    Employee() = default;
    Employee(uint32_t id, std::string name, uint16_t grade) : m_id(id), m_name(name), m_grade(grade){};
    friend bool operator==(const Employee& el1, const Employee& el2);
    friend bool operator!=(const Employee& el1, const Employee& el2);
    friend std::ostream& operator<<(std::ostream& out, const Employee& emp);
    friend std::istream& operator>>(std::istream& in, Employee& emp);
    friend class AddressBook;
};

class AddressBook{
private:
    class Node
    {
    public:
        Employee m_data;
        Node* next = nullptr;
        Node() = default;
        Node(const Employee& data) : m_data(data){}

    };
    Node* m_head = nullptr;
    size_t m_size = 0;
public:
    AddressBook() = default;
    AddressBook(const AddressBook& a_book);
    void add_el(const Employee& el);
    void delete_el(size_t id);
    void clear();
    Employee& find(const std::string& name);
    Employee& find(const std::string& name) const;
    Employee& find(size_t id);
    Employee& find(size_t id) const;
    void operator+(const Employee& emp);
    void operator-(size_t id);
    Employee& operator[](size_t id);
    const Employee& operator[](size_t id) const;
    Employee& operator[](const std::string& name);
    const Employee& operator[](const std::string& name) const;
    AddressBook& operator=(const AddressBook& a_book);
    friend std::ostream& operator<<(std::ostream& out, const AddressBook& address_book);
};
#endif //ADDRESSBOOK_H
