#pragma once

#include <vector>
#include <exception>
#include "Message.h"



//ÐºÐ»Ð°ÑÑ Ð´Ð»Ñ ÑÐ¾ÑÐ¼Ð¸ÑÐ¾Ð²Ð°Ð½Ð¸Ñ Ð¸ÑÐºÐ»ÑÑÐµÐ½Ð¸Ð¹ Ð² ÑÑÐ½ÐºÑÐ¸Ð¸ ÑÑÐµÐ½Ð¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð¸Ð· Ð²ÐµÐºÑÐ¾ÑÐ° Ð¿ÐµÑÑÐ¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹

class bad_range :public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "EXCEPTION: index is out of range\n";
	}

};


//Ð¿ÑÐµÐ´Ð²Ð°ÑÐ¸ÑÐµÐ»ÑÐ½Ð¾Ðµ Ð¾Ð±ÑÑÐ²Ð»ÐµÐ½Ð¸Ðµ ÑÐ²Ð½Ð¾Ð¹ ÑÐ¿ÐµÑÐ¸Ð°Ð»Ð¸Ð·Ð°ÑÐ¸Ð¸ ÑÐ°Ð±Ð»Ð¾Ð½Ð½Ð¾Ð³Ð¾ ÐºÐ»Ð°ÑÑÐ° Message
//ÐºÐ¾ÑÐ¾ÑÑÐ¹ Ð²ÑÐ¾Ð´Ð¸Ñ Ð² Ð¾Ð±ÑÂ¤Ð²Ð»ÐµÐ½Ð¸Ðµ ÐºÐ»Ð°ÑÑÐ° User
template<> class Message <std::string>;

//ÐºÐ»Ð°ÑÑ Ð¾Ð¿Ð¸ÑÑÐ²Ð°ÐµÑ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ ÑÐ°ÑÐ°
class User
{
public:
	//ÐºÐ¾Ð½ÑÑÑÑÐºÑÐ¾ÑÑ 


	User() {}
	User(const std::string& login, const std::string& passw, const std::string& name) :
		_login(login), _password(passw), _name(name) {}


	//Ð´ÐµÑÑÑÑÐºÑÐ¾ÑÑ
	~User() {}

	//Ð³ÐµÑÑÐµÑÑ Ð¿ÑÐ¸Ð²Ð°ÑÐ½ÑÑ Ð´Ð°Ð½Ð½ÑÑ
	std::string getName() const;
	std::string getLogin() const;

	//ÑÑÑÑÐµÑÑ Ð¿ÑÐ¸Ð²Ð°ÑÐ½ÑÑ Ð´Ð°Ð½Ð½ÑÑ
	void setName(const std::string& name);
	void setPass(const std::string& pass);

	//Ð¿ÑÐ¾Ð²ÐµÑÐºÐ° Ð¿Ð°ÑÐ¾Ð»Ñ
	bool checkPass(const std::string& psw);

	//ÑÐ°Ð±Ð¾ÑÐ° Ñ ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸ÐµÐ¹ Ð¿ÐµÑÑÐ¾Ð¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹
	void addMessageToMyCollection(const Message<std::string>& msg);
	size_t countReceivedMsg() const;
	void readPersonalMsg(const size_t n);

	//Ð·Ð°Ð¿Ð¸ÑÑ Ð¸ Ð²Ð¾ÑÑÑÐ°Ð½Ð¾Ð²Ð»ÐµÐ½Ð¸Ðµ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð¸Ð· ÑÐ°Ð¹Ð»Ð°
	friend std::ofstream& operator <<(std::ofstream& os, User& user);
	
private:
	const std::string _login; //ÐºÐ¾Ð½ÑÑÐ°Ð½ÑÐ½Ð°Ñ Ð¿ÐµÑÐµÐ¼ÐµÐ½Ð½Ð°Ñ Ð´Ð»Ñ Ð¾Ð´Ð½Ð¾Ð·Ð½Ð°ÑÐ½Ð¾Ð³Ð¾ Ð¾Ð¿ÑÐµÐ´ÐµÐ»ÐµÐ½Ð¸Ñ ÑÐ·ÐµÑÐ° Ð² ÑÐ¿Ð¸ÑÐºÐµ
	std::string _password;
	std::string _name;

	// ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ñ Ð¿ÐµÑÑÐ¾Ð¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð´Ð»Ñ Ð´Ð°Ð½Ð½Ð¾Ð³Ð¾ ÑÐ·ÐµÑÐ°

	std::vector<Message<std::string> > receivedMessg;

};
