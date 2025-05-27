#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << _name << "is being created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " is being destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}