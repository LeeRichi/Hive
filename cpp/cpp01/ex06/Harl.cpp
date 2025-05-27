#include <iostream>
#include <string>
#include "Harl.hpp"

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*methods[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4 && level != levels[i])
		i++;

	switch (i) {
		case 0:
			(this->*methods[0])();
		case 1:
			(this->*methods[1])();
		case 2:
			(this->*methods[2])();
		case 3:
			(this->*methods[3])();
			break;
		default:
			std::cout << "UNKNOWN: Invalid complaint level." << std::endl;
	}
}
