#include "User.h"

//конструктор с созданием хэшированного пароля
User::User(const std::string& login, const std::string& passw, const std::string& name) :
	_login(login), _name(name) {

	//создание и заполнение массива для передач в хэш-функцию
	char hash_pass[PASS];
	passw.copy(hash_pass, passw.length() + 1);

	//инициализация указателя на хэшированный пароль
	_hash = sha1(hash_pass, (uint)sizeof(hash_pass));
}

//геттеры 
std::string User::getName() const { return _name; }
std::string User::getLogin() const { return _login; }

//сэттеры
void User::setName(const std::string& name) { _name = name; }
void User::setPass(const std::string& pass) {

	char hash_pass[PASS];
	pass.copy(hash_pass, pass.length() + 1);

	//инициализация указателя на хэшированный пароль
	_hash = sha1(hash_pass, (uint)sizeof(hash_pass));
}


//проверка пароля
bool User::checkPass(const std::string& psw) {

	char hash_pass[PASS];
	psw.copy(hash_pass, psw.length() + 1);

	uint* pass_trial = sha1(hash_pass, (uint)sizeof(hash_pass));

	
	return !memcmp(_hash, pass_trial, SHA1HASHLENGTHBYTES);
}

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

