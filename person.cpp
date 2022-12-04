#include <string>
#include "person.h"

using namespace std;

Person::Person(string namee, uint32_t idd, uint16_t gradee) {
    name = namee;
    id = idd;
    grade = gradee;
}

string Person::getName() {
    return name;
}

uint32_t Person::getId() {
    return id;
}

uint16_t Person::getGrade() {
    return grade;
}



