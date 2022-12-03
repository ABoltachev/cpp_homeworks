//
// Created by home on 26.11.22.
//
#ifndef UNTITLED14_ADDRESS_BOOK_H
#define UNTITLED14_ADDRESS_BOOK_H

#include <iostream>
#include <cstdint>
class Employee
{
private:
    uint32_t m_id;
    std::string m_name;
    uint16_t m_grade;
    friend class AddressBook;
public:
    friend std::istream& operator>> (std::istream& , Employee&);
    friend std::ostream& operator<<( std::ostream&, const Employee&);
    bool operator ==(const Employee& other) const;
    bool operator !=(const Employee & other) const;
    Employee() = default;
    Employee(uint32_t id, std::string& name, uint16_t grade){m_id = id;m_name = name;m_grade = grade;}
    Employee(const Employee& old_employee){m_id = old_employee.m_id; m_name = old_employee.m_name; m_grade = old_employee.m_grade;}
};
class AddressBook
{
private:
    class Node
    {
    public:
        Employee m_data;
        Node* m_next = nullptr;
        Node() = default;
        Node(const Employee &data) : m_data(data){};
    };
    Node* m_head=nullptr;
    size_t m_size=0;
public:
    AddressBook(){m_head=nullptr;m_size=0;}
    AddressBook(const AddressBook& book);
    void add_employee(const Employee& new_employee);
    void add_employee(uint32_t id, std::string& name, uint16_t grade);
    void delete_employee(uint32_t id);
    void clear();
    const Node* at (const uint32_t id) const;
    const Node* at(const std::string& name) const;
    void operator += (const Employee& new_employee);
    void operator -= (uint32_t id);
    const Employee& operator [](uint32_t id) const;
    const Employee& operator [](std::string& name) const;
    friend std::ostream& operator<<( std::ostream&, const AddressBook&);
    void print_employees() const;
    ~AddressBook();
};

#endif //UNTITLED14_ADDRESS_BOOK_H
