#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {}

void HumanB::attack() const
{
    if (!_weapon)
        std::cout << _name << " no weapon to attack" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
