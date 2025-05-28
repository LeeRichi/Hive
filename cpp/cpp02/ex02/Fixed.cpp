#include "Fixed.hpp"
#include "printLog.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPoint(0) {
    printLog("Default constructor called");
}

// Int constructor
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    if (intValue > MAX_FIXED || intValue < MIN_FIXED)
        throw std::out_of_range("Fixed: intValue out of bounds");
    _fixedPoint = intValue << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    if (floatValue > MAX_FIXED || floatValue < MIN_FIXED)
        throw std::out_of_range("Fixed: floatValue out of bounds");
    _fixedPoint = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    printLog("Copy constructor called");
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    printLog("Copy assignment operator called");
    if (this != &other)
        this->_fixedPoint = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    printLog("Destructor called");
}

int Fixed::getRawBits(void) const {
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw) {
    _fixedPoint = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPoint / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPoint >> _fractionalBits;
}

// << operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
