#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <forward_list> // односвязный список
#include <string>
#include <cstdint>
#include <algorithm>
#include <iostream>

class Employee {
public:
	uint32_t id = 0;
	std::string name = "";
	uint16_t grade = 0;
	friend class AddressBook; // прямой доступ к редактированию полей

	Employee(uint32_t id, std::string const& name, uint16_t grade) : id(id), name(name), grade(grade) {};
};

bool operator==(Employee const& lhs, Employee const& rhs) {
	return lhs.id == rhs.id && lhs.name == rhs.name && lhs.grade == rhs.grade;
}
std::ostream& operator<<(std::ostream& os, Employee const& e) {
	os << e.id << " " << e.name << " " << e.grade;
	return os;
}
std::istream& operator>>(std::istream& is, Employee& e) {
	is >> e.id >> e.name >> e.grade;
	return is;
}

class AddressBook {
private:
	std::forward_list<Employee> list_ = {};
public:
	void add(Employee const& e) {
		list_.push_front(e);
	}
	void add(uint32_t id, std::string const& name, uint16_t grade) {
		list_.emplace_front(id, name, grade);
	}
	void del(uint32_t id) {
		list_.remove_if([id](Employee const& e) {
			return e.id == id;
			});
	}
	Employee const& find(uint32_t id) const {
		auto it = std::find_if(list_.begin(), list_.end(), [id](Employee const& e) {
			return e.id == id;
			});
		if (it == list_.end()) {
			throw std::out_of_range("ID not found");
		}
		return *it;
	}
	Employee const& find(std::string const& name) const {
		auto it = std::find_if(list_.begin(), list_.end(), [&name](Employee const& e) {
			return e.name == name;
			});
		if (it == list_.end()) {
			throw std::out_of_range("ID not found");
		}
		return *it;
	}
	Employee const& operator[](uint32_t id) const {
		return find(id);
	}
	Employee const& operator[](std::string const& name) const {
		return find(name);
	}
	std::forward_list<Employee> const& list() const noexcept {
		return list_;
	}
	AddressBook& operator+=(Employee const& rhs) {
		add(rhs);
		return *this;
	}
	AddressBook& operator-=(uint32_t id) {
		del(id);
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, AddressBook const& ab) {
	std::for_each(ab.list().begin(), ab.list().end(), [&os](Employee const& e) {
		os << e << std::endl;
		});
	return os;
}

#endif
