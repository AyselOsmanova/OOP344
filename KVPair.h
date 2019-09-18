#ifndef _SICT_KVPAIR_H
#define _SICT_KVPAIR_H
#include <iostream>
#include <iomanip>
using namespace std;
extern int fieldWidth;

namespace sict
{
	template<typename K, typename V>
	class KVPair
	{
		K key;
		V value;
	public:
		KVPair() : key{}, value{} {}
		KVPair(const K& k_key, const V& v_value) : key{ k_key }, value{ v_value } {}
		template<typename F>void display(ostream& os, F f) const
		{
			os << left << setw(fieldWidth) << key << " " << ":" << " " << right << setw(fieldWidth) << value << setw(fieldWidth) << f(value) << endl;
		}
	};
}

#endif