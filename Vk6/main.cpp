#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Student.h"
#include "Utils.h"

using namespace std;

int main()
{
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection) {
        case 0: {
            string name;
            int age;

            cout << "Give name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Give age: ";
            cin >> age;

            studentList.emplace_back(name, age);
            break;
        }

        case 1:
            for (const auto& s : studentList) {
                cout << s.getName() << endl;
            }
            break;

        case 2:
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getName() < b.getName();
                 });
            for (const auto& s : studentList) {
                printStudentInfo(s);
            }
            break;

        case 3:
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getAge() < b.getAge();
                 });
            for (const auto& s : studentList) {
                printStudentInfo(s);
            }
            break;

        case 4: {
            string name;
            cout << "Give name to find: ";
            cin >> ws;
            getline(cin, name);

            auto it = find_if(studentList.begin(), studentList.end(),
                              [&](const Student& s) {
                                  return s.getName() == name;
                              });

            if (it != studentList.end()) {
                printStudentInfo(*it);
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}
