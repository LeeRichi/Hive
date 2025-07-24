#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

    (void)av;
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    

    convert(av[1]);
    
    return 0;
}
