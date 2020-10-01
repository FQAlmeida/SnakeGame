#include "../Corpo.hpp"
namespace Cobra {
class Cauda : public Corpo {
   private:
    /* data */
   public:
    Cauda(Structure::Coordiante coordinate, sf::Color color);
    ~Cauda();
};

}  // namespace Cobra
