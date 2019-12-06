#ifndef SETTINGS_H
#define SETTINGS_H
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Common/b2Math.h>


namespace Settings
{
    extern sf::String title;
    extern sf::Vector2f buttonSize;
    extern sf::Vector2f screen;
    extern sf::String name;
    extern sf::String difficulty;
    extern int effectVolume;
    extern int musicVolume;
    extern sf::Keyboard::Key up;
    extern sf::Keyboard::Key down;
    extern sf::Keyboard::Key left;
    extern sf::Keyboard::Key right;
    extern sf::Keyboard::Key jump;
    extern sf::Keyboard::Key action;
    extern sf::Color background;
    extern int port;
    extern float32 velocityIterations;
    extern sf::String currentMap;
    extern int32 positionIterations;
    extern float32 timeStep;
    extern sf::String levelDirectory;
    extern sf::String currentMap;
    extern std::string map;
    extern float boxPixRatio;
}
#endif // SETTINGS_H
