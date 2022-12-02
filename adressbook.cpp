#include "adressbook.h"
adressbook::adressbook(uint32_t newid, const std::string &newname, uint16_t newgrade): id(newid), name(newname),grade(newgrade) {
}
void adressbook::setid(uint32_t newid) {
    id = newid;
}
void adressbook::setname(const std::string &newname) {
    name = newname;
}
void adressbook::setgrade(uint16_t newgrade) {
    grade = newgrade;
}
uint32_t adressbook::getid() const {
    return id;
}
std::string adressbook::getname() const {
    return name;
}
uint16_t adressbook::getgrade() const {
    return grade;
}
void adressbook::disp() const {
    std::cout << "id:" << this->getid() << std::endl;
    std::cout << "name:" << this->getname() << std::endl;
    std::cout << "grade:" << this->getgrade() << std::endl;
}
bool operator==(const adressbook & person1, const adressbook& person2) {
    if (person1.getid() == person2.getid() and person1.getname() == person2.getname() and person1.getgrade() == person2.getgrade()) {
        return true;
    }
    else {
        return false;
    }
}
bool operator!=(const adressbook& person1, const adressbook& person2) {
    if (person1.getid() != person2.getid() or person1.getname() != person2.getname() or person1.getgrade() != person2.getgrade()) {
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
void adresslist::addperson(const adressbook& data) {
    node* node = new adresslist::node;
    node->data = data;
    addnewnode(node);
}

void adresslist::addperson(uint32_t uid,const std::string& name, uint16_t grade) {
    addperson(adressbook(uid, name, grade));
}
adresslist::node* adresslist::delperson(uint32_t delid) {
    node* head = first;
    node* prev = nullptr;
    while (head) {
        if (head->data.getid() == delid) {
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
        if (head->data.getid() == findid) {
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
        if (head->data.getname() == findname) {
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
void idbyindex(adresslist& list, int i) {
    adresslist::node* head = list.first;
    bool flag = true;
    for (int j = 0; j < i; j++) {
        if (head) {
            head = head->next;
        }
        else {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << head->data.getid();
    }
    else {
        std::cout << "Book don't have " << i << "st/nd/rd/th id" << std::endl;
    }
}
void namebyindex(adresslist& list, int i) {
    adresslist::node* head = list.first;
    bool flag=true;
    for (int j = 0; j < i; j++) {
        if (head) {
            head = head->next;
        }
        else {
            flag=false;
            break;
        }
    }
    if (flag) {
        std::cout << head->data.getname();
    }
    else {
        std::cout << "Book don't have " << i << "st/nd/rd/th name" << std::endl;
    }
}
adresslist& adresslist::operator=(const adresslist& list) {
    if (this == &list) {
        return *this;
    }
    first = list.first;
    return *this;
}
adresslist& adresslist::operator+(adressbook& person) {
    this->addperson(person);
    return *this;
}
adresslist& adresslist::operator-(adressbook& person) {
    this->delperson(person.getid());
    return *this;
}
adressbook& adresslist::operator[](int i) {
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
std::ostream& operator<<(std::ostream& os, const adressbook& person) {
    std::cout << "id: " << person.getid() << std::endl;
    std::cout << "name: " << person.getname() << std::endl;
    std::cout << "grade: " << person.getgrade() << std::endl;
    return std::cout;
}
std::istream& operator>>(std::istream& is, adressbook& person) {
    uint32_t id;
    std::string name;
    uint16_t grade;
    std::cin >>id >> name>> grade;
    person.setid(id);
    person.setname(name);
    person.setgrade(grade);
    return std::cin;
}