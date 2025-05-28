#include "Fixed.hpp"

bool Fixed::operator>(const Fixed& other) const { return _fixedPoint > other._fixedPoint; }
bool Fixed::operator<(const Fixed& other) const { return _fixedPoint < other._fixedPoint; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedPoint >= other._fixedPoint; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedPoint <= other._fixedPoint; }
bool Fixed::operator==(const Fixed& other) const { return _fixedPoint == other._fixedPoint; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedPoint != other._fixedPoint; }

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++_fixedPoint;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_fixedPoint;
    return temp;
}

Fixed& Fixed::operator--() {
    --_fixedPoint;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_fixedPoint;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

