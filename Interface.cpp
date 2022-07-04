#include "Interface.h"


//������ ������� ����������
bool Interface::Enable(Chat& chat)
{
	//����� ���� � ������� � ������ ����� 
	std::cout << "Please, choose an option:\n"
		<< "1 Registration of a new user.\n"
		<< "2 Sign in as an existing user\n"
		<< "3 Quit the Chat" << std::endl;
	int input;
	while (!(std::cin >> input))//�������� �����
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input shood be an integer from 1 to 3. Please, try again.\n";
	}

	//�������� �� ����
	switch (input)
	{
	case 3:
	{
		quit();
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

	default: return false;//���� ������� �� 1, 2, 3, �� ������� �� ����
	}
}

//����������� � ���� ������ ������������
void Interface::registration(Chat& cht)
{
	std::string name;
	std::string login;
	std::string pass;
	std::cout << "Enter your login (it can not be changed in future):\n";
	std::cin >> login;

	//�������� ������, ����� ����� ��� ����.
	while (cht.findUser(login))
	{
		std::cout << "This login is engaged, choose another one:\n";
		std::cin >> login;
	}

	std::cout << "Enter your name (you may change it in future):\n";
	std::cin >> name;
	std::cout << "Enter your password:\n";
	std::cin >> pass;

	User user(login, pass, name);//�������� ������� ������������, ������� ����� ���������� � ������

	//�������� ������������ � ���� ������
	cht.addUser(user);
	std::cout << "Your user account successfully created.\n";

}


//���� � ��� ������������������� ������������ �� ������ � ������
void Interface::logIn(Chat& cht)
{
	std::cout << "Enter your loggin:\n";
	std::string lg_inp;
	std::cin >> lg_inp;

	if (!cht.findUser(lg_inp))//�������� ���������� ������ �� ������� ������ �����
	{
		std::cout << "There is no user with this login.\n";
		return;
	}


	active_user = cht.getUser(lg_inp);//��������� ��������� �� ������������

	std::cout << "Enter your password:\n";
	std::string pass_inp;
	std::cin >> pass_inp;

	if (active_user->checkPass(pass_inp))
	{
		std::cout << "You have successfully signed in.\n\n";
		LoggedIn = true;//��������� ���������� ������� ������
	}
	else
		std::cout << "The password is incorrect.\n";
}

//����� �� ����
void Interface::quit()
{
	enable = false;//���������� ������� ������ ����������
}

//��������� ����� ��������� �� ����������������� �����
void Interface::readTheInput(std::string& str)
{
	char ch[100];
	std::cin.get(ch, 100, '#');
	str += ch;
}

//��������� ������� ������
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
	while (!(std::cin >> input))//�������� �����
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input shood be an integer from 1 to 6. Please, try again.\n";
	}

	switch (input)
	{
		//�������� ��������� ��� ����
	case 1: {
		std::cout << "Enter the message up to 100 symbols (enter # to finish the message):\n";
		std::string inp_text;
		readTheInput(inp_text);

		std::string from = (active_user->getName());
		std::string to = "all";

		Message<std::string> fresh(to, from, inp_text);//�������� ������� ���������

		cht.addMessageToAll(fresh);

		return true;
	}

		  //�������� ��������� ����������� ������������
	case 2: {

		{//�������� ������������� ��������
			std::cout << "\nList of current users:\n";
			cht.showUsers();
		}
		//������ ����������
		std::cout << "Enter recipient's name:\n";
		std::string to;
		std::cin >> to;
		//�������� �� ������� ������ ����������
		if (!cht.findUserByName(to))
		{
			std::cout << "Can Not Find the user.\n";
			return true;
		}

		std::string from = (active_user->getName());
		std::cout << "Enter the message up to 100 symbols (enter # to finish the message):\n";
		std::string inp_text;
		readTheInput(inp_text);

		Message<std::string> fresh(to, from, inp_text);//�������� ������� ���������

		//��������� ���������� ������� �����
		std::cout << "Adding message to a recepients thread\n";

		User* recipient_user = cht.getUserByName(to);//��������� �� ���������� ���������
		if (recipient_user)
		{
			recipient_user->addMessageToMyCollection(fresh);
			std::cout << "Added\n";
		}
		else
			std::cout << "Something went wrong.\n";

		return true;

	}

		  //�������� ��������� �� ������� ����� ���������
	case 3:
	{
		std::cout << "Enter a serial number of a message you want to read:\n";
		size_t n;
		while (!(std::cin >> n))//�������� �����
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Input shood be a posotive integer. Please, try again.\n";
		};

		//��������� ���������� ���� ���������� ����� ��������
		try {
			cht.readMsgAll(n);
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
		}

		return true;
	}

	//�������� ��������� �� ������� ������������ ���������
	case 4:
	{
		std::cout << "Enter a serial number of a message you want to read:\n";
		size_t n;
		while (!(std::cin >> n))//�������� �����
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Input shood be a positive integer. Please, try again.\n";
		}

		//��������� ���������� ���� ���������� ����� ��������
		try {
			active_user->readPersonalMsg(n);
		}

		catch (std::exception& e)
		{
			std::cout << e.what();
		}
		return true;
	}

	//������������ ��������� ��� ����� ������ � ����� ������������
	case 5:
	{
		bool in_personal = true;//��������� ���������� ������ ������������� ����������
		while (in_personal)
		{
			std::cout << "You may change your user's name and password:\n";
			std::cout << "1 Change user's name.\n";
			std::cout << "2 Change user's password.\n";
			std::cout << "3 Go upward menu.\n";
			int input;
			while (!(std::cin >> input))//�������� �����
			{
				std::cin.clear();
				while (std::cin.get() != '\n')
					continue;
				std::cout << "Input shood be an integer 1, 2  or 3. Please, try again.\n";
			}

			switch (input)
			{
			case 1://����� ����� ������������
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
			case 2://����� ������ ������������
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
			case 3://����� �� ������������� ���� �� ������ ������� ����������
			{
				in_personal = false;
				break;
			}
			default://���� ������� �� 1, 2, 3, �� ���� ����� �� ������ ������� ����������
			{
				in_personal = false;
				break;
			}

			}
		}


		return true;
	}


	case 6: //����� � ������ ������� ����������
	{

		LoggedIn = false;
		return false;
	}


	default: //���� ������� ����� �� �� 1 �� 6, �� ���� ����� � ������ ������� ����������
		return false;
	}


}