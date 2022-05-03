#include <iostream>
#include <vector>
#include "Chat.h"
#include "Message.h"
#include "User.h"


std::string User::getName() const { return _name; }
std::string User::getLogin() const { return _login; }


void User::setName(const std::string& name) { _name = name; }
void User::setPass(const std::string& pass) { _password = pass; }
bool User::checkPass(const std::string& psw) { return (0 == psw.compare(_password)); }

void User::Add_msg_to_my_collection(Message<std::string>& msg)
{
	receivedMessg.push_back(msg);
}

const size_t User::Count_received_msg()
{
	return receivedMessg.size();
}

void User::Read_personal_msg(const size_t n)
{
	if (receivedMessg.empty())
	{
		std::cout << "There is no messages yet\n";
	}
	else
	{
		
		if ((size_t)n <= (int)receivedMessg.size())
		{
			
			receivedMessg[n - 1].Show_Message(); 
		}
		else
			throw bad_range();

	}
}

