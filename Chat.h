#pragma once

#include <vector>
#include "User.h"

//��������������� ���������� ����� ������������� ���������� ������ Message
//������� ������ � ���������� ������ Chat
template<> class Message <std::string>;


//��������������� ���������� ������
//������������� ��� ����������� ������ Chat
class User;

//����� Chat
//������ ������ �������������
//������ ������ ����� ���������
//������������ ������ � ����� ���������
class Chat
{
public:
	//����������� � ���������� ������
	Chat() {}
	~Chat() {}

	//������ � �������� �������������
	void addUser(const User& usr);
	void showUsers();
	bool findUser(const std::string& login);
	bool findUserByName(const std::string& name);
	User* getUser(const std::string& login);
	User* getUserByName(const std::string& name);

	//�������� ����������� ��������� � ����� � ������ ��������� 
	//��� ������ �� �������� �� ������ ������������� user
	void chatState(User* usr);

	//������ � �������� ����� ���������
	void addMessageToAll(const Message<std::string>& msg_all);
	size_t countAllMessages() const;
	void readMsgAll(const size_t num_of_msg);


private:
	//������ �������������
	std::vector<User> Users;

	//������ ����� ���������, ��������� ���� �������������
	std::vector <Message<std::string> > all_messages;
};
