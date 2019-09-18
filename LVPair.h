#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H
#include <iostream>
#include <string>

namespace sict
{
	template <typename L, typename V>
	class LVPair
	{
		L m_label;
		V m_value;
	public:
		LVPair(): m_label{}, m_value{}{}
		LVPair(const L& label, const V& value): m_label(label), m_value(value){}

		const L& getLabel() const 
		{
			return m_label; 
		}
		const V& getValue() const 
		{
			return m_value;
		}

		virtual void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		static V initialValue;
		static size_t minWidth;
	public:
		SummableLVPair(){}

		SummableLVPair(const L& label, const V& v)
			: LVPair<L, V>(label, v)
		{
			if (minWidth < label.size())
				minWidth = label.size() + 1;
		}

		static const V& getInitialValue()
		{
			return initialValue;
		}

		V sum(const L& label, const V& sum) const
		{
			return LVPair<L, V>::getValue() + sum;
		}

		void display(std::ostream& os) const
		{
			os.setf(std::ios::left);
			os.width(minWidth);
			os << LVPair<L, V>::getLabel() << ": " << LVPair<L, V>::getValue() << std::endl;
			os.unsetf(std::ios::left);
		}

	};

	// Replace with static member as per: https://en.cppreference.com/w/cpp/language/template_specialization
	// template<> 
	// SummableLVPair<std::string, std::string>::SummableLVPair(const std::string& label, const std::string& v)
	// 	: SummableLVPair(label, v)
	// {
	// }
	// template<> 
	// SummableLVPair<std::string, int>::SummableLVPair(const std::string& label, const int& v)
	// 	: SummableLVPair(label, v)
	// {
	// }

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const
	{
		return (value + " " + LVPair<std::string, std::string>::getValue());
	}
}


#endif 