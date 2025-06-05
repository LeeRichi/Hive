#pragma once
#include <iostream>
#include <string>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &other);

        void makeSound() const;
        std::string getType() const;
        void setType(const std::string &type);
    private:
        std::string _type;
};
