#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H
#include <iostream>

class Employee {
    friend class AddressBook;
private:
    uint32_t m_id = 0;
    std::string m_name = "";
    uint16_t m_grade = 0;
public:
    Employee() = default;
    Employee(uint32_t id, std::string name, uint16_t grade) : m_id(id), m_name(name), m_grade(grade) {};
    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
    friend std::istream& operator>>(std::istream& in, Employee& employee);
    friend bool operator==(const Employee& employee1, const Employee& employee2);
    friend bool operator!=(const Employee& employee1, const Employee& employee2);
};

class AddressBook
{
private:
    class Node {
    public:
        Employee m_data;
        Node* next = nullptr;

        Node() = default;
        Node(const Employee& data) : m_data(data) {};
    };
    Node* m_head = nullptr;
    size_t m_size = 0;
public:
    AddressBook() = default;
    AddressBook(const AddressBook& book);
    Employee operator[](const uint32_t& id);
    Employee operator[](const std::string& name);
    AddressBook& operator=(const AddressBook& book);
    void ClearAddressBook();
    AddressBook& operator-(const Employee& employee);
    AddressBook& operator+(const Employee& data);
    friend std::ostream& operator<<(std::ostream& out, const AddressBook& book);
};
#endif