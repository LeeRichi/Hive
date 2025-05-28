#include "Point.hpp"

static Fixed area(Point const p1, Point const p2, Point const p3) {
    // Using cross product formula for area * 2 (so no division by 2, to keep Fixed exact)
    // abs((x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)))
    Fixed val = p1.getX() * (p2.getY() - p3.getY()) +
                p2.getX() * (p3.getY() - p1.getY()) +
                p3.getX() * (p1.getY() - p2.getY());
    if (val.toFloat() < 0)
        val = Fixed(-val.toFloat()); // abs
    return val;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    Fixed sumAreas = area1 + area2 + area3;

    // Point is strictly inside if:
    // sum of subareas == total area
    // and no subarea is zero (means point is on edge or vertex)
    if (sumAreas.toFloat() == totalArea.toFloat() &&
        area1.toFloat() > 0 &&
        area2.toFloat() > 0 &&
        area3.toFloat() > 0) {
        return true;
    }
    return false;
}
