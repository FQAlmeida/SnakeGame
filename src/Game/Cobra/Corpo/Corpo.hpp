#pragma once
// Global
#include <SFML/Graphics/Color.hpp>
// Local
#include "../../../Structures/Coordinate/Coordinate.hpp"
#include "../../../Structures/Direction/Direction.hpp"

namespace Cobra {
class Corpo {
   protected:
    Structure::Coordiante coordinate;
    sf::Color color;

   public:
    Corpo(Structure::Coordiante coordinate, sf::Color color);
    Structure::Coordiante get_coordinate();
    sf::Color get_color();
    ~Corpo();
};

}  // namespace Cobra
