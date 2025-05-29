#pragma once
#include <iostream>
#include <string>

class Animal {
    public:
        Animal();
        Animal(const Animal &other);
        virtual ~Animal();

        Animal &operator=(const Animal &other);

        virtual void makeSound() const = 0; //This syntax means pure virtual function, and it makes the class abstract and cannot be instantiated.
        //It forces derived classes to provide their own implementation of makeSound().

        std::string getType() const;
        void setType(const std::string &type);
    private:
        std::string _type;
};
