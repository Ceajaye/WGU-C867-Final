#pragma once
#include "student.h"


class Roster
{
	public:
		const static int numStudents = 5;
		Student* classRosterArray[numStudents]; //pointer array for roster of students
		int LastIndex = -1;


public:

	 Roster(); //constructor
	~Roster(); //destructor
	void parse(string row);
	void add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeprogram);
	void printAll();
	void printAverageDaysInCourse(string StudentID); //average days in course
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void remove(string StudentID);

};

