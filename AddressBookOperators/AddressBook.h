#pragma once

#include "Employee.h"
#include <forward_list>

class AddressBook {
	std::forward_list<Employee> list_;
public:
	AddressBook();

	AddressBook(AddressBook const& other);

	AddressBook(AddressBook&& other)noexcept;

	~AddressBook();

	AddressBook& operator=(AddressBook const& other);

	AddressBook& operator=(AddressBook&& other)noexcept;

	void add(Employee const& elem);

	void erase(uint32_t id);

	Employee const* find(uint32_t id)const;

	Employee const* find(std::string const& name)const;

	void clear();

	friend std::ostream& operator<<(std::ostream& ostrm, AddressBook const& obj);

	AddressBook& operator+=(Employee const& elem);

	AddressBook& operator-=(uint32_t id);

	Employee const& operator[](uint32_t id)const;

	Employee const& operator[](std::string const& name)const;
};