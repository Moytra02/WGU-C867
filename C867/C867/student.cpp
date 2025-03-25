#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
#include "student.h"

//default Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->CourseDays[0] = 0;
	this->CourseDays[1] = 0;
	this->CourseDays[2] = 0;
	this->Degree;
}

Student::Student(string studentID, string fName, string lName, string email, int age, int days[], degree degreeType)//full constructor
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArray; i++) this->CourseDays[i] = days[i];
	this->Degree = degreeType;
}

//Set student ID
void Student::setID(string id) {
	this->studentID = id;
	return;
}

//Set student's first name
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

//Set student's last name
void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

//Set student's email address
void Student::setEmail(string email) {
	this->email = email;
	return;
}

//Set student's age
void Student::setAge(int age) {
	this->age = age;
	return;
}

//Set number of days to complete a student's 3 courses
void Student::setCourseDays(int num1, int num2, int num3) {
	this->CourseDays[0] = num1;
	this->CourseDays[1] = num2;
	this->CourseDays[2] = num3;
	return;
}

//Sets student's degree program
void Student::setDegree(degree degreePr) {
	this->Degree = degreePr;
	return;
}

//Gets student ID
string Student::getID() {
	return studentID;
}

//Gets student's first name
string Student::getFirstName() {
	return firstName;
}

//Gets studetn's last name
string Student::getLastName() {
	return lastName;
}

//Gets studetn's email address
string Student::getEmail() {
	return email;
}

//Gets studetn's age
int Student::getAge() {
	return age;
}

//days to complete 3 course
int Student::getCourse1() {
	return CourseDays[0];
}

int Student::getCourse2() {
	return CourseDays[1];
}

int Student::getCourse3() {
	return CourseDays[2];
}

//Get's students degree program
degree Student::getDegree() {
	return Degree;
}

//Prints all student info in the required format
void Student::print() {
	string degreeString;
	if (Degree == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (Degree == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (Degree == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}

	cout << studentID << "   First Name: " << firstName << "   Last Name: " << lastName << "   Age: " << age << "   {" << CourseDays[0] << ", " << CourseDays[1]
		<< ", " << CourseDays[2] << "}   Degree Program: " << degreeString << "." << endl;

	return;
}