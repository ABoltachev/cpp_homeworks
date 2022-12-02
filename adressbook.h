#pragma once
#include <iostream>
class adressbook {
protected:
	uint32_t id;
	std::string name;
	uint16_t grade;
public:
		adressbook() = default;
		adressbook(uint32_t newid, const std::string &newname, uint16_t newgrade);
		void setid(uint32_t newid);
		void setname(const std::string &newname);
		void setgrade(uint16_t newgrade);
		uint32_t getid() const;
		std::string getname() const;
		uint16_t getgrade() const;
		void disp() const;
};
bool operator==(const adressbook& person1, const adressbook& person2);
bool operator!=(const adressbook& person, const adressbook& person2);
class adresslist {
public:
	struct node {
		adressbook data;
		node* next = nullptr;
	}*first = nullptr;
	adresslist() = default;
	adresslist(adresslist& list);
	void addnewnode(node* node);
	void addperson(const adressbook& data);
	void addperson(uint32_t uid, const std::string& name, uint16_t grade);
	node* delperson(uint32_t delid);
	void findperson(uint32_t findid);
	void findperson(const std::string& findname);
	void clearbook();
	adresslist& operator=(const adresslist& list);
	adresslist& operator+(adressbook& person);
	adresslist& operator-(adressbook& person);
	adressbook& operator[](int i);
};
void idbyindex(adresslist& list, int i);
void namebyindex(adresslist& list, int i);
std::ostream& operator<<(std::ostream& os, const adresslist& list);
std::ostream& operator<<(std::ostream& os, const adressbook& person);
std::istream& operator>>(std::istream& is,adressbook& person);