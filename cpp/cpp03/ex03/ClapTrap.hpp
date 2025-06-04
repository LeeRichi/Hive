
#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        // Orthodox Canonical
        ClapTrap();
        ClapTrap(const std::string& name, unsigned int hitPoints = 10, unsigned int energyPoints = 10, unsigned int attackDamage = 0); // New
        ClapTrap(const ClapTrap& other); // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
        virtual ~ClapTrap();

        // Member functions
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //getters
        // unsigned int getHitPoints() const;
        // unsigned int getEnergyPoints() const;
        // unsigned int getAttackDamage() const;

        // std::string getName() const;
};
