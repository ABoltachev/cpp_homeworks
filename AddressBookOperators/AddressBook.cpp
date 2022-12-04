#include "AddressBook.h"

namespace AddressBookLibrary {
	AddressBook::~AddressBook() {
		book = DeleteList(book);
	}

	AddressBook& AddressBook::operator = (const AddressBook& another) {
		if (this != &another) {
			book = DeleteList(book);
			book = nullptr;
			list* dop = another.book;
			while (dop) {
				AddEmployee(&book, dop->person);
				dop = dop->next;
			}
		}
		return *this;
	}

	void AddressBook::AddEmployee(list** book, Employee person) {
		while (*book)
			book = &((*book)->next);
		list* new_list = new list;
		new_list->person = person;
		new_list->next = nullptr;
		(*book) = new_list;
	}

	AddressBook& AddressBook::operator += (Employee person) {
		AddEmployee(&book, person);
		return *this;
	}

	AddressBook::list* AddressBook::DeleteByID(list** book, uint32_t id) {
		if (*book) {
			if ((*book)->person.id == id)
				return (*book)->next;
			else {
				(*book)->next = DeleteByID(&((*book)->next), id);
				return (*book);
			}
		}
		else
			return (*book);
	}

	AddressBook& AddressBook::operator -= (uint32_t id) {
		book = DeleteByID(&book, id);
		return *this;
	}

	void AddressBook::FindByID(list** book, uint32_t id) {
		while (*book) {
			if ((*book)->person.id == id) {
				std::cout << (*book)->person;
				return;
			}
			book = &((*book)->next);
		}
		list* new_list = new list;
		new_list->next = nullptr;
		new_list->person.id = id;
		(*book) = new_list;
	}

	AddressBook& AddressBook::operator [] (uint32_t id) {
		FindByID(&book, id);
		return *this;
	}

	void AddressBook::FindByName(list** book, std::string name) {
		while (*book) {
			if ((*book)->person.name == name) {
				std::cout << (*book)->person;
				return;
			}
			book = &((*book)->next);
		}
		list* new_list = new list;
		new_list->next = nullptr;
		new_list->person.name = name;
		(*book) = new_list;
	}

	AddressBook& AddressBook::operator [] (std::string name) {
		FindByName(&book, name);
		return *this;
	}

	std::ostream& operator << (std::ostream& os, const AddressBook& ad) {
		AddressBook::list* dop = ad.book;
		os << "Address Book: \n";
		while (dop) {
			os << dop->person << std::endl;
			dop = dop->next;
		}
		return os;
	}

	AddressBook::list* AddressBook::DeleteList(list* ad) {
		if (ad) {
			DeleteList(ad->next);
			delete ad;
		}
		return nullptr;
	}
}