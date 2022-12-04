#include "Address_Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <forward_list>

namespace HW_1 {
	
	// employee
	Employee::Employee(uint32_t new_id, const std::string new_name, uint16_t new_grade): id(new_id), name(new_name), grade(new_grade) {
	}
	void Employee::setID(uint32_t new_id) { id = new_id; }

	void Employee::setName(std::string& new_name) { name = new_name; }

	void Employee::setGrade(uint16_t new_grade) { grade = new_grade; }

	bool operator==(const Employee& lft, const Employee& rgh) {
		if ((lft.id == rgh.id) and (lft.name == rgh.name) and (lft.grade == rgh.grade)) {
			return true;
		}
		return false;
	}

	bool operator!=(const Employee& lft, const Employee& rgh) {
		if ((lft.id != rgh.id) or (lft.name != rgh.name) or (lft.grade != rgh.grade)) {
			return true;
		}
		return false;
	}

	std::istream& operator>>(std::istream& in, Employee& new_employee) {
		uint32_t new_id;
		std::string new_name;
		uint16_t new_grade;
		in >> new_id >> new_name >> new_grade;
		new_employee.setID(new_id);
		new_employee.setName(new_name);
		new_employee.setGrade(new_grade);
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const Employee& old_employee) {
		out << "ID: " << old_employee.id << std::endl;
		out << "Name: " << old_employee.name << std::endl;
		out << "Grade: " << old_employee.grade << std::endl;
		return out;
	}

	// addressbook

	// changes
	void AddressBook::addEmployee(uint32_t new_id, const std::string& new_name, uint16_t new_grade) {
		book.push_front(Employee(new_id, new_name, new_grade));
	}
	void AddressBook::addEmployee(const Employee& new_employee) {
		book.push_front(new_employee);
	}
	void AddressBook::removeEmployee(uint32_t delete_id) {
		book.remove(findEmployee_withID(delete_id));
	}
	void AddressBook::clearBook() {
		book.clear();
	}

	// more functions
	Employee& AddressBook::findEmployee_withID(uint32_t need_id) {
		for (Employee& i : book) {
			if (i.id == need_id) {
				return i;
			}
		}
		book.push_front(Employee(need_id, "", 0));
		return book.front();
	}
	Employee& AddressBook::findEmployee_withName(const std::string& need_name) {
		for (Employee& i : book) {
			if (i.name == need_name) {
				return i;
			}
		}
		book.push_front(Employee(0, need_name, 0));
		return book.front();
	}
	const Employee& AddressBook::findEmployee_withID(uint32_t need_id) const {
		for (const Employee& i : book) {
			if (i.id == need_id) {
				return i;
			}
		}
		std::cout << "There is no such ID in the book" << std::endl;
	}
	const Employee& AddressBook::findEmployee_withName(const std::string& need_name) const {
		for (const Employee& i : book) {
			if (i.name == need_name) {
				return i;
			}
		}
		std::cout << "There is no such Name in the book" << std::endl;
	}

	// operators
	AddressBook& AddressBook::operator=(const AddressBook& another_employee) {
		if (this != &another_employee) {
			book = another_employee.book;
		}
		return *this;
	}
	AddressBook& AddressBook::operator+(const Employee& new_employee) {
		addEmployee(new_employee);
		return *this;
	}
	AddressBook& AddressBook::operator-(uint32_t delete_id) {
		removeEmployee(delete_id);
		return *this;
	}
	Employee& AddressBook::operator[](uint32_t need_id) {
		return findEmployee_withID(need_id);
	}
	Employee& AddressBook::operator[](const std::string& need_name) {
		return findEmployee_withName(need_name);
	}

	const Employee& AddressBook::operator[](uint32_t need_id) const {
		return findEmployee_withID(need_id);
	}
	const Employee& AddressBook::operator[](const std::string& need_name) const {
		return findEmployee_withName(need_name);
	}

	// cout
	std::ostream& operator<<(std::ostream& out, const AddressBook& old_book) {
		if (!old_book.book.empty()) {
			out << std::endl << "This is the book:" << std::endl;
			for (auto& i : old_book.book) {
				out << i << std::endl;
			}
		}
		else {
			out << "The book is empty." << std::endl;
		}
		return out;
	}
}
