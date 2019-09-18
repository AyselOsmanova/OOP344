
/*************************************************************************
// SubjectCode Deliverable  Name
// File: String.h
// Version: Version Goes here
// Date: 1.21.2019
// Author: Aysel Osmanova
// Description:
// This file contains declaration of String constructor and query named display,non-friend helper function
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/
#include <iostream>
#ifndef SICT_STRING_H
#define SICT_STRING_H

namespace sict {

	
	class String {
	private:
		char *astring;
	public:
		String(const char *other_string);
		void display(std::ostream &os) const; 
	};
	std::ostream &operator<<(std::ostream &os, const String &string);
}


#endif
