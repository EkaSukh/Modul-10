#include <iostream>
#include <vector>
#include "Chat.h"
#include "Message.h"
#include "User.h"



//работа с вектором полюзователей

//добавляем юзера в конец массива пользователей
void Chat::AddUser(const User& usr)
{
	Users.push_back(usr);
	
}

//Выводим список пользователей чата по имени
void Chat::ShowUsers()
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)//движение по списку юзеров с использованием итератора
	{
		std::cout << usr->getName() << std::endl;
	}
}

//находит пользователя по логину и возвращает успешность
bool Chat::FindUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)//движение по списку юзеров с использованием итератора
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
			return true;
	}

	return false;

}

//находит пользователя по имени и возвращает успешность
bool Chat::FindUser_by_name(const std::string& name)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)//движение по списку юзеров с использованием итератора
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
			return true;
	}

	return false;

}

//Возвращает указатель на пользователя с данным логином
User* Chat::GetUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end();i++,usr++)//движение по списку юзеров с использованием итератора
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
		{
			
			return &Users[i];
		}
					
	}
	return nullptr;
		
}

//Возвращает указатель на пользователя с данным именем
User* Chat::GetUser_by_name(const std::string& name)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end();i++, usr++)
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
		{
			return &Users[i];
		}

	}
	return nullptr;

}

//отображает количество сообщений в массивах общих и персоональных сообщений для конкретного пользователя
void Chat::ChatState(User* usr)
{
	std::cout << "Messages from all users: " << count_allMessages() << std::endl;
	std::cout << "Personal mesages: " << usr->Count_received_msg() << std::endl;

}


//работа с вектором общих сообщений

//добавляет сообщение в конец вектора общих сообщений
void Chat::Add_message_to_all(const Message<std::string>& msg_all)
{
	all_messages.push_back(msg_all);
}

//подсчитывает количество сообщений в массиве общих сообщений
const size_t Chat::count_allMessages()
{
	return all_messages.size();
}

//вывод текста сообщения по его порядковому номеру в массиве общих сообщений 
void Chat::Read_msg_in_all(const size_t num_of_msg)
{
	//когда сообщений нет
	if (all_messages.empty())
	{
		std::cout << "There is no messages yet.\n";
	}
	else//есть сообщения
	{
		if ((num_of_msg <= all_messages.size()))
		{			
			all_messages[num_of_msg - 1].Show_Message();
		}
		else
			throw bad_range();
		
	}
}


