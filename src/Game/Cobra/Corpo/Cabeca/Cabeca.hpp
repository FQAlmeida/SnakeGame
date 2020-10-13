#pragma once
#include "../Corpo.hpp"
#include "../../../../Structures/Direction/Direction.hpp"
namespace Cobra {
namespace Corpo {
namespace Cabeca {


class Cabeca : public Corpo {
   private:
    Structure::Direction::Direction direction;

   public:
    Cabeca(Structure::Coordinate coordinate, sf::Color color, Structure::Direction::Direction direction);
    void set_direction(Structure::Direction::Direction direction);
    Structure::Direction::Direction get_direction();
    void update();
    ~Cabeca();
};

}  // namespace Cabeca
}  // namespace Corpo
}  // namespace Cobra
