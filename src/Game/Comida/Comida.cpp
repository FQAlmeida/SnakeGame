// Local
#include "./Comida.hpp"

namespace Comida {

Comida::Comida(size_t qtd_alimento, Structure::Coordiante coordinate, sf::Color color) : qtd_alimento{qtd_alimento}, coordinate{coordinate}, color{color} {
}
size_t Comida::get_qtd_alimento() {
    return this->qtd_alimento;
}
Structure::Coordiante Comida::get_coordinate() {
    return this->coordinate;
}
sf::Color Comida::get_color() {
    return this->color;
}

Comida::~Comida() {
}
}  // namespace Comida
