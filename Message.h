#pragma once
#include <iostream>

// ���� ������ ����� ��������������
//����� ��������
//������� ���� ������������ ������� �������� �� ���� std::string
template <typename Field>
class Message
{
public:
	Message() {}
	Message(const Field& to, const Field& from, const Field& text) :
		_to(to), _from(from), _text(text) {}
	~Message() {}
	Field showFrom() const { return _from; }
	Field showTo() const { return _to; }
	Field showText() const { return _text; }
	void showMessage() const
	{
		std::cout << "_____________\n";
		std::cout << "From: " << showFrom() << std::endl;
		std::cout << "To: " << showTo() << std::endl;
		std::cout << "** " << showText() << " **" << std::endl;
		std::cout << "_____________\n";

	}

private:
	Field _to;
	Field _from;
	Field _text;
};

//���� ������������ ������� �� ���� std::string
//����� ����������� ����� ������������� ����� ���������� ��������
template<> class Message <std::string>
{
public:
	Message() {}
	Message(const std::string& to, const std::string& from, const std::string& text) :
		_to(to), _from(from), _text(text) {}
	~Message() {}
	std::string showFrom() const { return _from; }
	std::string showTo() const { return _to; }
	std::string showText() const { return _text; }
	void showMessage() const
	{
		std::cout << "_____________\n";
		std::cout << "From: " << showFrom() << std::endl;
		std::cout << "To: " << showTo() << std::endl;
		std::cout << "** " << showText() << " **" << std::endl;
		std::cout << "_____________\n";

	}

private:
	std::string _to;
	std::string _from;
	std::string _text;
};
