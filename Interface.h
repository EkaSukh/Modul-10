#pragma once

#pragma once
#include <iostream>
#include <vector>

class Message;
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

	/*void Set_active_user(std::string& log)
	{
		U_login = log;

	}

	std::string Get_active_user() const
	{
		return U_login;
	}*/



private:
	bool enable = true;
	//bool registration = false;
	bool LoggedIn = false;

	std::shared_ptr<User> active_user = nullptr;
	//std::string U_login;
};
