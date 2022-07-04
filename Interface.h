#pragma once
#include "User.h"
#include "Chat.h"


//предварительное объ¤влени¤ классов
//используемых при определении класса Interface
class User;
class Chat;

//класс реализует общение между пользователем и внутренними классами программы
class Interface
{
public:
	//конструктор и деструктор
	Interface()
	{}
	~Interface() {}

	//ѕервый уровень интерфэйса общени¤
	bool Enable(Chat& chat);//булева функци¤ используетс¤ во внешнем цикле запуска

	//функции работают в первом уровне интерфэйса и вызываютс¤ из Enable()
	static void registration(Chat& cht);
	void logIn(Chat& cht);
	void quit();

	//¬торой уровень интерфэйса
	bool startChat(Chat& cht);

	//читает ввод пользовател¤ дл¤ формировани¤ текста сообщени¤
	static void readTheInput(std::string& str);

private:
	//переменные контролируют подключение уровн¤ интерфэйса
	bool enable = true;//подключает 1-ый уровень интерфэйса
	bool LoggedIn = false;//подключает 2-ой уровень интерфэйса

	//указатель на юзера, который вошЄл через процедуру ввода парол¤ во 2-ой уровень интерфэйса
	User* active_user = nullptr;

};