#include "Chat.h"



//ÑÐ°Ð±Ð¾ÑÐ° Ñ Ð²ÐµÐºÑÐ¾ÑÐ¾Ð¼ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹

//Ð´Ð¾Ð±Ð°Ð²Ð»ÑÐµÐ¼ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð² ÐºÐ¾Ð½ÑÐµÐ½ÐµÑ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹



void Chat::addUser(const User& usr)
{
	Users.insert({ usr.getLogin(), usr});
}


//Ð²ÑÐ²Ð¾Ð´Ð¸Ð¼ ÑÐ¿Ð¸ÑÐ¾Ðº Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹ ÑÐ°ÑÐ° Ð¿Ð¾ Ð¸Ð¼ÐµÐ½Ð¸
void Chat::showUsers()
{
	std::map <std::string , User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)

	{
		std::cout << usr->second.getName() << std::endl;
	}
}

//Ð½Ð°ÑÐ¾Ð´Ð¸Ñ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð¿Ð¾ Ð»Ð¾Ð³Ð¸Ð½Ñ Ð¸ Ð²Ð¾Ð·Ð²ÑÐ°ÑÐ°ÐµÑ ÑÑÐ¿ÐµÑÐ½Ð¾ÑÑÑ

bool Chat::findUser(const std::string& login)
{
	std::map <std::string, User>::iterator usr = Users.find(login);
	
	if(usr != Users.end())
			return true;
	else
		return false;
}


//Ð½Ð°ÑÐ¾Ð´Ð¸Ñ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ð¿Ð¾ Ð¸Ð¼ÐµÐ½Ð¸ Ð¸ Ð²Ð¾Ð·Ð²ÑÐ°ÑÐ°ÐµÑ ÑÑÐ¿ÐµÑÐ½Ð¾ÑÑÑ
bool Chat::findUserByName(const std::string& name)
{
	std::map <std::string, User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();++usr)

	{
		std::string tmp = usr->second.getName();
		if (0 == tmp.compare(name))
			return true;
	}

	return false;

}


//Ð²Ð¾Ð·Ð²ÑÐ°ÑÐ°ÐµÑ ÑÐºÐ°Ð·Ð°ÑÐµÐ»Ñ Ð½Ð° Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ñ Ð´Ð°Ð½Ð½ÑÐ¼ Ð»Ð¾Ð³Ð¸Ð½Ð¾Ð¼

User* Chat::getUser(const std::string& login)
{
	std::map <std::string, User>::iterator usr = Users.find(login);
	
	if (usr != Users.end())
		return &(usr->second);
	else
		return nullptr;
}


//Ð²Ð¾Ð·Ð²ÑÐ°ÑÐ°ÐµÑ ÑÐºÐ°Ð·Ð°ÑÐµÐ»Ñ Ð½Ð° Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ Ñ Ð´Ð°Ð½Ð½ÑÐ¼ Ð¸Ð¼ÐµÐ½ÐµÐ½Ð¼

User* Chat::getUserByName(const std::string& name)
{

	std::map <std::string, User>::iterator usr;

	for (usr = Users.begin();usr != Users.end();++usr)

	{
		std::string tmp = usr->second.getName();
		if (0 == tmp.compare(name))
			return &(usr->second);
	}	
	return nullptr;

}


//Ð¾ÑÐ¾Ð±ÑÐ°Ð¶Ð°ÐµÑ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð² Ð¼Ð°ÑÑÐ¸Ð²Ð°Ñ Ð¾Ð±ÑÐ¸Ñ Ð¸ Ð¿ÐµÑÑÐ¾Ð¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð´Ð»Ñ ÐºÐ¾Ð½ÐºÑÐµÑÐ½Ð¾Ð³Ð¾ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ

void Chat::chatState(User* usr)
{
	std::cout << "Messages from all users: " << countAllMessages() << std::endl;
	std::cout << "Personal mesages: " << usr->countReceivedMsg() << std::endl;

}


//ðàáîòà ñ âåêòîðîì îáùèõ ñîîáùåíèé


//Ð´Ð¾Ð±Ð°Ð²Ð»ÑÐµÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ðµ Ð² ÐºÐ¾Ð½ÐµÑ Ð²ÐµÐºÑÐ¾ÑÐ° Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹

void Chat::addMessageToAll(const Message<std::string>& msg_all)
{
	all_messages.push_back(msg_all);
}


//Ð¿Ð¾Ð´ÑÑÐ¸ÑÑÐ²Ð°ÐµÑ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð² Ð¼Ð°ÑÑÐ¸Ð²Ðµ Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹

size_t Chat::countAllMessages() const
{
	return all_messages.size();
}


//Ð²ÑÐ²Ð¾Ð´ ÑÐµÐºÑÑÐ° ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð¿Ð¾ ÐµÐ³Ð¾ Ð¿Ð¾ÑÑÐ´ÐºÐ¾Ð²Ð¾Ð¼Ñ Ð½Ð¾Ð¼ÐµÑÑ Ð² Ð¼Ð°ÑÑÐ¸Ð²Ðµ Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹
void Chat::readMsgAll(const size_t num_of_msg)
{
	//ÐºÐ¾Ð³Ð´Ð° Ð½ÐµÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹



	if (all_messages.empty())
	{
		std::cout << "There is no messages yet.\n";
	}
	else//åñòü ñîîáùåíèÿ
	{
		if ((num_of_msg <= all_messages.size()))
		{
			all_messages[num_of_msg - 1].showMessage();
		}
		else
			throw bad_range();

	}
}


//Ð·Ð°Ð¿Ð¸ÑÑ ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸ Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð² ÑÐ°Ð¹Ð»
void Chat::printToFile()
{
	std::ofstream messages_file("messages_to_all.txt");
	//ÑÐ¸ÐºÑÐ¸ÑÑÐµÐ¼ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð² ÑÑÐ°Ð½Ð¸Ð»Ð¸ÑÐµ
	messages_file << countAllMessages();

	//Ð·Ð°Ð¿Ð¸ÑÑÐ²Ð°ÐµÐ¼ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð² ÑÑÐ°Ð½Ð¸Ð»Ð¸ÑÐµ
	for(auto itr = all_messages.begin(); itr != all_messages.end(); ++itr)
		messages_file << *itr;

	//Ð¾Ð¿ÑÐµÐ´ÐµÐ»ÑÐµÐ¼ Ð¿ÑÐ°Ð²Ð° Ð´Ð¾ÑÑÑÐ¿Ð° Ðº ÑÐ°Ð¹Ð»Ñ ÑÐ¾Ð»ÑÐºÐ¾ Ð´Ð»Ñ Ð²Ð»Ð°Ð´ÐµÐ»ÑÑÐ°
	std::filesystem::permissions("messages_to_all.txt", std::filesystem::perms::group_all | std::filesystem::perms::others_all, std::filesystem::perm_options::remove);
}

//ÑÑÐµÐ½Ð¸Ðµ ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸ Ð¾Ð±ÑÐ¸Ñ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹ Ð¸Ð· ÑÐ°Ð¹Ð»Ð°
void Chat::readFromFile()
{
	std::ifstream messages_file("messages_to_all.txt");
	//ÐµÑÐ»Ð¸ ÑÐ°ÐºÐ¾Ð³Ð¾ ÑÐ°Ð¹Ð»Ð° Ð½ÐµÑ
	if(!messages_file)
	return;

	messages_file.seekg(0, std::ios_base::beg);
	//Ð¿Ð¾Ð»ÑÑÐ°ÐµÐ¼ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸ Ð² ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ð¸
	size_t number_of_messages;
	messages_file >> number_of_messages;

	//Ð²ÑÐ¾Ð´Ð¸Ð¼ Ð² ÑÐ¸ÐºÐ» Ð¿Ð¾ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ñ ÑÐ¾Ð¾Ð±ÑÐ¸Ð½Ð¸Ð¹
	while(number_of_messages != 0)
	{
		//ÑÑÐ¸ÑÑÐ²Ð°ÐµÐ¼ ÑÐ¾Ð¾Ð±ÑÐ¸ÐµÐ½Ð¸Ðµ Ð²Ð¾ Ð²ÑÐµÐ¼ÐµÐ½Ð½ÑÐ¹ Ð¾Ð±ÑÐµÐºÑ Ð¸ ÐºÐ»Ð°Ð´ÐµÐ¼ ÐµÐ³Ð¾ Ð² ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ñ
		Message<std::string> msg_tmp;
		messages_file >> msg_tmp;
		all_messages.push_back(msg_tmp);

		//Ð¿Ð¾ÑÐ»Ðµ ÑÑÐ¸ÑÑÐ²Ð°Ð½Ð¸Ñ ÑÐ¸Ð¼Ð²Ð¾Ð» '#' Ð¾ÑÑÐ°Ð»ÑÑ Ð² Ð¿Ð¾ÑÐ¾ÐºÐµ Ð¸ Ð½ÑÐ¶Ð½Ð¾ ÐµÐ³Ð¾ Ð¿ÑÐ¾Ð¿ÑÑÑÐ¸ÑÑ
		int position = messages_file.tellg();
		messages_file.seekg(position + 1, std::ios_base::beg);

		--number_of_messages;
	}
}

//Ð·Ð°Ð¿Ð¸ÑÑ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹ Ð² ÑÐ°Ð¹Ð»
void Chat::writeUsersToFile()
{
	std::ofstream users_file("users_file.txt");
	//ÑÐ¸ÐºÑÐ¸ÑÑÐµÐ¼ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ Ð² ÑÑÐ°Ð½Ð¸Ð»Ð¸ÑÐµ
	users_file << Users.size();

	//Ð·Ð°Ð¿Ð¸ÑÑÐ²Ð°ÐµÐ¼ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð² ÑÑÐ°Ð½Ð¸Ð»Ð¸ÑÐµ
	for(auto itr = Users.begin(); itr != Users.end(); ++itr)
		users_file << itr->second;

	//Ð¾Ð¿ÑÐµÐ´ÐµÐ»ÑÐµÐ¼ Ð¿ÑÐ°Ð²Ð° Ð´Ð¾ÑÑÑÐ¿Ð° Ðº ÑÐ°Ð¹Ð»Ñ ÑÐ¾Ð»ÑÐºÐ¾ Ð´Ð»Ñ Ð²Ð»Ð°Ð´ÐµÐ»ÑÑÐ°
	std::filesystem::permissions("users_file.txt", std::filesystem::perms::group_all | std::filesystem::perms::others_all, std::filesystem::perm_options::remove);

}

//Ð²Ð¾ÑÑÑÐ°Ð½Ð¾Ð²Ð»ÐµÐ½Ð¸Ðµ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹ Ð¸Ð· ÑÐ°Ð¹Ð»Ð°
void Chat::restoreUsersFromFile()
{
	
	std::ifstream users_file("users_file.txt");
	//ÐµÑÐ»Ð¸ Ð½ÐµÑ ÑÐ°ÐºÐ¾Ð³Ð¾ ÑÐ°Ð¹Ð»Ð°
	if(!users_file)
		return;

	//Ð¿Ð¾Ð»ÑÑÐ°ÐµÐ¼ ÑÐºÐ¾Ð»ÑÐºÐ¾ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»ÐµÐ¹ Ð·Ð°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð² ÑÐ°Ð¹Ð»
	int num_users;
	users_file >> num_users;
	
	//ÐºÐ°Ð¶Ð´Ð¾Ð³Ð¾ Ð¿Ð¾Ð»ÑÐ·Ð¾Ð²Ð°ÑÐµÐ»Ñ ÑÐ¾Ð·Ð´Ð°ÐµÐ¼ Ð¿Ð¾ Ð¾ÑÐµÑÐµÐ´Ð¸ Ð¿Ð¾ÐºÐ° Ð½Ðµ Ð²Ð¾ÑÑÑÐ°Ð½Ð¾Ð²Ð¸Ð¼ Ð²ÑÐµÑ
	while(num_users != 0)
	{
		--num_users;
		//ÑÐ¾Ð·Ð´Ð°ÐµÐ¼ Ð²ÑÐµÐ¼ÐµÐ½Ð½ÑÐ¹ Ð¾Ð±ÑÐµÐºÑ 
		std::string tmp_login;
		users_file >> tmp_login;
		std::string tmp_pass;
		users_file >> tmp_pass;
		std::string tmp_name;
		users_file >> tmp_name;

		User user_tmp(tmp_login, tmp_pass, tmp_name);
		
		//Ð¿Ð¾Ð»ÑÑÐ°ÐµÐ¼ ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÐµÐ³Ð¾ Ð¿ÐµÑÑÐ¾Ð½Ð°Ð»ÑÐ½ÑÑ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ð¹
		size_t num_msg;
		users_file >> num_msg;
		
		//Ð²Ð¾ÑÑÑÐ°Ð½Ð°Ð²Ð»Ð¸Ð²Ð°ÐµÐ¼ Ð²ÑÐµ ÑÐ¾Ð¾Ð±ÑÐµÐ½Ð¸Ñ Ð¸Ð· ÐºÐ¾Ð»ÐµÐºÑÐ¸Ð¸ Ð¿Ð¾ Ð¾ÑÐµÑÐµÐ´Ð¸
		while(num_msg != 0)
		{
			--num_msg;

			//ÑÐ¾Ð·Ð´Ð°ÐµÐ¼ Ð²ÑÐµÐ¼ÐµÐ½Ð½ÑÐ¹ Ð¾Ð±ÑÐµÐºÑ Ð¸ ÐºÐ»Ð°Ð´ÐµÐ¼ ÐµÐ³Ð¾ Ð² ÐºÐ¾Ð»Ð»ÐµÐºÑÐ¸Ñ
			Message<std::string> msg_tmp;
			users_file >> msg_tmp;
			user_tmp.addMessageToMyCollection(msg_tmp);
			
			//Ð¿Ð¾ÑÐ»Ðµ ÑÑÐ¸ÑÑÐ²Ð°Ð½Ð¸Ñ ÑÐ¸Ð¼Ð²Ð¾Ð» '#' Ð¾ÑÑÐ°Ð»ÑÑ Ð² Ð¿Ð¾ÑÐ¾ÐºÐµ Ð¸ Ð½ÑÐ¶Ð½Ð¾ ÐµÐ³Ð¾ Ð¿ÑÐ¾Ð¿ÑÑÑÐ¸ÑÑ
			int position = users_file.tellg();
			users_file.seekg(position + 1, std::ios_base::beg);
		}
		//
		addUser(user_tmp);
		
	}
  }
