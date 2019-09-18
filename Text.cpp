/*
Name: Aysel Osmanova
ID: 123615163
Email:aosmanova@myseneca.ca
Data:1.2.2019

*/

#include <iostream>
#include <fstream>
#include "Text.h"

namespace sict {




	Text::Text() {
		line_Cont = nullptr;
		count = 0;
	}

	Text::Text(const char* fileName)
	{
		count = 0;
		line_Cont = nullptr;


		fstream file(fileName, ios::in);
		if (file.is_open())//If the file exists, 
		{
			string avalible_line_no;
			while (getline(file, avalible_line_no))
				count++;
			file.clear();
			file.seekp(0);
			line_Cont = new string[count]; //the one-argument constructor allocates memory for the number of lines contained in the file 
			for (int i = 0; i < count; i++)
			{
				getline(file, line_Cont[i]);
				auto fr = line_Cont[i].find('\r'); //and copies them into memory. 
				if (fr != string::npos)
					line_Cont[i].erase(fr, 1);
			}
			file.close();
		}

	}

	Text::Text(const Text& text)
	{
		count = 0;
		line_Cont = nullptr;
		*this = text;
	}

	Text& Text::operator=(const Text& text)
	{
		if (this != &text)
		{

			delete[] line_Cont;
			count = text.count;
			line_Cont = new  string[count];
			for (int i = 0; i < count; i++)
				line_Cont[i] = text.line_Cont[i];
		}
		return *this;
	}

	Text::Text(Text&& text)

	{
		count = 0;
		line_Cont = nullptr;
		*this = move(text);
	}

	Text& Text::operator=(Text&& text)
	{
		if (this != &text)//If the file does not exist, the Text object assumes a safe empty state. 
		{
			count = text.count;
			delete[] line_Cont;
			line_Cont = text.line_Cont;
			//deleting sourse data 
			text.line_Cont = nullptr;
			text.count= 0;
		}
		return *this;
	}

	Text::~Text()
	{
		delete[] line_Cont;
		line_Cont = nullptr;
	}

	size_t Text::size() const
	{
		return count;


	}
}