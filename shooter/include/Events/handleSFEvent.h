#ifndef SHOOTER_HANDLESFEVENT_H
#define SHOOTER_HANDLESFEVENT_H
#include <SFML/Windows/Event.hpp>

class SFEventHandler
{
    public:
        virtual void handleSFEvent(const sf::Event &event) = 0;
};

#endif // SHOOTER_HANDLESFEVENT_H
