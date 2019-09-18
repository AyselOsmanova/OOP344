/*
Name: Aysel Osmanova
ID: 123615163
Email:aosmanova@myseneca.ca
Data:1.2.2019

*/

#include <iostream>
#include<iomanip>
#include<chrono>
#include "Timekeeper.h"
#include<cstring>



namespace sict {



	Timekeeper::Timekeeper() {
		static int no_of_obj = 0;
		count = 0;
		record->msg = nullptr;
		record->unit = nullptr;
		no_of_obj++;
	}

	void Timekeeper::start() {
		start_t = chrono::steady_clock::now();
	}

	void Timekeeper::stop() {
		stop_t = chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* other)
	{
		static int counter = 0;
		const char* Time_u = " seconds";
		record[counter].msg = other;
		record[counter].unit = Time_u;
		auto returnTime = record->duration_t = chrono::duration_cast<chrono::milliseconds>(stop_t - start_t);
		record[counter].duration_t = ((stop_t - start_t) / 1000);
		counter++;
		count++;
	}

	ostream& Timekeeper::report(ostream&os)const {

		os << "\nExecution Times: " << endl;
		for (int i = 0; i < count; i++) {

			os << record[i].msg << " " << setw(6) << record[i].duration_t.count() << record[i].unit << endl;
		}

		return os;
	}

	Timekeeper::~Timekeeper() {

	}


}

