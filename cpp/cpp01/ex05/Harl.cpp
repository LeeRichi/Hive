#include <iostream>
#include <string>

#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;

}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

static Level getLevelFromString(const std::string& levelStr) {
    if (levelStr == "DEBUG")
        return DEBUG;
    else if (levelStr == "INFO")
        return INFO;
    else if (levelStr == "WARNING")
        return WARNING;
    else if (levelStr == "ERROR")
        return ERROR;
    else
        return UNKNOWN;
}

void Harl::complain(std::string level) {
    Level levelSwitch = getLevelFromString(level);

    switch (levelSwitch) {
        case DEBUG:
            debug();
            break;
        case INFO:
            info();
            break;
        case WARNING:
            warning();
            break;
        case ERROR:
            error();
            break;
        default:
            std::cout << "UNKNOWN: Invalid complaint level." << std::endl;
    }
}
