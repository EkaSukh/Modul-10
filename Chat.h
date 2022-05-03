#pragma once
#include <iostream>
#include <vector>

class Message;
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

	
	bool Add_message_to_all(const Message& msg_all);
	void Show_AllMessages_sender();
	const int count_allMessages();
	void Read_msg_in_all(const int num_of_msg);
	
	

	

private:
	std::vector<User> Users;

	std::vector <Message> all_messages;
	//std::vector<std::vector <Message>> personal_mesages;
};
