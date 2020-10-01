#pragma once
// Global
#include <SFML/Graphics.hpp>
// Local
#include "../Structures/Coordinate/Coordinate.hpp"
#include "./Cobra/Cobra.hpp"
#include "./Comida/Comida.hpp"

namespace Game {

class Game {
   private:
    Cobra::Cobra cobra;
    Comida::Comida comida;
    sf::RenderWindow& window;
    Structure::Coordiante size;

   protected:
    void create_comida();

   public:
    Game(sf::RenderWindow& window, Structure::Coordiante size);
    void render();
    void update(Cobra::Direction direction);
    ~Game();
};

}  // namespace Game