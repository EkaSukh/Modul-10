#pragma once
#include <iostream>
#include <vector>
#include "Message.h"


template<> class Message <std::string>;
class User;

class Chat
{
public:
	Chat() {}
	~Chat() {}

	bool AddUser(const User& usr);
	void ShowUsers();
	bool FindUser(const std::string& login);
	bool FindUser_by_name(const std::string& name);
	User* GetUser(const std::string& login);
	User* GetUser_by_name(const std::string& name);
	

	void ChatState(User* usr);

	
	bool Add_message_to_all(const Message<std::string>& msg_all);
	//void Show_AllMessages_sender();
	const size_t count_allMessages();
	void Read_msg_in_all(const size_t num_of_msg);
	
	

	

private:
	std::vector<User> Users;

	std::vector <Message<std::string> > all_messages;
	
};
