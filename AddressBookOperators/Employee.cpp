#include "Employee.h"

Employee::Employee() :id(0), name(), grade(0) {}

Employee::Employee(uint32_t id_, std::string const& name_, uint16_t grade_) : id(id_), name(name_), grade(grade_) {}

Employee::~Employee() {}

std::ostream& operator<<(std::ostream& ostrm, Employee const& obj) {
	ostrm << "Employee(" << obj.id << ", " << obj.name << ", " << obj.grade << ")";
	return ostrm;
}

std::istream& operator>>(std::istream& istrm, Employee& obj) {
	istrm >> obj.id >> obj.name >> obj.grade;
	return istrm;
}

bool Employee::operator==(Employee const& other)const {
	return (id == other.id) && (name == other.name) && (grade == other.grade);
}

bool Employee::operator!=(Employee const& other)const {
	return !operator==(other);
}