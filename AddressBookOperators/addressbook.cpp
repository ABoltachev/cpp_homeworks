#include "addressbook.h"

Addressbook::emp_it Addressbook::add(const uint32_t& iniz_id, const std::string& iniz_name, const uint16_t& iniz_grade){
    book.push_front(Employee(iniz_id, iniz_name, iniz_grade));}
Addressbook::emp_it Addressbook::find(const uint32_t& find_id){
    auto it = book.begin();
    while(it != book.end()) {
        if(it->id == find_id) {
            return it;
        }
        ++it;
    }
    if(text_panic) std::cout << error_with_find + "id = " + std::to_string(find_id) << std::endl;
    return book.end();
}
Addressbook::emp_it Addressbook::find(const std::string& find_name){
    auto it = book.begin();
    while(it != book.end()) {
        if(it->name == find_name) {
            return it;
        }
        ++it;
    }
    if(text_panic) std::cout << error_with_find + "name = " + find_name << std::endl;
    return book.end();
}
Addressbook::emp_it Addressbook::remove(const uint32_t& remove_id) {
    auto prev = book.before_begin();
    for (auto it = book.begin(); it != book.end(); ++it)
    {
        if(it->id == remove_id)
        {
            book.erase_after(prev);
            return prev;
        }
        prev = it;
    }
    book.erase_after(prev);
    return prev;
}
Addressbook::emp_it Addressbook::remove(const std::string& remove_name) {
    auto prev = book.before_begin();
    for (auto it = book.begin(); it != book.end(); ++it)
    {
        if(it->name == remove_name)
        {
            book.erase_after(prev);
            return prev;
        }
        prev = it;
    }
    book.erase_after(prev);
    return prev;
}

[[maybe_unused]] void Addressbook::change_panic() {text_panic = !text_panic; }
void Addressbook::clr() {
    book.clear();
}
void Addressbook::print() const {
    for(const auto& it : book) {
        std::cout << "id: " << it.id << ", name: " << it.name << ", grade: " << it.grade << "\n";
    }
}

std::ostream &operator<<(std::ostream &output, const Addressbook &book_out) {
    for(const auto& x : book_out.book) {
        output << "id: " << x.id << ", ";
        output << "name: " << x.name << ", ";
        output << "grade: " << x.grade << ";\n";
    }
    return output;
}

std::ostream &operator<<(std::ostream &output, const Addressbook::Employee &emp_out) {
    output << "id: " << emp_out.id << ", ";
    output << "name: " << emp_out.name << ", ";
    output << "grade: " << emp_out.grade << ";\n";
    return output;
}
std::istream& operator>>(std::istream &input, Addressbook::Employee& emp_in)
{
    input >> emp_in.id >> emp_in.name >> emp_in.grade;
    return input;
}
Addressbook& operator+(Addressbook& left_op, const Addressbook::Employee& right_op){
    left_op.add(right_op.id, right_op.name, right_op.grade);
    return left_op;
}
Addressbook& operator+(const Addressbook::Employee& left_op, Addressbook& right_op) {
    right_op.add(left_op.id, left_op.name, left_op.grade);
    return right_op;
}
Addressbook& operator-(Addressbook& left_op, const uint32_t& remove_id) {
    left_op.remove(remove_id);
    return left_op;
}
Addressbook& operator-(const uint32_t& remove_id, Addressbook& right_op) {
    right_op.remove(remove_id);
    return right_op;
}
