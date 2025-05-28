#pragma once
#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
        // Orthodox Canonical
        ScavTrap();
        ScavTrap(const std::string& name);          // Param constructor
        ScavTrap(const ScavTrap& other); // Copy constructor
        ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator
        ~ScavTrap();

        // Member functions
        void attack(const std::string& target) override;
        void guardGate();



        // void takeDamage(unsigned int amount);
        // void beRepaired(unsigned int amount);
};
