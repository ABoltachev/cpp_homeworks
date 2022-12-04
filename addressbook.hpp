#pragma once

#include <cinttypes>
#include <string>
#include <forward_list>
#include <algorithm>
#include <stdexcept>
#include <optional>

class Employee {
private:
	uint32_t _id;
	std::string _name;
	uint16_t _grade;
	friend class  AddressBook;
public:
	Employee() : _id(0), _name("Undefined"), _grade(0) {}

	Employee(uint32_t id, const std::string& name, uint16_t grade) :
		_id(id), _name(name), _grade(grade) {}

	friend std::istream& operator>>(std::istream& i, Employee& e);
	friend std::ostream& operator<<(std::ostream& o, const Employee& e);

	bool operator==(const Employee& other) const;
	bool operator!=(Employee const& other) const;

	~Employee() = default;

};

class AddressBook {
	std::forward_list<Employee> employees;
public:
	AddressBook() = default;

	void add(const Employee& employee);

	Employee* find(uint32_t id);

	Employee* find(const std::string name);

	void delete_by_id(uint32_t id);

	friend std::ostream& operator<<(std::ostream& o, const AddressBook& ab);

	AddressBook& operator=(const AddressBook& other);

	AddressBook(const AddressBook& to_copy);

	AddressBook operator+(const Employee& employee_to_add) const;
	AddressBook& operator+=(const Employee& employee_to_add);

	AddressBook operator-(uint32_t id_to_delete) const;
	AddressBook& operator-=(uint32_t id_to_delete);

	Employee& operator[](uint32_t id);
	Employee& operator[](const std::string& name);

	void clear();

	~AddressBook() {}
};
