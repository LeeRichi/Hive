#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: <progame.name> <level>" << std::endl;
		return (1);
	}

	Harl rich;
	rich.complain(av[1]);

	return 0;
}
