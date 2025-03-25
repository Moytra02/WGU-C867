#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main()
{
    cout << "C867: Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001172014 " << endl;
    cout << "Name: Artyom Basov" << endl << endl;

    //Student Data
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Artyom,Basov,abasov1@wgu.edu,20,22,14,32,SOFTWARE"
    };

    //Creating Class Roster
    Roster* classRoster = new Roster(5);

    //populating studentData with each student
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };

    //Printing class roster
    classRoster->printAll();

    //Printing invalid emails
    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;

    //Printing students with SOFTWARE Degree
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;

    //Removing Student A3
    classRoster->remove("A3");
    cout << endl;

    //Printing new class roster
    classRoster->printAll();
    cout << endl;

    //Testing "student not found" error
    classRoster->remove("A3");
    cout << endl;

    //Destructor
    classRoster->~Roster();
    delete classRoster;

}