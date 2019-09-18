/*
Name: Aysel Osmanova
ID: 123615163
Email:aosmanova@myseneca.ca
Data:1.2.2019

*/

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include<iostream>
#include <chrono>

using namespace std;
namespace sict {
	const int MAX_REC = 10;


	class Timekeeper {
		int count;
		chrono::steady_clock::time_point start_t;
		chrono::steady_clock::time_point stop_t;

		struct {
			const char* msg;
			const char* unit;
			std::chrono::steady_clock::duration duration_t;

		}record[MAX_REC];


	public:

		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		std::ostream& report(std::ostream&)const;
		~Timekeeper();
	};
}

#endif