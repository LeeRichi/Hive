#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <value>" << std::endl;
        return 1;
    }

    std::string input(av[1]);

    try
    {
        ScalarConverter::convert(input);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
