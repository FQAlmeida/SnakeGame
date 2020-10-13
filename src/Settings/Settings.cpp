#include "./Settings.hpp"

namespace Settings {
Settings* Settings::instance = nullptr;

Settings::Settings() {
    std::ifstream settings_file{"./config/config.json"};
    this->json = nlohmann::json::parse(settings_file);
    settings_file.close();
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
nlohmann::json& Settings::get_config() {
    return this->json;
}
Settings::~Settings() {
}
}  // namespace Settings
