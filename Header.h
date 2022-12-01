#pragma once
#include<stdio.h>
#include<string>
#include<iostream>

class Node
{
	Employee x;
	class Node* next;
	friend class AdressBook;
	Node() = default;
	Node(const Employee& data) : x(data) {};
};

class Employee
{
public:
	uint32_t id;
	std::string name;
	uint16_t grade;

	friend class AddressBook;
	friend std::istream& operator>> (std::istream&, Employee&);
	friend std::ostream& operator<<(std::ostream&, Employee&);
	bool operator ==(Employee& other);
	bool operator !=(Employee& other);
	Employee(uint32_t Nid, std::string Nname, uint16_t Ngrade) { id = Nid;name = Nname;grade = Ngrade; }
	Employee(const Employee& old_employee) { id = old_employee.id; name = old_employee.name; grade = old_employee.grade; }
};
class AdressBook
{
	Node* head;
	int count = 0;
	Node* tail;
public:
	AdressBook() { head = NULL; tail = NULL;} 
	int getCount() { return count; } 
	void Clear();
	Node* Add(Employee& data, Node*);
	void Delete(unsigned int id);
	Node* FindId(unsigned int);
	Node* FindName(std::string);
	Node* operator+ (Node*);
	void operator- (unsigned int);
	Node* operator[] (std::string);
};