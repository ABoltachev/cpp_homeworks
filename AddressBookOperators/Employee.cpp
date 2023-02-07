#include "Employee.h"

namespace AddressBookLibrary {
	Employee& Employee::operator = (const Employee& another) {
		if (this != &another) {
			id = another.id;
			name = another.name;
			grade = another.grade;
		}
		return *this;
	}

	const bool operator == (const Employee& emp1, const Employee& emp2) {
		return ((emp1.id == emp2.id) && (emp1.name == emp2.name) && (emp1.grade == emp2.grade));
	}

	const bool operator != (const Employee& emp1, const Employee& emp2) {
		return !((emp1.id == emp2.id) && (emp1.name == emp2.name) && (emp1.grade == emp2.grade));
	}

	std::istream& operator >> (std::istream& in, Employee& emp) {
		in >> emp.id >> emp.name >> emp.grade;
		return in;
	}

	std::ostream& operator << (std::ostream& os, const Employee& emp) {
		os << "\n";
		os << "ID: " << emp.id << std::endl;
		os << "Name: " << emp.name << std::endl;
		os << "Grade: " << emp.grade << std::endl;
		return os;
	}
}
