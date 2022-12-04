#pragma once
#include <string>
using namespace std;

class Person {
    string name;
    uint32_t id;
    uint16_t grade;

public:
    Person(string, uint32_t, uint16_t);
    string getName();
    uint32_t getId();
    uint16_t getGrade();
};

