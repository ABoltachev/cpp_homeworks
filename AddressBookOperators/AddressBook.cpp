#include "AddressBook.h"

AddressBook::AddressBook() {}


AddressBook::AddressBook(AddressBook const& other) :list_(other.list_) {}

    
AddressBook::AddressBook(AddressBook&& other) noexcept :list_(std::move(other.list_)) {}

AddressBook::~AddressBook() {}

AddressBook& AddressBook::operator=(AddressBook const& other) {
	list_ = other.list_;
	return *this;
}

AddressBook& AddressBook::operator=(AddressBook&& other)noexcept {
	list_ = std::move(other.list_);
	return *this;
}

void AddressBook::add(Employee const& elem) {
		 list_.insert_after(list_.before_begin(), elem);
	 }

void AddressBook::erase(uint32_t id) {
	auto prev = list_.before_begin();
	auto cur = list_.begin();
	auto const end = list_.end();
	while (cur != end) {
		if (cur->id == id) {
			break;
		}
		else {
			prev = cur;
			++cur;
		}
	}
	if (cur != end)
		list_.erase_after(prev);
}

Employee const* AddressBook::find(uint32_t id) const {
	auto cur = list_.begin();
	auto const end = list_.end();
	while (cur != end) {
		if (cur->id == id) {
			break;
		}
		else {
			++cur;
		}
	}
	if (cur != end)
		return &(*cur);
	else
		return nullptr;
}

Employee const* AddressBook::find(std::string const& name) const {
	auto cur = list_.begin();
	auto const end = list_.end();
	while (cur != end) {
		if (cur->name == name) {
			break;
		}
		else {
			++cur;
		}
	}
	if (cur != end)
		return &(*cur);
	else
		return nullptr;
}

void AddressBook::clear() {
	list_.clear();
}

std::ostream& operator<<(std::ostream& ostrm, AddressBook const& obj) {
	if (obj.list_.begin() == obj.list_.end())
		ostrm << "<empty address book>";
	else
		for (auto i = obj.list_.begin(); i != obj.list_.end(); ++i)
			ostrm << *i << std::endl;
	return ostrm;
}

AddressBook& AddressBook::operator+=(Employee const& elem) {
	add(elem);
	return *this;
}

AddressBook& AddressBook::operator-=(uint32_t id) {
	erase(id);
	return *this;
}

Employee const& AddressBook::operator[](uint32_t id)const {
	auto found = find(id);
	if (found != nullptr)
		return *found;
	else
		throw std::logic_error("id not found");
}

Employee const& AddressBook::operator[](std::string const& name)const {
	auto found = find(name);
	if (found != nullptr)
		return *found;
	else
		throw std::logic_error("name not found");
}