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

	bool Enable(Chat& chat);//������ ������� ������������ �� ������� ����� �������

	void Registration(Chat& cht);
	
	void LogIn(Chat& cht);

	void Quit();

	bool StartChat(Chat& cht);

	

private:
	bool enable = true;
	bool LoggedIn = false;

	User* active_user = nullptr;
	
};
