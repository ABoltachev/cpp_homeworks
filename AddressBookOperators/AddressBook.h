#ifndef HW1_ADDRESSBOOK_H
#define HW1_ADDRESSBOOK_H
#include <iostream>
class AddressBook;
class Employee {
public:
    uint32_t m_id;
    std::string m_name;
    uint16_t m_grade;
    friend AddressBook;
    friend std::ostream& operator <<(std::ostream &os, const Employee& employee) {
        os<< employee.m_id<<" "<<employee.m_name<<" "<<employee.m_grade<<std::endl;
        return os;
    }
    Employee(){
        m_id=0;
        m_name="";
        m_grade=0;
    };
    Employee(uint32_t id,const std::string& name, uint16_t grade){
        m_id=id;
        m_name=name;
        m_grade=grade;
    };
};
struct Node {
    Employee m_employee;
    Node *next = nullptr;
};
Node* Copy(Node*);

class AddressBook {
private:
    Node *m_head= nullptr;
public:
    void AddEmployee(uint32_t,const std::string&,uint16_t);
    void DeleteEmployee(uint32_t);
    Employee* Find(uint32_t);
    Employee* Find(const std::string&);
    void Clear();
    void print() const;
    AddressBook(){
        m_head= nullptr;
    }
    AddressBook(const AddressBook& book)
    {
        Node* a = book.m_head;
        this->m_head = Copy(a);
    }
    friend std::ostream& operator <<(std::ostream &os, const AddressBook& book) {
        AddressBook copy=book;
        while(copy.m_head){
            std::cout<<copy.m_head->m_employee;
            copy.m_head=copy.m_head->next;
        }
        return os;
    }
    AddressBook& operator=(const AddressBook &book){
        Node* a = book.m_head;
        this->m_head = Copy(a);
        return *this;
    }
    AddressBook& operator +(Employee& new_employee){
        Node* new_node = new Node();
        new_node->m_employee = new_employee;
        new_node->next = m_head;
        m_head = new_node;
        return *this;
    }
    AddressBook& operator -(uint32_t id){
        this->DeleteEmployee(id);
        return *this;
    }
    Employee& operator[] (const uint32_t id){
        return *(this->Find(id));
    };
    Employee& operator[] (const std::string& name){
        return *(this->Find(name));
    };
};
#endif //HW1_ADDRESSBOOK_H
