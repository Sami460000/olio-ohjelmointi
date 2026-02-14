#pragma once
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    Student(const std::string& n, int a);

    std::string getName() const;
    int getAge() const;
};
