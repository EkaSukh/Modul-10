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

void User::Add_msg_to_my_collection(Message& msg)
{
	int n = receivedMessg.size() + 1;
	receivedMessg.resize(n);
	receivedMessg.push_back(msg);
}

const int User::Count_received_msg()
{
	return receivedMessg.size();
}

void User::Read_personal_msg(const int n)
{
	if (receivedMessg.empty())
	{
		std::cout << "There is no messages yet\n";
	}
	else
	{
		if (n <= receivedMessg.size())
		{
			std::cout << "Text:\n";
			std::cout << receivedMessg[n - 1].Show_Text() << std::endl;
		}
		else
			std::cout << "Index is out of range.\n";

	}
}

/*
// It is collections of messages
void User::ShowSent()
{}

void User::ShowThread()
{}
void User::ShowRecievedNames() //list of users from whom has messages
{}
void User::ShowFrom(const std::string& name) //messages form selected user
{}*/