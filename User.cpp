#include "User.h"



//Ð³ÐµÑÑÐµÑÑ
std::string User::getName() const { return _name; }
std::string User::getLogin() const { return _login; }

//ÑÐµÑÑÐµÑÑ

void User::setName(const std::string& name) { _name = name; }
void User::setPass(const std::string& pass) { _password = pass; }
//ïðîâåðêà ïàðîëÿ
bool User::checkPass(const std::string& psw) { return (0 == psw.compare(_password)); }


//Ð´Ð¾Ð±Ð°Ð²Ð»ÐµÐ½Ð¸Ðµ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð² ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ñ Ð¿ÐµÑÑÐ¾Ð¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹

void User::addMessageToMyCollection(const Message<std::string>& msg)
{
	receivedMessg.push_back(msg);
}


//Ð¿Ð¾Ð´ÑÑÐµÑ Ð¿ÐµÑÑÐ¾Ð¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸ Ð² ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸

size_t User::countReceivedMsg() const
{
	return receivedMessg.size();
}


//ÑÑÐµÐ½Ð¸Ðµ Ð²ÑÐ±ÑÐ°Ð½Ð½Ð¾Ð³Ð¾ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð¸Ð· ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸ Ð¿Ð¾ Ð¿ÐµÑÑÐ¾Ð½Ð°Ð»ÑÐ½Ð¾Ð¼Ñ Ð½Ð¾Ð¼ÐµÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ

void User::readPersonalMsg(const size_t n)
{
	if (receivedMessg.empty())//íåò ñîîáùåíèé
	{
		std::cout << "There is no messages yet\n";
	}
	else//åñòü ñîîáùåíèÿ
	{

		if ((n <= receivedMessg.size()))
		{

			receivedMessg[n - 1].showMessage();
		}
		else
			throw bad_range();

	}

}

//Ð¾Ð¿ÑÐµÐ´ÐµÐ»ÐµÐ½Ð¸Ðµ Ð¿ÑÐ¾ÑÐµÐ´ÑÑÑ Ð·Ð°Ð¿Ð¸ÑÐ¸ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð² ÑÐ°Ð¹Ð»
std::ofstream& operator <<(std::ofstream& os, User& user)
{
	os << user._login;
	os << ' ';
	os << user._password;
	os << ' ';
	os << user._name;
	os << ' ';
	//Ð·Ð°Ð¿Ð¸ÑÑÐ²Ð°ÐµÐ¼ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð² ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸
	os << user.countReceivedMsg();
	os << ' ';
	//Ð·Ð°Ð¿Ð¸ÑÑÐ²Ð°ÐµÐ¼ Ð²ÑÑ ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹
	for(auto itr = user.receivedMessg.begin(); itr != user.receivedMessg.end(); ++itr)
	os << *itr;

	return os;
}

