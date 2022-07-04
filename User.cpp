#include "User.h"


//геттеры 
std::string User::getName() const { return _name; }
std::string User::getLogin() const { return _login; }

//сэттеры
void User::setName(const std::string& name) { _name = name; }
void User::setPass(const std::string& pass) { _password = pass; }
//проверка пароля
bool User::checkPass(const std::string& psw) { return (0 == psw.compare(_password)); }

//добавление сообщения в коллекцию персональных сообщений
void User::addMessageToMyCollection(const Message<std::string>& msg)
{
	receivedMessg.push_back(msg);
}

//подсчет персональных сообщений в коллекции
size_t User::countReceivedMsg() const
{
	return receivedMessg.size();
}

//чтения выбранного сообщения из коллекции по порядковому номеру сообщения
void User::readPersonalMsg(const size_t n)
{
	if (receivedMessg.empty())//нет сообщений
	{
		std::cout << "There is no messages yet\n";
	}
	else//есть сообщения
	{

		if ((n <= receivedMessg.size()))
		{

			receivedMessg[n - 1].showMessage();
		}
		else
			throw bad_range();

	}
}