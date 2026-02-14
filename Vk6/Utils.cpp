#include "Utils.h"
#include <iostream>

void printStudentInfo(const Student& s) {
    std::cout << "Name: " << s.getName()
    << ", Age: " << s.getAge() << std::endl;
}
