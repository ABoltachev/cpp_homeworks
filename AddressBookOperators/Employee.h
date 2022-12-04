#pragma once

#include <iostream>
#include <string>

class Employee {
public:
	uint32_t id;
	std::string name;
	uint16_t grade;

	Employee();

	Employee(uint32_t id_, std::string const& name_, uint16_t grade_);

	~Employee();

	friend std::ostream& operator<<(std::ostream& ostrm, Employee const& obj);

	friend std::istream& operator>>(std::istream& istrm, Employee& obj);

	bool operator==(Employee const& other)const;

	bool operator!=(Employee const& other)const;
};