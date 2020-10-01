#pragma once
// Global
#include <cstddef>
#include <fstream>
// Local
#include "../../ThirdParty/json.hpp"
#include "../Typedefs/Typedef.hpp"

namespace Settings {

typedef struct Screensize Screensize;
struct Screensize {
    uint height;
    uint width;
};

class Settings {
   private:
    Settings *instance;

   public:
    Settings *get_instance();
    void iniatilize();
    Settings();
    ~Settings();
    void set_screensize(uint height, uint width);
    uint get_height();
    uint get_width();
    Screensize get_screensize();
};

}  // namespace Settings
