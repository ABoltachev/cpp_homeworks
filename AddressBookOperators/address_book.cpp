#include "address_book.hpp"

namespace AB
{

bool Employee::operator==(const Employee& emp) const
{
    return (m_id == emp.m_id) && (m_name == emp.m_name) && (m_grade == emp.m_grade);
}

bool Employee::operator!=(const Employee& emp) const
{
    return !(*this == emp);
}

std::ostream& operator<<(std::ostream& out, const Employee& emp)
{
    out << "Id: " << emp.m_id << ' ';
    out << "Name: " << emp.m_name << ' ';
    out << "Grade: " << emp.m_grade << ' ';
    return out;
}

std::istream& operator>>(std::istream& in, Employee& emp)
{
    in >> emp.m_id;
    in >> emp.m_name;
    in >> emp.m_grade;
}

AddressBook::Node::Node(const Node& node)
{
    m_data = node.m_data;
}

AddressBook::Node& AddressBook::Node::operator=(const Node& other)
{
    m_data = other.m_data;
    return *this;
}

AddressBook::AddressBook(const AddressBook& address_book)
{
    m_size = address_book.m_size;
    Node* start = new Node(*address_book.m_list);
    Node* last_node = start;
    Node* cur = start->next;
    for (size_t i = 1; i < m_size; i++) {
        last_node->next = new Node(*cur);
        last_node = last_node->next;
        cur = cur->next;
    }
}

void AddressBook::add(const Employee& employee)
{
    m_size++;
    if (!m_list) {
        m_list = new Node(employee);
        return;
    }
    Node* cur = m_list;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new Node(employee);
}

void AddressBook::Delete(const size_t id)
{
    if (!m_list) {
        return;
    }

    if (m_list->m_data.m_id == id) {
        m_size--;
        Node* tmp = m_list;
        m_list = m_list->next;
        delete tmp;
        return;
    }

    bool found = false;
    Node* cur = m_list;
    while (cur->next) {
        if (cur->next->m_data.m_id == id) {
            found = true;
            break;
        }
        cur = cur->next;
    }

    if (!found) {
        return;
    }

    m_size--;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

Employee& AddressBook::find(const size_t id)
{
    if (!m_list) {
        Employee emp = Employee();
        return emp;
    }

    Node* cur = m_list;
    while (cur && cur->m_data.m_id != id) {
        cur = cur->next;
    }
    if (!cur) {
        Employee emp = Employee();
        return emp;
    }

    return cur->m_data;
}

Employee& AddressBook::find(const size_t id) const
{
    return find(id);
}

Employee& AddressBook::find(const std::string& name)
{
    if (!m_list) {
        Employee emp = Employee();
        return emp;
    }

    Node* cur = m_list;
    for (size_t i = 0; i < m_size && cur->m_data.m_name != name; i++) {
        cur = cur->next;
    }

    if (!cur) {
        Employee emp = Employee();
        return emp;
    }

    return cur->m_data;
}

Employee& AddressBook::find(const std::string& name) const
{
    return find(name);
}

void AddressBook::clear()
{
    if (!m_list) {
        return;
    }

    Node* cur = m_list;
    while (cur) {
        m_size--;
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    m_list = nullptr;
}

AddressBook& AddressBook::operator=(const AddressBook& address_book)
{
    m_size = address_book.m_size;
    Node* start = new Node(*address_book.m_list);
    Node* last_node = start;
    Node* cur = start->next;
    for (size_t i = 1; i < m_size; i++) {
        last_node->next = new Node(*cur);
        last_node = last_node->next;
        cur = cur->next;
    }

    return *this;
}

void AddressBook::operator+(const Employee& emp)
{
    add(emp);
}

void AddressBook::operator-(const size_t id)
{
    Delete(id);
}

Employee& AddressBook::operator[](const size_t id)
{
    return find(id);
}

const Employee& AddressBook::operator[](const size_t id) const
{
    return find(id);
}

Employee& AddressBook::operator[](const std::string& name)
{
    return find(name);
}

const Employee& AddressBook::operator[](const std::string& name) const
{
    return find(name);
}

std::ostream&
operator<<(std::ostream& out, const AddressBook& address_book)
{
    AddressBook::Node* cur = address_book.m_list;

    for (size_t i = 0; i < address_book.m_size; i++) {
        out << cur->m_data << std::endl;
        cur = cur->next;
    }
}

}  // namespace AB