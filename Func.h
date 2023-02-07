#pragma once

#include <iostream>
#include <string>

class AddressBook;

class Employee
{
	uint32_t id;
	std::string name;
	uint16_t grade;

public:	
	// Конструкторы 
	Employee() = default;
	Employee(uint32_t idx, const std::string& n, uint16_t g);

	bool operator==(const Employee& another) const;
	bool operator!=(const Employee& another) const;

	friend AddressBook;
	friend std::ostream& operator<<(std::ostream& os, const Employee& person);
	friend std::istream& operator>>(std::istream& is, Employee& person);
	friend std::ostream& operator<<(std::ostream& os, const AddressBook& list);
};


class AddressBook
{
	struct node
	{
		Employee person;
		node* next = nullptr;
	} *List = nullptr;

	void deleteBook(node* List);

public:
	// Конструкторы 
	AddressBook() = default;
	AddressBook(const AddressBook& list);

	// Методы 
	void addEmployee(const Employee& person);
	void addEmployee(uint32_t uid, const std::string& name, uint16_t grade);

	void deleteEmployee(uint32_t idx);

	void findEmployee(const std::string& name);
	void findEmployee(uint32_t idx);

	void findEmployee(const std::string& name) const;
	void findEmployee(uint32_t idx) const;
	
	void deleteBook();

	//void printBook(const AddressBook& list);

	// Операторы 
	AddressBook& operator+=(const Employee& person); 
	AddressBook& operator-=(uint32_t idx); // удаление из адресной книги 

	AddressBook operator+(const Employee& person) const;
	AddressBook operator-(uint32_t idx) const;

	AddressBook& operator=(const AddressBook& list);

	Employee& operator[](uint32_t idx);
	Employee& operator[](const std::string& name);

	const Employee& operator[](uint32_t idx) const;
	const Employee& operator[](const std::string& name) const;

	friend std::ostream& operator<<(std::ostream& os, const AddressBook& list);
};



