#pragma once
#include <iostream>
#include <vector>
#include "Message.h"

template<> class Message <std::string>;
class User;
class Chat;

class Interface
{
public: 
	Interface()
	{}
	~Interface() {}

	bool Enable(Chat& chat);//булева функция используется во внешнем цикле запуска

	void Registration(Chat& cht);
	
	void LogIn(Chat& cht);

	void Quit();

	bool StartChat(Chat& cht);

	void Read_the_input(std::string& str);

	

private:
	bool enable = true;
	bool LoggedIn = false;

	User* active_user = nullptr;
	
};
