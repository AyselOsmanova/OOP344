/*
Name: Aysel Osmanova
ID: 123615163
Email:aosmanova@myseneca.ca
Data:1.2.2019

*/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
#include <string>
using namespace std;
namespace sict {




	class Text {
		int count;
		string* line_Cont; //manages a dynamically allocated array of strings.  


	public:
		Text();
		Text(const char* fileName);//receives the address of a C-style null terminated string containing the name of a file
		Text(const Text& text);
		Text& operator=(const Text& text);
		Text(Text&& text);
		Text& operator=(Text&& text);
		~Text();
		size_t size() const; //	a member function named size_t size() const that returns the number of records of text data
	};




}



#endif