#pragma once
#include "Fixed.hpp"

class Point
{
	private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float para_x, const float para_y);
        Point(const Point &original);
        Point& operator=(const Point& other) = delete;
        ~Point();

        Fixed getX() const;
        Fixed getY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);
