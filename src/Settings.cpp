#include "Settings.h"

Settings::Settings():m_ButtonSize({300, 50})
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
    static sf::Vector2f bPosition(250, 350);
    sf::Vector2f temp = bPosition;
    temp.y += 50 * pos;

    return temp;
}


sf::Vector2f Settings::buttonSize() const
{
    return m_ButtonSize;
}

Settings::~Settings()
{
    //dtor
}
