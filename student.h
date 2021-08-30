#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student
{
public:

	const static int DaysInCourse = 3; //constant for array
	

private:

	string StudentID;
	string FirstName;
	string LastName;
	string EmailAddress;
	int Age;
	int Days[DaysInCourse];
	DegreeProgram degreeProgram;

public:
	
	Student(); //constructor
	Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram); //full constructor
	~Student(); //destructor


	//accessors-getters

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();



	//mutator-setters

	void setStudentID(string StudentID);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmailAddress(string EmailAddress);
	void setAge(int Age);
	void setDays(int Days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);



	static void printHeader(); //to print specific student data

	void print();

};


