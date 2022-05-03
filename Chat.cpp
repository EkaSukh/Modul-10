#include <iostream>
#include <vector>
#include "Chat.h"
#include "Message.h"
#include "User.h"



//работа с вектором юзеров

//добавляем юзера в конец
bool Chat::AddUser(const User& usr)
{
	Users.push_back(usr);
	return true;
	//а когда же функция будет принимать значения ложь?

}

//Выводим список юзеров по имени
void Chat::ShowUsers()
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)
	{
		std::cout << usr->getName() << std::endl;
	}
}

//находит юзера по логину и возвращает успешность
bool Chat::FindUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
			return true;
	}

	return false;

}

bool Chat::FindUser_by_name(const std::string& name)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
			return true;
	}

	return false;

}


User* Chat::GetUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end();i++,usr++)
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
		{
			
			return &Users[i];
		}
					
	}
	return nullptr;
		
}

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

void Chat::ChatState(User* usr)
{
	std::cout << "Messages from all users: " << count_allMessages() << std::endl;
	std::cout << "Personal mesages: " << usr->Count_received_msg() << std::endl;

}


//работа с вектором общих сообщений
bool Chat::Add_message_to_all(const Message<std::string>& msg_all)
{
	all_messages.push_back(msg_all);
	return true;
	//а когда же функция будет принимать значения ложь?
}



const size_t Chat::count_allMessages()
{
	return all_messages.size();
}

void Chat::Read_msg_in_all(const size_t num_of_msg) //сделать этоц функции exception
{
	if (all_messages.empty())
	{
		std::cout << "There is no messages yet.\n";
	}
	else
	{
		if (num_of_msg <= all_messages.size())
		{			
			all_messages[num_of_msg - 1].Show_Message();
		}
		else
			throw bad_range();
		
	}
}


