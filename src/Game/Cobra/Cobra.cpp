// Global
#include <iostream>
// Local
#include "../../Structures/Coordinate/Coordinate.hpp"
#include "./Cobra.hpp"

namespace Cobra {

Cobra::Cobra(/* args */) : cabeca{Structure::Coordiante{10, 10}, sf::Color::Green, RIGHT}, qtd_comida{0} {
    this->cauda = std::vector<Cauda>{
        {{9, 10}, sf::Color::Blue},
        {{8, 10}, sf::Color::Blue},
        {{7, 10}, sf::Color::Blue},
    };
}

std::vector<Cauda> Cobra::get_cauda() {
    return this->cauda;
}
Cabeca Cobra::get_cabeca() {
    return this->cabeca;
}

void Cobra::update() {
    this->cauda.insert(this->cauda.begin(), Cauda{{this->cabeca.get_coordinate().x, this->cabeca.get_coordinate().y}, sf::Color::Blue});
    if (this->qtd_comida > 0) {
        this->qtd_comida--;
    } else {
        this->cauda.pop_back();
    }
    this->cabeca.update();
}
void Cobra::Cobra::set_direction(Direction direction) {
    this->cabeca.set_direction(direction);
}
void Cobra::comer(size_t qtd_comida){
    this->qtd_comida += qtd_comida;
}
Cobra::~Cobra() {
}
}  // namespace Cobra