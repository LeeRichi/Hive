#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float para_x, const float para_y) : x(para_x), y(para_y) {}

Point::Point(const Point& original) : x(original.getX()), y(original.getY()) {}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }
