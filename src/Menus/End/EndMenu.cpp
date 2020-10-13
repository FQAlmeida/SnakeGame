#include "./EndMenu.hpp"

namespace Menu {
namespace End {

EndMenu::EndMenu(sf::RenderWindow& window) : opcao{0}, window{window}, state{END} {
    this->font.loadFromFile("./fonts/MenuFont.ttf");
}

void EndMenu::update(Structure::Keys::Keys key) {
    switch (key) {
        case Structure::Keys::UP:
            this->opcao = (this->opcao == 0) ? QTD_MENU_OPCOES - 1 : this->opcao - 1;
            break;
        case Structure::Keys::DOWN:
            this->opcao = (this->opcao + 1) % QTD_MENU_OPCOES;
            break;
        case Structure::Keys::ENTER:
            this->select_option();
            break;
        default:
            break;
    }
}

void EndMenu::select_option() {
    if (MENU_OPCOES[this->opcao].compare("REINICIAR") == 0) {
        this->state = States::RUNNING;
    } else if (MENU_OPCOES[this->opcao].compare("SAIR") == 0) {
        this->state = States::EXIT;
    }
}

States EndMenu::get_state() {
    return this->state;
}

void EndMenu::render() {
    // Screen Size
    sf::Vector2u screensize = this->window.getSize();
    float option_height = 50.0f;
    float option_width = 200.0f;
    float offset = 2.0f * screensize.y / 10.0f + 35.0f;
    // Create a rect with 50%, 20%
    sf::RectangleShape gave_over_container{sf::Vector2f{screensize.x / 2.0f, 2.0f * screensize.y / 10.0f}};
    gave_over_container.setFillColor(sf::Color{184, 184, 184});
    gave_over_container.setOrigin(sf::Vector2f{screensize.x / 2.0f, 0} / 2.0f);
    gave_over_container.move(sf::Vector2f{screensize.x / 2.0f, 35.0f});
    window.draw(gave_over_container);
    // Write Game Over
    sf::Text game_over_text;
    game_over_text.setFont(this->font);
    game_over_text.setString("GAME OVER");
    game_over_text.setCharacterSize(32);  // in pixels, not points!
    game_over_text.setFillColor(sf::Color(255, 255, 255));
    game_over_text.setOrigin(sf::Vector2f{game_over_text.getLocalBounds().width, game_over_text.getLocalBounds().height} / 2.0f);
    game_over_text.move(sf::Vector2f{screensize.x / 2.0f, (2.0f * screensize.y / 10.0f) / 2 + 35.0f});
    this->window.draw(game_over_text);
    // Create a rect with 50%, 55%  on center screen
    sf::RectangleShape center_container{sf::Vector2f{screensize.x / 2.0f, 55.0f * screensize.y / 100.0f}};
    center_container.setFillColor(sf::Color{115, 115, 115});
    center_container.setOrigin(sf::Vector2f{screensize.x / 2.0f, 55.0f * screensize.y / 100.0f} / 2.0f);
    center_container.move(sf::Vector2f{screensize.x / 2.0f, (screensize.y + offset) / 2.0f});
    window.draw(center_container);
    offset += 80.0f;
    // For each option
    for (size_t i = 0; i < QTD_MENU_OPCOES; i++) {
        // If selected option, draw a select rect
        if (i == this->opcao) {
            sf::RectangleShape selected_option_container{sf::Vector2f{option_width, option_height}};
            selected_option_container.setFillColor(sf::Color{255, 0, 128});
            selected_option_container.setOrigin(sf::Vector2f{option_width, 0} / 2.0f);
            selected_option_container.move(sf::Vector2f{screensize.x / 2.0f, offset});
            window.draw(selected_option_container);
        }
        // Write Option
        sf::Text option_text;
        option_text.setFont(this->font);
        option_text.setString(std::string(MENU_OPCOES[i]));
        option_text.setCharacterSize(24);  // in pixels, not points!
        option_text.setFillColor(sf::Color(255, 255, 255));
        option_text.setOrigin(sf::Vector2f{option_text.getLocalBounds().width, option_text.getLocalBounds().height} / 2.0f);
        option_text.move(sf::Vector2f{screensize.x / 2.0f, offset + (option_height / 2)});
        this->window.draw(option_text);
        // Upd Offset
        offset += option_height + 15.0f;
    }
}

EndMenu::~EndMenu() {
}

}  // namespace End
}  // namespace Menu