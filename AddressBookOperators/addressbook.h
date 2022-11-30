#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <forward_list>
#include <algorithm>
class Addressbook{

private:
    [[maybe_unused]] bool text_panic = false;
    const std::string error_with_find = "\nНе удалось найти ";

public:
    struct Employee {
        uint32_t id;
        std::string name;
        uint16_t grade;

         Employee(const uint32_t& iniz_id = 0, const std::string& iniz_name = "DummyBob", const uint16_t& iniz_grade = 0) {
            id = iniz_id, name = iniz_name, grade = iniz_grade;
        }

        friend std::ostream& operator<<(std::ostream &output, const Employee& emp_out);
        friend std::istream& operator>>(std::istream &input, Employee& emp_in);

        bool operator==(const Employee& right_op) const{
            if(id == right_op.id && name == right_op.name && grade == right_op.grade) return true;
            else return false;
        }
        bool operator!=(const Employee& right_op) const {
            return !(*this == right_op);
        }

    };

    typedef std::forward_list<Employee>::iterator emp_it;

    std::forward_list<Employee> book;

    Addressbook() = default;
     Addressbook(const std::forward_list<Employee>& iniz_book) {
        book = iniz_book;
    }
    Addressbook(const Addressbook &copy_book) {
        book = std::forward_list<Employee>(copy_book.book);
    }

    emp_it add(const uint32_t& iniz_id, const std::string& iniz_name, const uint16_t& iniz_grade);
    emp_it find(const uint32_t& find_id);
    emp_it find(const std::string& find_name);
    emp_it remove(const uint32_t& remove_id);
    emp_it remove(const std::string& remove_name);

    [[maybe_unused]] void change_panic();
    void clr();
    void print() const;

    friend std::ostream& operator<<(std::ostream &output, const Addressbook& book_out);
    friend Addressbook& operator+(Addressbook& left_op, const Employee& right_op);
    friend Addressbook& operator+(const Employee& left_op, Addressbook& right_op);
    friend Addressbook& operator-(Addressbook& left_op, const uint32_t& remove_id);
    Employee& operator[] (const uint32_t& i) {
        return *(this->find(i));
    }
    Employee& operator[] (const std::string& i) {
        return *(this->find(i));
    }
};

#endif
