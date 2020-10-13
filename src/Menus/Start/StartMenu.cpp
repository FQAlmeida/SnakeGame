#include "./StartMenu.hpp"

namespace Menu {
namespace Start {

StartMenu::StartMenu(sf::RenderWindow& window) : opcao{0}, window{window}, state{START} {
    this->font.loadFromFile("./fonts/MenuFont.ttf");
}

void StartMenu::update(Structure::Keys::Keys key) {
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

void StartMenu::select_option() {
    if(MENU_OPCOES[this->opcao].compare("INICIAR") ==0){
        this->state = States::RUNNING;
    }else if(MENU_OPCOES[this->opcao].compare("SAIR") ==0){
        this->state = States::EXIT;
    }
}

States StartMenu::get_state() {
    return this->state;
}

void StartMenu::render() {
    // Screen Size
    sf::Vector2u screensize = this->window.getSize();
    float option_height = 50.0f;
    float option_width = 200.0f;
    float offset = (screensize.y - 3.0f * screensize.y / 4.0f + option_height) / 2;
    // Create a rect with 50%, 75%  on center screen
    sf::RectangleShape center_container{sf::Vector2f{screensize.x / 2.0f, 3.0f * screensize.y / 4.0f}};
    center_container.setFillColor(sf::Color{115, 115, 115});
    center_container.setOrigin(sf::Vector2f{screensize.x / 2.0f, 3.0f * screensize.y / 4.0f} / 2.0f);
    center_container.move(sf::Vector2f{screensize.x / 2.0f, screensize.y / 2.0f});
    window.draw(center_container);
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

StartMenu::~StartMenu() {
}

}  // namespace Start
}  // namespace Menu