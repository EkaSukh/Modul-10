#include "User.h"


//������� 
std::string User::getName() const { return _name; }
std::string User::getLogin() const { return _login; }

//�������
void User::setName(const std::string& name) { _name = name; }
void User::setPass(const std::string& pass) { _password = pass; }
//�������� ������
bool User::checkPass(const std::string& psw) { return (0 == psw.compare(_password)); }

//���������� ��������� � ��������� ������������ ���������
void User::addMessageToMyCollection(const Message<std::string>& msg)
{
	receivedMessg.push_back(msg);
}

//������� ������������ ��������� � ���������
size_t User::countReceivedMsg() const
{
	return receivedMessg.size();
}

//������ ���������� ��������� �� ��������� �� ����������� ������ ���������
void User::readPersonalMsg(const size_t n)
{
	if (receivedMessg.empty())//��� ���������
	{
		std::cout << "There is no messages yet\n";
	}
	else//���� ���������
	{

		if ((n <= receivedMessg.size()))
		{

			receivedMessg[n - 1].showMessage();
		}
		else
			throw bad_range();

	}
}