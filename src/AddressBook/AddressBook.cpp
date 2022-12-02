#include "AddressBook.hpp"

void AddressBook::add(const Employee &employee) {
    uint32_t id = employee.id;
    for (const auto &employee_: employees) {
        if (id == employee_.id) {
            std::cerr << "Error! (id = " << id << " - already exists) \nThe add didn't happen.\n";
            return;
        }
    }
    employees.push_front(employee);
}

bool AddressBook::del(const uint32_t id) {
    auto prevEmploy = employees.before_begin();
    for (auto employee = employees.begin(); employee != employees.end(); ++employee) {
        if (employee->id == id) {
            employees.erase_after(prevEmploy);
            return true;
        }
        prevEmploy = employee;
    }
    return false;
}

std::optional<Employee> AddressBook::find(uint32_t id) {
    for (auto &employee: employees) {
        if (employee.id == id) {
            return std::ref(employee);
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

void AddressBook::update(uint32_t id, const Employee &data) {
    uint32_t id_ = data.id;
    bool isUniqueId = true;
    for (const auto &employee: employees) {
        if (id != employee.id && employee.id == id_) {
            isUniqueId = false;
            break;
        }
    }

    if (!isUniqueId) {
        std::cerr << "Error! (id = " << id_ << " - already exists) \nThe data update didn't happen.\n";
        return;
    }

    for (auto &employee: employees) {
        if (employee.id == id) {
            employee = data;
            return;
        }
    }
    std::cerr << "Error! (Employer with id = " << id << " - not exists) \nThe data update didn't happen.\n";
}

const Employee &AddressBook::operator[](uint32_t id) const {
    for (const auto &employee: employees) {
        if (id == employee.id) {
            return employee;
        }
    }
    std::cerr << "Access error! (id = " << id << " - not found).\n";
}

const Employee &AddressBook::operator[](const std::string &name) const {
    for (const auto &employee: employees) {
        if (name == employee.name) {
            return employee;
        }
    }
    std::cerr << "Access error! (name = \"" << name << "\" - not found).\n";
}

AddressBook &AddressBook::operator+=(const Employee &employee) {
    this->add(employee);
    return *this;
}

AddressBook operator+(AddressBook ab, const Employee &employee) {
    ab += employee;
    return ab;
}

AddressBook &AddressBook::operator-=(const uint32_t id) {
    this->del(id);
    return *this;
}

AddressBook operator-(AddressBook ab, uint32_t id) {
    ab -= id;
    return ab;
}
