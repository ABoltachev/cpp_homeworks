#include "addressbook.h"

bool operator==(const Employee& el1, const Employee& el2){
    if ((el1.m_id == el2.m_id) && (el1.m_name == el2.m_name) && (el1.m_grade == el2.m_grade))
        return true;
    return false;
}

bool operator!=(const Employee& el1, const Employee& el2)
{
    if (el1 == el2)
        return false;
    return true;
}

std::ostream& operator<<(std::ostream& out, const Employee& el)
{
    out << "Id: " << el.m_id << ' '<< "Name: " << el.m_name << ' '<< "Grade: " << el.m_grade << ' ';
    return out;
}

std::istream& operator>>(std::istream& in, Employee& el)
{
    in >> el.m_id;
    in >> el.m_name;
    in >> el.m_grade;
}

AddressBook::AddressBook(const AddressBook& a_book) {
    m_size = a_book.m_size;
    Node* head = new Node(*a_book.m_head);
    Node* pred_cur = head;
    Node* cur = pred_cur->next;
    for(size_t i = 0; i < m_size-1; i++)
    {
        pred_cur->next = new Node(*cur);
        pred_cur = pred_cur->next;
        cur = cur->next;
    }
}

void AddressBook::add_el(const Employee& el)
{
    m_size++;
    if (!m_head) {
        m_head = new Node(el);
        return;
    }
    Node* cur = m_head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new Node(el);
}

void AddressBook::delete_el(size_t id)
{
    if (!m_head) {
        return;
    }
    if (m_head->m_data.m_id == id) {
        m_size--;
        Node* tmp = m_head;
        m_head = m_head->next;
        delete tmp;
        return;
    }
    bool found = false;
    Node* cur = m_head;
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

void AddressBook::clear()
{
    while(m_head) {
        delete_el(m_head->m_data.m_id);
    }
}

Employee& AddressBook::find(const std::string& name)
{
    if (!m_head) {
        Employee el = Employee();
        return el;
    }
    Node* cur = m_head;
    while((cur) && (cur->m_data.m_name != name))
    {
        cur = cur->next;
    }

    if (!cur) {
        Employee el = Employee();
        return el;
    }

    return cur->m_data;
}

Employee& AddressBook::find(const std::string& name) const
{
    if (!m_head) {
        Employee el = Employee();
        return el;
    }
    Node* cur = m_head;
    while((cur) && (cur->m_data.m_name != name))
    {
        cur = cur->next;
    }

    if (!cur) {
        Employee el = Employee();
        return el;
    }

    return cur->m_data;
}

Employee& AddressBook::find(size_t id)
{
    if (!m_head) {
        Employee el = Employee();
        return el;
    }
    Node* cur = m_head;
    while (cur && cur->m_data.m_id != id) {
        cur = cur->next;
    }
    if (!cur) {
        Employee el = Employee();
        return el;
    }
    return cur->m_data;
}

Employee& AddressBook::find(size_t id) const
{
    if (!m_head) {
        Employee el = Employee();
        return el;
    }
    Node* cur = m_head;
    while (cur && cur->m_data.m_id != id) {
        cur = cur->next;
    }
    if (!cur) {
        Employee el = Employee();
        return el;
    }
    return cur->m_data;
}

void AddressBook::operator+(const Employee& el)
{
    add_el(el);
}

void AddressBook::operator-(size_t id)
{
    delete_el(id);
}

Employee& AddressBook::operator[](const std::string& name)
{
    return find(name);
}

const Employee& AddressBook::operator[](const std::string& name) const
{
    return find(name);
}

Employee& AddressBook::operator[](size_t id)
{
    return find(id);
}

const Employee& AddressBook::operator[](size_t id) const
{
    return find(id);
}

AddressBook& AddressBook::operator=(const AddressBook& a_book)
{
    m_size = a_book.m_size;
    Node* head = new Node(*a_book.m_head);
    Node* pred_cur = head;
    Node* cur = pred_cur->next;
    for(size_t i = 0; i < m_size-1; i++)
    {
        pred_cur->next = new Node(*cur);
        pred_cur = pred_cur->next;
        cur = cur->next;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const AddressBook& book) {
    AddressBook::Node* cur = book.m_head;
    while (cur) {
        out << cur->m_data << std::endl;
        cur = cur->next;
    }
    return out;
};
