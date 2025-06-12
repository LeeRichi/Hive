#pragma once
#include <iostream>
#include <string>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &other);

        void makeSound() const;
        std::string getType() const;
        void setType(const std::string &type);
    protected:
        std::string _type;
};
