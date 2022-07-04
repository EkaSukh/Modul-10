#include "Interface.h"
#include "Chat.h"
#include <iostream>


int main()
{
	Interface interface;//объект интрефэйса
	Chat chat; //объект чата
	std::cout << "Welcome to our chat!\n";

	while (interface.Enable(chat)) //вход в интерфэйс первого уровня
	{
		while (interface.startChat(chat))//вход в интерфэйс второго уровня
			continue;
	}
	std::cout << "Thank you for chatting.";

	return 0;
}