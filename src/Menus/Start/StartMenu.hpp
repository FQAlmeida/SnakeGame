#pragma once
// SFML
#include <SFML/Graphics.hpp>
// Global
#include <cstddef>
// Local
#include "../../Structures/Keys/Keys.hpp"
#include "../../main.hpp"

namespace Menu {
namespace Start {

const size_t QTD_MENU_OPCOES = 2;
const std::string MENU_OPCOES[] = {"INICIAR", "SAIR"};

class StartMenu {
   private:
    unsigned int opcao;
    sf::RenderWindow& window;
    States state;
    sf::Font font;

   protected:
    void select_option();

   public:
    StartMenu(sf::RenderWindow& window);
    void update(Structure::Keys::Keys key);
    void render();
    States get_state();
    ~StartMenu();
};

}  // namespace Start
}  // namespace Menu