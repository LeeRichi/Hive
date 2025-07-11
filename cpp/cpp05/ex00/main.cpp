#include "Bureaucrat.hpp"

int main()
{
    std::cout << "hello cpp05" << std::endl;
    try {
        Bureaucrat a1("Alice", 0);  // this should throw exception
    } catch (const std::exception &e) {
        std::cerr << "Failed to create Bureaucrat: " << e.what() << std::endl;
    }

    // Bureaucrat a1("Alice", 0); //ummmmmmmm //dont do this

    try
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        Bureaucrat b3("Charlie", 1);
        Bureaucrat b4; // Default constructor
        Bureaucrat b5(b1);
        Bureaucrat b6 = b2;
        Bureaucrat b7;
        b7 = b3;

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
        std::cout << b4 << std::endl;
        std::cout << b5 << std::endl;
        std::cout << b6 << std::endl;
        std::cout << b7 << std::endl;
        b2.decrementGrade();
        std::cout << "After incrementing grade of " << b2.getName() << ": " << b2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Failed to create Bureaucrat: " << e.what() << std::endl;
    }

    return 0;
}
