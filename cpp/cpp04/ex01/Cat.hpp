#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(const Cat &other);
        ~Cat();

        Cat &operator=(const Cat &other);

        void makeSound() const override;
        std::string getType() const;
        void setType(const std::string &type);
        Brain *getBrain() const;

    private:
        Brain *_brain;
};
