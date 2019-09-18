/*
Name: Aysel Osmanova
ID: 123615163
Email:aosmanova@myseneca.ca
Data:2.4.2019

*/


#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
extern int FW;
extern int ND;

namespace sict {
	template<class T>
	class DataTable {
		std::vector<std::pair<T, T>> data;

	private:
	
		std::pair<T, T> sumsOf_x_y() const {
			T t_x = { 0 };
			T t_y = { 0 };

			t_x += std::accumulate(data.begin(), data.end(), static_cast<T>(0), [](auto& i, auto& j) { 
				return i + j.first;
			});

			t_y += std::accumulate(data.begin(), data.end(), static_cast<T>(0), [](auto& i, auto& j) {
				return i + j.second;
			});

			return std::make_pair(t_x, t_y);
		}

		std::pair<std::vector<T>, std::vector<T>> xy_collection() const {
			std::vector<T> x;
			std::vector<T> y;

			for (auto& i : data) {

				x.push_back(std::get<0>(i));
				y.push_back(std::get<1>(i));

			}

			return std::make_pair(x, y);
		}

		
		T mean() const {
			std::pair<T, T> t_xy = sumsOf_x_y();
			return std::get<1>(t_xy) / data.size();
		}


		T sigma() const {
			T total = { 0 };
			std::pair<std::vector<T>, std::vector<T>> v_xy = xy_collection();
			std::vector<T> y = std::get<1>(v_xy);

			std::for_each(y.begin(), y.end(), [&](T& n) {
				total += std::pow(n - mean(), 2);
			});

			return std::sqrt(total / (y.size() - 1));
		}

		
		T median() const {
			std::pair<std::vector<T>, std::vector<T>> xy = xy_collection();
			std::vector<T> y = std::get<1>(xy);
			std::sort(y.begin(), y.end());

			return y[y.size() / 2];
		}

		
		T slope() const {
			size_t n = data.size();
			std::pair<T, T> sumsOf_xy = sumsOf_x_y();
			std::pair<std::vector<T>, std::vector<T>> v_xy = xy_collection();
			std::vector<T> x = std::get<0>(v_xy);

			T sumOf_x = std::get<0>(sumsOf_xy);
			T sumOf_y = std::get<1>(sumsOf_xy);
			T sumOfProd_a_b = { 0 };

			std::for_each(data.begin(), data.end(), [&](auto& i) {
				sumOfProd_a_b += i.first * i.second;
			});

			T sum_squared_x = { 0 };
			std::for_each(x.begin(), x.end(), [&](auto& i) {
				sum_squared_x += i * i;
			});

			T numerator = (n * sumOfProd_a_b) - (sumOf_x * sumOf_y);
			T denominator = ((n * sum_squared_x) - (sumOf_x * sumOf_x));

			return numerator / denominator;
		}

		T intercept() const {
			size_t n = data.size();
			std::pair<T, T> sumsOf_xy = sumsOf_x_y();
			T sumOf_x = std::get<0>(sumsOf_xy);
			T sumOf_y = std::get<1>(sumsOf_xy);

			return (sumOf_y - (slope() * sumOf_x)) / n;
		}
	public:

		
		explicit DataTable(std::ifstream& file) {
			bool keepReading = true;
			if (file) {
				T x = { 0 };
				T y = { 0 };
				do {
					if (file >> x >> y)
						data.push_back(std::make_pair(x, y));
					else
						keepReading = false;
				} while (keepReading);
			}
		}

	
		void displayData(std::ostream& os) {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

			for (const auto& i : data)
				os << std::fixed << std::setprecision(ND) << std::setw(FW) << std::right << std::get<0>(i) <<
				std::setprecision(ND) << std::setw(FW) << std::get<1>(i) << std::endl;
		}

	
		void displayStatistics(std::ostream& os) {
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y mean    = " << std::setw(FW) << mean() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y sigma   = " << std::setw(FW) << sigma() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y median  = " << std::setw(FW) << median() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  slope     = " << std::setw(FW) << slope() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  intercept = " << std::setw(FW) << intercept() << std::endl;
		}

	};
}
#endif 