#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <exception>
#include "Message.h"

class bad_range :public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "EXCEPTION: index is out of range\n";
	}

};



template<> class Message <std::string>;
 
class User
{
public:
	User() {}
	User(const std::string& login, const std::string& passw, const std::string& name) :
		_login(login), _password(passw), _name(name) {}

	~User() {}

	std::string getName() const;
	std::string getLogin() const;
	
	
	void setName(const std::string& name);
	void setPass(const std::string& pass);
	bool checkPass(const std::string& psw);

	
	void Add_msg_to_my_collection(Message<std::string> & msg);
	const size_t Count_received_msg();
	void Read_personal_msg(const size_t n);

	
private:
	const std::string _login;
	std::string _password;
	std::string _name;

	std::vector<Message<std::string> > receivedMessg;
	
};
