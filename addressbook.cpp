#include "addressbook.hpp"
#include <iostream>
#include <string>

std::istream& operator>>(std::istream& i, Employee& e) {
	uint32_t id; std::string name; uint16_t grade;
	if (i >> id >> name >> grade) {
		e._id = id;
		e._name = name;
		e._grade = grade;
	}
	return i;
}

std::ostream& operator<<(std::ostream& o, const Employee& e) {
	o << "[id]: " << e._id
		<< " [name]: " << e._name
		<< " [grade]: " << e._grade << std::endl;
	return o;
}

std::ostream& operator<<(std::ostream& o, const AddressBook& ab)
{
	o << "[AddressBook] :" << std::endl;
	for (const auto& e : ab.employees)
		o << e << std::endl;
	return o;
}


void AddressBook::add(const Employee& employee) {
	employees.push_front(employee);
}

Employee* AddressBook::find(uint32_t id)
{
	auto res = std::find_if(employees.begin(), employees.end(), [id](const Employee& e) {
		return e._id == id;
		});
	if (res != employees.end())
		return &(*res);
	return nullptr;
}

Employee* AddressBook::find(const std::string name)
{
	auto res = std::find_if(employees.begin(), employees.end(), [&name](const Employee& e) {
		return !e._name.compare(name);
		});
	if (res != employees.end())
		return &(*res);
	return nullptr;
}

void AddressBook::delete_by_id(uint32_t id)
{
	if (!this->find(id))
		throw std::runtime_error("Employee with id " + std::to_string(id) + " is not exist");
	employees.remove_if([id](const Employee& e) {
		return e._id == id;
		});
}

AddressBook& AddressBook::operator=(const AddressBook& other)
{
	this->clear();
	for (const auto& e : other.employees)
		this->add(e);
	return *this;
}

AddressBook::AddressBook(const AddressBook& to_copy)
{
	for (const auto& e : to_copy.employees)
		this->add(e);
}

AddressBook AddressBook::operator+(const Employee& employee_to_add) const
{
	AddressBook tmp(*this);
	tmp += employee_to_add;
	return tmp;
}

AddressBook& AddressBook::operator+=(const Employee& employee_to_add)
{
	this->add(employee_to_add);
	return *this;
}

AddressBook AddressBook::operator-(uint32_t id_to_delete) const
{
	AddressBook tmp(*this);
	tmp -= id_to_delete;
	return tmp;
}

AddressBook& AddressBook::operator-=(uint32_t id_to_delete)
{
	this->delete_by_id(id_to_delete);
	return *this;
}

Employee& AddressBook::operator[](uint32_t id)
{
	auto res = this->find(id);
	if (!res) {
		throw std::runtime_error("No such employee with id " + std::to_string(id));
	}
	return *res;
}

Employee& AddressBook::operator[](const std::string& name)
{
	auto res = this->find(name);
	if (!res) {
		throw std::runtime_error("No such employee with id " + name);
	}
	return *res;
}

bool Employee::operator==(const Employee& other) const
{
	if (this->_id == other._id &&
		!this->_name.compare(other._name) &&
		this->_grade == other._grade)
		return true;
	return false;
}

bool Employee::operator!=(Employee const& other) const
{
	return !(*this == other);
}

void AddressBook::clear()
{
	employees.clear();
}
