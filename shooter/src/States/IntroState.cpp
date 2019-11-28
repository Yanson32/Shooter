#include "States/IntroState.h"
#include "States/Id.h"
#include <SFML/Window/Event.hpp>
#include "Events/EventManager.h"
#include <iostream>
#include "Settings.h"
#include "Events/Events.h"
#include "Gui/IntroPanel.h"
#include "Settings.h"
#include "Gui/MapLoader.h"
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
//tgui::Gui IntroState::gui(window);

IntroState::IntroState(sf::RenderWindow &newWindow, tgui::Gui &newGui):
StateBase(newWindow, newGui, States::Id::INTRO_STATE)
{
    //ctor
    //panel.reset(new IntroPanel());
    //gui.add(panel);

}

/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void IntroState::Init()
{
//    gui.add(startButton);
//    gui.add(multiplayerButton);
//    gui.add(optionButton);
//    gui.add(mapButton);
    switch(panelId)
    {
        case Gui::id::MAP_LOADER:
            panel.reset(new MapLoader());
        break;
        default:
            panel.reset(new IntroPanel());
    };

    gui.add(panel);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void IntroState::Clean()
{
    gui.removeAllWidgets();
}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
{
    if(window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            handleSFEvent(engin, event);
            gui.handleEvent(event);
        }
    }

    //GameUtilities event loop
    GU::Evt::EventPtr evtPtr;
    while(EventManager::inst().Poll((evtPtr)))
    {
        handleGUEvent(engin, evtPtr);
    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::Update(GU::Engin::Engin& engin, const float &deltaTime)
{

}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear(Settings::background);
    gui.draw();
    window.display();
}

void IntroState::handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event)
{
    StateBase::handleGUEvent(engin, event);

    switch(event->id)
    {
        case Events::Id::CLICK:
            std::shared_ptr<GU::Evt::Click> temp =  std::dynamic_pointer_cast<GU::Evt::Click>(event);
            switch(temp->buttonId)
            {
                case Gui::id::MAP_LOADER:
                    this->panelId = Gui::id::MAP_LOADER;
                break;
            }
        break;

    }
}

IntroState::~IntroState()
{
    //dtor
}
