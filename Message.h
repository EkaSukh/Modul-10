#pragma once
#include <iostream>


class Message
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