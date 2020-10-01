// Global
#include <iostream>
// Local
#include "./Corpo.hpp"
namespace Cobra {

Corpo::Corpo(Structure::Coordiante coordinate, sf::Color color) : coordinate{coordinate}, color{color} {
}
Structure::Coordiante Corpo::get_coordinate() {
    return this->coordinate;
}
sf::Color Corpo::get_color() {
    return this->color;
}

Corpo::~Corpo() {
}
}  // namespace Cobra
