//
#include "main.hpp"
// Global
#include <iostream>
// SFML
#include <SFML/Graphics.hpp>
// Local
#include "./Game/Game.hpp"
#include "./Settings/Settings.hpp"
#include "./Structures/Direction/Direction.hpp"

int main() {
    std::cout << "Setting Up" << std::endl;
    std::cout << "Load Window" << std::endl;
    sf::RenderWindow window{sf::VideoMode{800, 600}, "Snake Game"};
    Game::Game game{window, {100, 100}};
    sf::Clock clock;
        Cobra::Direction direction = Cobra::RIGHT;
    while (window.isOpen()) {
        // Set the bg to black in case window resized
        window.clear(sf::Color::Black);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        direction = Cobra::UP;
                        std::cout << "Up" << std::endl;
                        break;
                    case sf::Keyboard::Down:
                        direction = Cobra::DOWN;
                        std::cout << "Down" << std::endl;
                        break;
                    case sf::Keyboard::Left:
                        direction = Cobra::LEFT;
                        std::cout << "Left" << std::endl;
                        break;
                    case sf::Keyboard::Right:
                        direction = Cobra::RIGHT;
                        std::cout << "Right" << std::endl;
                        break;
                    default:
                        break;
                }
            }
        }
        if (clock.getElapsedTime() >= sf::seconds(0.1)) {
            clock.restart();
            game.update(direction);
        }
        game.render();
        window.display();
    }

    return 0;
}
