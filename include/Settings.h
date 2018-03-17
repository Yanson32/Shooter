#ifndef SETTINGS_H
#define SETTINGS_H
#include <SFML/System/String.hpp>

class Settings
{
    public:
        sf::String getTitle() const;
        static Settings& inst();
    private:
        sf::String title;
        Settings();
        Settings operator = (const Settings settings) = delete;
        Settings(const Settings &settings) = delete;
        virtual ~Settings();
    protected:
    private:
};

#endif // SETTINGS_H
