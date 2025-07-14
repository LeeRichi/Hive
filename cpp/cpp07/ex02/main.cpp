#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i) {
        a[i] = i * 10;
    }

    Array<int> b = a; // test copy constructor
    b[0] = 999;

    Array<int> c;
    c = a; // test assignment operator

    std::cout << "Original: " << a[0] << "\n"; // Should not be 999
    std::cout << "Copy: " << b[0] << "\n";
    std::cout << "Assigned: " << c[0] << "\n";

    for (unsigned int i = 0; i < a.size(); ++i) {
        std::cout << "a[" << i << "] = " << a[i] << "\n";
    }

    try {
        std::cout << a[999] << "\n"; // Should throw
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
