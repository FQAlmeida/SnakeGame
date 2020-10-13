#pragma once
// SFML
#include <SFML/Graphics.hpp>
// Global
#include <cstddef>
// Local
#include "../../Structures/Keys/Keys.hpp"
#include "../../main.hpp"

namespace Menu {
namespace End {

const size_t QTD_MENU_OPCOES = 2;
const std::string MENU_OPCOES[] = {"REINICIAR", "SAIR"};

class EndMenu {
   private:
    unsigned int opcao;
    sf::RenderWindow& window;
    States state;
    sf::Font font;

   protected:
    void select_option();

   public:
    EndMenu(sf::RenderWindow& window);
    void update(Structure::Keys::Keys key);
    void render();
    States get_state();
    ~EndMenu();
};

}  // namespace End
}  // namespace Menu