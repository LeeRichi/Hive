
#include "Weapon.hpp"

#pragma once

class HumanB
{
	private:
        std::string _name;
        Weapon *_weapon;

    public:
        HumanB(std::string name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon &weapon);
};
