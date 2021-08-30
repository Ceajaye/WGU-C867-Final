#pragma once
#include "roster.h"

Roster::Roster()
{
}



void Roster::parse(string studentData)
{
	DegreeProgram degreeProgram = SECURITY; //default value
	if (studentData.back() == 'K') degreeProgram = NETWORK; //checks the back character of degreeProgram to identify which program a student is in
	else if (studentData.back() == 'E') degreeProgram = SOFTWARE; // checks the back character of degreeProgram to identify which program a student is in

	int rhs = studentData.find(",");   //parsing student data
	string StudentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EmailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days1 = stoi(studentData.substr(lhs, rhs - lhs));
				

    lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days3 = stoi(studentData.substr(lhs, rhs - lhs));


	add(StudentID, FirstName, LastName, EmailAddress, Age, Days1, Days2, Days3, degreeProgram); //add student object

}


void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram)
{
	int Days[3] = { Days1, Days2, Days3 }; // DaysInCourse put in array for constructor

	classRosterArray[++LastIndex] = new Student(StudentID, FirstName, LastName, Email, Age, Days, degreeProgram);
}


void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDays()[0]; cout << '\t';
		cout << classRosterArray[i]->getDays()[1]; cout << '\t';
		cout << classRosterArray[i]->getDays()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}


void Roster::printAverageDaysInCourse(string StudentID)
{
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID()==StudentID)
		{
			cout << " Student ID: ";
			cout << StudentID ;
			cout << ",";
			cout << " averages ";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2])/3;
			cout << " days in a course.";
			
			
		}

	}cout << endl;
}



void Roster::printInvalidEmails()
{	
		bool any = false;

	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		string EmailAddress = (classRosterArray[i]->getEmailAddress());
		if (EmailAddress.find("@") == string::npos || (EmailAddress.find('.') == string::npos) || (EmailAddress.find(' ') != string::npos))
		{
			any = true;
			cout << EmailAddress << ": " << classRosterArray[i]->getEmailAddress() << std::endl;


		}
	}
	if (!any) cout << "NONE" << std::endl;


}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::LastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
	

}


void Roster::remove(string StudentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::LastIndex--;



		}

	}
	if (success)
	{
		cout << StudentID << " removed from roster." << endl << std::endl;
		this->printAll();
	}

	else cout << StudentID << " studentID not found" << std::endl << std::endl;

}

Roster::~Roster()
{
	cout << "Destructor Called" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}

};














	





