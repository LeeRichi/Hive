#include "iter.hpp"
#include <iostream>
#include <string>

void printElement(const int& element) {
    std::cout << element << std::endl;
}

void each_one_say_hi(const std::string& str) {
    std::cout << str << std::endl;
}

int main()
{
    int tab[] = { 0, 1, 2, 3, 4 };

    std::cout << "Iterating over int array:" << std::endl;
    iter(tab, 5, printElement);

    std::cout << "------------------------" << std::endl;

    std::string strTab[] = { "Hello", "World", "!" };

    std::cout << "Iterating over string array:" << std::endl;
    iter(strTab, 3, each_one_say_hi);

    return 0;
}
