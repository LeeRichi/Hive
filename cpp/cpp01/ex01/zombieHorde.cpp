#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 1) return NULL;

    Zombie* horde = new Zombie[N];

    for(size_t i; i = 0; i < N)
    {
        horde[i].setName(name);
    }
    return (horde);
}