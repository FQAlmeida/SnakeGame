// Global
#include <iostream>
#include <random>
// Local
#include "Game.hpp"
namespace Game {

Game::Game(sf::RenderWindow& window, Structure::Size& size) : comida{1, Structure::Coordinate{(size_t)(size.x / 1.5), (size_t)(size.y / 1.5)}, sf::Color::Red}, window{window}, size{size}, state{RUNNING} {
    std::srand(std::time(NULL));
    create_comida();
}
void Game::reset(){
    state = RUNNING;
    cobra = Cobra::Cobra{};
    create_comida();
}
void Game::render() {
    sf::Vector2u screensize = this->window.getSize();
    // std::cout << "screensize: " << screensize.x / (float)this->size.x << " " << screensize.y << std::endl;
    // Render Cobra
    // Render Cabeca
    sf::RectangleShape cabeca_shape{
        sf::Vector2f{screensize.x / (float)this->size.x, screensize.y / (float)this->size.y}};
    cabeca_shape.setFillColor(this->cobra.get_cabeca().get_color());
    cabeca_shape.move(screensize.x / (float)this->size.x * this->cobra.get_cabeca().get_coordinate().x, screensize.y / (float)this->size.y * this->cobra.get_cabeca().get_coordinate().y);
    this->window.draw(cabeca_shape);
    // Render Cauda
    for (size_t corpo_index = 0; corpo_index < this->cobra.get_cauda().size(); corpo_index++) {
        sf::RectangleShape body_shape{
            sf::Vector2f{screensize.x / (float)this->size.x, screensize.y / (float)this->size.y}};
        body_shape.setFillColor(this->cobra.get_cauda()[corpo_index].get_color());
        body_shape.move(screensize.x / (float)this->size.x * this->cobra.get_cauda()[corpo_index].get_coordinate().x, screensize.y / (float)this->size.y * this->cobra.get_cauda()[corpo_index].get_coordinate().y);
        this->window.draw(body_shape);
    }
    // Render Comida
    sf::RectangleShape comida_shape{
        sf::Vector2f{screensize.x / (float)this->size.x, screensize.y / (float)this->size.y}};
    comida_shape.setFillColor(this->comida.get_color());
    comida_shape.move(screensize.x / (float)this->size.x * this->comida.get_coordinate().x, screensize.y / (float)this->size.y * this->comida.get_coordinate().y);
    this->window.draw(comida_shape);
}
void Game::update(Structure::Direction::Direction& direction, Structure::Direction::Direction* last_direction, sf::Clock& clock) {
    // upd speed
    if (clock.getElapsedTime() >= sf::seconds(0.2)) {
        clock.restart();
        *last_direction = direction;
        // check cabeca out of border after next update,
        if (
            (this->cobra.get_cabeca().get_coordinate().y == 0 && direction == Structure::Direction::UP) ||
            (this->cobra.get_cabeca().get_coordinate().x == 0 && direction == Structure::Direction::LEFT) ||
            (this->cobra.get_cabeca().get_coordinate().y == this->size.y - 1 && direction == Structure::Direction::DOWN) ||
            (this->cobra.get_cabeca().get_coordinate().x == this->size.x - 1 && direction == Structure::Direction::RIGHT)) {
            this->state = END;
            return;
        }
        this->cobra.set_direction(direction);
        this->cobra.update();
        // Check pos cabeca e comida
        if (this->cobra.get_cabeca().get_coordinate() == this->comida.get_coordinate()) {
            std::cout << "Cobra comeu: " << this->comida.get_qtd_alimento() << " alimentos" << std::endl;
            this->cobra.comer(this->comida.get_qtd_alimento());
            this->create_comida();
        }

        //check pos cabeca e corpo
        for (size_t i = 0; i < this->cobra.get_cauda().size(); i++) {
            if (this->cobra.get_cauda()[i].get_coordinate() == this->cobra.get_cabeca().get_coordinate()) {
                // End Game
                this->state = END;
                return;
            }
        }
    }
}

void Game::create_comida() {
    this->comida = Comida::Comida{(size_t)(std::rand() % 3 + 1), Structure::Coordinate{(size_t)(std::rand() % (this->size.x - 1)) + 1, (size_t)(std::rand() % (this->size.x - 1)) + 1}, sf::Color::Red};
}
States Game::get_state() {
    return this->state;
}

Game::~Game() {
}
}  // namespace Game