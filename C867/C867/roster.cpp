#include <iostream>
#include <string>
#include <numeric>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>
#include <vector>
using namespace std;

//Class Constructor
Roster::Roster(int classSize) {
	this->classSize = classSize;
	this->index = 0;
	for (int i = 0; i < classSize; ++i) {
		this->classRosterArray[i] = new Student;
	}
	return;
}

//Get student ID from Student class
string Roster::GetStudentID(int index) {
	string studentID = classRosterArray[index]->getID();
	return studentID;
}

//Creating new Student objects in the classRosterArray
void Roster::parse(string studentData) {
	string studentID, firstName, lastName, email;
	int Age, course1, course2, course3;
	if (index < classSize) {

		classRosterArray[index] = new Student();

		int i = studentData.find(",");
		studentID = studentData.substr(0, i);
		classRosterArray[index]->setID(studentID);

		int j = i + 1;
		i = studentData.find(",", j);
		firstName = studentData.substr(j, i - j);
		classRosterArray[index]->setFirstName(firstName);

		j = i + 1;
		i = studentData.find(",", j);
		lastName = studentData.substr(j, i - j);
		classRosterArray[index]->setLastName(lastName);

		j = i + 1;
		i = studentData.find(",", j);
		email = studentData.substr(j, i - j);
		classRosterArray[index]->setEmail(email);

		j = i + 1;
		i = studentData.find(",", j);
		Age = stoi(studentData.substr(j, i - j));
		classRosterArray[index]->setAge(Age);

		j = i + 1;
		i = studentData.find(",", j);
		course1 = stoi(studentData.substr(j, i - j));

		j = i + 1;
		i = studentData.find(",", j);
		course2 = stoi(studentData.substr(j, i - j));

		j = i + 1;
		i = studentData.find(",", j);
		course3 = stoi(studentData.substr(j, i - j));
		classRosterArray[index]->setCourseDays(course1, course2, course3);

		j = i + 1;
		i = studentData.find(",", j);
		string type = studentData.substr(j, i - j);
		if (type == "SECURITY") {
			classRosterArray[index]->setDegree(SECURITY);
		}
		else if (type == "NETWORK") {
			classRosterArray[index]->setDegree(NETWORK);
		}
		else if (type == "SOFTWARE") {
			classRosterArray[index]->setDegree(SOFTWARE);
		}
		else {
			cout << "Unknown Degree." << endl;
		}
		++index;
	}
	return;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int course1, int course2, int course3, degree Degree)
{
	int daysArray[3] = { course1, course2, course3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysArray, Degree);//use full constructor
}

//Remove student
void Roster::remove(string studentID) {

	bool foundStudent = false;
	for (int i = 0; i < classSize; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (studentID == classRosterArray[i]->getID()) {
			classRosterArray[i] = nullptr;
			foundStudent = true;
			break;
		}
	}
	if (foundStudent == false) {
		cout << "The student with the ID: " << studentID << " was not found." << endl;
	}
	else if (foundStudent == true) {
		cout << "Removing " << studentID << ":" << endl;
	}
	return;
}

//Print all current students
void Roster::printAll() {
	cout << "Displaying all students: " << endl;
	for (int i = 0; i < classSize; ++i) {
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
	return;
}

//Print average number of days for a students 3 courses
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < classSize; ++i) {
		if (studentID == classRosterArray[i]->getID()) {
			int temparray[3] = { classRosterArray[i]->getCourse1(), classRosterArray[i]->getCourse2(), classRosterArray[i]->getCourse3() };
			double averageDays = (static_cast<double>(temparray[0]) + static_cast<double>(temparray[1]) + static_cast<double>(temparray[2])) / 3.0;
			cout << "Student " << studentID << "'s average: " << averageDays << endl;;
		}
	}
	return;
}

//Prints invalid emails
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i < classSize; ++i) {
		string email = classRosterArray[i]->getEmail();
		if ((email.find(' ') != string::npos) || (email.find('.') == string::npos) || (email.find('@') == string::npos)) {
			cout << email << " - is invalid." << endl;
		}
	}
	cout << endl;
	return;
}

//Prints all students 
void Roster::printByDegreeProgram(degree degree) {
	string degreeString;
	if (degree == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degree == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degree == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}
	cout << "Showing students in degree program: " << degreeString << endl;
	int numStudents = 0;
	for (int i = 0; i < classSize; ++i) {
		if (classRosterArray[i]->getDegree() == degree) {
			classRosterArray[i]->print();
			++numStudents;
		}
	}
	if (numStudents == 0) {
		cout << "No students with this degree found." << endl;
	}
	return;
}

//Destructor
Roster::~Roster() {
	return;
}