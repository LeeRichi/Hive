#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    _name = ClapTrap::_name;
    std::cout << "DiamondTrap default constructor called for " << this->_name << std::endl;
    _hitPoints = FragTrap::defaultHitPoints;
    _energyPoints = ScavTrap::defaultEnergyPoints;
    _attackDamage = FragTrap::defaultAttackDamage;
    std::cout << "values are: " << this->_hitPoints << " " << this->_energyPoints << " " << this->_attackDamage << std::endl;
}

// Param constructor
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap constructed by ClapTrap's param constructor "<<  this->_name << std::endl;
    _hitPoints = FragTrap::defaultHitPoints;
    _energyPoints = ScavTrap::defaultEnergyPoints;
    _attackDamage = FragTrap::defaultAttackDamage;
	std::cout << "values are: " << this->_hitPoints << " " << this->_energyPoints << " " << this->_attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	this->_name = other._name;
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
    std::cout << "values are: " << this->_hitPoints << " " << this->_energyPoints << " " << this->_attackDamage << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
        ClapTrap::_name = other._name + "_clap_name";
        this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
    std::cout << "updated values are: " << this->_hitPoints << " " << this->_energyPoints << " " << this->_attackDamage << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}
// Override attack
void DiamondTrap::attack(const std::string& target) {
    if (_energyPoints == 0 || _hitPoints == 0) {
        std::cout << "DiamondTrap " << _name << " can't attack. No energy or hit points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "DiamondTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
