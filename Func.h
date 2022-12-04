#pragma once
#include <iostream>
#include <string>

class AddressBook;

class Employee
{
public:
	uint32_t id;
	std::string name;
	uint16_t grade;

	
	// ������������ 
	Employee() = default;
	Employee(uint32_t idx, std::string n, uint16_t g);

	bool operator==(const Employee& another) const;
	bool operator!=(const Employee& another) const;

	friend AddressBook;
};


class AddressBook
{
public:
	struct node
	{
		Employee person;
		node* next = nullptr;
	} *List = nullptr;


	// ������������ 
	AddressBook() = default;
	AddressBook(AddressBook& list);

	// ������ 
	void addEmployee(const Employee person);
	void addEmployee(uint32_t uid, const std::string& name, uint16_t grade);

	void deleteEmployee(const uint32_t idx);

	void findEmployee(const std::string name);
	void findEmployee(const uint32_t idx);

	void deleteBook(node** List);
	void deleteBook();

	//void printBook(const AddressBook& list);

	// ��������� 
	AddressBook operator+(const Employee person); 
	AddressBook operator-(const uint32_t idx); // �������� �� �������� ����� 
	AddressBook operator=(const AddressBook& list);

	Employee operator[](const uint32_t idx);
	Employee operator[](const std::string name);

};

std::ostream& operator<<(std::ostream& os, const Employee& person);
std::ostream& operator<<(std::ostream& os, const AddressBook& list);
std::istream& operator>>(std::istream& is, Employee& person);
