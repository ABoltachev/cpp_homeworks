#pragma once
#include <iostream>
#include <string>
class Employee
{
private:
	friend class AdressBook;
	uint16_t grade = 0;
	std::string name = "";
	uint32_t id = 0;
public:
	
	Employee() = default;
	Employee(const std::string name, const uint16_t grade, const uint32_t id);
	
	bool operator==(const Employee& other);
	bool operator!=(const Employee& other);
	Employee& operator=(const Employee& other);

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
	friend std::istream& operator>>(std::istream& is, Employee& employee);
};

class AdressBook
{
private:
	struct Book
	{
		Employee employee;
		Book* next_page = nullptr;
		void clear_book();
	};
	Book* head = nullptr;
public:
	AdressBook() = default;
	AdressBook(const AdressBook& other);

	friend std::ostream& operator<<(std::ostream& os, const AdressBook& adress_book);
	AdressBook operator+(const Employee& employee);
	AdressBook operator-(const uint32_t id);
	AdressBook& operator=(const AdressBook& other);
	Employee& operator[](const uint32_t id);
	Employee& operator[](const std::string name);
	

	void Delete_Employee(const uint32_t id);
	void Push_Employee(const Employee& employee);
	bool Find_Employee(const uint32_t id);
	bool Find_Employee(const std::string name);
	void Delete_AdressBook();
};

