#include "Engin/StateBase.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include "Settings.h"
#include <GameUtilities/Engin/Engin.h>

sf::RenderWindow StateBase::window(sf::VideoMode({800, 600}), Settings::inst().getTitle());
tgui::Gui StateBase::gui(window);

StateBase::StateBase()
{
    //ctor
}


void StateBase::handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event)
{
    std::cout << "Gu event " << std::endl;
}

void StateBase::handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event)
{
    switch(event.type)
    {
        case sf::Event::Closed:
            engin.Quit();
        break;
    }
}

StateBase::~StateBase()
{
    //dtor
}
