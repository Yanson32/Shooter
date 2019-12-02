#ifndef SHOOTER_HANDLESFEVENT_H
#define SHOOTER_HANDLESFEVENT_H
#include <SFML/Window/Event.hpp>
#include <GameUtilities/Engin/Engin.h>

class SFEventHandler
{
    public:
        virtual void handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event) = 0;
};

#endif // SHOOTER_HANDLESFEVENT_H
