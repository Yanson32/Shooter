#include "Functions.h"
#include <SFML/System/Vector2.hpp>
#include "Settings.h"

float METERPIXLERATIO = Settings::boxPixRatio;

float32 toMeters(const float &pixles)
{
    return float32(pixles / METERPIXLERATIO);
}

float toPixles(const float32 &meters)
{
    return meters * METERPIXLERATIO;
}


b2Vec2 toMeters(const sf::Vector2f &pixles)
{
    return b2Vec2(toMeters(pixles.x), toMeters(pixles.y));
}


sf::Vector2f toPixles(const b2Vec2 &meters)
{
    return sf::Vector2f(toPixles(meters.x), toPixles(meters.y));
}
