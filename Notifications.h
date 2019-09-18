#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"
#include "MessagePack.h"
#include <string>

namespace sict
{
	class Notifications
	{
		const Message** p_arrAddresses;	
		int max_num;
		int num_address;

	public:

		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();

		Notifications(int);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, Notifications& n);
}

#endif