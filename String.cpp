// SubjectCode Deliverable  Name
// File: String.cpp
// Version: Version Goes here
// Date: 1.21.2019
// Author: Aysel Osmanova
// Description:
// This file contains dynamically allocation of memory,a query named display(), a helper non-friend operator
// Revision History

#include <iostream>
#include<cstring>
#include "String.h"

using namespace std;
static int c = 3;

namespace sict {

	
	String::String(const char *other_string)
	{

		if (other_string == nullptr){
			astring = nullptr;
                  }
		else
                 {
			astring = new char[sizeof(other_string)];
                  }
		for (size_t a = 0; a < sizeof(other_string); a++) {
			astring[a] = other_string[a];
			astring[sizeof(other_string)] = '\0';
		}
		
	}

	void String::display(std::ostream &os) const
	{
		os << astring;
	}

	std::ostream & operator<<(std::ostream &os, const String &string) 
	{
		os << c++ << ": "; 
		string.display(os);
		return os;
	}
}

