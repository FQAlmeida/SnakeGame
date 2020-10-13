// Global
#include <iostream>
// Local
#include "../../Structures/Coordinate/Coordinate.hpp"
#include "../../Structures/Direction/Direction.hpp"
#include "./Cobra.hpp"

namespace Cobra {

Cobra::Cobra() : cabeca{Structure::Coordinate{10, 10}, sf::Color::Green, Structure::Direction::RIGHT}, qtd_comida{0} {
    this->cauda = std::vector<Corpo::Cauda::Cauda>{
        {{9, 10}, sf::Color::Blue},
        {{8, 10}, sf::Color::Blue},
        {{7, 10}, sf::Color::Blue},
    };
}

std::vector<Corpo::Cauda::Cauda> Cobra::get_cauda() {
    return this->cauda;
}
Corpo::Cabeca::Cabeca Cobra::get_cabeca() {
    return this->cabeca;
}

void Cobra::update() {
    this->cauda.insert(this->cauda.begin(), Corpo::Cauda::Cauda{{this->cabeca.get_coordinate().x, this->cabeca.get_coordinate().y}, sf::Color::Blue});
    if (this->qtd_comida > 0) {
        this->qtd_comida--;
    } else {
        this->cauda.pop_back();
    }
    this->cabeca.update();
}
void Cobra::Cobra::set_direction(Structure::Direction::Direction direction) {
    this->cabeca.set_direction(direction);
}
void Cobra::comer(size_t qtd_comida){
    this->qtd_comida += qtd_comida;
}
Cobra::~Cobra() {
}
}  // namespace Cobra