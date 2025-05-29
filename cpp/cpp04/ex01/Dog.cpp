#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
    setType("Dog");
    std::cout << "Dog constructed 🐶 " << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
    std::cout << "Dog copy constructed 🐶🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assigned 🐶 = 🐶" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return *this;
}

Dog::~Dog() {
    if (_brain)
        delete _brain;
    std::cout << "Dog destroyed 🐶🫥" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! 🐶💥" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}

std::string Dog::getType() const {
    return Animal::getType();
}

void Dog::setType(const std::string &type) {
    Animal::setType(type);
}
