#include <iostream>
#include "easyfind.hpp"

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5};
    try {
        auto it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
        it = easyfind(vec, 0);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    //const version
    try
	{
        const std::vector<int> vec = {1, 2, 3, 4, 5};
		auto searched = easyfind(vec, 5);
		std::cout << "Found: " << *searched << std::endl;
		searched = easyfind(vec, -1);
		std::cout << "Found: " << *searched << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}
