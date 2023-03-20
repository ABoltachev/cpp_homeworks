#pragma once
#include <iostream>
class adresslist;
class Friend {
protected:
	uint32_t id;
	std::string name;
	uint16_t grade;
public:
	friend adresslist;
	Friend() = default;
	Friend(uint32_t newid, const std::string &newname, uint16_t newgrade);
	void setid(uint32_t newid);
	void setname(const std::string &newname);
	void setgrade(uint16_t newgrade);
	uint32_t getid() const;
	std::string getname() const;
	uint16_t getgrade() const;
	void disp() const;
};
bool operator==(const Friend& person1, const Friend& person2);
bool operator!=(const Friend& person, const Friend& person2);
class adresslist {
public:
	struct node {
		Friend data;
		node* next = nullptr;
	}*first = nullptr;
	adresslist() = default;
	adresslist(adresslist& list);
	void addnewnode(node* node);
	void addperson(const Friend& data);
	void addperson(uint32_t uid, const std::string& name, uint16_t grade);
	node* delperson(uint32_t delid);
	void findperson(uint32_t findid);
	void findperson(const std::string& findname);
	void clearbook();
	adresslist& operator=(const adresslist& list);
	adresslist& operator+(Friend& person);
	adresslist& operator-(Friend& person);
	Friend& operator[](int i);
	const Friend& operator[](int i) const;
};
std::ostream& operator<<(std::ostream& os, const adresslist& list);
std::ostream& operator<<(std::ostream& os, const Friend& person);
std::istream& operator>>(std::istream& is,Friend& person);