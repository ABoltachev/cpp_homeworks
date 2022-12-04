#ifndef TESTLIB_H
#define TESTLIB_H

#include <iostream>
#include <fstream>
#include <string>

namespace TestLib {
    class Employee {
    private:
        uint32_t m_id;
        std::string m_name;
        uint16_t m_grade;
    public:
        Employee() = default;
        Employee(uint32_t id, std::string& name, uint16_t grade);

        friend std::istream& operator>> (std::istream& in, Employee& emp);
        friend std::ostream& operator<< (std::ostream& out, const Employee& emp);

        bool operator== (const Employee& emp);
        bool operator!= (const Employee& emp);

        friend class AddressBook;
    };

    class AddressBook {
    private:
        class Node {
        public:
            Employee m_data;
            Node* next = nullptr;

            Node() = default;
            Node(const Employee& data) : m_data(data) {}
        };
        Node* m_head = nullptr;
        size_t m_size;
    public:
        AddressBook();
        AddressBook(const AddressBook& addr_book);
        AddressBook& operator= (const AddressBook& addr_book);

        void addEmployee(const Employee& emp);
        AddressBook& operator+ (const Employee& emp);

        void delEmployee(uint32_t id);
        AddressBook& operator- (uint32_t id);

        void clearAddressBook();

        Employee& find(uint32_t id) const;
        Employee& find(const std::string& name) const;

        const Employee& operator[] (uint32_t id) const;
        Employee& operator[] (uint32_t id);

        const Employee& operator[] (const std::string& name) const;
        Employee& operator[] (const std::string& name);

        friend std::ostream& operator<< (std::ostream& out, const AddressBook& addr_book);

        ~AddressBook();
    };

}

#endif