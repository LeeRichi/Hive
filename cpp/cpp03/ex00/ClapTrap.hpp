
#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
	private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        // Orthodox Canonical
        ClapTrap();
        ClapTrap(const std::string& name); // Param constructor
        ClapTrap(const ClapTrap& other); // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
        ~ClapTrap();

        // Member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
