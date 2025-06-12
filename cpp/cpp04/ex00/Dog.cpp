#include "Dog.hpp"

Dog::Dog() : Animal() {
	setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

std::string Dog::getType() const {
	return Animal::getType();
}

void Dog::setType(const std::string &type) {
	Animal::setType(type);
}

