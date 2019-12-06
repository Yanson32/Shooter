#include "Settings.h"

namespace Settings
{
    sf::String title = "Shooter";
    sf::Vector2f buttonSize(300, 50);
    sf::Vector2f screen(800, 450);
    sf::String name = "Player";
    sf::String difficulty = "Normal";
    int effectVolume = 10;
    int musicVolume = 10;
    sf::Keyboard::Key up = sf::Keyboard::W;
    sf::Keyboard::Key down = sf::Keyboard::S;
    sf::Keyboard::Key left = sf::Keyboard::A;
    sf::Keyboard::Key right = sf::Keyboard::D;
    sf::Keyboard::Key jump = sf::Keyboard::Space;
    sf::Keyboard::Key action = sf::Keyboard::J;
    sf::Color background = sf::Color::Black;
    int port = 5000;
    float32 velocityIterations = 8;
    int32 positionIterations = 3;
    float32 timeStep = 1.0/60.0;
    sf::String levelDirectory = "/home/me/Desktop/MyStuff/programming/Shooter/shooter/Assets/Level";
    sf::String currentMap = "";
    std::string map;
    float boxPixRatio = 30;
}
