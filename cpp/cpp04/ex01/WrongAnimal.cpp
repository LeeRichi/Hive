#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
		std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		_type = other._type;
		std::cout << "WrongAnimal assignment operator called" << std::endl;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a ~WrongAnimal sound~" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
void WrongAnimal::setType(const std::string &type) {
	_type = type;
}
