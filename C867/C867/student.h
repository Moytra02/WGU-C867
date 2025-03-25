#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;


class Student {
public:
	const static int daysArray = 3;
	Student();
	Student(string studentID, string firstName, string llastName, string email, int age, int days[], degree degreeType);
	void setID(string id);
	void setFirstName(string firstName);
	void setLastName(string lastname);
	void setEmail(string email);
	void setAge(int age);
	void setCourseDays(int num1, int num2, int num3);
	void setDegree(degree degreePr);
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int getCourse1();
	int getCourse2();
	int getCourse3();
	int getCourseDays();
	degree getDegree();
	void print();


private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int CourseDays[daysArray];
	degree Degree;
};

#endif