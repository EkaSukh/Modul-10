#include "Interface.h"
#include "Chat.h"
#include <iostream>


int main()
{
	Interface interface;//������ ����������
	Chat chat; //������ ����
	std::cout << "Welcome to our chat!\n";

	while (interface.Enable(chat)) //���� � ��������� ������� ������
	{
		while (interface.startChat(chat))//���� � ��������� ������� ������
			continue;
	}
	std::cout << "Thank you for chatting.";

	return 0;
}