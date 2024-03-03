#pragma once

#include <exception>
#include <iostream>
#include <string>

class StackException: public std::exception
{
public:
	StackException() :
		whatStr("StackOverflow") {};

	const char* what() const noexcept override 
	{
		return whatStr.c_str();
	};
	~StackException() noexcept = default;

private:
	std::string whatStr;
};

class WrongStackSize : public std::exception 
{
public:
	WrongStackSize() :
		whatStr("Stack is empty!") {};

	const char* what() const noexcept override
	{
		return whatStr.c_str();
	}
	~WrongStackSize() noexcept = default;
private:
	std::string whatStr;
};