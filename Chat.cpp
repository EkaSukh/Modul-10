#include <iostream>
#include <vector>
#include "Chat.h"
#include "Message.h"
#include "User.h"

//работа с вектором юзеров

//добавляем юзера в конец
bool Chat::AddUser(const User& usr)
{
	Users.push_back(usr);
	return true;
	//а когда же функция будет принимать значения ложь?

}

//Выводим список юзеров по имени
void Chat::ShowUsers()
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)
	{
		std::cout << usr->getName() << std::endl;
	}
}

//находит юзера по логину и возвращает успешность
bool Chat::FindUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
			return true;
	}

	return false;

}

bool Chat::FindUser_by_name(const std::string& name)
{
	std::vector<User>::iterator usr;
	for (usr = Users.begin();usr != Users.end();usr++)
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
			return true;
	}

	return false;

}


std::shared_ptr<User> Chat::GetUser(const std::string& login)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end();i++,usr++)
	{
		std::string tmp = usr->getLogin();
		if (0 == tmp.compare(login))
		{
			std::shared_ptr<User> usr(&Users[i]);
			return usr;
		}
					
	}
	return nullptr;
		
}

std::shared_ptr<User> Chat::GetUser_by_name(const std::string& name)
{
	std::vector<User>::iterator usr;
	int i = 0;
	for (usr = Users.begin();usr != Users.end();i++, usr++)
	{
		std::string tmp = usr->getName();
		if (0 == tmp.compare(name))
		{
			std::shared_ptr<User> usr(&Users[i]);
			return usr;
		}

	}
	return nullptr;

}

void Chat::ChatState(std::shared_ptr<User> usr)
{
	std::cout << "Messages from all users: " << count_allMessages() << std::endl;
	std::cout << "Personal mesages: " << usr->Count_received_msg() << std::endl;

	/*
	if (threads.empty())
		std::cout << "Personal messages to you: " << threads.size() << std::endl;
	else
	{
		std::cout << "Total number of personal threads: " << threads.size() << std::endl;
		if (FindThread(usr->getName())) 
		{
			std::cout << "Found your thread.\n";
			std::shared_ptr<std::vector<Message> > found_t_ptr = get_thread_ptr(usr->getName());
			std::cout << "got your thread pointer\n";
			int n = 

		}
			
		else
			std::cout << "Did not find your thread.\n";
	}
		*/


	//std::cout << "Personal messages to you: " << count_in_thread(get_thread_ptr(usr->getName()));

}


//работа с вектором общих сообщений
bool Chat::Add_message_to_all(const Message& msg_all)
{
	all_messages.push_back(msg_all);
	return true;
	//а когда же функция будет принимать значения ложь?
}

void Chat::Show_AllMessages_sender()
{
	if (all_messages.empty())
	{
		std::cout << "There is no messages yet/\n";
	}
	else
	{ 
	std::vector<Message>::iterator msg;
	int i = 0;
		for (msg = all_messages.begin();msg != all_messages.end();i++,msg++)
		{
			std::cout << "#" << i + 1 << " from " << msg->Show_From() << std::endl;

		}
	}
}

const int Chat::count_allMessages()
{
	return all_messages.size();
}

void Chat::Read_msg_in_all(const int num_of_msg) //сделать этоц функции exception
{
	if (all_messages.empty())
	{
		std::cout << "There is no messages yet\n";
	}
	else
	{
		if (num_of_msg <= all_messages.size())
		{
			std::cout << "Text:\n";
			std::cout << all_messages[num_of_msg - 1].Show_Text() << std::endl;

		}
		else
			std::cout << "Index is out of range.\n";
		
	}
}



//работа с вектором векторов персональных сообщений



/*
* void Chat::Create_Personal_Thread(User& usr)
{
	if (usr.GetMyThread())
	{
		std::cout << "Personal thread for this user already exist.\n";
		return;
	}
	else
	{
		std::vector <Message> fresh_user;
		threads.push_back(fresh_user);

		int t = threads.size() - 1;
		std::shared_ptr<std::vector <Message> > fresh_user_ptr (&threads[t]);
		
		usr.SetMyThread(fresh_user_ptr);
		std::cout << "Setted thread for a new user.\n";

	}
	
}

const int Chat::count_in_thread(const User& usr)
{
	return (usr.GetMyThread())->size();
}

void Chat::Add_msg_to_personal_thrd(const std::string to_name, const Message& msg)
{
	std::shared_ptr<User> to_whom_ptr = GetUser_by_name(to_name);
	std::shared_ptr< std::vector<Message> > pers_recip_thrd_ptr = to_whom_ptr->GetMyThread();
	//пложить в конец вектора по ссылке
	pers_recip_thrd_ptr->push_back(msg);
	std::cout << "Your message has been sent.\n";
}
const int Chat::count_threads()
{
	return threads.size();
}

void Chat::Show_threads()
{
	std::vector <std::vector<Message> > ::iterator trd_ptr;
	int i = 0;
	for (trd_ptr = threads.begin(); trd_ptr != threads.end(); i++, trd_ptr++)
	{
		std::cout << "There are " << count_threads() << " personal threads.\n";
		std::cout << "thread" << i+1 << " to " << threads[i][0].Show_To() << std::endl;
	}
}

bool Chat::FindThread(const std::string& name)
{
	std::vector <std::vector<Message> > ::iterator trd_itr;
	int i = 0;
	for (trd_itr = threads.begin(); trd_itr != threads.end(); i++, trd_itr++)
	{
		if (0 == name.compare(threads[i][0].Show_To()))
			return true;
	}

	return false;	
}

std::shared_ptr<std::vector<Message> > Chat::get_thread_ptr(const std::string& name)
{
	std::vector <std::vector<Message> > ::iterator trd_itr;
	
	int i = 0;
	for (trd_itr = threads.begin(); trd_itr != threads.end(); i++, trd_itr++)
	{
		if (0 == name.compare(threads[i][0].Show_To()))
		{
			std::shared_ptr<std::vector<Message> > t_ptr(& threads[i]);
			return t_ptr ;
		}
	}

	return nullptr;

}

const int Chat::count_in_thread(std::shared_ptr<std::vector<Message> > t_ptr)
{
	return t_ptr->size();
}


bool Chat::Add_mesage_to_existing_thread(Message& msg, std::shared_ptr<std::vector<Message> > t_ptr)
{
	t_ptr->push_back(msg);
	return true;

}

bool Chat::Add_mesage_to_new_thread(Message& msg)
{
	std::vector<Message> fresh_m;
	fresh_m.push_back(msg);
	threads.push_back(fresh_m);
	return true;
}

void Chat::Read_msg_in_thread(const int num_of_msg, std::shared_ptr<std::vector<Message> > t_ptr)
{
	std::vector<Message> ::iterator trd_ptr;
	std::cout << "Text:\n";
	trd_ptr = t_ptr->begin();//Какая-то страннач конструкция
	Message msg = *trd_ptr;
	std::cout << msg.Show_Text() << std::endl;
}

*/