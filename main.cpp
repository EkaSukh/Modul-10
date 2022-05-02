#include "Message.h"
#include "User.h"
#include "Interface.h"
#include "Chat.h"
#include <iostream>
#include <vector>

int main()
{
	Interface interface1;
	Chat *chat1 = new Chat;
	std::cout << "Welcome to our chat!\n";

	while (interface1.Enable(*chat1))
	{
		while (interface1.StartChat(*chat1))
			continue;
	}
	std::cout << "Thak you for chatting.";

	return 0;
}