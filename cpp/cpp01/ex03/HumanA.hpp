
#include "Weapon.hpp"

#pragma once

class HumanA
{
	private:
        std::string _name;
        Weapon &_weapon; // reference // no copy

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack() const;
};
