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

	
	//положить пользователя в лист юзеров и сказать результат
	cht.AddUser(user);
	std::cout << "Your user account successfully created.\n";
	
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

	//std::cout << "Call of GetUser\n";
	//приватный указатель интерфейса указывает на signed in user

	active_user = nullptr;
	if (!active_user)
	{
		//std::cout << "Pointer of active user is nullptr.\n";
		
		active_user = cht.GetUser(lg_inp);
		if (active_user->checkPass(pass_inp))
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

void Interface::Read_the_input(std::string& str)
{
	char ch[100];
	std::cin.get(ch, 100, '#');
	str += ch;
}

bool Interface::StartChat(Chat& cht)
{
	if (!LoggedIn)
		return false;

	cht.ChatState(active_user);

	std::cout << "You may choose an option:\n";
	std::cout << "1 Send a message to all other users\n";
	std::cout << "2 Send a message to a selected user\n";
	std::cout << "3 Read a messages from all users\n";
	std::cout << "4 Read a personal message\n";
	std::cout << "5 Personal: change name or password\n";
	std::cout << "6 Go to main menu\n\n";

	
	
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
		std::cout << "Enter the message up to 100 symbols (enter # to finish the message):\n";
		std::string inp_text;
		
		//std::cin >> inp_text;
		Read_the_input(inp_text);
		

		std::string from = (active_user->getName());
		std::string to = "all";
		Message<std::string> fresh(to, from, inp_text);
		cht.Add_message_to_all(fresh);

		return true;
	}


	case 2:{

		{
			std::cout << "\nList of current users:\n";
			cht.ShowUsers();
		}
		
		std::cout << "Enter recipient's name:\n";
		std::string to;
		std::cin >> to;
		if (!cht.FindUser_by_name(to))
		{
			std::cout << "Can Not Find the user.\n";
			return true;
		}
		std::string from = (active_user->getName());

		std::cout << "Enter the message up to 100 symbols (enter # to finish the message):\n";
		std::string inp_text;
		//std::cin >> inp_text;
		Read_the_input(inp_text);
		
		
		Message<std::string> fresh(to, from, inp_text);

		//процедура нахождения именной нитки
		std::cout << "Adding message to a recepients thread\n";
		User* recipient_user = cht.GetUser_by_name(to);
		if (recipient_user) 
		{
			recipient_user->Add_msg_to_my_collection(fresh);
			std::cout << "Added\n";
		}
		else
			std::cout << "Something went wrong.\n";

		

		return true;

	}
	case 3:
	{
		std::cout << "Enter a number of a message you want to read:\n";
		size_t n;
		while (!(std::cin >> n))//проверка ввода
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Input shood be an integer. Please, try again.\n";
		};
		
		try {
			cht.Read_msg_in_all(n);
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
		}
		

		return true;

	}

	case 4:
	{
		std::cout << "Enter a number of a message you want to read:\n";
		size_t n;
		
		while (!(std::cin >> n))//проверка ввода
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Input shood be an integer. Please, try again.\n";
		}

		try {
			active_user->Read_personal_msg(n);
		}

		catch (std::exception& e)
		{
			std::cout << e.what();
		}
		return true;

	}

	case 5:
	{
		
		bool in_personal = true;
		while (in_personal)
		{
			std::cout << "You may change your user's name and password:\n";
			std::cout << "1 Change user's name.\n";
			std::cout << "2 Change user's name.\n";
			std::cout << "3 Go upward menu.\n";
			int input;
			while (!(std::cin >> input))//проверка ввода
			{
				std::cin.clear();
				while (std::cin.get() != '\n')
					continue;
				std::cout << "Input shood be an integer 1  or 2. Please, try again.\n";
			}

			switch (input)
			{
			case 1:
			{
				std::cout << "Your current user's name is " << active_user->getName() << std::endl;
				std::cout << "Would you like to change it? (y/n)\n";
				char ch;
				std::cin >> ch;
				if ((ch == 'y') || (ch == 'Y'))
				{
					std::cout << "Enter new name:\n";
					std::string new_name;
					std::cin >> new_name;

					active_user->setName(new_name);
					std::cout << "Your new name is \"" << active_user->getName() << "\".\n";
					break;

				}
				else
					break;
			}
			case 2:
			{
				std::cout << "Would you like to change your password? (y/n)\n";
				char ch;
				std::cin >> ch;
				if ((ch == 'y') || (ch == 'Y'))
				{
					std::cout << "Enter new password:\n";
					std::string new_pass;
					std::cin >> new_pass;

					active_user->setPass(new_pass);
					std::cout << "Your password is changed";
					break;

				}
				else
					break;


			}
			case 3:
			{
				in_personal = false;
				break;
			}
			default:
			{
				in_personal = false;
				break;
			}
							
			}
		}
		

		return true;
	}


	case 6:
	{
		
		LoggedIn = false;
		return false;
	}
		

	default:
		return false;
	}


}