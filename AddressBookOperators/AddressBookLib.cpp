#include <iostream>
#include <string>
#include <forward_list>
#include "Employee.h"
#include "AddressBookLib.h"

namespace AddressBookLib {
    AddressBook &AddressBook::operator=(const AddressBook &another) {
        if (this != &another)
            *this = another;
        return *this;
    }

    void AddressBook::addNewRecord(uint32_t new_id, const std::string &new_name, uint16_t new_grade) {
        m_recordList.push_front(Employee(new_id, new_name, new_grade));
    }

    void AddressBook::addNewRecord(Employee &new_record) {
        m_recordList.push_front(new_record);
    }

    void AddressBook::removeRecordById(uint32_t id) {
        m_recordList.remove(findRecordById(id));
    }

    Employee &AddressBook::findRecordById(uint32_t id) {
        for (Employee &emp: m_recordList) {
            if (emp.m_id == id)
                return emp;
        }
        m_recordList.push_front(Employee());
        return m_recordList.front();
    }

    Employee &AddressBook::findRecordByName(const std::string &name) {
        for (Employee &emp: m_recordList) {
            if (emp.m_name == name)
                return emp;
        }
        m_recordList.push_front(Employee());
        return m_recordList.front();
    }

    void AddressBook::clear() {
        m_recordList.clear();
    }

    std::ostream &operator<<(std::ostream &out, const AddressBook &book) {
        if (book.m_recordList.empty())
            out << "This book doesn\'t contain any records\n";
        else {
            out << "This book contains these next records:\n";
            for (auto &emp: book.m_recordList)
                out << emp << std::endl;
        }
        return out;
    }

    void AddressBook::print() {
        std::cout << *this << std::endl;
    }

    AddressBook& AddressBook::operator+=(Employee &employee) {
        addNewRecord(employee);
        return *this;
    }

    AddressBook& AddressBook::operator-=(Employee &employee) {
        removeRecordById(employee.m_id);
        return *this;
    }

    Employee &AddressBook::operator[](const int index) {
        return findRecordById(index);
    }

    Employee &AddressBook::operator[](const std::string& index_name) {
        return findRecordByName(index_name);
    }
}