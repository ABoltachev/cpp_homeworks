#include <iostream>
#include "address_book.h"
int main() {
    AddressBook book = AddressBook();
    book.add_employee(Employee(1,"Alexandra",10000));
    book.add_employee(Employee(2,"Nikita",9999));
    book.add_employee(Employee(3,"Ivan",1030));
    book += Employee(4,"Victor",5000);
    AddressBook book2 = book;
    book2.print_employees();
    book += Employee(1,"Alex",1000);
    book2 -=3;
    std::cout<<book[4];
    return 0;
}
