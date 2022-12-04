#include "Homework_1.h"
#include <iostream>
Employee::Employee(const std::string name, const uint16_t grade, const uint32_t id)
{
    this->grade = grade;
    this->id = id;
    this->name = name;
}

bool Employee::operator==(const Employee& other)
{
    return this->grade == other.grade && this->id == other.id && this->name == other.name;
}

bool Employee::operator!=(const Employee& other)
{
    return this->grade != other.grade || this->id != other.id || this->name != other.name;;
}

Employee& Employee::operator=(const Employee& other)
{
    this->grade = other.grade;
    this->id = other.id;
    this->name = other.name;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << employee.name << " " << employee.grade << " " << employee.id;
    return os;
}

std::istream& operator>>(std::istream& is, Employee& employee)
{
    is >> employee.name >> employee.grade >> employee.id;
    return is;
}

std::ostream& operator<<(std::ostream& os, const AdressBook& adress_book)
{
    if (!adress_book.head)
    {
        os << "Книга пуста" << std::endl;
    }
    else
    {
        AdressBook::Book* temp = adress_book.head;
        while (temp)
        {
            os << temp->employee << "\r\n";
            temp = temp->next_page;
        }
    }
    return os;
}

AdressBook::AdressBook(const AdressBook& other)
{
    
    if (&other == this)
        return;
    if (other.head == nullptr)
        return;
    head = new Book;
    head->employee = other.head->employee;
    auto temp_copy = other.head->next_page;
    auto temp = head;
    while (temp_copy)
    {
        temp->next_page = new Book;
        temp = temp->next_page;
       
        temp->employee = temp_copy->employee;
        temp_copy = temp_copy->next_page;

    }
    
}

AdressBook AdressBook::operator+(const Employee& employee)
{
    AdressBook temp = *this;
    temp.Push_Employee(employee);
    return temp;
}

AdressBook AdressBook::operator-(const uint32_t id)
{
    AdressBook temp = *this;
    temp.Delete_Employee(id);
    return temp;
}

AdressBook& AdressBook::operator=(const AdressBook& other)
{
    if (&other == this)
    {
        return *this;
    } 
    else
    {
        Delete_AdressBook();
        if (other.head == nullptr)
        {
            return *this;
        }
        else
        {
            head = new Book;
            /*head->employee.grade = other.head->employee.grade;
            head->employee.name = other.head->employee.name;
            head->employee.id = other.head->employee.id;*/
            head->employee = other.head->employee;
            if (other.head->next_page != nullptr)
            {
                auto temp_copy = other.head->next_page;
                auto temp = head;
                while (temp_copy)
                {
                    temp->next_page = new Book;
                    temp = temp->next_page;
                    /*temp->employee.name = temp_copy->employee.name;
                    temp->employee.grade = temp_copy->employee.grade;
                    temp->employee.id = temp_copy->employee.id;*/
                    temp->employee = temp_copy->employee;
                    temp_copy = temp_copy->next_page;
                }
                return *this;
            }
            return *this;
        }
        
        
    }
}

Employee& AdressBook::operator[](const uint32_t id)
{
    auto temp_head = this->head;
    while (temp_head)
    {
        if (temp_head->employee.id == id)
        {
            return temp_head->employee;
        }
        temp_head = temp_head->next_page;
    }
    temp_head = new Book;
    temp_head->employee.id = id;
    Push_Employee(temp_head->employee);
    return temp_head->employee; 
}

Employee& AdressBook::operator[](const std::string name)
{
    auto temp_head = this->head;
    while (temp_head)
    {
        if (temp_head->employee.name == name)
        {
            return temp_head->employee;
        }
        temp_head = temp_head->next_page;
    }
    temp_head = new Book;
    temp_head->employee.name = name;
    Push_Employee(temp_head->employee);
    return temp_head->employee;
}

void AdressBook::Delete_Employee(const uint32_t id)
{
    if (!head)
    {
        return;
    }
    else if (head->employee.id == id)
    {

        auto del_page = head;
        head = head->next_page;
        delete del_page;
    }
    else
    {
        auto temp_head = head;
        while (temp_head->next_page->employee.id != id)
        {
            temp_head = temp_head->next_page;
        }
        if (temp_head->next_page->next_page)
        {
            auto del_page = temp_head->next_page;
            temp_head->next_page = temp_head->next_page->next_page;
            delete del_page;
        }
        else
        {
            delete temp_head->next_page;
            temp_head->next_page = nullptr;
        }

    }
}

void AdressBook::Push_Employee(const Employee& employee)
{
    if (!head)
    {
        head = new Book;
        head->employee = employee;
    }
    else
    {
        Book* new_page = new Book;
        new_page->employee = employee;
        auto temp_head = head;
        while (temp_head->next_page)
        {
            temp_head = temp_head->next_page;
        }
        temp_head->next_page = new_page;
    }
}

bool AdressBook::Find_Employee(const uint32_t id)
{
    if (!head)
    {
        return false;
    }
    else
    {
        auto temp_head = head;
        while (temp_head)
        {
            if (temp_head->employee.id == id)
            {
                return true;
            }
            temp_head = temp_head->next_page;
        }
        return false;
    }
}

bool AdressBook::Find_Employee(const std::string name)
{
    if (!head)
    {
        return false;
    }
    else
    {
        auto temp_head = head;
        while (temp_head)
        {
            if (temp_head->employee.name == name)
            {
                return true;
            }
            temp_head = temp_head->next_page;
        }
        return false;
    }
}

void AdressBook::Delete_AdressBook()
{
    if (!head)
    {
        return;
    }
    head->clear_book();
    delete head;
    head = nullptr;
}

void AdressBook::Book::clear_book()
{
    if (next_page)
    {
        next_page->clear_book();
    }
    delete next_page;
    next_page = nullptr;
}
