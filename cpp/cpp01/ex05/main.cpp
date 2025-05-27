#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl rich;

	std::cout << ":::valid session:::" << std::endl;
	std::cout << std::endl << "--- dubug ---" << std::endl;
	rich.complain("DEBUG");
	std::cout << std::endl << "--- info ---" << std::endl;
	rich.complain("INFO");
	std::cout << std::endl << "--- warning ---" << std::endl;
	rich.complain("WARNING");
	std::cout << std::endl << "--- error ---" << std::endl;
	rich.complain("ERROR");

	std::cout << std::endl << ":::invalid session:::" << std::endl;
	rich.complain("something else");
	return 0;
}
