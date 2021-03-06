#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace Structure {
namespace Direction {

enum Direction {
    UP = sf::Keyboard::Up,
    DOWN = sf::Keyboard::Down,
    LEFT = sf::Keyboard::Left,
    RIGHT = sf::Keyboard::Right
};
}
}  // namespace Structure
