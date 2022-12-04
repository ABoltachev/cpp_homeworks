#pragma once
#include<iostream>

class Employee{
	uint32_t m_id;
	std::string m_name;
	uint16_t m_grade;
public:
	Employee() = default;
	Employee(uint32_t id, std::string name, uint16_t grade);

	bool operator==(const Employee& other) const;
	bool operator!=(const Employee& other) const;

	
	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
	friend std::istream& operator>>(std::istream& in, Employee& employee);
	friend class Addressbook;
};

class Addressbook
{
	class Node {
	public:
		Employee m_data;
		Node* next = nullptr;
		Node() = default;
		Node(const Employee& data) : m_data(data) {};
	};
	Node* m_head = nullptr;
	size_t m_size;
public:
	Addressbook();
	Addressbook(const Addressbook& book);

	void AddEmployee(const Employee& new_emp);
	void DeleteEmployee(uint32_t id);

	Node* FindId(uint32_t id) const;
	Node* FindName(const std::string& name) const;

	Addressbook& operator+(const Employee& new_emp);
	Addressbook& operator-(uint32_t id);
	Addressbook& operator=(const Addressbook& another);

	Employee& operator[](uint32_t id);
	Employee& operator[](const std::string& name);

	const Employee& operator[](uint32_t id) const;
	const Employee& operator[](const std::string& name) const;

	void ClearAddressbook();
};

