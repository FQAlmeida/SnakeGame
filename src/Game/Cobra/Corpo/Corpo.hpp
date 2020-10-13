#pragma once
// Global
#include <SFML/Graphics/Color.hpp>
// Local
#include "../../../Structures/Coordinate/Coordinate.hpp"
#include "../../../Structures/Direction/Direction.hpp"

namespace Cobra {
namespace Corpo {

class Corpo {
   protected:
    Structure::Coordinate coordinate;
    sf::Color color;

   public:
    Corpo(Structure::Coordinate coordinate, sf::Color color);
    Structure::Coordinate get_coordinate();
    sf::Color get_color();
    ~Corpo();
};

}  // namespace Corpo
}  // namespace Cobra
