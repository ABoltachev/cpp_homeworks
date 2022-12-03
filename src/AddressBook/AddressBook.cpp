#include "AddressBook.hpp"

void AddressBook::add(const Employee &employee) {
<<<<<<< HEAD
    const uint32_t id = employee.id;
=======
    uint32_t id = employee.id;
>>>>>>> hw_vvtsygankov
    for (const auto &employee_: employees) {
        if (id == employee_.id) {
            std::cerr << "Error! (id = " << id << " - already exists) \nThe add didn't happen.\n";
            return;
        }
    }
    employees.push_front(employee);
}

<<<<<<< HEAD
void AddressBook::add(const AddressBook &addressBook) {
    for (const auto &employee: addressBook.employees) {
        this->add(employee);
    }
}

bool AddressBook::del(const uint32_t id) {
    auto prevEmployee = employees.before_begin();
    for (auto employee = employees.begin(); employee != employees.end(); ++employee) {
        if (employee->id == id) {
            employees.erase_after(prevEmployee);
            return true;
        }
        prevEmployee = employee;
=======
bool AddressBook::del(const uint32_t id) {
    auto prevEmploy = employees.before_begin();
    for (auto employee = employees.begin(); employee != employees.end(); ++employee) {
        if (employee->id == id) {
            employees.erase_after(prevEmploy);
            return true;
        }
        prevEmploy = employee;
>>>>>>> hw_vvtsygankov
    }
    return false;
}

std::optional<Employee> AddressBook::find(uint32_t id) {
    for (auto &employee: employees) {
        if (employee.id == id) {
<<<<<<< HEAD
            return employee;
=======
            return std::ref(employee);
>>>>>>> hw_vvtsygankov
        }
    }
    return std::nullopt;
}

std::forward_list<Employee> AddressBook::find(const std::string &name) {
    std::forward_list<Employee> foundEmployees;
    for (const auto &employee: employees) {
        if (employee.name == name) {
            foundEmployees.push_front(employee);
        }
    }
    if (!foundEmployees.empty()) {
        return foundEmployees;
    }
    return {};
}

void AddressBook::clear() {
    employees.clear();
}

std::forward_list<Employee> AddressBook::getEmployers() {
    return employees;
}

std::ostream &operator<<(std::ostream &stream, const AddressBook &addressBook) {
    stream << "AddressBook: \n";
    size_t size = 0;
    for (const auto &employer: addressBook.employees) {
        ++size;
        stream << employer;
    }
    stream << "\tcount : " << size << "\n\n";
    return stream;
}

<<<<<<< HEAD
void AddressBook::update(const uint32_t id, const Employee &data) {
    const uint32_t id_ = data.id;
=======
void AddressBook::update(uint32_t id, const Employee &data) {
    uint32_t id_ = data.id;
>>>>>>> hw_vvtsygankov
    bool isUniqueId = true;
    for (const auto &employee: employees) {
        if (id != employee.id && employee.id == id_) {
            isUniqueId = false;
            break;
        }
    }

    if (!isUniqueId) {
        std::cerr << "Error! (id = " << id_ << " - already exists) \nThe data update didn't happen.\n";
<<<<<<< HEAD
=======
        return;
>>>>>>> hw_vvtsygankov
    }

    for (auto &employee: employees) {
        if (employee.id == id) {
            employee = data;
            return;
        }
    }
<<<<<<< HEAD
    const std::string error = "Error! (Employer with id = " + std::to_string(id) + " - not exists) \nThe data update didn't happen.\n";
    throw std::invalid_argument(error);
=======
    std::cerr << "Error! (Employer with id = " << id << " - not exists) \nThe data update didn't happen.\n";
>>>>>>> hw_vvtsygankov
}

const Employee &AddressBook::operator[](uint32_t id) const {
    for (const auto &employee: employees) {
        if (id == employee.id) {
            return employee;
        }
    }
<<<<<<< HEAD
    const std::string error = "\"Access error! (id = \"" + std::to_string(id) + "\" - not found).\n";
    throw std::invalid_argument(error);
=======
    std::cerr << "Access error! (id = " << id << " - not found).\n";
>>>>>>> hw_vvtsygankov
}

const Employee &AddressBook::operator[](const std::string &name) const {
    for (const auto &employee: employees) {
        if (name == employee.name) {
            return employee;
        }
    }
<<<<<<< HEAD
    const std::string error = "Access error! (name = \"" + name + "\" - not found).\n";
    throw std::invalid_argument(error);
=======
    std::cerr << "Access error! (name = \"" << name << "\" - not found).\n";
>>>>>>> hw_vvtsygankov
}

AddressBook &AddressBook::operator+=(const Employee &employee) {
    this->add(employee);
    return *this;
}

<<<<<<< HEAD
AddressBook &AddressBook::operator+=(const AddressBook &addressBook) {
    this->add(addressBook);
    return *this;
}

AddressBook operator+(AddressBook lhs, const Employee &rhs) {
    lhs += rhs;
    return lhs;
}


AddressBook operator+(const AddressBook &lhs, const AddressBook &rhs) {
    auto copy = lhs;
    copy += rhs;
    return copy;
=======
AddressBook operator+(AddressBook ab, const Employee &employee) {
    ab += employee;
    return ab;
>>>>>>> hw_vvtsygankov
}

AddressBook &AddressBook::operator-=(const uint32_t id) {
    this->del(id);
    return *this;
}
<<<<<<< HEAD
AddressBook operator-(AddressBook addressBook, uint32_t id) {
    addressBook -= id;
    return addressBook;
=======

AddressBook operator-(AddressBook ab, uint32_t id) {
    ab -= id;
    return ab;
>>>>>>> hw_vvtsygankov
}
