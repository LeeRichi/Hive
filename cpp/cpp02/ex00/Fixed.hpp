
#pragma once
#include <iostream>

class Fixed
{
	private:
        int _fixedPoint;
        static const int _fractionalBits = 8;

    public:
        // Orthodox Canonical
        Fixed();
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment operator
        ~Fixed();
        // Member functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
