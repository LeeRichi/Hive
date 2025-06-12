#pragma once
#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
        void setType(const std::string &type);
};
