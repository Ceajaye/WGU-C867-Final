#pragma once
#include <string> 



enum DegreeProgram {SECURITY, NETWORK, SOFTWARE }; //Defines an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, SOFTWARE and OTHER

//Below content creates an array of strings for each degree, to output string values to screen
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };