#pragma once
#include "../Corpo.hpp"
namespace Cobra {
namespace Corpo {
namespace Cauda {

class Cauda : public Corpo {
   private:
    /* data */
   public:
    Cauda(Structure::Coordinate coordinate, sf::Color color);
    ~Cauda();
};

}  // namespace Cauda
}  // namespace Corpo
}  // namespace Cobra
