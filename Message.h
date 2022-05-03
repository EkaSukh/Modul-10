#pragma once
#include <iostream>

template <typename Field>
class Message
{
public:
	Message() {}
	Message(const Field& to, const Field& from, const Field& text) :
		_to(to), _from(from), _text(text) {}
	~Message() {}
	Field Show_From() const { return _from; }
	Field Show_To() const { return _to; }
	Field Show_Text() const { return _text; }
	void Show_Message()
	{
		std::cout << "_____________\n";
		std::cout << "From: " << Show_From() << std::endl;
		std::cout << "To: " << Show_To() << std::endl;
		std::cout << "** " << Show_Text() << " **" << std::endl;
		std::cout << "_____________\n";

	}

private:
	Field _to;
	Field _from;
	Field _text;
};

template<> class Message <std::string>
{
public:
	Message() {}
	Message(const std::string& to, const std::string& from, const std::string& text) :
		_to(to), _from(from), _text(text) {}
	~Message() {}
	std::string Show_From() const { return _from; }
	std::string Show_To() const { return _to; }
	std::string Show_Text() const { return _text; }
	void Show_Message()
	{
		std::cout << "_____________\n";
		std::cout << "From: " << Show_From() << std::endl;
		std::cout << "To: " << Show_To() << std::endl;
		std::cout << "** " << Show_Text() << " **" << std::endl;
		std::cout << "_____________\n";

	}

private:
	std::string _to;
	std::string _from;
	std::string _text;
};