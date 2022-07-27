#include "Interface.h"
#include "Chat.h"
#include "syscall.h"

int main()
{
//выполнение системных вызовов для вывода данных о системе
#if defined(__linux__)
printVersionLinux();
#elif defined(_WIN32)
printVersionWind32();
#elif defined(_WIN64)
printVersionWind64();  
#endif


//создание объетов чата
	Interface interactive_menu;//объект интрефэйса
	Chat chat; //объект чата
	std::cout << "Welcome to our chat!\n";

//восстановление состояния чата из файлов
	//колекция общих сообщений
	chat.readFromFile();
	//состояния пользователей и их персональных коллеций сообщений
	chat.restoreUsersFromFile();

//вход в тело чата
	while (interactive_menu.Enable(chat)) //вход в интерфэйс первого уровня
	{
		while (interactive_menu.startChat(chat))//вход в интерфэйс второго уровня
			continue;
	}
	std::cout << "Thank you for chatting.\n";

	return 0;
}
