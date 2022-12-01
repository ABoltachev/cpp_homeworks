#ifndef MAIN_CPP_HOMEWORKS_H
#define MAIN_CPP_HOMEWORKS_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class Employee {
public:
    uint32_t m_id;
    std::string m_name;
    uint16_t m_grade;

    bool operator!=(const Employee& other) const;
    bool operator==(const Employee& other) const;

    friend std::istream& operator>>(std::istream& in, const Employee& employee);
    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
};


class AddressBook{
private:
    class Node {
    public:
        Employee m_data;
        Node* next_node = nullptr;

        Node() = default;
        Node(const Employee& data) : m_data(data) {}
    };
    Node* m_list = nullptr;
    size_t m_size;

public:
    AddressBook();
    AddressBook(const AddressBook& addressBook);

    void addEmployee(const Employee& employee);

    Node* findID(uint32_t id);
    Node* findName(const std::string& name);

    void deleteEmployee(uint32_t id);
    void clearBook();

    AddressBook& operator=(const AddressBook& another);
    AddressBook& operator+(const Employee& another);
    AddressBook& operator-(uint32_t id);

    AddressBook& operator[](uint32_t id);
    AddressBook& operator[](const std::string& name);

    friend std::ostream& operator<<(std::ostream& out, const AddressBook& addressBook);

    friend class Employee;
    ~AddressBook();
};


#endif //MAIN_CPP_HOMEWORKS_H
