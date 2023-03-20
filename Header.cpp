#include "Header.h"

Employee::Employee(uint32_t id, const std::string& name, uint16_t grade)
	: m_id(id), m_name(name), m_grade(grade) {
}

void Employee::setId(uint32_t id)
{
	m_id = id;
}

void Employee::setName(const std::string& name)
{
	m_name = name;
}

void Employee::setGrade(uint16_t grade)
{
	m_grade = grade;
}
bool Employee::operator==(const Employee& other) const {
	if (other.m_id != this->m_id) 
		return false;
	if (other.m_name != this->m_name) 
		return false; 
	if (other.m_grade != this->m_grade)
		return false;
	return true;
}
bool Employee::operator!=(const Employee& other) const {
	if (other.m_id == this->m_id)
		return false;
	if (other.m_name == this->m_name)
		return false;
	if (other.m_grade == this->m_grade)
		return false;
	return true;
}

std::istream& operator>>(std::istream& in, Employee& employee)
{
	std::cout << "Entering employee id: ";
	in >> employee.m_id;
	std::cout << "Entering the employee's name: ";
	in >> employee.m_name;
	std::cout << "Entering an employee's grade: ";
	in >> employee.m_grade;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
	out << "id: " << employee.m_id << std::endl;
	out << " name: " << employee.m_name << std::endl;
	out << " grade: " << employee.m_grade << std::endl;
	return out;
}

AddressBook::AddressBook(const AddressBook& addressBook)
{
	if (!this->m_head) {
		this->m_head = new Node(addressBook.m_head->m_data);
	}
	Node* start_node = addressBook.m_head;
	Node* curr_node;
	while (start_node->sl_node)
	{
		curr_node = this->m_head;
		while (curr_node->sl_node) {
			curr_node = curr_node->sl_node;
		}
		curr_node->sl_node = new Node(curr_node->m_data);
		start_node = start_node->sl_node;
	}
	this->m_size = addressBook.m_size;
}

void AddressBook::add(const Employee& employee)
{
	if (!m_head) {
		m_head = new Node(employee);
		m_size++;
	}
	else {
		Node* curr_node = m_head;
		while (curr_node->sl_node) {
			curr_node = curr_node->sl_node;
		}
		curr_node->sl_node = new Node(employee);
		m_size++;
	}
}

AddressBook::Node* AddressBook::findid(uint32_t id) const
{
	Node* curr_node = m_head;
	while (curr_node && (curr_node->m_data.m_id != id)) {
		curr_node = curr_node->sl_node;
	}
	return curr_node;
}

AddressBook::Node* AddressBook::findname(const std::string& name) const
{
	Node* curr_node = m_head;
	while (curr_node && (curr_node->m_data.m_name != name)) {
		curr_node = curr_node->sl_node;
	}
	return curr_node;
}

void AddressBook::deleteid(uint32_t id)
{
	Node* curr_node = m_head;
	Node* pred=nullptr;
	if (curr_node) {
		int count = 0;
		while ((curr_node->sl_node) && (curr_node->m_data.m_id != id)) {
			pred = curr_node;
			curr_node = curr_node->sl_node;
			count++;
		}
		if (count != m_size) {
			m_size--;
			if (pred)
			{
				pred->sl_node = curr_node->sl_node;
				curr_node->sl_node = nullptr;
			}
			else 
			{
				m_head = m_head->sl_node;
			}
		}
	}
}

void AddressBook::clear()
{
	Node* curr_node = m_head;
	if (curr_node) {
		while (curr_node) {
			deleteid(curr_node->m_data.m_id);
		}
	}
}

AddressBook& AddressBook::operator=(const AddressBook& another)
{
	if (this == &another)
		return *this;
	(*this).clear();
	this->m_head = new Node(another.m_head->m_data);
	Node* start_node = another.m_head->sl_node;
	Node* curr_node;
	while (start_node->sl_node) {
		curr_node = this->m_head;
		while (curr_node->sl_node) {
			curr_node = curr_node->sl_node;
		}
		curr_node->sl_node = new Node(start_node->sl_node->m_data);
		start_node = start_node->sl_node;
	}
	this->m_size = another.m_size;
	return *this;
}

AddressBook& AddressBook::operator+(const Employee& another) 
{
	add(another);
}

AddressBook& AddressBook::operator-(uint32_t id)
{
	deleteid(id);
}

AddressBook& AddressBook::operator[](uint32_t id)
{
	findid(id);
}

AddressBook& AddressBook::operator[](const std::string& name)
{
	findname(name);
}

std::ostream& operator<<(std::ostream& out, const AddressBook& addressBook)
{
	AddressBook::Node* curr_node = addressBook.m_head;
	while(curr_node){
		out << curr_node->m_data << std::endl;
		curr_node = curr_node->sl_node;
	}
	return out;
}
