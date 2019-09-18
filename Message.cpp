#include <iostream>
#include <string>
#include "Message.h"

using namespace std;
using namespace sict;

Message::Message() : tweet{ "" }, sender{ "" }, message{ "" }, receiver{ "" }, to_recipient{ true }, p{ 0 } {}

Message::Message(const std::string& str) : message{ str }, to_recipient{ message.find('@') != string::npos ? true : false }, p{ 0 }
{
	size_t next_space = { message.find(' ') };
	sender = { message.substr(p, next_space) };

	if (sender.size() > 0 && sender.size() != message.size())
	{
		if (to_recipient)
		{
			p = next_space;
			size_t at_pos = { message.find('@', p + 1) };
			next_space = { message.find(' ', p + 1) };

			receiver = { message.substr(at_pos + 1, next_space - at_pos) };
		}
		p = { next_space };
		tweet = message.substr(p + 1, message.size());
	}
	else
	{
		*this = Message();
	}
}

bool Message::empty() const
{
	if (tweet.size() < 1)
		return true;
	else
		return false;
}

void Message::display(ostream& os) const
{
	if (message.size())
	{
		os << ">User  : " << sender << std::endl;
		if (receiver.size() > 0)
			os << " Reply : " << receiver << std::endl;
		os << " Tweet : " << tweet << std::endl;
	}
}

