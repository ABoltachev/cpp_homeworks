#include "TestLib.hpp"

#include <cassert>

namespace TestLib {

    Employee::Employee(uint32_t id, std::string& name, uint16_t grade)
        : m_id(id), m_name(name), m_grade(grade)
    {}

    std::istream& operator>>(std::istream& in, Employee& emp)
    {
        in >> emp.m_id >> emp.m_name >> emp.m_grade;
        return in;
    }

    std::ostream& operator<<(std::ostream& out, const Employee& emp)
    {
        out << "ID: " << emp.m_id << " NAME: " << emp.m_name << " GRADE: " << emp.m_grade << std::endl;
        return out;
    }

    bool Employee::operator==(const Employee& emp)
    {
        return (m_id == emp.m_id) && (m_name == emp.m_name) && (m_grade == emp.m_grade);
    }

    bool Employee::operator!=(const Employee& emp)
    {
        return !((m_id == emp.m_id) && (m_name == emp.m_name) && (m_grade == emp.m_grade));
    }

    AddressBook::AddressBook()
        : m_head(nullptr), m_size(0)
    {}

    AddressBook::AddressBook(const AddressBook& addr_book)
    {
        Node* first = new Node(*addr_book.m_head);
        Node* second = first;
        m_size = addr_book.m_size;
        first = first->next;
        for (size_t i = 0; i < m_size - 1; i++) {
            second->next = new Node(*first);
            second = second->next;
            first = first->next;
        }
    }

    AddressBook& AddressBook::operator= (const AddressBook& addr_book)
    {
        Node* first = new Node(*addr_book.m_head);
        Node* second = first;
        m_size = addr_book.m_size;
        first = first->next;
        for (size_t i = 0; i < m_size - 1; i++) {
            second->next = new Node(*first);
            second = second->next;
            first = first->next;
        }
        return *this;
    }

    void AddressBook::addEmployee(const Employee& emp) {
        m_size++;
        if (!m_head) {
            m_head = new Node(emp);
            return;
        }
        Node* cur_node = m_head;
        while (cur_node->next) {
            cur_node = cur_node->next;
        }
        cur_node->next = new Node(emp);
    }

    AddressBook& AddressBook::operator+ (const Employee& emp)
    {
        addEmployee(emp);
        return *this;
    }

    void AddressBook::delEmployee(uint32_t id)
    {
        if (m_head) {
            if (m_size == 1) {
                m_head = nullptr;
                m_size--;
                return;
            }
            bool flaq = false;
            Node* cur_node = m_head;
            Node* temp = nullptr;
            while (cur_node->next) {
                if (cur_node->m_data.m_id == id) {
                    flaq = true;
                    break;
                }
                temp = cur_node;
                cur_node = cur_node->next;
            }
            if (flaq) {
                if (temp)
                {
                    temp->next = cur_node->next;
                    cur_node->next = nullptr;
                }
                else
                {
                    m_head = m_head->next;
                }

                m_size--;
            }
        }
        return;
    }

    AddressBook& AddressBook::operator- (uint32_t id)
    {
        delEmployee(id);
        return *this;
    }

    void AddressBook::clearAddressBook()
    {
        while (m_head) {
            delEmployee(m_head->m_data.m_id);
        }
    }

    Employee& AddressBook::find(uint32_t id) {
        Node* cur_node = m_head;
        while (cur_node && (cur_node->m_data.m_id != id)) {
            cur_node = cur_node->next;
        }
        if (!cur_node) {
            Employee new_emp = Employee();
            new_emp.m_id = id;
            addEmployee(new_emp);
            return new_emp;
        }
        return cur_node->m_data;
    }

    Employee& AddressBook::find(const std::string& name) {

        Node* cur_node = m_head;
        while (cur_node && (cur_node->m_data.m_name != name)) {
            cur_node = cur_node->next;
        }
        if (!cur_node) {
            Employee new_emp = Employee();
            new_emp.m_name = name;
            addEmployee(new_emp);
            return new_emp;
        }
        return cur_node->m_data;
    }

    const Employee& AddressBook::operator[](uint32_t id) const
    {
        Node* cur_node = m_head;
        while (cur_node && (cur_node->m_data.m_id != id)) {
            cur_node = cur_node->next;
        }
        return cur_node->m_data;
    }

    Employee& AddressBook::operator[](uint32_t id)
    {
        return find(id);
    }

    const Employee& AddressBook::operator[](const std::string& name) const
    {
        Node* cur_node = m_head;
        while (cur_node && (cur_node->m_data.m_name != name)) {
            cur_node = cur_node->next;
        }
        return cur_node->m_data;
    }

    Employee& AddressBook::operator[](const std::string& name)
    {
        return find(name);
    }

    std::ostream& operator<< (std::ostream& out, const AddressBook& addr_book)
    {
        AddressBook::Node* cur_node = addr_book.m_head;
        for (size_t i = 0; i < addr_book.m_size; i++)
        {
            out << cur_node->m_data << std::endl;
            cur_node = cur_node->next;
        }
        return out;

    }

    AddressBook::~AddressBook()
    {
        clearAddressBook();
    }
}