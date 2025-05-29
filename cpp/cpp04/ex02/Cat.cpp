#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
		setType("Cat");
		std::cout << "Cat constructed 🐱" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
		std::cout << "Cat copy constructed 🐱🐱" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
		std::cout << "Cat copy assigned 🐱 = 🐱" << std::endl;
		if (this != &other) {
				Animal::operator=(other);
				*_brain = *other._brain;
		}
		return *this;
}

Cat::~Cat() {
		if (_brain)
				delete _brain;
		std::cout << "Cat destroyed 🐱🫥" << std::endl;
}

void Cat::makeSound() const {
		std::cout << "Meow! 🐱💥" << std::endl;
}

std::string Cat::getType() const {
		return Animal::getType();
}

void Cat::setType(const std::string &type) {
		Animal::setType(type);
}

Brain* Cat::getBrain() const {
		return _brain;
}
