#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

// #include "Fixed.hpp"
// #include <iostream>
// #include <exception>

// int main() {
//     try {
//         Fixed a;
//         Fixed const b(9000000);         // Will throw
//         Fixed const c(9000000.0f);      // throw
//         Fixed const d(b);
//         a = Fixed(1234.4321f);
//         std::cout << "a is " << a << std::endl;
//         std::cout << "b is " << b << std::endl;
//         std::cout << "c is " << c << std::endl;
//         std::cout << "d is " << d << std::endl;
//         std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//         std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//         std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//         std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//     } catch (const std::out_of_range& e) {
//         std::cerr << "Caught exception: " << e.what() << std::endl;
//     }
//     return 0;
// }
