#pragma once
#include <cstddef>

namespace Structure {

typedef struct Coordinate Coordinate;

struct Coordiante {
    size_t x;
    size_t y;
    bool operator==(const Coordiante& destiny){
        return this->x == destiny.x && this->y == destiny.y;
    }
};

}  // namespace Structure