#include <stdint.h>
#include <string>
#include <iostream>
#include <cassert>

class AdressBook;

class Employee
{
public:
	Employee() = default;
	Employee(uint32_t id, const std::string& name, uint16_t grade);
	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
	friend std::istream& operator>>(std::istream& in, Employee& employee);

	const bool operator==(const Employee& employee) const;
	const bool operator!=(const Employee& employee) const;
private:
	friend class AdressBook;

	uint32_t id = 0;
	std::string name;
	uint16_t grade = 0;
};

class AdressBook 
{
private:
	struct node 
	{
		node* next;
		Employee employee;
		node();
		// ~node();

		void recursive_clear();
	};
	node* head;
	size_t __size__;

	void _push_first(const Employee& employee);
	void _pop_last();
	node* __find__(uint32_t id) const;
	node* __find__(const std::string& name) const;

	void pop_front();
	void pop_back();
	void __erase__(node* _node_);
public:
	AdressBook();
	AdressBook(const AdressBook& copy);
	void push(const Employee& employee);
	void push(uint32_t id, const std::string& name, uint16_t grade);
	bool find(uint32_t id) const;
	bool find(const std::string& name) const;

	void erase(uint32_t id);
	void clear();

	AdressBook operator+(const Employee& employee) const;
	AdressBook operator-(uint32_t id) const;
	AdressBook& operator=(const AdressBook& copy);

	const Employee& operator[](uint32_t id) const;
	const Employee& operator[](const std::string& name) const;

	Employee& operator[](uint32_t id);
	Employee& operator[](const std::string& name);

	friend std::ostream& operator<<(std::ostream& out, const AdressBook& adress_book);

	~AdressBook();
};