#include "AddressBook.h"
Node* Copy(Node* head) {
    if (!head)
        return nullptr;
    Node* new_node = new Node;
    new_node->m_employee = head->m_employee;
    new_node->next = Copy(head->next);
    return new_node;
}
void AddressBook::AddEmployee(uint32_t id,const std::string& name,uint16_t grade)
{
    Node* new_node = new Node();
    Employee new_employee(id,name,grade);
    new_node->m_employee = new_employee;
    new_node->next = m_head;
    m_head = new_node;
}
Employee* AddressBook::Find(uint32_t id){
    Node* current = m_head;
    while (current) {
        if (current->m_employee.m_id == id)
            return &(current->m_employee);
        current = current->next;
    }
    return nullptr;
}
Employee* AddressBook::Find(const std::string& name) {
    Node* current = m_head;
    while (current) {
        if (current->m_employee.m_name == name)
            return &(current->m_employee);
        current = current->next;
    }
    return nullptr;
}
void AddressBook::Clear()
{
    Node* current = m_head;
    Node* next = nullptr;
    while (current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    m_head = nullptr;
}
void AddressBook::DeleteEmployee(uint32_t id) {
    Node* current = m_head;
    Node* prev = nullptr;
    while (current) {
        if (current->m_employee.m_id == id){
            if(prev){
                prev->next=current->next;
                delete current;
                return;
            }
            else{
                m_head=current->next;
                delete current;
                return;
            }
        }
        prev=current;
        current = current->next;
    }
}
void AddressBook::print() const{
    Node* current = m_head;
    if(current) {
        while (current) {
            std::cout << current->m_employee.m_name << "->";
            current = current->next;
        }
        std::cout<<std::endl;
    }
    else
        std::cout<<"List is empty";
}

