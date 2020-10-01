#include "./Settings.hpp"

namespace Settings {
Settings::Settings() {
    std::ifstream settings_file{"config.json"};
}
Screensize Settings::get_screensize() {
    return {600, 800};
}
uint Settings::get_height() {
    return 600;
}
uint Settings::get_width() {
    return 800;
}

void Settings::iniatilize() {
    instance = new Settings;
}

Settings* Settings::get_instance() {
    if (instance == nullptr) {
        iniatilize();
    }
    return instance;
}
Settings::~Settings() {
}
}  // namespace Settings
