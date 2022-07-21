#include "Interface.h"
#include "Chat.h"
#include <iostream>


int main()
{
	Interface interface;//объект интрефэйса
	Chat chat; //объект чата
	std::cout << "Welcome to our chat!\n";
	//восстановление состояния чата из файлов
	//колекция общих сообщений
	chat.readFromFile();
	//состояния пользователей и их персональных коллеций сообщений
	chat.restoreUsersFromFile();

	while (interface.Enable(chat)) //вход в интерфэйс первого уровня
	{
		while (interface.startChat(chat))//вход в интерфэйс второго уровня
			continue;
	}
	std::cout << "Thank you for chatting.";

	return 0;
}