#ifndef _SICT_LIST_H
#define _SICT_LIST_H
#include <iostream>
#include <cstddef>
using namespace std;
namespace sict
{
	template <class T, int N>
	class List
	{
		T array_list[N];
		size_t num_element = { 0u };
	public:
		size_t size() const
		{
			return num_element;
		}
		const T& operator[](size_t i) const
		{
			const T& t = array_list[i];
			return t;
		}
		void operator+=(const T& t)
		{
			if (num_element < N)
			{
				array_list[num_element] = t;
				num_element++;
			}
		}
	};

	template<typename T, typename L, typename V, int N>
	class LVList : public List<T, N>
	{
	public:

		V accumulate(const L& label) const
		{
			
		    SummableLVPair<L, V> currentSummable;
			V sumOfElementsInCurrentLVList =  currentSummable.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&)*this).size(); ++i)
			{
				// If the labels match, append the values
				if (label == ((List<T, N>&)*this)[i].getLabel())
					sumOfElementsInCurrentLVList = ((List<T, N>&)*this)[i].sum(label, sumOfElementsInCurrentLVList);
			}

			return sumOfElementsInCurrentLVList;
		}
	};
}

#endif