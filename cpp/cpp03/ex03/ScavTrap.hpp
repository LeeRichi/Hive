#pragma once
#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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

        static const unsigned int defaultHitPoints = 100;
        static const unsigned int defaultEnergyPoints = 50;
        static const unsigned int defaultAttackDamage = 20;
};
