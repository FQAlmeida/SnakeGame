// Global
#include <iostream>
// Local
#include "./Cabeca.hpp"
namespace Cobra {

Cabeca::Cabeca(Structure::Coordiante coordinate, sf::Color color, Direction direction) : Corpo{coordinate, color}, direction{direction} {
}

void Cabeca::set_direction(Direction direction) {
    this->direction = direction;
}
Direction Cabeca::get_direction() {
    return this->direction;
}
void Cabeca::update() {
    // std::cout << "Dir: "<< this->direction << std::endl;
    switch (this->direction) {
        case UP:
            this->coordinate.y -= 1;
            break;
        case DOWN:
            this->coordinate.y += 1;
            break;
        case RIGHT:
            this->coordinate.x += 1;
            break;
        case LEFT:
            this->coordinate.x -= 1;
            break;
        default:
            break;
    }
}
Cabeca::~Cabeca() {
}
}  // namespace Cobra