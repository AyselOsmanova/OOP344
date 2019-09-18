
/*************************************************************************
// SubjectCode Deliverable  Name
// File: w1.cpp
// Version: Version Goes here
// Date: 1.21.2019
// Author: Aysel Osmanova
// Description:
// This is contain main () function 
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <iostream>
#include <fstream>
#include "process.h"
#include "String.h"

extern int INITIAL;
int main(int argc, char* argv[]) {

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}


	std::cout << std::endl;
	if (argc < 0) {
		std::cout << "***Insufficient number of arguments***";
		return 1;
	}

	for (size_t i = 1; i < static_cast<size_t> (argc); i++) {

		sict::process(argv[i]);
	}

	
	return 0;
}
