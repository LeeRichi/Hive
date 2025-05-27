#include <string>

#pragma once

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(std::string name);
        ~Weapon();
        //getter
        const std::string &getType(void) const;
        //setter
        void setType(std::string type);
};
