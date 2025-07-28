#pragma once
// #include <vector>
#include <climits>
#include <stdexcept>
#include <stack>

class RPN{
	private:
		std::stack<int> value_stack;

	public:
		RPN();
		RPN(const RPN &og);
		RPN &operator=(const RPN &og);
		~RPN();

		void evaluate(const std::string &expression);
};
