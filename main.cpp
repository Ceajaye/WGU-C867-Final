#pragma once
#include "roster.h"
#include "student.h"


int main()
{
	cout << "Course : Scripting and Programming Application C867" << std::endl;
	cout << "Language used: C++" << std::endl;
	cout << "WGU ID: 001495581" << std::endl;
	cout << "Name: Joseph Kennedy" << std::endl;
	cout << "\n";





	const string studentData[] =
	{ 
		
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Joseph,Kennedy,jken252@wgu.edu,39,34,25,45,SOFTWARE" 

	};


	const int numStudents = 5;
	Roster classRoster;



	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

	cout << "Class Roster: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	
	
	cout << "Displaying invalid Emails:" << std::endl;
	cout << "\n";
	classRoster.printInvalidEmails();
	cout << std::endl;

	
	
	cout << "Average days in course for each student is: " << std::endl;
	cout << "\n";
	for (int i = 0; i < numStudents; i++) 
	{

		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());



	}
	
	 

	cout << "\n";
	cout << "Displaying by degree program: " << degreeProgramStrings[2] << std::endl;
	cout << "\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	
	cout << std::endl;
	

	cout << "Removing Student A3" << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	
	cout << "Removing Student A3 again" << std::endl;
	classRoster.remove("A3");
	cout << std::endl;



	system("pause");
	return 0;


}

































