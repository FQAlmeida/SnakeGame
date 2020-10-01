#include "../Corpo.hpp"
namespace Cobra {
enum Direction{
    UP, DOWN, LEFT, RIGHT
};
class Cabeca : public Corpo {
   private:
    Direction direction;
   public:
    Cabeca(Structure::Coordiante coordinate, sf::Color color, Direction direction);
    void set_direction(Direction direction);
    Direction get_direction();
    void update();
    ~Cabeca();
};

}  // namespace Cobra
