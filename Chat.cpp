#include "Chat.h"


//������ � �������� �������������

//��������� ����� � ����� ������� �������������
void Chat::addUser(const User& usr)
{
	Users.push_back(usr);

}

//������� ������ ������������� ���� �� �����
void Chat::showUsers()
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)//�������� �� ������ ������ � �������������� ���������
	{
		std::cout << usr->getName() << std::endl;
	}
}

//������� ������������ �� ������ � ���������� ����������
bool Chat::findUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)//�������� �� ������ ������ � �������������� ���������
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
			return true;
	}

	return false;

}

//������� ������������ �� ����� � ���������� ����������
bool Chat::findUserByName(const std::string& name)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)//�������� �� ������ ������ � �������������� ���������
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
			return true;
	}

	return false;

}

//���������� ��������� �� ������������ � ������ �������
User* Chat::getUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end(); ++i, ++usr)//�������� �� ������ ������ � �������������� ���������
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
		{

			return &Users[i];
		}

	}
	return nullptr;

}

//���������� ��������� �� ������������ � ������ ������
User* Chat::getUserByName(const std::string& name)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end(); ++i, ++usr)
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
		{
			return &Users[i];
		}

	}
	return nullptr;

}

//���������� ���������� ��������� � �������� ����� � ������������� ��������� ��� ����������� ������������
void Chat::chatState(User* usr)
{
	std::cout << "Messages from all users: " << countAllMessages() << std::endl;
	std::cout << "Personal mesages: " << usr->countReceivedMsg() << std::endl;

}


//������ � �������� ����� ���������

//��������� ��������� � ����� ������� ����� ���������
void Chat::addMessageToAll(const Message<std::string>& msg_all)
{
	all_messages.push_back(msg_all);
}

//������������ ���������� ��������� � ������� ����� ���������
size_t Chat::countAllMessages() const
{
	return all_messages.size();
}

//����� ������ ��������� �� ��� ����������� ������ � ������� ����� ��������� 
void Chat::readMsgAll(const size_t num_of_msg)
{
	//����� ��������� ���
	if (all_messages.empty())
	{
		std::cout << "There is no messages yet.\n";
	}
	else//���� ���������
	{
		if ((num_of_msg <= all_messages.size()))
		{
			all_messages[num_of_msg - 1].showMessage();
		}
		else
			throw bad_range();

	}
}

