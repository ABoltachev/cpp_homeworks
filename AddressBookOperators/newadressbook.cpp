#include "newadressbook.hpp"

std::ostream& operator<<(std::ostream& out, const Employee& employee){
    out << "id: " << employee.m_id << " name: " << employee.m_name << " grade: " << employee.m_grade << std::endl;
    return out;
};

std::istream& operator>>(std::istream& in, Employee& employee) {
    std::cout << "Input employee data:" << std::endl;
    std::cout << "id: ";
    in >> employee.m_id;
    std::cout << "name: ";
    in >> employee.m_name;
    std::cout << "grade: ";
    in >> employee.m_grade;
    return in;
};

bool operator==(const Employee& employee1, const Employee& employee2) {
    if (employee1.m_id != employee2.m_id)
        return false;
    if (employee1.m_name != employee2.m_name)
        return false;
    if (employee1.m_grade != employee2.m_grade)
        return false;
    return true;
};

bool operator!=(const Employee& employee1, const Employee& employee2) {
    if (employee1 == employee2)
        return false;
    return true;
};

AddressBook::AddressBook(const AddressBook& book) {
    if (!book.m_head)
        return;
    if (!this->m_head) {
        this->m_head = new Node(book.m_head->m_data);
    }
    Node* bookptr = book.m_head->next;
    Node* current;
    while(bookptr){
        current = this->m_head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(bookptr->m_data);
        bookptr = bookptr->next;
    }
    this->m_size = book.m_size;
};

Employee AddressBook::operator[](const uint32_t& id){
    Node* current = this->m_head;
    if (current == nullptr) {
        Employee employee = { id, "", 0 };
        (*this) + employee;
        return this->m_head->m_data;
    }
    while (current->next != nullptr) {
        if (current->m_data.m_id == id)
            return current->m_data;
        current = current->next;
    }
    if (current->m_data.m_id == id)
        return current->m_data;
    Employee employee = { id, "", 0 };
    (*this) + employee;
    return current->next->m_data;
};

Employee AddressBook::operator[](const std::string& name){
    Node* current = this->m_head;
    if (current == nullptr) {
        Employee employee = { 0, name, 0 };
        (*this) + employee;
        return current->m_data;
    }
    while (current->next != nullptr) {
        if (current->m_data.m_name == name)
            return current->m_data;
        current = current->next;
    }
    if (current->m_data.m_name == name)
        return current->m_data;
    Employee employee = { 0, name, 0 };
    (*this) + employee;
    return current->next->m_data;
};

AddressBook& AddressBook::operator+(const Employee& data){
    if (!(this->m_head)) {
        (this)->m_head = new Node(data);
        this->m_size++;
        return *this;
    }
    Node* current = this->m_head;
    while (current->next) {
        current = current->next;
    }
    current->next = new Node(data);
    this->m_size++;
    return *this;
};

AddressBook& AddressBook::operator=(const AddressBook& book){
    if (this == &book)
        return *this;
    (*this).ClearAddressBook();
    this->m_head = new Node(book.m_head->m_data);
    Node* bookptr = book.m_head->next;
    Node* current;
    while (bookptr) {
        current = this->m_head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(bookptr->m_data);
        bookptr = bookptr->next;
    }
    this->m_size = book.m_size;
    return *this;
};

std::ostream& operator<<(std::ostream& out, const AddressBook& book) {
    AddressBook::Node* bookptr = book.m_head;
    while (bookptr) {
        out << bookptr->m_data << std::endl;
        bookptr = bookptr->next;
    }
    return out;
};

AddressBook& AddressBook::operator-(const Employee& employee){
    if (!(this->m_head))
        return (*this);
    Node* current = this->m_head;
    Node* temp;
    while(current && (current->m_data.m_id == employee.m_id)){
        temp = current->next;
        delete current;
        this->m_head = temp;
        this->m_size--;
        current = temp;
    }
    current = this->m_head;
    while (current && current->next)
    {
        temp = current->next->next;
        if (current->next->m_data.m_id == employee.m_id) {
            delete current->next;
            current->next = temp;
            this->m_size--;
        } else
            current = current->next;
    }
    return *this;
};

void AddressBook::ClearAddressBook() {
    Node* current = m_head;
    if (!current)
        return;
    Node* temp;
    while (current->next)
    {
        temp = current->next->next;
        delete current->next;
        current->next = temp;
    }
    delete m_head;
    m_head = nullptr;
};

