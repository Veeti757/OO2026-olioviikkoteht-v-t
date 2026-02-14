#include "student.h"
#include <iostream>
using namespace std;
Student::Student(string s, int i)
{
    age = i;
    name = s;
}

void Student::setAge(int i)
{
    age = i;
}

void Student::setName(string s)
{
    name = s;
}

int Student::getAge()
{
    return age;
}

void Student::printStudentInfo()
{
    cout << "Student: " << name << " " << "age: " << age << endl;
}


string Student::getName()
{
    return name;
}

