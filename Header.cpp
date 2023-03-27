#include"Header.h"
#include<stdio.h>
#include<string>
#include<cassert>

std::istream& operator>> (std::istream& in, Employee& data)
{
	in >> data.id >> data.name >> data.grade;
	return in;
}
std::ostream& operator<< (std::ostream& out, Employee& data)
{
	out << data.id << " " << data.name << " " << data.grade;
	return out;
}
bool Employee::operator== (Employee& data)
{
	bool z = false;
	if (id == data.id && grade == data.grade && name == data.name)
	{
		z = true;
	}
	return z;
}
bool Employee::operator!=(Employee& data)
{
	bool z = true;
	if (id == data.id && grade == data.grade && name == data.name)
	{
		z = false;
	}
	return z;
}


Node* AdressBook::Add(Employee& data ,Node* node)
{
	node->x = data;
	count++;
	if (tail == NULL) 
	{
		head = node;
		tail = node;
		tail->next = NULL;
	}
	else {
		tail->next = node;			
		tail = node;
	}
	return node;
}
void AdressBook::Delete(unsigned int Nid)
{
	Node* elem = head;
	while (elem != NULL && elem->x.id == Nid)
	{
		delete head;
		head = elem->next;

	}
	if (elem != NULL)
	{
		while (elem->next != NULL)
		{
			int z = 1;
			if (elem->x.id == Nid)
			{
				if (tail != elem->next) {
					Node* node = elem->next->next;
					delete elem->next;
					elem->next = node;
				}
				else
				{
					delete elem->next;
					elem->next = NULL;
					tail = elem;
				}
				z = 0;
			}
			if (z != 0)
			{
				elem = elem->next;
			}
		}
	}
}
Node* AdressBook::FindId(unsigned int id)
{
	Node* elem = head;
	int z = 1;
	while (elem != NULL)
	{
		if (elem->x.id == id)
		{
			z = 0;
			return elem;
		}
		else
		{
			elem = elem->next;
		}
	}
	if (z == 1)
	{
		return NULL;
	}
}
Node* AdressBook::FindName(std::string name)
{
	Node* elem = head;
	int z = 1;
	while (elem != NULL)
	{
		if (elem->x.name == name)
		{
			z = 0;
			return elem;
		}
		else
		{
			elem = elem->next;
		}
	}
	if (z == 1)
	{
		return NULL;
	}
}
void AdressBook::Clear()
{
	class Node* p = head;
	if (p == NULL) return;
	while (p != NULL)
	{
		Node* d = p;
		p = d->next;
		delete d;
	}
	count = 0;
	head = NULL;
}
Node* AdressBook::operator+ (Node* node)
{
	tail->next = node;
	Node* elem = node;
	while (elem->next != NULL)
	{
		elem = elem->next;
	}
	tail = elem;
}
void AdressBook::operator- (unsigned int id)
{
	AdressBook::Delete(id);
}
Node* AdressBook::operator[](std::string str)
{
	int z = 0;
	for (int i = 0; i < str.size() && z == 0;++i)
	{
		if (str[i] <= 48 && str[i] >= 57)
		{
			z = 1;
		}
	}
	if (z == 0)
	{
		FindId(stoi(str));
	}
	else
	{
		FindName(str);
	}
}

