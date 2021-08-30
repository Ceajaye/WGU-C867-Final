#pragma once
#include "student.h"

Student::Student() //constructor with no parameters

{
	this->StudentID = ""; //using empty string value instead of NULL pointer, which would be nothing
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	this->Age = 0;
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY; // default value is SECURITY
}

Student::Student(string StudentId, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram) //full constructor

{
	this->StudentID = StudentId;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->EmailAddress = EmailAddress;
	this->Age = Age;
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = Days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} //destructor does not produce or effect anything

//getters

string Student::getStudentID() { return this->StudentID; }
string Student::getFirstName() { return this->FirstName; }
string Student::getLastName() { return this->LastName; }
string Student::getEmailAddress() { return this->EmailAddress; }
int Student::getAge() { return this->Age; };
int* Student::getDays() { return this->Days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//setters

void Student::setStudentID(string StudentID) { this->StudentID = StudentID; }
void Student::setFirstName(string FirstName) { this->FirstName = FirstName; }
void Student::setLastName(string LastName) { this->LastName = LastName; }
void Student::setEmailAddress(string EmailAddress) {this->EmailAddress = EmailAddress;}
void Student::setAge(int Age) { this->Age = Age; }
void Student::setDays(int Days[])
{

	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = Days[i];

}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeProgram = degreeprogram; }

void Student::printHeader()//to print student data
{
	cout << "Output format: StudentID|FirstName|LastName|Email|Age|DaysInCourse|DegreeProgram\n";
}

void Student::print()
{
	cout << this->getStudentID() << '\t'; // tab separates the output values
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';

};























