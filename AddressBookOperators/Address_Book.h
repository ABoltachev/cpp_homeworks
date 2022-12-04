#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <forward_list>

namespace HW_1 {
	class Employee {
	private:
		uint32_t id;
		std::string name;
		uint16_t grade;
	public:
		// constructors
		Employee() = default;
		Employee(uint32_t id, const std::string name, uint16_t grade);

		// setters
		void setID(uint32_t id);
		void setName(std::string& name);
		void setGrade(uint16_t grade);

		// comparison operators
		friend bool operator==(const Employee& lft, const Employee& rgh);
		friend bool operator!=(const Employee& lft, const Employee& rgh);

		// cin, cout
		friend std::istream& operator>>(std::istream& in, Employee& new_employee);
		friend std::ostream& operator<<(std::ostream& out, const Employee& old_employee);
		
		friend class AddressBook;
	};

	class AddressBook {
	private:
		std::forward_list<Employee> book;
	public:
		AddressBook() = default;
		AddressBook(const AddressBook& book) = default;
		
		// changes
		void addEmployee(uint32_t new_id, const std::string& new_name, uint16_t new_grade);
		void addEmployee(const Employee& new_employee);
		void removeEmployee(uint32_t delete_id);
		void clearBook();

		// more functions
		Employee& findEmployee_withID(uint32_t need_id);
		Employee& findEmployee_withName(const std::string& need_name);
		const Employee& findEmployee_withID(uint32_t need_id) const;
		const Employee& findEmployee_withName(const std::string& need_name) const;
		
		// operators
		AddressBook& operator=(const AddressBook& another_employee);
		AddressBook& operator+(const Employee& new_employee);
		AddressBook& operator-(uint32_t delete_id);
		Employee& operator[](uint32_t need_id);
		Employee& operator[](const std::string& need_name);
		const Employee& operator[](uint32_t need_id) const;
		const Employee& operator[](const std::string& need_name) const;


		// cout
		friend std::ostream& operator<<(std::ostream& out, const AddressBook& old_book);

		friend class Employee;
	};

}
