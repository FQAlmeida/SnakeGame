#pragma once
// Global
#include <cstddef>
#include <fstream>
// Local
#include "../../ThirdParty/json.hpp"
#include "../Typedefs/Typedef.hpp"
// TP

namespace Settings {

typedef struct Screensize Screensize;
struct Screensize {
    uint height;
    uint width;
};

class Settings {
   protected:
    static Settings *instance;

   private:
    nlohmann::json json;

   public:
    static Settings *get_instance();
    static void iniatilize();

   public:
    Settings();
    ~Settings();
    void set_screensize(uint height, uint width);
    uint get_height();
    uint get_width();
    Screensize get_screensize();
    nlohmann::json& get_config();
};

}  // namespace Settings
