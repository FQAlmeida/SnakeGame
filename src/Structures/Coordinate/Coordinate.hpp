#pragma once
// Global
#include <cstddef>
// Local
#include "../Size/Size.hpp"

namespace Structure {

typedef struct Coordinate Coordinate;

struct Coordinate : Size {
    Coordinate(size_t x, size_t y) : Size{x, y} {}
    bool operator==(const Coordinate& destiny) {
        return this->x == destiny.x && this->y == destiny.y;
    }
};

}  // namespace Structure