#include "Book.h"

namespace AddressBookLib
{
    // Constructor
    Book::Book() = default;
    Book::Book(const Book& new_book) = default;
    Book::Book(const Employee &employee) {
        address_book.push_back(employee);
    }

    // Destructor (I guess it makes no sense but IDK)
    Book::~Book() { address_book.clear(); }

    void Book::add_user(const Employee &employee) {
        address_book.push_back(employee);
    }
    void Book::add_user(const uint32_t id, const std::string& name, const uint16_t grade) {
        address_book.emplace_back(id, name, grade);
    }

    void Book::remove_by_id(const uint32_t id)
    {
        for (auto it = address_book.begin(); it != address_book.end(); ++it) {
            if (it->u_id == id) {
                address_book.erase(it);
                return;
            }
        }
    }

    Employee Book::find(const uint32_t id)
    {
        for (const Employee& it : address_book)
        {
            if (it.u_id == id)
                return it;
        }
        Employee new_employee;
        new_employee.u_id = id;
        this->address_book.push_back(new_employee);
        return new_employee;
    }
    Employee Book::find(const std::string& name)
    {
        for (const Employee& it : address_book)
        {
            if (it.u_name == name)
                return it;
        }
        Employee new_employee;
        new_employee.u_name = name;
        this->address_book.push_back(new_employee);
        return new_employee;
    }

    void Book::clear() { address_book.clear(); }

    Book& Book::operator=(const Book &new_book){
        if (this != &new_book) {
            address_book = new_book.address_book;
        }
        return *this;
    }
    std::ostream &operator<<(std::ostream &out, const Book& obj) {
        for (const auto& it : obj.address_book) {
            out << it << " -> ";
        }
        std::cout << "null";
        return out;
    }
    Book Book::operator+(const Employee &emp) {
        this->add_user(emp);
        return *this;
    }
    Book Book::operator-(const uint32_t id) {
        remove_by_id(id);
        return *this;
    }

    Employee &Book::operator[](uint32_t id) const
    {
        const auto it = (std::find_if(
                address_book.begin(),
                address_book.end(),
                [id] (const Employee& emp) -> bool { return emp.u_id == id; }));
        return const_cast<Employee &>(*it);
    }

    std::ostream &operator<<(std::ostream &out, const Employee &obj) {
        out << "Employee(u_id=" << obj.u_id << ", u_name=" << obj.u_name << ", u_grade=" << obj.u_grade << ")";
        return out;
    }
    std::istream &operator>>(std::istream &in, Employee &obj) {
        in >> obj.u_id >> obj.u_name >> obj.u_grade;
        return in;
    }
    bool operator==(const Employee &emp_1, const Employee &emp_2) {
        return emp_1.u_id == emp_2.u_id && emp_1.u_name == emp_2.u_name && emp_1.u_grade == emp_2.u_grade;
    }
    bool operator!=(const Employee &emp_1, const Employee &emp_2) {
        return !(emp_1 == emp_2);
    }
}
