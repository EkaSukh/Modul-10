#include "Chat.h"


//работа с вектором полюзователей

//добавляем юзера в конец map пользователей
void Chat::addUser(const User& usr)
{
	Users.insert({ usr.getLogin(), usr});
}

//Выводим список пользователей чата по имени
void Chat::showUsers()
{
	std::map <std::string , User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)//движение по списку юзеров с использованием итератора
	{
		std::cout << usr->second.getName() << std::endl;
	}
}

//находит пользователя по логину и возвращает успешность
bool Chat::findUser(const std::string& login)
{
	std::map <std::string, User>::iterator usr = Users.find(login);
	
	if(usr != Users.end())
			return true;
	else
		return false;
}

//находит пользователя по имени и возвращает успешность
bool Chat::findUserByName(const std::string& name)
{
	std::map <std::string, User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)//движение по списку юзеров с использованием итератора
	{
		std::string tmp = usr->second.getName();
		if (0 == tmp.compare(name))
			return true;
	}

	return false;

}

//Возвращает указатель на пользователя с данным логином
User* Chat::getUser(const std::string& login)
{
	std::map <std::string, User>::iterator usr = Users.find(login);
	
	if (usr != Users.end())
		return &(usr->second);
	else
		return nullptr;
}

//Возвращает указатель на пользователя с данным именем
User* Chat::getUserByName(const std::string& name)
{

	std::map <std::string, User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)//движение по списку юзеров с использованием итератора
	{
		std::string tmp = usr->second.getName();
		if (0 == tmp.compare(name))
			return &(usr->second);
	}	
	return nullptr;

}

//отображает количество сообщений в массивах общих и персоональных сообщений для конкретного пользователя
void Chat::chatState(User* usr)
{
	std::cout << "Messages from all users: " << countAllMessages() << std::endl;
	std::cout << "Personal mesages: " << usr->countReceivedMsg() << std::endl;

}


//работа с вектором общих сообщений

//добавляет сообщение в конец вектора общих сообщений
void Chat::addMessageToAll(const Message<std::string>& msg_all)
{
	all_messages.push_back(msg_all);
}

//подсчитывает количество сообщений в массиве общих сообщений
size_t Chat::countAllMessages() const
{
	return all_messages.size();
}

//вывод текста сообщения по его порядковому номеру в массиве общих сообщений 
void Chat::readMsgAll(const size_t num_of_msg)
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
			all_messages[num_of_msg - 1].showMessage();
		}
		else
			throw bad_range();

	}
}

