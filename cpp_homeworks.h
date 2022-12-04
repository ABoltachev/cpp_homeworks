#ifndef MAIN_CPP_HOMEWORKS_H
#define MAIN_CPP_HOMEWORKS_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class Employee {
private:
    uint32_t m_id;
    std::string m_name;
    uint16_t m_grade;

public:
    Employee() = default;
    Employee(uint32_t id, const std::string &name, uint16_t grade);

    void setUid(uint32_t uid);
    void setName(std::string& name);
    void setGrade(uint16_t grade);

    bool operator!=(const Employee& other) const;
    bool operator==(const Employee& other) const;

    friend std::istream& operator>>(std::istream& in, const Employee& employee);
    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

    friend class AddressBook;
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

    Node* findID(uint32_t id) const;
    Node* findName(const std::string& name) const;

    void deleteEmployee(uint32_t id);
    void clearBook();

    AddressBook& operator=(const AddressBook& another);
    AddressBook& operator+(const Employee& another);
    AddressBook& operator-(uint32_t id);

    AddressBook& operator[](uint32_t id);
    AddressBook& operator[](const std::string& name);

    const AddressBook& operator[](uint32_t id) const;
    const AddressBook& operator[](const std::string& name) const;

    friend std::ostream& operator<<(std::ostream& out, const AddressBook& addressBook);

    friend class Employee;
    ~AddressBook();
};


#endif //MAIN_CPP_HOMEWORKS_H
