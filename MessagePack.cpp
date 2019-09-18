#include <iostream>
#include <utility>
#include "Message.h"
#include "MessagePack.h"

namespace sict
{
	MessagePack::MessagePack(): message{ nullptr }, num_element{ 0 }{}
	MessagePack::MessagePack(const MessagePack& obj){*this = obj;}
	MessagePack & MessagePack::operator=(const MessagePack& obj)
	{
		if (this != &obj){
			delete[] message;
			num_element = obj.num_element;

			for (int i = 0; i < num_element; i++)
				message[i] = obj.message[i];
		}
		return *this;
	}
	MessagePack::MessagePack(MessagePack&& obj)
	{
		*this = std::move(obj);
	}
	MessagePack& MessagePack::operator=(MessagePack&& obj)
	{
		if (this != &obj)
		{
			message = obj.message;
			num_element = obj.num_element;
			obj.message = { nullptr };
			obj.num_element = { 0 };
		}
		return *this;
	}
	MessagePack::~MessagePack()
	{
		delete[] message;
		message = nullptr;
	}
	
	MessagePack::MessagePack(Message** p, int num_array)
	{
		if (num_array > 0 && p != nullptr)
		{
			num_element = { 0 };
			message = new Message[num_array];

			for (int i = 0; i < num_array; ++i)
			{
				if (!(*p[i]).empty())
					message[i] = *p[i];
				else
					message[i] = Message();

				num_element++;
			}
			for (int i = 0; i < num_element; ++i)
			{
				if (message[i].empty())
				{
					for (int x = i; x < num_element - 1; ++x)
						message[x] = message[x + 1];

					message[num_element - 1] = Message();
				}
			}

			num_element--;
		}
	}
	void MessagePack::display(std::ostream& os) const
	{
		for (int i = 0; i < num_element; i++)
		{
			if (!message[i].empty())
				message[i].display(os);
		}
	}
	size_t MessagePack::size() const
	{
		return size_t(num_element);
	}
	std::ostream& operator<<(std::ostream& os, const MessagePack& m)
	{
		m.display(os);
		return os;
	}
}