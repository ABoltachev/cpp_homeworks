//
// Created by home on 26.11.22.
//

#include "address_book.h"
#include <cassert>

std::istream& operator >> (std::istream& in,Employee& input_employee)
{
    in >> input_employee.m_id >> input_employee.m_name >> input_employee.m_grade;
    return in;
}
std::ostream& operator << (std::ostream& out,const Employee& output_employee)
{
    out <<"id:" <<output_employee.m_id <<" name: "<<output_employee.m_name <<" grade: "<<output_employee.m_grade;
    return out;
}
bool Employee::operator== (const Employee& other) const
{
    return ((m_id == other.m_id) and (m_grade == other.m_grade) and (m_name == other.m_name));
}
bool Employee::operator!=(const Employee &other) const
{
    return !((m_id == other.m_id) and (m_grade == other.m_grade) and (m_name == other.m_name));
}
void AddressBook::add_employee(const Employee& new_employee)
{
    m_size++;
    if (!m_head)
    {
        m_head = new Node(new_employee);
        return;
    }
    Node* cur_node = m_head;
    while (cur_node->m_next)
    {
        cur_node=cur_node->m_next;
    }
    cur_node->m_next = new Node(new_employee);

}
void AddressBook::add_employee(uint32_t id, std::string& name, uint16_t grade)
{
    add_employee(Employee(id,name,grade));
}
void AddressBook::delete_employee(uint32_t id) {
    Node* cur_node = m_head;
    if(!cur_node)
        return;
    if(cur_node->m_data.m_id == id) {
        m_head = cur_node->m_next;
        delete (cur_node);
        m_size--;
        return;
    }
    for(int index = 0; index < m_size-1; index++)
    {
        if(cur_node->m_next->m_data.m_id == id)
        {
            Node* temp = cur_node->m_next;
            cur_node->m_next = cur_node->m_next->m_next;
            delete temp;
            m_size--;
            break;
        }
        cur_node = cur_node->m_next;
    }
}
void AddressBook::clear()
{
    while(m_head) {
        delete_employee(m_head->m_data.m_id);
    }
}
AddressBook::AddressBook(const AddressBook& book)
{
    if(m_head)
    {
        clear();
    }
    if(book.m_size ==0)
    {
        m_head = nullptr;
        m_size = 0;
        return;
    }
    Node* cur_old_node = book.m_head;
    m_head = new Node(cur_old_node -> m_data);
    m_size = book. m_size;
    Node* cur_new_node = m_head;
    for(int index = 0; index < book.m_size-1; index++)
    {
        cur_new_node->m_next = new Node(cur_old_node->m_next->m_data);
        cur_new_node = cur_new_node -> m_next;
        cur_old_node = cur_old_node -> m_next;
    }

}

const AddressBook::Node* AddressBook::at(uint32_t id) const
{
    Node* cur_node = m_head;
    while((cur_node)&&(cur_node->m_data.m_id != id))
    {
        cur_node = cur_node -> m_next;
    }
    assert(cur_node);
    return cur_node;
}
const AddressBook::Node* AddressBook::at( const std::string& name) const
{
    Node* cur_node = m_head;
    while((cur_node) && (cur_node->m_data.m_name != name))
    {
        cur_node = cur_node -> m_next;
    }
    return cur_node;
}
void AddressBook::print_employees() const {
    Node *cur_node = m_head;
    for (int index = 0; index < m_size; index++) {
        std::cout << cur_node->m_data << std::endl;
        cur_node = cur_node->m_next;
    }
}
std::ostream& operator << (std::ostream& out, const AddressBook& addressBook)
{
    AddressBook::Node *cur_node = addressBook.m_head;
    for (int index = 0; index < addressBook.m_size; index++) {
        out << cur_node->m_data << std::endl;
        cur_node = cur_node->m_next;
    }
}
void AddressBook::operator += (const Employee& new_employee)
{
    add_employee(new_employee);
}
void AddressBook::operator -= (uint32_t id)
{
    delete_employee(id);
}
const Employee& AddressBook::operator[] (uint32_t id) const
{
    assert(at(id));
    return at(id)->m_data;
}
const Employee& AddressBook::operator[](std::string& name) const
{
    assert(at(name));
    return at(name)->m_data;
}
 Employee& operator [](std::string& name)
{
    if(!at(name))
    {
       Employee new_employee = Employee();
       new_employee.m_name = name;
       add_employee(new_employee);
    }
    return at(name)->m_data;
}
 Employee& operator [](uint32_t id)
 {
    if(!at(id))
    {
       Employee new_employee = Employee();
       new_employee.m_id = id;
       add_employee(new_employee);
    }
    return at(id)->m_data;
 }
AddressBook::~AddressBook()
{
    clear();
}
