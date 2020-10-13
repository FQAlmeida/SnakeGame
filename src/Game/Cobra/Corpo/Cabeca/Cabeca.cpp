// Global
#include <iostream>
// Local
#include "./Cabeca.hpp"
namespace Cobra {
namespace Corpo {

namespace Cabeca {

Cabeca::Cabeca(Structure::Coordinate coordinate, sf::Color color, Structure::Direction::Direction direction) : Corpo{coordinate, color}, direction{direction} {
}

void Cabeca::set_direction(Structure::Direction::Direction direction) {
    this->direction = direction;
}
Structure::Direction::Direction Cabeca::get_direction() {
    return this->direction;
}
void Cabeca::update() {
    // std::cout << "Dir: "<< this->direction << std::endl;
    switch (this->direction) {
        case Structure::Direction::UP:
            this->coordinate.y -= 1;
            break;
        case Structure::Direction::DOWN:
            this->coordinate.y += 1;
            break;
        case Structure::Direction::RIGHT:
            this->coordinate.x += 1;
            break;
        case Structure::Direction::LEFT:
            this->coordinate.x -= 1;
            break;
        default:
            break;
    }
}
Cabeca::~Cabeca() {
}
}  // namespace Cabeca
}  // namespace Corpo
}  // namespace Cobra