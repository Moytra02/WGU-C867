#include <iostream>
#include <string>
#include "degree.h"
#include <array>
#include "student.h"
using namespace std;


class Roster {
public:
	int lastIndex = -1;
	const static int studentData = 5;
	Student* classRosterArray[studentData];
	Roster(int classSize);
	string GetStudentID(int index);
	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string email, int age, int course1, int course2, int course3, degree Degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(degree degree);
	~Roster();
	int classSize;
	int index;

};