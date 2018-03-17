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

Settings::~Settings()
{
    //dtor
}
