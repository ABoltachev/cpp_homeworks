#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

namespace AddressBookLibrary {

	class Employee {
	private:
		uint32_t id = 0;
		std::string name = "";
		uint16_t grade = 0;
		friend class AddressBook;
	public:
		Employee() = default;

		Employee(uint32_t new_id, const std::string& new_name, uint16_t new_grade) : id(new_id), name(new_name), grade(new_grade)
		{
		}

		Employee(const Employee& person) = default;
		Employee& operator = (const Employee& another);

		friend const bool operator == (const Employee& emp1, const Employee& emp2);
		friend const bool operator != (const Employee& emp1, const Employee& emp2);

		friend std::istream& operator >> (std::istream& in, Employee& emp);
		friend std::ostream& operator << (std::ostream& os, const Employee& emp);
	};
}
#endif
