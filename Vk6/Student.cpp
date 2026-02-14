#include "Student.h"

Student::Student(const std::string& n, int a)
    : name(n), age(a) {}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}
