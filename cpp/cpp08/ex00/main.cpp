#include <iostream>
#include "easyfind.hpp"

int main() {

    std::vector<int> vec = {1, 2, 3, 4, 5};
    try {
        auto it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
