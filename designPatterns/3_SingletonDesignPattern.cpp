#include <iostream>
#include <string>

class GameSetting {
    static GameSetting* _instance;
    int _brightness = 0, _width = 0, _height = 0;
    GameSetting() :_width{ 786 }, _height{ 1300 }, _brightness{ 75 }{};
public:
    static GameSetting* getInstance() {
        if (_instance == nullptr) {
            _instance = new GameSetting();
        }
        return _instance;
    }

    void setWidth(int width) { this->_width = width; }
    void setHeight(int height) { this->_height = height; }
    void setBrightness(int brightness) { this->_brightness = brightness; }

    int getWidth() { return this->_width; }
    int getHeight() { return this->_height; }
    int getBrightness() { return this->_brightness; }

};

GameSetting* GameSetting::_instance = nullptr;

int main(int argc, char const* argv[]) {
    GameSetting* instance = GameSetting::getInstance();

    if (instance == nullptr) {
        std::cout << "Could not load Game Settings !" << std::endl;
        exit(0);
    }

    instance->setHeight(720);
    instance->setWidth(1368);
    instance->setBrightness(80);

    std::cout << "Height, Width, Brightness = "
        << instance->getHeight() << " "
        << instance->getWidth() << " "
        << instance->getBrightness() << std::endl;

    return 0;
}
