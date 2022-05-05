#include "Message.h"
#include "User.h"
#include "Interface.h"
#include "Chat.h"
#include <iostream>
#include <vector>
#include <memory>

int main()
{
	Interface interface1;//объект интрефэйса
	std::unique_ptr<Chat> chat1(new Chat); //объект чата
	std::cout << "Welcome to our chat!\n";

	while (interface1.Enable(*chat1)) //вход в интерфэйс первого уровня
	{
		while (interface1.StartChat(*chat1))//вход в интерфэйс второго уровня
			continue;
	}
	std::cout << "Thank you for chatting.";

	return 0;
}