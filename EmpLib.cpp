#include"EmpLib.h"

namespace EmpLib {

	void AdressBook::clear() {
		if (head)
		{
			Node* temp = head;
			while (head)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
			head = nullptr;
			size_of_the_book = 0;
		}
	}

	void AdressBook::add_worker(const Employee& emp)
	{
		if (!head) {
			head = new Node(Employee(emp));
		}
		else {
			Node *temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = new Node(Employee(emp));
		}
	}

	void AdressBook::del_worker(uint32_t id)
	{
		if (head)
		{
			Node *it_head = head;
			if (it_head->data.id == id) // Удаляем, если 1-й элемент
			{
				head = head->next;
				delete it_head;
				return;
			}
			while (it_head->next->next) // Если удаляем в центре
			{
				if (it_head->next->data.id == id)
				{
					Node* temp = it_head->next;
					it_head->next = it_head->next->next;
					delete temp;
					return;
				}
				it_head = it_head->next;
			}
			if (it_head->next->data.id == id)
			{
				delete it_head->next;
				it_head->next = nullptr;
				return;
			}
		}
	}


	void AdressBook::del_worker(const std::string& name)
	{
		if (head)
		{
			Node* it_head = head;
			if (it_head->data.name == name) // Удаляем, если 1-й элемент
			{
				head = head->next;
				delete it_head;
				return;
			}
			while (it_head->next->next) // Если удаляем в центре
			{
				if (it_head->next->data.name == name)
				{
					Node* temp = it_head->next;
					it_head->next = it_head->next->next;
					delete temp;
					return;
				}
				it_head = it_head->next;
			}
			if (it_head->next->data.name == name)
			{
				delete it_head->next;
				it_head->next = nullptr;
				return;
			}
		}
	}



	Employee& AdressBook::find_worker(const std::string &name)
	{
		if (head)
		{
			Node* it_head = head;
			if (it_head->data.name == name)
			{
				return it_head->data;
			}
			while (it_head->next)
			{
				if (it_head->next->data.name == name)
				{
					return it_head->next->data;
				}
				it_head = it_head->next;
			}
		}
		Node* new_emp = new Node(Employee(1, name, 1));
		new_emp->next = head;
		head = new_emp;
		return head->data;
	}

	const Employee& AdressBook::find_worker(const std::string& name) const 
	{
		if (head)
		{
			Node* it_head = head;
			if (it_head->data.name == name)
			{
				return it_head->data;
			}
			while (it_head->next)
			{
				if (it_head->next->data.name == name)
				{
					return it_head->next->data;
				}
				it_head = it_head->next;
			}
		}
		assert(false); // такого элемента нет
	}

	AdressBook operator+(AdressBook& book, const Employee& emp)
	{
		AdressBook::Node* temp = book.head;
		if (!temp)
		{
			book.head = new AdressBook::Node(Employee(emp));
		}
		else
		{
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = new AdressBook::Node(Employee(emp));
		}
		return book;
	}


	AdressBook operator-(AdressBook& book, uint32_t id)
	{
		book.del_worker(id);
		return book;
	}

	AdressBook operator-(AdressBook& book, const std::string &name)
	{
		book.del_worker(name);
		return book;
	}


	AdressBook& AdressBook::operator+=(const Employee& emp)
	{
		*this = *this + emp;
		return *this;
	}

	AdressBook& AdressBook::operator-=(uint32_t id)
	{
		*this = *this - id;
		return *this;
	}

	AdressBook& AdressBook::operator-=(const std::string& name)
	{
		*this = *this - name;
		return *this;
	}

	Employee& AdressBook::operator[](uint32_t id)
	{
		return this->find_worker(id);
	}

	const Employee& AdressBook::operator[](uint32_t id) const 
	{
		return this->find_worker(id);
	}

	const Employee& AdressBook::operator[](const std::string& name) const 
	{
		return this->find_worker(name);
	}

	Employee& AdressBook::operator[](const std::string& name)
	{
		return this->find_worker(name);
	}

	Employee& AdressBook::find_worker(uint32_t id)
	{
		if (head)
		{
			Node* it_head = head;
			if (it_head->data.id == id)
			{
				return it_head->data;
			}
			while (it_head->next)
			{
				if (it_head->next->data.id == id)
				{
					return it_head->next->data;
				}
				it_head = it_head->next;
			}
		}
		Node* new_emp = new Node(Employee(id, "Undefine", 1));
		new_emp->next = head;
		head = new_emp;
		return head->data;
	}

	const Employee& AdressBook::find_worker(uint32_t id) const 
	{
		if (head)
		{
			Node* it_head = head;
			if (it_head->data.id == id)
			{
				return it_head->data;
			}
			while (it_head->next)
			{
				if (it_head->next->data.id == id)
				{
					return it_head->next->data;
				}
				it_head = it_head->next;
			}
		}
		assert(false); // такого элемента нет
	}
	
	Employee::Employee(const uint32_t in_id, const std::string& in_name, const uint16_t in_grade) 
		: id(in_id), name(in_name), grade(in_grade) {};

	std::ostream& operator<<(std::ostream& out, const Employee& emp)
	{
		out << "Emp(" << emp.id << ", " << emp.name << ", " << emp.grade << ")";
		return out;
	}

	std::istream& operator>>(std::istream& in, Employee& emp)
	{
		std::cout << "Enter new Employee: {" << std::endl;
		std::cout << "id: ";
		in >> emp.id;
		std::cout << "name: ";
		in >> emp.name;
		std::cout << "grade: ";
		in >> emp.grade;
		std::cout << "}" << std::endl;
		return in;
	}



	std::ostream& operator<<(std::ostream& out, const AdressBook& book)
	{
		out << "AdressBook {\n";
		AdressBook::Node* temp = book.head;
		while (temp)
		{
			out << "\t" << temp->data << std::endl;
			temp = temp->next;
		}
		out << "}\n";
		return out;
	}



	bool Employee::operator>(const Employee& emp)
	{
		return this->grade > emp.grade;
	}

	bool Employee::operator<(const Employee& emp)
	{
		return this->grade < emp.grade;
	}

	bool Employee::operator>=(const Employee& emp)
	{
		return this->grade >= emp.grade;
	}

	bool Employee::operator<=(const Employee& emp)
	{
		return this->grade <= emp.grade;
	}

	bool operator==(const Employee& emp1, const Employee& emp2)
	{
		return (emp1.id == emp2.id) && (emp1.name == emp2.name) && (emp1.grade == emp2.grade);
	}

	bool operator!=(const Employee& emp1, const Employee& emp2)
	{
		return (emp1.id != emp2.id) || (emp1.name != emp2.name) || (emp1.grade != emp2.grade);
	}

	AdressBook::AdressBook(const AdressBook& adress_book) 
	{
		if (&adress_book == this || !adress_book.head)
		{
			head = nullptr;
			size_of_the_book = 0;
		}
		else 
		{
			head = new AdressBook::Node(adress_book.head->data);
			auto iter_copy = adress_book.head;
			auto iter = head;
			while (iter_copy->next)
			{
				iter->next = new AdressBook::Node(iter_copy->next->data);
				iter_copy = iter_copy->next;
				iter = iter->next;
			}
			size_of_the_book = adress_book.size_of_the_book;
		}
	}

	AdressBook& AdressBook::operator=(const AdressBook& adress_book) 
	{
		if (&adress_book == this)
			return *this;
		clear();
		if (!adress_book.head)
			return *this;

		head = new AdressBook::Node(adress_book.head->data);
		auto iter_copy = adress_book.head;
		auto iter = head;
		while (iter_copy->next)
		{
			iter->next = new AdressBook::Node(iter_copy->next->data);
			iter_copy = iter_copy->next;
			iter = iter->next;
		}
		size_of_the_book = adress_book.size_of_the_book;
		
		return *this;
	}
}
