#include "adressbook.h"
Friend::Friend(uint32_t newid, const std::string &newname, uint16_t newgrade): id(newid), name(newname),grade(newgrade) {
}
void Friend::setid(uint32_t newid) {
    id = newid;
}
void Friend::setname(const std::string &newname) {
    name = newname;
}
void Friend::setgrade(uint16_t newgrade) {
    grade = newgrade;
}
uint32_t Friend::getid() const {
    return id;
}
std::string Friend::getname() const {
    return name;
}
uint16_t Friend::getgrade() const {
    return grade;
}
void Friend::disp() const {
    std::cout << "id:" << this->id << std::endl;
    std::cout << "name:" << this->name << std::endl;
    std::cout << "grade:" << this->grade << std::endl;
}
bool operator==(const Friend & person1, const Friend& person2) {
    if (person1.getid() == person2.getid() and person1.getname() == person2.getname() and person1.getgrade() == person2.getgrade()) {
        return true;
    }
    else {
        return false;
    }
}
bool operator!=(const Friend& person1, const Friend& person2) {
    if (person1.getid()!= person2.getid() or person1.getname() != person2.getname() or person1.getgrade() != person2.getgrade()) {
        return true;
    }
    else {
        return false;
    }
}


adresslist::adresslist(adresslist& list) {
    this->first=list.first;
}

void adresslist::addnewnode(node* node) {
    if (first) {
        adresslist::node *newnode = first;
        while (newnode->next) {
            newnode = newnode->next;
        }
        newnode->next = node;
    }
    else {
        first = node;
    }
}
void adresslist::addperson(const Friend& data) {
    node* node = new adresslist::node;
    node->data = data;
    addnewnode(node);
}

void adresslist::addperson(uint32_t uid,const std::string& name, uint16_t grade) {
    addperson(Friend(uid, name, grade));
}
adresslist::node* adresslist::delperson(uint32_t delid) {
    node* head = first;
    node* prev = nullptr;
    while (head) {
        if (head->data.id == delid) {
            if (first == head) {
                head = first->next;
                first = head;
                return head;
            }
            else {
                prev->next = head->next;
                head->next = nullptr;
                return first;
            }
        }
        else {
            prev = head;
            head = head->next;
        }
    }
    std::cout << delid << "not found" << std::endl;
}
void adresslist::findperson(uint32_t findid) {
    node* head = first;
    int count = 0;
    while (head) {
        if (head->data.id == findid) {
            head->data.disp();
            count++;
            head = head->next;
        }
        else {
            head= head->next;
        }
    }
    if (count == 0) {
        std::cout <<"id: " << findid << ' ' << "Not found" << std::endl;
    }
}
void adresslist::findperson(const std::string& findname) {
    node* head = first;
    int count = 0;
    while (head) {
        if (head->data.name == findname) {
            head->data.disp();
            count++;
            head = head->next;
        }
        else {
            head = head->next;
        }
    }
    if (count == 0) {
        std::cout<<"name: " << findname << ' ' << "Not found" << std::endl;
    }
}
void adresslist::clearbook() {
    first->next = nullptr;
    first = nullptr;
}

adresslist& adresslist::operator=(const adresslist& list) {
    if (this == &list) {
        return *this;
    }
    first = list.first;
    return *this;
}
adresslist& adresslist::operator+(Friend& person) {
    this->addperson(person);
    return *this;
}
adresslist& adresslist::operator-(Friend& person) {
    this->delperson(person.id);
    return *this;
}
Friend& adresslist::operator[](int i) {
    bool flag = true;
    node* head = first;
    for (int j = 0; j < i; j++) {
        if (head) {
            if (j == 0) {
                continue;
            }
            head = head->next;
        }
        else {
            std::cout << "index out of range" << std::endl;
            flag = false;
            break;
   
        }
    }
    if (flag = true) { 
        return head->data; 
    }
    else {
        return first->data; 
    }
}
const Friend& adresslist::operator[](int i)const {
    bool flag = true;
    node* head = first;
    for (int j = 0; j < i; j++) {
        if (head) {
            if (j == 0) {
                continue;
            }
            head = head->next;
        }
        else {
            std::cout << "index out of range" << std::endl;
            flag = false;
            break;

        }
    }
    if (flag = true) {
        return head->data;
    }
    else {
        return first->data;
    }
}
std::ostream& operator<<(std::ostream& os,const adresslist& list) {
    adresslist::node* head = list.first;
    while (head) {
        std::cout <<"id: " << head->data.getid() << std::endl;
        std::cout <<"name: " << head->data.getname() << std::endl;
        std::cout <<"grade: "<< head->data.getgrade() << std::endl << std::endl;
        head = head->next;
    }
    return std::cout;
}
std::ostream& operator<<(std::ostream& os, const Friend& person) {
    std::cout << "id: " << person.getid() << std::endl;
    std::cout << "name: " << person.getname() << std::endl;
    std::cout << "grade: " << person.getgrade() << std::endl;
    return std::cout;
}
std::istream& operator>>(std::istream& is, Friend& person) {
    uint32_t id;
    std::string name;
    uint16_t grade;
    std::cin >>id >> name>> grade;
    person.setid(id);
    person.setname(name);
    person.setgrade(grade);
    return std::cin;
}