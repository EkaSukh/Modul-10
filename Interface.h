#pragma once
#include "User.h"
#include "Chat.h"


//��������������� ��������� �������
//������������ ��� ����������� ������ Interface
class User;
class Chat;

//����� ��������� ������� ����� ������������� � ����������� �������� ���������
class Interface
{
public:
	//����������� � ����������
	Interface()
	{}
	~Interface() {}

	//������ ������� ���������� ������
	bool Enable(Chat& chat);//������ ������ ����������� �� ������� ����� �������

	//������� �������� � ������ ������ ���������� � ��������� �� Enable()
	static void registration(Chat& cht);
	void logIn(Chat& cht);
	void quit();

	//������ ������� ����������
	bool startChat(Chat& cht);

	//������ ���� ����������� �� ����������� ������ ��������
	static void readTheInput(std::string& str);

private:
	//���������� ������������ ����������� ����� ����������
	bool enable = true;//���������� 1-�� ������� ����������
	bool LoggedIn = false;//���������� 2-�� ������� ����������

	//��������� �� �����, ������� ����� ����� ��������� ����� ����� �� 2-�� ������� ����������
	User* active_user = nullptr;

};