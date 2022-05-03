#include <iostream>
#include <vector>
#include <string>
#include "Chat.h"
#include "Message.h"
#include "User.h"
#include "Interface.h"

bool Interface::Enable(Chat& chat)
{
	//вывод меню в консоль и запрос ввода 
	std::cout << "Please, choose an option:\n"
		<<"1 Registration of a new user.\n"
		<<"2 Sign in as an existing user\n"
		<<"3 Quit the Chat" << std::endl;
	int input;
	while (!(std::cin >> input))//проверка ввода
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input shood be an integer from 1 to 3. Please, try again.\n";
	}	

	//движение по меню
	switch (input)
	{
	case 3: 
	{
		Quit();
		return enable;	
	}
	case 2:
	{
		LogIn(chat);
		return enable;
	}

	case 1:
	{
		Registration(chat);
		return enable;
	}

	default: return false;
	}
}

void Interface::Registration(Chat& cht)
{
	std::string name;
	std::string login;
	std::string pass;
	std::cout << "Enter your login (it can not be changed in future):\n";
	std::cin >> login;

	//Проверка логина, вдруг такой уже есть..
	while (cht.FindUser(login))
	{
		std::cout << "This login is engaged, choose another one:\n";
		std::cin >> login;
	}

	std::cout << "Enter your name (you may change it in future):\n";
	std::cin >> name;
	std::cout << "Enter your password:\n";
	std::cin >> pass;

	User user(login, pass, name);

	//создаем персональную линию сообщений для данного юзера
	//cht.Create_Personal_Thread(user);

	//положить пользователя в лист юзеров и сказать результат
	cht.AddUser(user);
	std::cout << "Your user account successfully created.\n";
	
	{
		std::cout << "\nList of current users:\n";
		cht.ShowUsers();		
	}
}



void Interface::LogIn(Chat& cht)
{
	std::cout << "Enter your loggin:\n";
	std::string lg_inp;
	std::cin >> lg_inp;
	if(!cht.FindUser(lg_inp))
	{
		std::cout << "There is no user with this login.\n";
		return;
	}
	std::cout << "Enter your password:\n";
	std::string pass_inp;
	std::cin >> pass_inp;

	std::cout << "Call of GetUser\n";
	//приватный указатель интерфейса указывает на signed in user

	active_user = nullptr;
	if (!active_user)
	{
		std::cout << "Pointer of active user is nullptr.\n";
		
		active_user = cht.GetUser(lg_inp);
		if (lg_inp->checkPass(pass_inp))
		{
			std::cout << "You have successfully signed in.\n\n";
			LoggedIn = true;
		}
		else
			std::cout << "The password is incorrect.\n";

	}
	else
		std::cout << "could not nulled pointer on active_user.\n";
		
		
	
}

void Interface::Quit()
{
	enable = false;
}

bool Interface::StartChat(Chat& cht)
{
	if (!LoggedIn)
		return false;

	cht.ChatState(active_user);

	std::cout << "You may choose an option:\n";
	std::cout << "1 To send a message to all other users\n";
	std::cout << "2 To send a message to a selected user\n";
	std::cout << "3 To read a messages for all\n";
	std::cout << "4 To read personal messages \n";
	std::cout << "5 To go to main menu\n\n";

	
	
	int input;
	while (!(std::cin >> input))//проверка ввода
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input shood be an integer from 1 to 6. Please, try again.\n";
	}

	switch (input)
	{
	case 1: {
		std::cout << "Enter the text:\n";
		std::string inp_text;
		std::cin >> inp_text;
		//getline(std::cin, inp_text);//и сколько она будет считывать?
		std::string from = (active_user->getName());
		std::string to = "all";
		Message fresh(to, from, inp_text);
		cht.Add_message_to_all(fresh);

		//Для отладки
		std::cout << "\nLets see changes:\n";
		cht.ChatState(active_user);
		
		return true;
	}


	case 2:{
		
		std::cout << "Enter recipient's name:\n";
		std::string to;
		std::cin >> to;

		std::string from = (active_user->getName());

		std::cout << "Enter the text:\n";
		std::string inp_text;
		std::cin >> inp_text;
		//getline(std::cin, inp_text);//и сколько она будет считывать?
				

		Message fresh(to, from, inp_text);

		//процедура нахождения именной нитки
		std::cout << "Adding message to recepients thread\n";
		std::shared_ptr <User> recipient_user = cht.GetUser_by_name(to);
		if (recipient_user && cht.FindUser_by_name(to))
		{
			recipient_user->Add_msg_to_my_collection(fresh);
			std::cout << "Added\n";
		}
		else
			std::cout << "Can Not Find the user.\n";

		std::cout << "\nLets see changes:\n";
		cht.ChatState(active_user);

		return true;

	}
	case 3:
	{
		std::cout << "Enter a number of a message you want to read:\n";
		int n;
		std::cin >> n;
		
		cht.Read_msg_in_all(n);

		return true;

	}

	case 4:
	{
		std::cout << "Enter a number of a message you want to read:\n";
		int n;
		std::cin >> n;
		
		active_user->Read_personal_msg(n);

		return true;

	}

	case 5:
	{
		
		LoggedIn = false;
		return false;
	}
		

	default:
		return false;
	}


}