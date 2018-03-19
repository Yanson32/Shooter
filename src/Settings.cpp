#include "Settings.h"

Settings::Settings()
{
    //ctor
    title = "Shooter";
}

sf::String Settings::getTitle() const
{
    return title;
}

Settings& Settings::inst()
{
    static Settings settings;
    return settings;
}

sf::Vector2f Settings::buttonPosition(const unsigned pos) const
{
    static sf::Vector2f bPosition(100, 100);
    sf::Vector2f temp = bPosition;
    temp.y += 50 * pos;

    return temp;
}

Settings::~Settings()
{
    //dtor
}
