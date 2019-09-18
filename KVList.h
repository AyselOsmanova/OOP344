#ifndef _SICT_KVLIST_H
#define _SICT_KVLIST_H

namespace sict
{
	template <class T>
	class KVList
	{
		T* list;
		int num_element;
		int num_cur_element;
	public:
		KVList() : list{ nullptr }, num_element{ 0 }, num_cur_element{ 0 } {}
		KVList(int n) {
			if (n > 0) {
				num_element = { n };
				num_cur_element = { 0 };
				list = new T[n];
			}
			else
				throw "ERROR: Number of elements must be a positive number";
		}
		KVList(KVList&& other)
		{
			if (this != &other)
			{
				list = other.list;
				num_element = other.num_element;
				num_cur_element = other.num_cur_element;

				other.list = { nullptr };
				other.num_element = { 0 };
				other.num_cur_element = { 0 };
			}
		}
		~KVList()
		{
			delete[] list;
			list = { nullptr };
		}
		const T& operator[](size_t i) const
		{
			if (i > num_element)
				throw "ERROR: The index passed to the subscripting operator is out-of-bounds";
			return list[i];
		}
		template<typename F>
		void display(std::ostream& os, F f) const
		{
			for (int i = 0; i < num_element; i++)
				list[i].display(os, f);
		}
		void push_back(const T& t)
		{
			if (num_cur_element + 1 <= num_element)
				list[num_cur_element] = t;

			++num_cur_element;
		}
		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
	};
}

#endif