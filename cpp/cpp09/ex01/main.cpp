#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <a string of RPN>" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.evaluate(av[1]);

	return 0;
}
