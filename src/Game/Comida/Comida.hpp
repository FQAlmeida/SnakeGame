#pragma once
// Global
#include <cstddef>
#include <SFML/Graphics/Color.hpp>
// Local
#include "../../Structures/Coordinate/Coordinate.hpp"
namespace Comida
{
    

class Comida {
   private:
    size_t qtd_alimento;
    Structure::Coordinate coordinate;
    sf::Color color;
   public:
    Comida(size_t qtd_alimento, Structure::Coordinate coordinate, sf::Color color);
    size_t get_qtd_alimento();
    sf::Color get_color();
    Structure::Coordinate get_coordinate();
    ~Comida();
};

} // namespace Comida
