//
#include "main.hpp"
// Global
#include <iostream>
// SFML
#include <SFML/Graphics.hpp>
// Local
#include "./Game/Game.hpp"
#include "./Menus/End/EndMenu.hpp"
#include "./Menus/Start/StartMenu.hpp"
#include "./Settings/Settings.hpp"
#include "./Structures/Direction/Direction.hpp"
#include "./Structures/Size/Size.hpp"

int main() {
    std::cout << "Setting Up" << std::endl;
    Settings::Settings *settings = Settings::Settings::get_instance();

    std::cout << "Load Window" << std::endl;
    Structure::Size window_size{
        settings->get_config()["window"]["size"]["width"].get<unsigned int>(),
        settings->get_config()["window"]["size"]["height"].get<unsigned int>()};
    sf::RenderWindow window{
        sf::VideoMode{(unsigned int)window_size.x, (unsigned int)window_size.y},
        "Snake Game"};

    std::cout << "Load Start Up Menu" << std::endl;
    States game_state = START;
    Menu::Start::StartMenu start_menu{window};

    std::cout << "Load End Game Menu" << std::endl;
    Menu::End::EndMenu end_menu{window};

    std::cout << "Load Game" << std::endl;
    Structure::Size game_size{
        settings->get_config()["game"]["size"]["width"].get<size_t>(),
        settings->get_config()["game"]["size"]["height"].get<size_t>()};
    Game::Game game{window, game_size};

    sf::Clock clock;

    Structure::Direction::Direction direction = Structure::Direction::RIGHT;
    Structure::Direction::Direction last_direction = Structure::Direction::RIGHT;

    while (window.isOpen()) {
        // Set the bg to black in case window resized
        window.clear(sf::Color::Black);

        // check all the window's events that were triggered since the last iteration of the loop
        switch (game_state) {
            case START: {
                sf::Event event;
                while (window.pollEvent(event)) {
                    // "close requested" event: we close the window
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    } else if (event.type == sf::Event::KeyReleased) {
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                start_menu.update(Structure::Keys::UP);
                                break;
                            case sf::Keyboard::Down:
                                start_menu.update(Structure::Keys::DOWN);
                                break;
                            case sf::Keyboard::Enter:
                                start_menu.update(Structure::Keys::ENTER);
                                break;
                            default:
                                break;
                        }
                    }
                }
                start_menu.render();
                game_state = start_menu.get_state();
                break;
            }
            case RUNNING: {
                sf::Event event;
                while (window.pollEvent(event)) {
                    // "close requested" event: we close the window
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    } else if (event.type == sf::Event::KeyReleased) {
                        if (event.key.code == sf::Keyboard::Up && last_direction != Structure::Direction::DOWN) {
                            direction = Structure::Direction::UP;
                        } else if (event.key.code == sf::Keyboard::Down && last_direction != Structure::Direction::UP) {
                            direction = Structure::Direction::DOWN;
                        } else if (event.key.code == sf::Keyboard::Left && last_direction != Structure::Direction::RIGHT) {
                            direction = Structure::Direction::LEFT;
                        } else if (event.key.code == sf::Keyboard::Right && last_direction != Structure::Direction::LEFT) {
                            direction = Structure::Direction::RIGHT;
                        }
                    }
                }
                game.update(direction, &last_direction, clock);
                game_state = game.get_state();
                game.render();
                break;
            }
            case END: {
                sf::Event event;
                while (window.pollEvent(event)) {
                    // "close requested" event: we close the window
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    } else if (event.type == sf::Event::KeyReleased) {
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                end_menu.update(Structure::Keys::UP);
                                break;
                            case sf::Keyboard::Down:
                                end_menu.update(Structure::Keys::DOWN);
                                break;
                            case sf::Keyboard::Enter:
                                end_menu.update(Structure::Keys::ENTER);
                                break;
                            default:
                                break;
                        }
                    }
                }
                end_menu.render();
                game_state = end_menu.get_state();

                if (game_state == RUNNING) {
                    game.reset();
                    direction = Structure::Direction::RIGHT;
                    last_direction = Structure::Direction::RIGHT;
                }
                break;
            }
            case EXIT: {
                window.close();
                break;
            }

            default:
                break;
        }
        window.display();
    }

    return 0;
}
