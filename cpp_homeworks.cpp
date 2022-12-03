#include "cpp_homeworks.h"
#include <cassert>


bool Employee::operator!=(const Employee &other) const{
    return !((other.m_id == this->m_id) && (other.m_name == this->m_name) && (other.m_grade == this->m_grade));
}


bool Employee::operator==(const Employee &other) const{
    if ((other.m_id == this->m_id) && (other.m_name == this->m_name) && (other.m_grade == this->m_grade)) {
        return true;
    }
    return false;
}


void Employee::setUid(uint32_t uid) { m_id = uid; }

void Employee::setName(std::string& name)  { m_name = name; }

void Employee::setGrade(uint16_t grade) { m_grade = grade; }

std::istream& operator>>(std::istream& in, Employee& employee) {
    uint32_t id;
    std::string name;
    uint16_t grade;
    in >> id >> name >> grade;
    employee.setUid(id);  employee.setName(name); employee.setGrade(grade);
    return in;
}


std::ostream& operator<<(std::ostream& out, const Employee& employee) {
    out << "Id: " << employee.m_id << " ";
    out << "Name: " << employee.m_name << " ";
    out << "Grade: " << employee.m_grade << std::endl;
    return out;
}


AddressBook::AddressBook() : m_list(nullptr), m_size(0) {}


AddressBook::AddressBook(const AddressBook &addressBook) {
    if (m_list){
        clearBook();
    }
    Node* first_node = addressBook.m_list;
    m_list = new Node(first_node->m_data);
    m_size = addressBook.m_size;
    Node* last_node = m_list;
    for (int i = 0; i < m_size; ++i) {
        first_node->next_node = new Node(last_node->next_node->m_data);
        first_node = first_node->next_node;
        last_node = last_node->next_node;
    }
}


void AddressBook::addEmployee(const Employee &new_employee) {
    ++m_size;
    if (!m_list) {
        m_list = new Node(new_employee);
        return;
    }
    Node* current = m_list;
    while (current->next_node) {
        current = current->next_node;
    }
    current->next_node = new Node(new_employee);
}


void AddressBook::deleteEmployee(uint32_t id) {
    if (!m_list) {
        return;
    }
    bool flag = true;
    Node* current = m_list;
    while (current->next_node) {
        if (current->m_data.m_id == id) {
            break;
        }
        current = current->next_node;
    }
    if (flag) {
        --m_size;
        Node* temp = m_list->next_node;
        current->next_node = temp->next_node;
        delete temp;
    }
}


AddressBook::Node* AddressBook::findID(uint32_t id) {
    Node* current = m_list;
    while (current && (current->m_data.m_id != id)) {
        current = current->next_node;
    }
    assert(current);
    return current;
}


AddressBook::Node* AddressBook::findName(const std::string &name) {
    Node* current = m_list;
    while (current && (current->m_data.m_name != name)) {
        current = current->next_node;
    }
    assert(current);
    return current;
}


void AddressBook::clearBook() {
    while (m_list) {
        deleteEmployee(m_list->m_data.m_id);
    }
}


AddressBook& AddressBook::operator=(const AddressBook &another) {
    m_size = another.m_size;
    Node* first_node = new Node(*another.m_list);
    Node* last_node = first_node;
    Node* current = first_node->next_node;
    for (size_t i = 1; i < m_size; ++i) {
        last_node->next_node = new Node(*current);
        last_node = last_node->next_node;
        current = current->next_node;
    }
}


AddressBook& AddressBook::operator+(const Employee &another) {
    addEmployee(another);
}


AddressBook& AddressBook::operator-(uint32_t id) {
    deleteEmployee(id);
}


AddressBook const& AddressBook::operator[](uint32_t id) {
    findID(id);
}


AddressBook const& AddressBook::operator[](const std::string& name) {
    findName(name);
}


std::ostream& operator<<(std::ostream& out, const AddressBook& addressBook) {
    AddressBook::Node* current = addressBook.m_list;
    for (size_t i = 0; i < addressBook.m_size; ++i) {
        out << current->m_data << std::endl;
        current = current->next_node;
    }
    return out;
}


AddressBook::~AddressBook() {
    clearBook();
}
