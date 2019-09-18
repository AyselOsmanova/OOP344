/*
Name: Aysel Osmanova
ID: 123615163
Email:aosmanova@myseneca.ca
Data:1.21.2019

*/

// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Chris Szalwinski
// 2019/01/08

#include <iostream>
#include "String.h"



namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}