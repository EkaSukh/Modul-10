#pragma once
#include <iostream>
#include <fstream>

// класс является самым низкоуровневым
//задан шаблоном
//создана явная специализаци¤ данного шаболона для типа std::string
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

//явная специализация шаблона для типа std::string
//данная спциализация будет использоваться всеми остальными классами
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
	//определение процедуры записи сообщения в файл
	friend std::ofstream& operator <<(std::ofstream& os, Message& msg)
	{
		os << ' ';
		os << msg._from;
		os << ' ';
		os << msg._to;
		os << ' ';
		os << msg._text;
		os << "#";

		return os;
	}

	//определение процедуры считывания сообщения из файла
	friend std::ifstream& operator >>(std::ifstream& is, Message& msg)
	{
		is >> msg._from;
		is >> msg._to;

		std::string text_str;
		char ch[100];
		is.get(ch, 100, '#');
		text_str += ch;
		msg._text = text_str;

		return is;
	}

private:
	std::string _to;
	std::string _from;
	std::string _text;
};
