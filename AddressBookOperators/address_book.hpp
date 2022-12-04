#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <iostream>

namespace AB
{

class Employee
{
    uint32_t m_id;
    std::string m_name;
    uint16_t m_grade;

   public:
    Employee() = default;
    Employee(uint32_t id, std::string name, uint16_t grade) : m_id(id), m_name(name), m_grade(grade){};
    bool operator==(const Employee& emp) const;
    bool operator!=(const Employee& emp) const;

    friend std::ostream& operator<<(std::ostream& out, const Employee& emp);
    friend std::istream& operator>>(std::istream& in, Employee& emp);

    friend class AddressBook;
};

class AddressBook
{
   private:
    class Node
    {
       public:
        Employee m_data;
        Node* next = nullptr;

        Node(const Node& node);
        Node(const Employee& data) : m_data(data) {}

        Node& operator=(const Node& other);
    };

    Node* m_list = nullptr;
    size_t m_size = 0;

   public:
    AddressBook() = default;
    AddressBook(const AddressBook& address_book);

    void add(const Employee& employee);
    void Delete(const size_t id);
    Employee& find(const size_t id);
    Employee& find(const size_t id) const;

    Employee& find(const std::string& name);
    Employee& find(const std::string& name) const;

    void clear();

    AddressBook& operator=(const AddressBook& other);

    void operator+(const Employee& emp);
    void operator-(const size_t id);

    Employee& operator[](const size_t id);
    const Employee& operator[](const size_t id) const;

    Employee& operator[](const std::string& name);
    const Employee& operator[](const std::string& name) const;

    friend std::ostream& operator<<(std::ostream& out, const AddressBook& address_book);
};

}  // namespace AB

#endif