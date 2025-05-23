#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde = zombieHorde(4, "Jared Heap Boi");
	if (!horde)
		return 1;
	horde[2].announce();
    delete[] horde;
	return (0);
}
