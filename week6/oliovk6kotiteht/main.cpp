#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;
         string name;
        int age;
        string studentToFind;
        switch(selection)
        {
        case 0:
            cout << "Student name ?" << endl;
            cin >> name;
            cout << "Student age ?" << endl;
            cin >> age;
            studentList.emplace_back(name,age);
            break;

        case 1:
            for(auto it = studentList.begin(); it!=studentList.end();it++)
            {
                cout << "Student " << it->getName() << " age " << it->getAge() << endl;
            }
            break;

        case 2:
            sort(studentList.begin(),studentList.end(),[](Student & a, Student & b){return a.getName() < b.getName();});// Järjestä StudentList vektorin Student oliot nimen mukaan
            for(auto it = studentList.begin(); it!=studentList.end();it++)
            {
                it->printStudentInfo();
            }
            break;

        case 3:
            sort(studentList.begin(),studentList.end(),[](Student & s, Student & c){return s.getAge() < c.getAge();});
            for(auto it = studentList.begin(); it!=studentList.end();it++)
            {
                it->printStudentInfo();
            }
            break;
        case 4:
        {
            cout << "Student to be found name = ?" << endl;
            cin >> studentToFind;
            auto it2 = find_if(studentList.begin(),studentList.end(),[studentToFind](Student & d){return d.getName() == studentToFind;});
            if(it2 != studentList.end())
            {
                it2->printStudentInfo();
            }
            else
                cout << "Not found" << endl;
            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
    }
}while(selection < 5);

    return 0;
}
