#ifndef EMPLIB
#define EMPLIB

#include <iostream>
#include <string>
#include <cassert>
//#include<iostream>

namespace EmpLib {

	class AdressBook;

	class Employee {
	private:
		uint32_t id;
		std::string name;
		uint16_t grade;
	public:
		Employee(const uint32_t in_id, const std::string &in_name,const uint16_t in_grade);
		Employee(const Employee& emp) = default;
		Employee() = default;
		uint32_t get_id() const { return id; };
		std::string get_name() const { return name; };
		uint16_t get_grade() const { return grade; };
		
		friend AdressBook;

		bool operator>(const Employee& emp);
		bool operator<(const Employee& emp);
		bool operator>=(const Employee& emp);
		bool operator<=(const Employee& emp);

		friend bool operator==(const Employee& emp1, const Employee& emp2);
		friend bool operator!=(const Employee& emp1, const Employee& emp2);

		friend std::ostream& operator<<(std::ostream& out, const Employee& emp);
		friend std::istream& operator>>(std::istream& in, Employee& emp);
	};
	
	class AdressBook {
	private:
		struct Node {
			Employee data;
			Node* next = nullptr;
			Node() = default;
			Node(const Employee& in_data) : data(in_data) {};
		};
		Node *head = nullptr;
		size_t size_of_the_book = 0;
	public:
		AdressBook() = default;
		AdressBook(const AdressBook& adress_book);
		void add_worker(const Employee &emp);
		size_t size() { return size_of_the_book; };
		void del_worker(uint32_t id);
		void del_worker(const std::string& name);
		Employee& find_worker(uint32_t id);
		Employee& find_worker(const std::string& name);

		const Employee& find_worker(uint32_t id) const;
		const Employee& find_worker(const std::string& name) const;
		void clear();

		friend std::ostream& operator<<(std::ostream& out, const AdressBook& book);

		friend AdressBook operator+(AdressBook& book, const Employee& emp);
		friend AdressBook operator-(AdressBook& book, uint32_t id);
		friend AdressBook operator-(AdressBook& book, const std::string &name);

		AdressBook& operator=(const AdressBook& adress_book);

		AdressBook& operator+=(const Employee& emp);
		AdressBook& operator-=(const std::string& name);
		AdressBook& operator-=(uint32_t id);

		Employee& operator[](uint32_t id);
		Employee& operator[](const std::string& name);

		const Employee& operator[](uint32_t id) const;
		const Employee& operator[](const std::string& name) const;
	};
}


#endif 
