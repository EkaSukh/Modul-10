#pragma once

#include <vector>
#include <map>

#include <filesystem>
#include "User.h"


//РїСЂРµРґРІР°СЂРёС‚РµР»СЊРЅРѕРµ РѕР±СЉСЏРІР»РµРЅРёРµ СЏРІРЅРѕР№ СЃРїРµС†РёР°Р»РёР·Р°С†РёРё С€Р°Р±Р»РѕРЅРЅРѕРіРѕ РєР»Р°СЃСЃР° Message
//РєРѕС‚РѕСЂС‹Р№ РІС…РѕРґРёС‚ РІ РѕР±СЉСЏРІР»РµРЅРёРµ РєР»Р°СЃСЃР° Chat
template<> class Message <std::string>;




//предварительное объявления класса
//используемого при определении класса Chat
class User;

//класс Chat
//хранит массив пользователей
//хранит массив общих сообщений
//осуществляет работу с этими массивами
class Chat
{
public:
	//конструктор и деструктор класса
	Chat() {}
	~Chat()
	//работа с массивом пользователей

	void addUser(const User& usr);
	void showUsers();
	bool findUser(const std::string& login);
	bool findUserByName(const std::string& name);
	User* getUser(const std::string& login);
	User* getUserByName(const std::string& name);

	void writeUsersToFile();
	void restoreUsersFromFile();

	//РѕС‚СЂР°Р¶Р°РµС‚ РєРѕР»Р»РёС‡РµСЃС‚РІРѕ СЃРѕРѕР±С‰РµРЅРёР№ РІ РѕР±С‰РµР№ Рё Р»РёС‡РЅРѕР№ РєРѕР»Р»РµРєС†РёРё 
	//РґР»СЏ С‡С‚РµРЅРёСЏ РёС… РІРѕС€РµРґС€РёРј РїРѕ РїР°СЂРѕР»СЋ РїРѕР»СЊР·РѕРІР°С‚РµР»РµРј user
	void chatState(User* usr);

	//СЂР°Р±РѕС‚Р° СЃ РјР°СЃСЃРёРІРѕРј РѕР±С‰РёС… СЃРѕРѕР±С‰РµРЅРёР№
	void addMessageToAll(const Message<std::string>& msg_all);
	size_t countAllMessages() const;
	void readMsgAll(const size_t num_of_msg);
	void printToFile();
	void readFromFile();


private:
	//РјР°СЃСЃРёРІ РїРѕР»СЊР·РѕРІР°С‚РµР»РµР№
	std::map <std::string, User> Users;

	//РјР°СЃСЃРёРІ СЃРѕРѕР±С‰РµРЅРёРµ, РґРѕСЃС‚СѓРїРЅС‹Р№ РІСЃРµРј РїРѕР»СЊР·РѕРІР°С‚РµР»СЏРј

	std::vector <Message<std::string> > all_messages;
};
