#pragma once
#include <iostream>
#include <string>

class Animal {
    public:
        Animal();
        Animal(const Animal &other);
        virtual ~Animal();

        Animal &operator=(const Animal &other);

        virtual void makeSound() const;
        std::string getType() const;
        void setType(const std::string &type);
    private:
        std::string _type;
};
