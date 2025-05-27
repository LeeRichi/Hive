#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str; //stringPTR: A pointer to the string.
    std::string &stringREF = str; //stringREF: A reference to the string

    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF.: " << &stringREF << std::endl;

    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value held by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value held by stringREF.: " << stringREF << std::endl;
}

