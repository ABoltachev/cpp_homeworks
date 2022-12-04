#ifndef BOOK_H
#define BOOK_H

#include "Employee.h"

namespace AddressBookLibrary {

	class AddressBook {
	private:
		struct list {
			Employee person;
			list* next;
		};
	public:
		list* book = nullptr;
		AddressBook() = default;
		~AddressBook();

		AddressBook(const AddressBook& book) = default;
		AddressBook& operator = (const AddressBook & another);

		void AddEmployee(list** book, Employee person);
		AddressBook& operator += (Employee person);

		list* DeleteByID(list** book, uint32_t id);
		AddressBook& operator -= (uint32_t id);

		void FindByID(list** book, uint32_t id);
		const AddressBook& operator [] (uint32_t id);

		void FindByName(list** book, const std::string& name);
		const AddressBook& operator [] (const std::string& name);

		friend std::ostream& operator << (std::ostream& os, const AddressBook& ad);
		list* DeleteList(list* ad);
	};
}

#endif
