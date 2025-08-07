#include "RPN.hpp"
#include <iostream>
#include <sstream>
// #include <string>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &og)
{
	if (this != &og)
	{
		this->value_stack = og.value_stack;
	}
	return *this;
}

RPN::~RPN() {}

static int valueIsInRange(int value) //yes, it is becasue of the subject being unclear
{
	return (value < 10);
}

void RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	int result;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (value_stack.size() < 2)
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return;
			}
			int temp = value_stack.top();
			value_stack.pop();
			if (token == "+")
				result = value_stack.top() + temp;
			else if (token == "-")
				result = value_stack.top() - temp;
			else if (token == "*")
				result = value_stack.top() * temp;
			else if (token == "/")
			{
				if (temp == 0)
				{
					std::cerr << "Error: can't devide by 0" << std::endl;
					return;
				}
				else
					result = value_stack.top() / temp;
			}
			value_stack.pop();
			value_stack.push(result);
		}
		else
		{
			try {
				size_t idx;
				int number = std::stoi(token, &idx);
				if (idx != token.length() || !valueIsInRange(number)) {
					std::cerr << "Error" << std::endl;
					return;
				}
				value_stack.push(number);
			}
			catch (const std::invalid_argument &e) {
				std::cerr << "Error" << std::endl;
				return;
			}
			catch (const std::out_of_range &e) {
				std::cerr << "Error" << std::endl;
				return;
			}
		}
	}
	if (value_stack.size() == 1)
		std::cout << value_stack.top() << std::endl;
	else
		std::cerr << "Error: invalid expression" << std::endl;
}
