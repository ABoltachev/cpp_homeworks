#include "Func.h"

Employee::Employee(uint32_t idx, const std::string& n, uint16_t g)
{
	id = idx;
	name = n;
	grade = g;
}

bool Employee::operator==(const Employee& another) const
{
	if ((this->id == another.id) and (this->name == another.name) and (this->grade == another.grade))
		return true;

	return false;
}

bool Employee::operator!=(const Employee& another) const
{
	if (!((this->id == another.id) and (this->name == another.name) and (this->grade == another.grade)))
		return true;
	return false;
}


// Работа с классом AddressBook

AddressBook::AddressBook(const AddressBook& list)
{
	this->List = list.List;
}

void AddressBook::addEmployee(const Employee& human)
{
	node* newNode = new AddressBook::node;
	newNode->person = human;

	if (List)
	{
		AddressBook::node* tmpList = List;
		while (tmpList->next)
		{
			tmpList = tmpList->next;
		}
		tmpList->next = newNode;
	}
	else
	{
		List = newNode;
	}
}

void AddressBook::addEmployee(uint32_t id, const std::string& name, uint16_t grade)
{
	addEmployee(Employee(id, name, grade));
}

void AddressBook::deleteEmployee(const uint32_t idx)
{
	node* cur = List;
	node* prev = nullptr;
	bool Flag = false;
	while (cur)
	{
		if (cur->person.id == idx)
		{
			Flag = true;
			if (!prev)
			{
				List = List->next;
			}
			else
			{
				prev->next = cur->next;
				cur->next = nullptr;
			}
			break;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	if (!Flag)
	{
		std::cout << idx << " NOT FOUND" << std::endl;
	}
}

void AddressBook::findEmployee(const std::string& name_f) 
{
	node* tmpList = List;
	bool Flag = false;

	while (tmpList)
	{
		if (tmpList->person.name == name_f)
		{
			std::cout << "Employee " << name_f << " FOUND" << std::endl;
			Flag = true;
			tmpList = tmpList->next;
		}
		else
		{
			tmpList = tmpList->next;
		}
	}

	if (!Flag)
	{
		std::cout << "Employee with the name: " << name_f << " " << " NOT FOUND" << std::endl;
		addEmployee(0, name_f, 0); // Добавляем Employee, которого не нашли
 	}	
}

void AddressBook::findEmployee(uint32_t idx)
{
	node* tmpList = List;
	bool Flag = false;

	while (tmpList)
	{
		if (tmpList->person.id == idx)
		{
			std::cout << "Employee " << idx << " FOUND" << std::endl;
			Flag = true;
			tmpList = tmpList->next;
		}
		else
		{
			tmpList = tmpList->next;
		}
	}

	if (!Flag)
	{
		std::cout << "Employee with the id: " << idx << " " << " NOT FOUND" << std::endl;
		addEmployee(idx, "", 0);
	}
}

void AddressBook::findEmployee(const std::string& name_f) const
{
	node* tmpList = List;
	bool Flag = false;

	while (tmpList)
	{
		if (tmpList->person.name == name_f)
		{
			std::cout << "Employee " << name_f << " FOUND" << std::endl;
			Flag = true;
			tmpList = tmpList->next;
		}
		else
		{
			tmpList = tmpList->next;
		}
	}

	if (!Flag)
	{
		std::cout << "Employee with the name: " << name_f << " " << " NOT FOUND" << std::endl;
	}
}

void AddressBook::findEmployee(uint32_t idx) const
{
	node* tmpList = List;
	bool Flag = false;

	while (tmpList)
	{
		if (tmpList->person.id == idx)
		{
			std::cout << "Employee " << idx << " FOUND" << std::endl;
			Flag = true;
			tmpList = tmpList->next;
		}
		else
		{
			tmpList = tmpList->next;
		}
	}

	if (!Flag)
	{
		std::cout << "Employee with the id: " << idx << " " << " NOT FOUND" << std::endl;
	}
}

void AddressBook::deleteBook(node* list)
{
	if (list->next)
	{
		deleteBook(list->next);
	}
	delete list->next;
	list->next = nullptr;
}

void AddressBook::deleteBook()
{
	if (List)
	{
		deleteBook(List);
		delete List;
		List = nullptr;
	}
}

AddressBook& AddressBook::operator+=(const Employee& person)
{
	this->addEmployee(person);
	return *this;
}

AddressBook AddressBook::operator+(const Employee& person) const
{
	AddressBook tmp;
	tmp = *this;
	tmp += person;
	return tmp;
}

AddressBook& AddressBook::operator-=(uint32_t idx)
{
	this->deleteEmployee(idx);
	return *this;
}

AddressBook AddressBook::operator-(uint32_t idx) const
{
	AddressBook tmp;
	tmp = *this;
	tmp -= idx;
	return tmp;
}

AddressBook& AddressBook::operator=(const AddressBook& list)
{
	if (this == &list)
	{
		return *this;
	}

	deleteBook();
	if (list.List == nullptr)
	{
		List = nullptr;
		return *this;
	}
	else
	{
		auto itr = list.List;
		while (itr)
		{
			addEmployee(itr->person);
			itr = itr->next;
		}
		return *this;
	}
}

Employee& AddressBook::operator[](uint32_t idx)
{
	node* tmpList = this->List;
	bool Flag = true;

	for (int i = 0; i < idx; i++)
	{
		if (tmpList)
		{
			tmpList = tmpList->next;
		}
		else
		{
			Flag = true;
			break;
		}
	}

	if (!Flag)
	{
		std::cout << "Book don't have this id " << idx << std::endl;
		addEmployee(idx, "", 0);
	}
	else
	{
		return tmpList->person;
	}
}

Employee& AddressBook::operator[](const std::string& name_f)
{
	node* tmpList = this->List;
	bool Flag = true;

	while (tmpList)
	{
		if (tmpList->person.name == name_f)
		{
			Flag = true;
			break;
		}
		
		tmpList = tmpList->next;
	}

	if (!Flag)
	{
		std::cout << "Book don't have this name " << name_f << std::endl;
		addEmployee(0, name_f, 0);
	}
	else
	{
		return tmpList->person;
	}
}

const Employee& AddressBook::operator[](uint32_t idx) const
{
	node* tmpList = this->List;
	bool Flag = true;

	for (int i = 0; i < idx; i++)
	{
		if (tmpList)
		{
			tmpList = tmpList->next;
		}
		else
		{
			Flag = true;
			break;
		}
	}

	if (!Flag)
	{
		std::cout << "Book don't have this id " << idx << std::endl;
	}
	else
	{
		return tmpList->person;
	}
}

const Employee& AddressBook::operator[](const std::string& name_f) const
{
	node* tmpList = this->List;
	bool Flag = true;

	while (tmpList)
	{
		if (tmpList->person.name == name_f)
		{
			Flag = true;
			break;
		}

		tmpList = tmpList->next;
	}

	if (!Flag)
	{
		std::cout << "Book don't have this name " << name_f << std::endl;
	}
	else
	{
		return tmpList->person;
	}
}

std::ostream& operator<<(std::ostream& os, const Employee& person)
{
	std::cout << "id: " << person.id << std::endl;
	std::cout << "name: " << person.name << std::endl;
	std::cout << "grade: " << person.grade << std::endl;
	return std::cout;
}

std::ostream& operator<<(std::ostream& os, const AddressBook& list)
{
	AddressBook::node* tmpList = list.List;
	while (tmpList)
	{
		std::cout << "id: " << tmpList->person.id << std::endl;
		std::cout << "name: " << tmpList->person.name << std::endl;
		std::cout << "grade: " << tmpList->person.grade << std::endl << std::endl;
		tmpList = tmpList->next;
	}
	return std::cout;
}

std::istream& operator>>(std::istream& is, Employee& person)
{
	uint32_t id;
	std::string name;
	uint16_t grade;

	std::cin >> id >> name >> grade;

	person.id = id;
	person.name = name;
	person.grade = grade;
	return std::cin;
}
