#include "Polygons.hpp"
#include <iostream>

int main() {
    // create a Pentagon, call its perimeter method
    Pentagon penta(2.0);
    std::cout << "Pentagon class -> perimeter = " << penta.computePerimeter() << std::endl;

    // create a Hexagon, call its perimeter method
    Hexagon hexa(2.0);
    std::cout << "Hexagon class -> perimeter = " << hexa.computePerimeter() << std::endl;

    // create a Hexagon, call the perimeter method through a reference to Polygon
    Hexagon hex(2.0);
    RegularPolygon &poly = hex;
    std::cout << "Just Hexagon class -> perimeter = " << hex.computePerimeter() << std::endl;
    std::cout << "Hexagon through a reference to Polygon -> perimeter = " << poly.computePerimeter() << std::endl;

    // retry virtual method

}
