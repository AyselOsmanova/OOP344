#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict
{
	Notifications::Notifications(): p_arrAddresses{ nullptr }, max_num{ 0 }, num_address{ 0 }{}

	Notifications::Notifications(const Notifications& other)
	{
		*this = other;
	}

	Notifications& Notifications::operator=(const Notifications& other)
	{
		if (this != &other)
		{
			delete[] p_arrAddresses;
			max_num = other.max_num;
			num_address = other.num_address;
			for (int i = 0; i < other.num_address; i++)
				p_arrAddresses[i] = other.p_arrAddresses[i];
		}
		return *this;
	}
	Notifications::Notifications(Notifications&& other)
	{
		*this = std::move(other);
	}
	Notifications& Notifications::operator=(Notifications&& other)
	{
		if (this != &other)
		{
			p_arrAddresses = other.p_arrAddresses;
			max_num = other.max_num;
			num_address = other.num_address;

			other.p_arrAddresses = { nullptr };
			other.max_num = { 0 };
			other.num_address = { 0 };
		}
		return *this;
	}
	Notifications::~Notifications()
	{
		delete[] p_arrAddresses;
		p_arrAddresses = { nullptr };
	}
	Notifications::Notifications(int max_numOfAggregation)
	{
		if (max_numOfAggregation > 0)
		{
			p_arrAddresses = new const Message*[max_numOfAggregation];
			max_num = max_numOfAggregation;
			num_address = { 0 };
		}
		else
			*this = Notifications();
	}
	Notifications& Notifications::operator+=(const Message& messagedToAdd)
	{
		bool space_available = num_address < max_num;

		if (!messagedToAdd.empty() && space_available)
		{
			p_arrAddresses[num_address] = &messagedToAdd;	
			++num_address;
		}

		return *this;
	}
	Notifications& Notifications::operator-=(const Message& msg_Remove)
	{
		for (int i = 0; i < num_address; i++)
		{
			bool address_found = p_arrAddresses[i] == &msg_Remove;

			if (address_found)
			{
			p_arrAddresses[i] = { nullptr };
				for (int x = i; x < num_address - 1; ++x)
					p_arrAddresses[x] = p_arrAddresses[x + 1];

				p_arrAddresses[num_address - 1] = { nullptr };
			}
		}
			num_address--;
		return *this;
	}
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < num_address; i++)
			(*p_arrAddresses[i]).display(os);
	}
	size_t Notifications::size() const
	{
		return num_address;
	}
	std::ostream & operator<<(std::ostream & os, Notifications & n)
	{
		n.display(os);
		return os;
	}
}