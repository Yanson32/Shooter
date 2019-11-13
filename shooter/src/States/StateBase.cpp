#include "States/StateBase.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include "Settings.h"
#include <GameUtilities/Engin/Engin.h>
#include "Events/Id.h"
#include "Events/Events.h"
#include "States/Id.h"
#include "States/States.h"

//sf::RenderWindow StateBase::window(sf::VideoMode({800, 600}), Settings::inst().getTitle());
//tgui::Gui StateBase::gui(window);

StateBase::StateBase(sf::RenderWindow &newWindow, tgui::Gui &newGui):
window(newWindow),
gui(newGui)
{
    //ctor
}


void StateBase::handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event)
{
    switch(event->id)
    {
        case Events::Id::PUSH_STATE:
            std::shared_ptr<GU::Evt::PushState> temp =  std::dynamic_pointer_cast<GU::Evt::PushState>(event);
            if(temp)
            {
                switch(temp->id)
                {
                    case States::Id::PLAY_STATE:
                        engin.Push<PlayState>(window, gui);
                    break;
                    case States::Id::MAP_CREATOR_STATE:
                        engin.Push<MapCreatorState>(window, gui);
                    break;
                }
            }
        break;
    }
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