#pragma once
// Global
#include <SFML/Graphics.hpp>
// Local
#include "../main.hpp"
#include "../Structures/Direction/Direction.hpp"
#include "../Structures/Size/Size.hpp"
#include "./Cobra/Cobra.hpp"
#include "./Comida/Comida.hpp"

namespace Game {

class Game {
   private:
    Cobra::Cobra cobra;
    Comida::Comida comida;
    sf::RenderWindow& window;
    Structure::Size size;
    States state;

   protected:
    void create_comida();

   public:
    Game(sf::RenderWindow& window, Structure::Size& size);
    void render();
    States get_state();
    void reset();
    void update(Structure::Direction::Direction& direction, Structure::Direction::Direction* last_direction, sf::Clock& clock);
    ~Game();
};

}  // namespace Game