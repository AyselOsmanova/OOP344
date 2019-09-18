#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <iostream>
#include <string>
using namespace std;
namespace sict
{
	class Message
	{
	private:
		string tweet;
		string sender;
		string message;
		string receiver;
		bool to_recipient;
		size_t p;
	public:
		Message();
		Message(const string& str);
		bool empty() const;
		void display(ostream& os) const;

	};
}


#endif 