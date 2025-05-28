#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    Point inside(1.0f, 1.0f);
    Point vertex(0.0f, 0.0f);
    Point edge(2.5f, 0.0f);
    Point outside(5.0f, 5.0f);

    std::cout << "Inside point: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Vertex point: " << (bsp(a, b, c, vertex) ? "True" : "False") << std::endl;
    std::cout << "Edge point: " << (bsp(a, b, c, edge) ? "True" : "False") << std::endl;
    std::cout << "Outside point: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;

    return 0;
}
