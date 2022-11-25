#include "AdressBook.hpp"

AdressBook::node::node() 
{
	this->employee = nullptr;
	this->next = nullptr;
}

AdressBook::node::~node() 
{
	delete employee;
}

AdressBook::AdressBook() 
{
	this->head = nullptr;
	this->__size__ = 0;
}

void AdressBook::_push_first(const Employee& employee) 
{
	head = new node;
	head->employee = new Employee(employee);
	__size__ = 1;
}

void AdressBook::push(const Employee& employee) 
{
	if (!__size__)
		_push_first(employee);
	else
	{
		node* new_node = new node;
		new_node->employee = new Employee(employee);
		auto iter = head;
		while (iter->next)
			iter = iter->next;
		iter->next = new_node;
		__size__++;
	}
}

Employee::Employee(uint32_t id, const std::string& name, uint16_t grade) 
{
	this->id = id;
	this->name = name;
	this->grade = grade;
}

void AdressBook::push(uint32_t id, const std::string& name, uint16_t grade) 
{
	push(Employee(id, name, grade));
}

AdressBook::node* AdressBook::__find__(uint32_t id) const
{
	auto iter = head;
	while (iter)
	{
		if (iter->employee->id == id)
			return iter;
		iter = iter->next;
	}
	return nullptr;
}

AdressBook::node* AdressBook::__find__(const std::string& name) const
{
	auto iter = head;
	while (iter)
	{
		if (iter->employee->name == name)
			return iter;
		iter = iter->next;
	}
	return nullptr;
}

void AdressBook::_pop_last() 
{
	delete head;
	__size__ = 0;
}

void AdressBook::pop_front() 
{
	if (__size__ == 0)
		return;
	if (__size__ == 1)
	{
		_pop_last();
		return;
	}
	auto old_head = head;
	head = head->next;
	delete old_head;
	__size__--;
}

void AdressBook::pop_back() 
{
	if (__size__ == 0)
		return;
	if (__size__ == 1)
	{
		_pop_last();
		return;
	}
	auto iter = head;
	while (iter->next->next)
		iter = iter->next;
	delete iter->next;
	__size__--;
}

bool AdressBook::find(uint32_t id) const 
{
	return __find__(id);
}

bool AdressBook::find(const std::string& name) const 
{
	return __find__(name);
}

void AdressBook::__erase__(node* _node_) 
{
	if (_node_ == nullptr)
		return;
	else if (_node_ == head)
		pop_front();
	else if (!_node_->next)
		pop_back();
	else
	{
		auto pred = head;
		while (pred->next != _node_)
			pred = pred->next;
		pred->next = _node_->next;
		delete _node_;
		__size__--;
	}
}

void AdressBook::erase(uint32_t id) 
{
	__erase__(__find__(id));
}

void AdressBook::node::recursive_clear() 
{
	if (next)
		next->recursive_clear();
	delete next;
}

void AdressBook::clear() 
{
	head->recursive_clear();
	delete head;
}

AdressBook::AdressBook(const AdressBook& copy) 
{
	if (&copy == this)
		return;
	if (copy.head == nullptr)
		return;
	head = new node;
	head->employee = new Employee(*copy.head->employee);
	auto iter_copy = copy.head->next;
	auto iter = head;
	while (iter_copy)
	{
		iter->next = new node;
		iter = iter->next;
		iter->employee = new Employee(*iter_copy->employee);
		iter_copy = iter_copy->next;
	}
	__size__ = copy.__size__;
}

std::ostream& operator<<(std::ostream& out, const Employee& employee) 
{
	return out << std::string("{id: ") << employee.id << std::string(", name: ") << employee.name << std::string(", grade: ") << employee.grade << "}";
}

std::ostream& operator<<(std::ostream& out, const AdressBook& adress_book) 
{
	out << adress_book.__size__ << "\r\n";
	auto iter = adress_book.head;
	while (iter)
	{
		out << *iter->employee << "\r\n";
		iter = iter->next;
	}
	return out;
}

const bool Employee::operator==(const Employee& employee) const 
{
	return id == employee.id && name == employee.name && grade == employee.grade;
}

const bool Employee::operator!=(const Employee& employee) const 
{
	return id != employee.id || name != employee.name || grade == employee.grade;
}

std::istream& operator>>(std::istream& in, Employee& employee) 
{
	std::string line, current = "";
	std::getline(in, line);
	size_t i = 5;
	for (;i < line.length(); ++i)
	{
		if (line[i] == ',')
			break;
		else
			current += line[i];
	}
	employee.id = std::stoi(current);
	current = "";
	i += 8;
	for (; i < line.length(); ++i)
	{
		if (line[i] == ',')
			break;
		else
			current += line[i];
	}
	employee.name = current;
	current = "";
	i += 9;
	for (; i < line.length(); ++i)
	{
		if (line[i] == '}')
			break;
		else
			current += line[i];
	}
	employee.grade = std::stoi(current);
	return in;
}

AdressBook AdressBook::operator+(const Employee& employee) const 
{
	AdressBook copy = *this;
	copy.push(employee);
	return copy;
}

AdressBook AdressBook::operator-(uint32_t id) const
{
	AdressBook copy = *this;
	copy.erase(id);
	return copy;
}

Employee& AdressBook::operator[](uint32_t id) 
{
	auto object = __find__(id);
	assert(object);
	return *(object->employee);
}

Employee& AdressBook::operator[](const std::string& name) 
{
	auto object = __find__(name);
	assert(object);
	return *(object->employee);
}

AdressBook::~AdressBook() 
{
	clear();
}