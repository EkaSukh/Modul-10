#include "Interface.h"


//ïåðâûé óðîâåíü èíòåðôýéñà
bool Interface::Enable(Chat& chat)
{

	//Ð²ÑÐ²Ð¾Ð´ Ð¼ÐµÐ½Ñ Ð² ÐºÐ¾Ð½ÑÐ¾Ð»Ñ Ð¸ Ð·Ð°Ð¿ÑÐ¾Ñ Ð²Ð²Ð¾Ð´Ð°

	std::cout << "Please, choose an option:\n"
		<< "1 Registration of a new user.\n"
		<< "2 Sign in as an existing user\n"
		<< "3 Quit the Chat" << std::endl;
	int input;

	while (!(std::cin >> input))//Ð·Ð°Ð¿ÑÐ¾Ñ Ð²Ð²Ð¾Ð´Ð°

	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input shood be an integer from 1 to 3. Please, try again.\n";
	}

	//äâèæåíèå ïî ìåíþ
	switch (input)
	{
	case 3:
	{

		quit(chat);

		return enable;
	}
	case 2:
	{
		logIn(chat);
		return enable;
	}

	case 1:
	{
		registration(chat);
		return enable;
	}

	default: return false;//åñëè ââåäåíî íå 1, 2, 3, òî âûõîäèì èç ÷àòà
	}
}

<
//ÑÐµÐ³Ð¸ÑÑÑÐ°ÑÐ¸Ñ Ð² ÑÐ°ÑÐµ Ð½Ð¾Ð²Ð¾Ð³Ð¾ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ

void Interface::registration(Chat& cht)
{
	std::string name;
	std::string login;
	std::string pass;
	std::cout << "Enter your login (it can not be changed in future):\n";
	std::cin >> login;


	//Ð¿ÑÐ¾Ð²ÐµÑÐºÐ° Ð»Ð¾Ð³Ð¸Ð½Ð°, Ð²Ð´ÑÑÐ³ ÑÐ°ÐºÐ¾Ð¹ ÑÐ¶Ðµ ÐµÑÑÑ

	while (cht.findUser(login))
	{
		std::cout << "This login is engaged, choose another one:\n";
		std::cin >> login;
	}

	std::cout << "Enter your name (you may change it in future):\n";
	std::cin >> name;
	std::cout << "Enter your password:\n";
	std::cin >> pass;


	User user(login, pass, name);//ÑÐ¾Ð·Ð´Ð°Ð½Ð¸Ðµ Ð¾Ð±ÑÐµÐºÑÐ° Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ, ÐºÐ¾ÑÐ¾ÑÑÐ¹ Ð±ÑÐ´ÐµÑ ÑÐºÐ¾Ð¿Ð¸ÑÐ¾Ð²Ð°Ð½ Ð² Ð¼Ð°ÑÑÐ¸Ð²

	//Ð¿Ð¾Ð»Ð¾Ð¶Ð¸ÑÑ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð² Ð»Ð¸ÑÑ ÑÐ·ÐµÑÐ¾Ð²

	cht.addUser(user);
	std::cout << "Your user account successfully created.\n";

}



//Ð²ÑÐ¾Ð´ Ð² ÑÐ°Ñ Ð·Ð°ÑÐµÐ³Ð¸ÑÑÑÐ¸ÑÐ¾Ð²Ð°Ð½Ð½Ð¾Ð³Ð¾ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð¿Ð¾ Ð»Ð¾Ð³Ð¸Ð½Ñ Ð¸ Ð¿Ð°ÑÐ¾Ð»Ñ


void Interface::logIn(Chat& cht)
{
	std::cout << "Enter your loggin:\n";
	std::string lg_inp;
	std::cin >> lg_inp;


	if (!cht.findUser(lg_inp))//Ð¿ÑÐ¾Ð²ÐµÑÐºÐ° Ð²Ð²ÐµÐ´ÐµÐ½Ð½Ð¾Ð³Ð¾ Ð»Ð¾Ð³Ð¸Ð½Ð° Ð½Ð° Ð½Ð°Ð»Ð¸ÑÐ¸Ðµ ÑÐ°ÐºÐ¾Ð³Ð¾ ÑÐ·ÐµÑÐ°

	{
		std::cout << "There is no user with this login.\n";
		return;
	}



	active_user = cht.getUser(lg_inp);//ÑÑÑÐ°Ð½Ð¾Ð²ÐºÐ° ÑÐºÐ°Ð·Ð°ÑÐµÐ»Ñ Ð½Ð° Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ


	std::cout << "Enter your password:\n";
	std::string pass_inp;
	std::cin >> pass_inp;

	if (active_user->checkPass(pass_inp))
	{
		std::cout << "You have successfully signed in.\n\n";

		LoggedIn = true;//Ð²ÐºÐ»ÑÑÐµÐ½Ð¸Ðµ ÐµÐ½ÑÐµÑÑÑÐ¹ÑÐ° Ð²ÑÐ¾ÑÐ¾Ð³Ð¾ ÑÑÐ¾Ð²Ð½Ñ

	}
	else
		std::cout << "The password is incorrect.\n";
}


//Ð²ÑÑÐ¾Ð´ Ð¸Ð· ÑÐ°ÑÐ°
void Interface::quit(Chat& cht)
{
	enable = false;//Ð¾ÑÐºÐ»ÑÑÐµÐ½Ð¸Ðµ Ð¿ÐµÑÐ²Ð¾Ð³Ð¾ ÑÑÐ¾Ð²Ð½Ñ Ð¸Ð½ÑÐµÑÑÑÐ¹ÑÐ°
	cht.printToFile();//Ð²ÑÐ²Ð¾Ð´Ð¸Ð¼ Ð¼Ð°ÑÑÐ¸Ð² Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð² ÑÐ°Ð¹Ð»
	cht.writeUsersToFile();//Ð²ÑÐ²Ð¾Ð´Ð¸Ð¼ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹ Ð² ÑÐ°Ð¹Ð»
}

//ÑÐ¾ÑÐ¼Ð¸ÑÑÐµÑ ÑÐµÐºÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð¸Ð· Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÑÑÐºÐ¾Ð³Ð¾ Ð²Ð²Ð¾Ð´Ð°

void Interface::readTheInput(std::string& str)
{
	char ch[100];
	std::cin.get(ch, 100, '#');
	str += ch;
}

//Ð¸Ð½ÑÐµÑÑÑÐ¹Ñ Ð²ÑÐ¾ÑÐ¾Ð³Ð¾ ÑÑÐ¾Ð²Ð½Ñ

bool Interface::startChat(Chat& cht)
{
	if (!LoggedIn)
		return false;

	cht.chatState(active_user);

	std::cout << "You may choose an option:\n";
	std::cout << "1 Send a message to all other users\n";
	std::cout << "2 Send a message to a selected user\n";
	std::cout << "3 Read a messages from all users\n";
	std::cout << "4 Read a personal message\n";
	std::cout << "5 Personal: change name or password\n";
	std::cout << "6 Go to main menu\n\n";


	int input;
	while (!(std::cin >> input))//ïðîâåðêà ââîäà
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input shood be an integer from 1 to 6. Please, try again.\n";
	}

	switch (input)
	{
		//íàïèñàòü ñîîáùåíèå äëÿ âñåõ
	case 1: {
		std::cout << "Enter the message up to 100 symbols (enter # to finish the message):\n";
		std::string inp_text;
		readTheInput(inp_text);

		std::string from = (active_user->getName());
		std::string to = "all";


		Message<std::string> fresh(to, from, inp_text);//ÑÐ¾Ð·Ð´Ð°Ð½Ð¸Ðµ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ


		cht.addMessageToAll(fresh);

		return true;
	}


		  //Ð½Ð°Ð¿Ð¸ÑÐ°ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ðµ Ð¸Ð·Ð±ÑÐ°Ð½Ð½Ð¾Ð¼Ñ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ
	case 2: {

		{//Ð¿Ð¾ÐºÐ°Ð·Ð°ÑÑ ÑÐ¿Ð¸ÑÐ¾Ðº Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹ Ð¿Ð¾ Ð¸Ð¼ÐµÐ½Ð°Ð¼
			std::cout << "\nList of current users:\n";
			cht.showUsers();
		}
		//Ð²Ð²ÐµÑÑÐ¸ Ð¿Ð¾Ð»ÑÑÐ°ÑÐµÐ»Ñ
		std::cout << "Enter recipient's name:\n";
		std::string to;
		std::cin >> to;
		//Ð¿ÑÐ¾Ð²ÐµÑÐºÐ° Ð½Ð° Ð½Ð°Ð»Ð¸ÑÐ¸Ðµ ÑÐ°ÐºÐ¾Ð³Ð¾ Ð¿Ð¾Ð»ÑÑÐ°ÑÐµÐ»Ñ

	
		if (!cht.findUserByName(to))
		{
			std::cout << "Can Not Find the user.\n";
			return true;
		}

		std::string from = (active_user->getName());
		std::cout << "Enter the message up to 100 symbols (enter # to finish the message):\n";
		std::string inp_text;
		readTheInput(inp_text);


		Message<std::string> fresh(to, from, inp_text);//ÑÐ¾Ð·Ð´Ð°Ð½Ð¸Ðµ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ

		
		
		//Ð¿ÑÐ¾ÑÐµÐ´ÑÑÐ° Ð½Ð°ÑÐ¾Ð¶Ð´ÐµÐ½Ð¸Ñ ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸ Ð¸Ð·Ð±ÑÐ°Ð½Ð½Ð¾Ð³Ð¾ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ
		User* recipient_user = cht.getUserByName(to);//ÑÐºÐ°Ð·Ð°ÑÐµÐ»Ñ Ð½Ð° Ð¿Ð¾Ð»ÑÑÐ°ÑÐµÐ»Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ

		if (recipient_user)
		{
			recipient_user->addMessageToMyCollection(fresh);
			std::cout << "Added\n";
		}
		else
			std::cout << "Something went wrong.\n";

		return true;

	}

		  //Ð¿ÑÐ¾ÑÐµÑÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ðµ Ð¸Ð· Ð¼Ð°ÑÑÐ¸Ð²Ð° Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹

	case 3:
	{
		std::cout << "Enter a serial number of a message you want to read:\n";
		size_t n;
		while (!(std::cin >> n))//ïðîâåðêà ââîäà
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Input shood be a posotive integer. Please, try again.\n";
		};


		//Ð¾Ð±ÑÐ°Ð±Ð¾ÑÐºÐ° Ð¸ÑÐºÐ»ÑÑÐµÐ½Ð¸Ñ ÐµÑÐ»Ð¸ Ð¿Ð¾ÑÑÐ´ÐºÐ¾Ð²ÑÐ¹ Ð½Ð¾Ð¼ÐµÑ Ð¿ÑÐµÐ²ÑÑÐµÐ½
=
		try {
			cht.readMsgAll(n);
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
		}

		return true;
	}

	//ïðî÷åñòü ñîîáùåíèå èç ìàññèâà ïåðñîíàëüíûõ ñîîáùåíèé
	case 4:
	{
		std::cout << "Enter a serial number of a message you want to read:\n";
		size_t n;

		while (!(std::cin >> n))//Ð¿ÑÐ¾Ð²ÐµÑÐºÐ° Ð²Ð²Ð¾Ð´Ð°

		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Input shood be a positive integer. Please, try again.\n";
		}


		//Ð¾Ð±ÑÐ°Ð±Ð¾ÑÐºÐ° Ð¸ÑÐºÐ»ÑÑÐµÐ½Ð¸Ñ ÐµÑÐ»Ð¸ Ð¿Ð¾ÑÑÐ´ÐºÐ¾Ð²ÑÐ¹ Ð½Ð¾Ð¼ÐµÑ Ð¿ÑÐµÐ²ÑÑÐµÐ½

		try {
			active_user->readPersonalMsg(n);
		}

		catch (std::exception& e)
		{
			std::cout << e.what();
		}
		return true;
	}

	//ïåðñîíàëüíûé èíòåðôýéñ äëÿ ñìåíû ïàðîëÿ è èìåíè ïîëüçîâàòåëÿ
	case 5:
	{

		bool in_personal = true;//Ð²Ð°Ð»Ð¸Ð´Ð°ÑÐ¾Ñ Ð½Ð°ÑÐ¾Ð¶Ð´ÐµÐ½Ð¸Ñ Ð²Ð½ÑÑÑÐ¸ Ð¿ÐµÑÑÐ¾Ð½Ð°Ð»ÑÐ½Ð¾Ð³Ð¾ Ð¸Ð½ÑÐµÑÑÑÐ¹ÑÐ°

		while (in_personal)
		{
			std::cout << "You may change your user's name and password:\n";
			std::cout << "1 Change user's name.\n";
			std::cout << "2 Change user's password.\n";
			std::cout << "3 Go upward menu.\n";
			int input;
			while (!(std::cin >> input))//ïðîâåðêà ââîäà
			{
				std::cin.clear();
				while (std::cin.get() != '\n')
					continue;
				std::cout << "Input shood be an integer 1, 2  or 3. Please, try again.\n";
			}

			switch (input)
			{
			case 1://ñìåíà èìåíè ïîëüçîâàòåëÿ
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
			case 2://ñìåíà ïàðîëÿ ïîëüçîâàòåëÿ
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
					std::cout << "Your password is changed\n";
					break;

				}
				else
					break;


			}
			case 3://âûõîä èç ïåðñîíàëüíîãî ìåíþ âî âòîðîé óðîâåíü èíòåðôýéñà
			{
				in_personal = false;
				break;
			}
			default://åñëè ââåäåíî íå 1, 2, 3, òî òîæå âûõîä âî âòîðîé óðîâåíü èíòåðôýéñà
			{
				in_personal = false;
				break;
			}

			}
		}


		return true;
	}


	case 6: //âûõîä â ïåðâûé óðîâåíü èíòåðôýéñà
	{

		LoggedIn = false;
		return false;
	}



	default: //ÐµÑÐ»Ð¸ Ð²Ð²ÐµÐ´ÐµÐ½Ð¾ ÑÐµÐ»Ð¾Ðµ Ð½Ðµ Ð¾Ñ 1 Ð´Ð¾ 6, ÑÐ¾ ÑÐ¾Ð¶Ðµ Ð²ÑÑÐ¾Ð´ Ð² Ð¿ÐµÑÐ²ÑÐ¹ ÑÑÐ¾Ð²ÐµÐ½Ñ Ð¸Ð½ÑÐµÑÑÑÐ¹ÑÐ°

		return false;
	}


}
