// Global
#include <iostream>
// Local
#include "./Corpo.hpp"
namespace Cobra {
namespace Corpo {

Corpo::Corpo(Structure::Coordinate coordinate, sf::Color color) : coordinate{coordinate}, color{color} {
}
Structure::Coordinate Corpo::get_coordinate() {
    return this->coordinate;
}
sf::Color Corpo::get_color() {
    return this->color;
}

Corpo::~Corpo() {
}
}  // namespace Corpo
}  // namespace Cobra
