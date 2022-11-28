#include "adr_book.hpp"

uint32_t AddressBook::Employee::getId() const { return this->id; }
std::string AddressBook::Employee::getName() const { return this->name; }
uint16_t AddressBook::Employee::getGrade() const { return this->grade; }
bool operator==(const AddressBook::Employee& a, const AddressBook::Employee& b) { return a.id == b.id and a.name == b.name and a.grade == b.grade; }
bool operator!=(const AddressBook::Employee& a, const AddressBook::Employee& b) { return a.id != b.id or a.name != b.name or a.grade != b.grade; }
AddressBook::Employee::Employee(uint32_t id, std::string name, uint16_t grade) : id(id), name(name), grade(grade) {}

void AddressBook::addEmployee(uint32_t id,std::string name,uint16_t grade)
{
    this->book.push_front(Employee(id,name,grade));
}

void AddressBook::addEmployee(AddressBook::Employee a)
{
    this->book.push_front(a);
}

AddressBook::Employee AddressBook::findEmpl(uint32_t id)
{
    for(auto& e : this->book)
        if(e.id == id)
            return e;
    Employee add;
    add.id = id;
    this->addEmployee(add);

    return add;
}

AddressBook::Employee AddressBook::findEmpl(std::string name)
{
    for(auto& e : this->book)
        if(e.name == name)
            return e;
    Employee add;
    add.name = name;
    this->addEmployee(add);

    return add;
}

bool AddressBook::empty() const { return this->book.empty(); }

std::istream& operator>>(std::istream& cin,AddressBook& book)
{
    AddressBook::Employee add;
    cin >> add.id >> add.name >> add.grade;
    book.addEmployee(add);

    return cin;
}

std::ostream& operator<<(std::ostream& cout,const AddressBook& book)
{
    if(book.book.empty())
        cout << "Address book is empty";
    else
        for(auto& e : book.book)
            cout << e;
    
    return cout;
}

std::ostream& operator<<(std::ostream& cout,const AddressBook::Employee& e)
{
    cout << "Entry:" << '\n';
    cout << "id: " << e.id << '\n';
    cout << "name: " << e.name << '\n';
    cout << "grade: " << e.grade << '\n';

    return cout;
}