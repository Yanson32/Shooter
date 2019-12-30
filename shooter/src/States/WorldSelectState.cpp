#include "States/WorldSelectState.h"
#include <GameUtilities/Event/EventManager.h>
#include "Editor/Functions.h"
#include "Settings.h"
#include <iostream>
#include <GameUtilities/Event/EventManager.h>
#include <GameUtilities/Event/PushState.h>

WorldSelectState::WorldSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, newMap, newId)
{
    //ctor
    currentWorldLabel = tgui::Label::create(toString(static_cast<int>(Settings::currentWorld)));
    gui.add(currentWorldLabel);
}


/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void WorldSelectState::Init()
{
    gui.add(currentWorldLabel);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void WorldSelectState::Clean()
{
    gui.removeAllWidgets();
}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void WorldSelectState::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
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
    while(GU::Evt::EventManager::inst().Poll((evtPtr)))
    {
        handleGUEvent(engin, evtPtr);
    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void WorldSelectState::Update(GU::Engin::Engin& engin, const float &deltaTime)
{
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void WorldSelectState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear();
    gui.draw();
    window.display();
}


void WorldSelectState::handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event)
{
    StateBase::handleSFEvent(engin, event);

    switch(event.type)
    {
        case sf::Event::KeyPressed:
            if(event.key.code == Settings::left)
            {
                if(Settings::currentWorld > 1)
                    Settings::currentWorld -= 1;

            }

            if(event.key.code == Settings::right)
            {
                if(Settings::currentWorld < Settings::unlockeWorld)
                {
                    Settings::currentWorld += 1;
                }
            }
            currentWorldLabel->setText(toString(static_cast<int>(Settings::currentWorld)));


        break;
        case sf::Event::KeyReleased:
            if(event.key.code == sf::Keyboard::Enter)
            {
                GU::Evt::EventManager::inst().Post<GU::Evt::PushState>(States::Id::LEVEL_SELECT_STATE);
            }
        break;
    }


}


WorldSelectState::~WorldSelectState()
{
    //dtor
}
