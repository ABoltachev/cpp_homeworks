#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Employee {
    friend class AddressBook;
private:
    uint32_t m_id;
    std::string m_name;
    uint16_t m_grade;
public:
    Employee() = default;
    Employee(uint32_t id, const std::string &name, uint16_t grade);
    void setId(uint32_t id);
    void setName(const std::string& name);
    void setGrade(uint16_t grade);
    bool operator==(const Employee& other) const;
    bool operator!=(const Employee& other) const;
    friend std::istream& operator>>(std::istream& in, Employee& employee);
    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

};

class AddressBook{
private:
    class Node {
    public:
        Employee m_data;
        Node* sl_node = nullptr;
        Node() = default;
        Node(const Employee& data) : m_data(data) {}
    };
    Node* m_head=nullptr;
    size_t m_size=0;
public:
    AddressBook() = default;
    AddressBook(const AddressBook& addressBook);
    void add(const Employee& employee);
    Node* findid(uint32_t id) const;
    Node* findname(const std::string& name) const;
    void deleteid(uint32_t id);
    void clear();
    AddressBook& operator+(const Employee& another);
    AddressBook& operator-(uint32_t id);
    AddressBook& operator=(const AddressBook& another);
    AddressBook& operator[](uint32_t id);
    AddressBook& operator[](const std::string& name);
    friend std::ostream& operator<<(std::ostream& out, const AddressBook& addressBook);
};
