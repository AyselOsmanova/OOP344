// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					Product* p = new Product(desc[i].desc, price[j].price);
					p->validate();
					priceList += p;
					delete p;	
					p = { nullptr };
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> p{ new Product(desc[i].desc, price[j].price) };
					p->validate();
					priceList += p;
				}
			}
		}
		return priceList;
}

}