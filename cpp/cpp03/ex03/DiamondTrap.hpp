/*
    ClapTrap
    /      \
   /        \
ScavTrap   FragTrap    // these two classes are virtual
   \        /
    \      /
   DiamondTrap
*/

// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#pragma once

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string _name = "Default";

    public:
        // Orthodox Canonical
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        void attack(const std::string& target) override;
        void whoAmI();
};

