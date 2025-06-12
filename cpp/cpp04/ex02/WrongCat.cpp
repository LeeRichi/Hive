#include "WrongCat.hpp"

WrongCat::WrongCat() {
		setType("WrongCat");
		std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
		std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
		std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		std::cout << "WrongCat assignment operator called" << std::endl;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "wrong cat Meow Meow" << std::endl;
}

std::string WrongCat::getType() const {
	return WrongAnimal::getType();
}

void WrongCat::setType(const std::string &type) {
	WrongAnimal::setType(type);
}
