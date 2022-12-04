#include "Addressbook.h"
#include <cassert>

Employee::Employee(uint32_t id, std::string name, uint16_t grade)
	: m_id(id), m_name(name), m_grade(grade)
{}

bool Employee::operator==(const Employee& other) const
{
	return (m_id==other.m_id)&& (m_name == other.m_name) && (m_grade == other.m_grade);
}

bool Employee::operator!=(const Employee& other) const
{
	return !((m_id == other.m_id) && (m_name == other.m_name) && (m_grade == other.m_grade));
}

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
	out << "Id: " << employee.m_id << ' ';
	out << "Name: " << employee.m_name << ' ';
	out << "Grade: " << employee.m_grade << ' ';
	return out;
}

std::istream& operator>>(std::istream& in, Employee& employee)
{
	in >> employee.m_id;
	in >> employee.m_name;
	in >> employee.m_grade;
}

Addressbook::Addressbook()
:m_head(nullptr), m_size(0)
{}

Addressbook::Addressbook(const Addressbook& book)
{
	Node* first_node = new Node(*book.m_head);
	Node* second_node = first_node;
	Node* cur = first_node->next;
	m_size = book.m_size;
	for (size_t i = 0; i < m_size - 1; i++) {
		second_node->next = new Node(*cur);
		second_node = second_node->next;
		cur = cur->next;
	}
}

void Addressbook::AddEmployee(const Employee& new_emp)
{
	m_size++;
	if (!m_head) {
		m_head = new Node(new_emp);
		return;
	}
	Node* cur = m_head;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = new Node(new_emp);
}

void Addressbook::DeleteEmployee(uint32_t id)
{
	if (!m_head) {
		return;
	}
	bool flag = true;
	Node* current = m_head;
	while (current->next) {
		if (current->m_data.m_id == id) {
			break;
		}
		current = current->next;
	}
	if (flag) {
		--m_size;
		Node* temp = m_head->next;
		current->next = temp->next;
		delete temp;
	}
}

Addressbook::Node* Addressbook::FindId(uint32_t id) const
{
	Node* current = m_head;
	while (current && (current->m_data.m_id != id)) {
		current = current->next;
	}
	assert(current);
	return current;
	
}

Addressbook::Node* Addressbook::FindName(const std::string& name) const
{
	Node* current = m_head;
	while (current && (current->m_data.m_name != name)) {
		current = current->next;
	}
	assert(current);
	return current;
}

Addressbook& Addressbook::operator+(const Employee& new_emp)
{
	AddEmployee(new_emp);
}

Addressbook& Addressbook::operator-(uint32_t id)
{
	DeleteEmployee(id);
}

Addressbook& Addressbook::operator=(const Addressbook& another)
{
	if (this == &another)
		return *this;
	(*this).ClearAddressbook();
	this->m_head = new Node(another.m_head->m_data);
	Node* bookptr = another.m_head->next;
	Node* current;
	while (bookptr) {
		current = this->m_head;
		while (current->next) {
			current = current->next;
		}
		current->next = new Node(bookptr->m_data);
		bookptr = bookptr->next;
	}
	this->m_size = another.m_size;
	return *this;
}

Addressbook& Addressbook::operator=(const Addressbook& another)
{
	m_size = another.m_size;
	Node* first_node = new Node(*another.m_head);
	Node* last_node = first_node;
	Node* current = first_node->next;
	for (size_t i = 1; i < m_size; ++i) {
		last_node->next = new Node(*current);
		last_node = last_node->next;
		current = current->next;
	}
}

	Employee& Addressbook::operator[](uint32_t id)
	{
		FindId(id);
	}

	Employee& Addressbook::operator[](const std::string& name)
{
	FindName(name);
}

const Employee& Addressbook::operator[](uint32_t id) const
{
	Node* cur_node = m_head;
	while (cur_node && (cur_node->m_data.m_id != id)) {
		cur_node = cur_node->next;
	}
	return cur_node->m_data;
}

const Employee& Addressbook::operator[](const std::string& name) const
{
	FindName(name);
}

void Addressbook::ClearAddressbook()
{
	Node* current = m_head;
	if (!current)
		return;
	Node* tmp;
	while (current->next)
	{
		tmp = current->next->next;
		delete current->next;
		current->next = tmp;
	}
	delete m_head;
	m_head = nullptr;
}

