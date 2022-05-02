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

private:
	std::string _to;
	std::string _from;
	std::string _text;
};