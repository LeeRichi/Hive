#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
    _name = ClapTrap::_name;
    _hitPoints = ClapTrap::_hitPoints;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap param constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}
