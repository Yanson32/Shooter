#ifndef SETTINGS_H
#define SETTINGS_H
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>

class Settings
{
    public:
        sf::String getTitle() const;
        sf::Vector2f buttonPosition(const unsigned pos = 0) const;
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
