#pragma once
#include <iostream>
#include <fstream>


// ÐºÐ»Ð°ÑÑ ÑÐ²Ð»ÑÐµÑ‚ÑÑ ÑÐ°Ð¼Ñ‹Ð¼ Ð½Ð¸Ð·ÐºÐ¾ÑƒÑ€Ð¾Ð²Ð½ÐµÐ²Ñ‹Ð¼
//Ð·Ð°Ð´Ð°Ð½ ÑˆÐ°Ð±Ð»Ð¾Ð½Ð¾Ð¼
//ÑÐ¾Ð·Ð´Ð°Ð½Ð° ÑÐ²Ð½Ð°Ñ ÑÐ¿ÐµÑ†Ð¸Ð°Ð»Ð¸Ð·Ð°Ñ†Ð¸Â¤ Ð´Ð°Ð½Ð½Ð¾Ð³Ð¾ ÑˆÐ°Ð±Ð¾Ð»Ð¾Ð½Ð° Ð´Ð»Ñ Ñ‚Ð¸Ð¿Ð° std::string


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


//ÑÐ²Ð½Ð°Ñ ÑÐ¿ÐµÑ†Ð¸Ð°Ð»Ð¸Ð·Ð°Ñ†Ð¸Ñ ÑˆÐ°Ð±Ð»Ð¾Ð½Ð° Ð´Ð»Ñ Ñ‚Ð¸Ð¿Ð° std::string
//Ð´Ð°Ð½Ð½Ð°Ñ ÑÐ¿Ñ†Ð¸Ð°Ð»Ð¸Ð·Ð°Ñ†Ð¸Ñ Ð±ÑƒÐ´ÐµÑ‚ Ð¸ÑÐ¿Ð¾Ð»ÑŒÐ·Ð¾Ð²Ð°Ñ‚ÑŒÑÑ Ð²ÑÐµÐ¼Ð¸ Ð¾ÑÑ‚Ð°Ð»ÑŒÐ½Ñ‹Ð¼Ð¸ ÐºÐ»Ð°ÑÑÐ°Ð¼Ð¸

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
	//Ð¾Ð¿Ñ€ÐµÐ´ÐµÐ»ÐµÐ½Ð¸Ðµ Ð¿Ñ€Ð¾Ñ†ÐµÐ´ÑƒÑ€Ñ‹ Ð·Ð°Ð¿Ð¸ÑÐ¸ ÑÐ¾Ð¾Ð±Ñ‰ÐµÐ½Ð¸Ñ Ð² Ñ„Ð°Ð¹Ð»
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

	//Ð¾Ð¿Ñ€ÐµÐ´ÐµÐ»ÐµÐ½Ð¸Ðµ Ð¿Ñ€Ð¾Ñ†ÐµÐ´ÑƒÑ€Ñ‹ ÑÑ‡Ð¸Ñ‚Ñ‹Ð²Ð°Ð½Ð¸Ñ ÑÐ¾Ð¾Ð±Ñ‰ÐµÐ½Ð¸Ñ Ð¸Ð· Ñ„Ð°Ð¹Ð»Ð°
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
