#pragma once
#include <iostream>
#include <vector>
#include "Message.h"

//предварительное объявление явной специализации шаблонного класса Message
//который входит в объявление класса Chat
template<> class Message <std::string>;
template<> class Message <std::string>;

//предварительное объявления класса
//используемого при определении класса Chat
class User;

//класс Chat
//хранит массив пользователей
//хранит массив общих сообщений
//осуществляет работу с этими массивами
class Chat
{
public:
	//конструктор и деструктор класса
	Chat() {}
	~Chat() {}

	//работа с массивом пользователей
	void AddUser(const User& usr);
	void ShowUsers();
	bool FindUser(const std::string& login);
	bool FindUser_by_name(const std::string& name);
	User* GetUser(const std::string& login);
	User* GetUser_by_name(const std::string& name);
	
	//отражает колличество сообщений в общей и личной коллекции 
	//для чтения их вошедшим по паролю пользователем user
	void ChatState(User* usr);

	//работа с массивом общих сообщений
	void Add_message_to_all(const Message<std::string>& msg_all);
	const size_t count_allMessages();
	void Read_msg_in_all(const size_t num_of_msg);
		

private:
	//массив пользователей
	std::vector<User> Users;

	//массив общих сообщений, доступных всем пользователям
	std::vector <Message<std::string> > all_messages;
};
