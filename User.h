#pragma once

#include <vector>
#include <exception>
#include <string>
#include "Message.h"
#include "SHA_1.h"

//константа для создания массива символов при хэшировании
const uint PASS = 15;

//класс дл¤ формировани¤ исключений в функции чтени¤ сообщени¤ из вектора персональных сообщений
class bad_range :public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "EXCEPTION: index is out of range\n";
	}

};


//предварительное объ¤вление ¤вной специализации шаблонного класса Message
//который входит в объ¤вление класса User
template<> class Message <std::string>;

//класс описывает пользовател¤ чата
class User
{
public:
	//конструкторы
	User() {}
	User(const std::string& login, const std::string& passw, const std::string& name);

	//деструктор
	~User() {
		delete _hash;
	}

	//гетеры приватных данных
	std::string getName() const;
	std::string getLogin() const;
	
	//сетеры приватных переменных
	void setName(const std::string& name);
	void setPass(const std::string& pass);

	//проверка парол¤
	bool checkPass(const std::string& psw);

	//работа с коллекцией персональных сообщений
	void addMessageToMyCollection(const Message<std::string> & msg);
	size_t countReceivedMsg() const;
	void readPersonalMsg(const size_t n);

	
private:
	const std::string _login; //константна¤ переменна¤ дл¤ однозначного определени¤ юзера в списке
	//std::string _password;
	std::string _name;
	
	// указатель на хэшированный пароль
	uint* _hash;
	
	// коллекци¤ персональных сообщений дл¤ данного юзера
	std::vector<Message<std::string> > receivedMessg;
	
};
